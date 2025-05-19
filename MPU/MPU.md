
# Memory region, type và attributes

 __MPU__ chia __Memory__ map thành nhiều __vùng (region)__, mỗi vùng có 1 __thuộc tính (memory type)__ xác định, có thể có thêm các __thuộc tính bổ sung (memory attributes)__.

 ## Memory Types

 `Normal`: Processor có thể __thay đổi thứ tự truy cập (re-oder)__ để tăng hiệu quả, hoặc __đọc dự đoán (speculative reads)__.

 `Device`: Processor __giữ nguyên thứ tự truy cập bộ nhớ__ so với các truy cập khác đến `Device` hoặc `Strongly-ordered`.

 `Strongly-ordered`: Processor __giữ thứ tự nghiêm ngặt__ giữa mọi truy cập bộ nhớ. Đây là loại nghiêm ngặt nhất.

 __GHI CHÚ:__
 Khác biệt giữa `Device` và `Strongly-ordered` là:
 - Với `Device`, hệ thống bộ nhớ có thể __buffer (đệm)__ việc ghi.
 - Với `Strongly-ordered`, __không được phép buffer__ → phải hoàn tất ghi trước khi tiến hành truy cập tiếp theo.


 ## Memory Attributes - Các thuộc tính vùng nhớ bổ sung

 `Shareable`: 
    - Nếu một vùng nhớ được đánh dấu là __"chia sẻ được" (shareable)__, thì __bộ nhớ hệ thống đảm bảo đồng bộ dữ liệu giữa các master__ (ví dụ: CPU và DMA cùng truy cập).
    - `Strongly-ordered memory` luôn luôn là `shareable`.   
    - Nếu __vùng không chia sẻ được (non-shareable)__ mà có nhiều master truy cập → phần mềm __phải tự đảm bảo tính nhất quán dữ liệu__.

 `Execute Never (XN)`: __Không cho phép thực thi mã lệnh__ từ vùng này. Nếu CPU cố gắng thực thi lệnh từ vùng bị gán XN, __sẽ sinh ra lỗi MemManage fault__.


# MPU

## Chế độ phân quyền truy cập bộ nhớ (privilege levels)
Trong kiến trúc ARM Cortex-M3 `privilege levels`  là một khái niệm cốt lõi trong việc dùng MPU và cũng là cơ chế bảo vệ kiểu hệ điều hành trên ARM Cortex-M. Có 2 chế độ thực thi chính:

 `Privileged`: Quyền Hệ Thống - Được phép truy cập mọi vùng nhớ, kể cả các vùng hạn chế. Thường dùng cho kernel, trình xử lý ngắt, RTOS scheduler, hoặc startup code


 `Unprivileged`: Quyền hạn chế - Bị giới hạn truy cập theo quy định của MPU. Chỉ được truy cập những vùng được phép trong cấu hình MPU. Thường dùng cho ứng dụng người dùng, task trong RTOS, hoặc plugin.

# Cấu trúc và chức năng MPU

MPU Hỗ trợ:
- Thiết lập `memory attribute` riêng cho từng phần
- Cho phép các vùng chồng lên nhau (overlapping regions)
- Xuất `memory attributes` ra hệ thống để sử dụng 

MPU trong Cortex-M3 định nghĩa:
- 8 `memory regions` riêng biệt từ 0-7
- 1 `background region`: là vùng nhớ chỉ phần mềm ở chế độ `Privileged` mới có thể truy cập. 
- `background region`: 
    - Chỉ tồn tại khi bật bit `PRIVDEFENA` trong thanh ghi `MPU_CTRL`
    - Không có cấu hình `AP, XN,...` riêng như các vùng MPU bình thường.
    - Có thể coi như "default access" cho kernel, trong khi user phải đi qua MPU region.

Nếu chương trình cố truy cập vào vùng mà MPU không cho phép -> Sinh ra lỗi `MemManage fault` và 1 exception sẽ được gọi.

# Chức năng các thanh ghi

`MPU_CTRL`: 
    - `PRIVDEFENA`: enable backfground region cho privileged 
    - `HFNMIENA`:  Cho phép MPU hoạt động trong NMI và HardFault handler
    - `ENABLE`  : Bật MPU hoạt động

`MPU_RNR` :
    - `REGION` : Chọn số thứ tự của vùng (0–7) để cấu hình
    - Có thể ghi vào thanh ghi `MPU_RBAR` và `MPU_RASR`, nó sẽ áp dụng lên vùng được chọn bởi `MPU_RNR`.

`MPU_RBAR` :
    - `ADDR` : Địa chỉ bắt đàu của vùng 
    - `VALID` : bật = 1 => dùng `REGION` trong `RBAR` và cập nhật vào `MPU_RNR`, nếu = 0 thì phải tự ghi vào `MPU_RNR->REGION` trước.
    - `REGION` : Chọn số thứ tự của vùng (0–7) để cấu hình, chỉ có ý nghĩa khi `VALID` = 1

`MPU_RASR` : Cấu hình toàn bộ thuộc tính bảo vệ, quyền truy cập, kích thước, và kiểm soát thực thi cho 1 vùng MPU đã chọn.
    - `XN` : Execute Never: Nếu = 1, cấm thực thi mã lệnh từ vùng này
    - `AP` : Access Permission: Quyền truy cập (RW/RO, privileged/unprivileged)
    - `TEX - S - C -B`: Memory Type Extension: định loại vùng nhớ (Normal, Device, etc.), Shareable, Cacheable, Bufferable.
    - `SRD` : Subregion Disable: Mỗi bit tắt 1 phần 1/8 vùng nhớ
    - `SIZE` : Kích thước vùng nhớ: Giá trị mã hoá 2^(SIZE+1)
    - `ENABLE` : Bật vùng: =1 thì vùng này được kích hoạt và kiểm soát bởi MPU

# Cấu hình MPU theo các chức năng

Cấu hình từng region như sau:
Đầu tiên phải disable toàn bộ MPU:`MPU_CTRL->CTRL`

Tiếp theo chọn region:` MPU_RNR->REGION` hoặc `MPU_RBAR->REGION`
Chọn địa chỉ bắt đầu cho region: `MPU_RBAR->ADDR`
    Nếu chọn region trong `MPU_RBAR->REGION` thì phải bật `VALID` lên 1.
Cấu hình ` attribute type `, size region, quyền truy cập (Privileged/Unprivileged), subregion :
    Kích thước của vùng nhớ: `MPU_RASR->SIZE`
    Quyền truy cập cho (Privileged/Unprivileged): `MPU_RASR->AP`
    Chọn `memory type`, `shareability` và `attribute type` từ MPU_RASR: `TEX - S - C -B`
    Chọn quyền cho phép/từ chối thực thi lệnh từ region:  `MPU_RASR->XN`
    Chọn disable MPU 1 subregion nhỏ trong region chính:  `MPU_RASR->SRD`
`MPU_RASR` : Cấu hình toàn bộ thuộc tính bảo vệ, quyền truy cập, kích thước, và kiểm soát thực thi cho 1 vùng MPU đã chọn.
    Enable region: `MPU_RASR->ENABLE`
Tiếp tục cấu hình các region như trên:

Sau khi cấu hình xong các region -> Cấu hình tổng quát và kích hoạt MPU trong: `MPU_CTRL`
    Có bật chế độ background region cho các vùng ngoài region hay không: `MPU_CTRL->PRIVDEFENA`
    Có cho phép MPU hoạt đông khi HMI và HardFault không: `MPU_CTRL->HFNMIENA`
    Có sử dụng MemFault để xử lý lỗi hay không: `SCB`
        Bật thanh ghi `MMARVALID` để kích hoạt `MemFault`
        Đọc lỗi và địa chỉ lỗi tại `MMFSR` và `MMFAR`
    Kích hoạt toàn bộ MPU: `MPU_CTRL->CTRL`

Sử dụng intrinsic functions đảm bảo MPU, cache, và peripheral hoạt động đúng ngay sau khi thay đổi:
    `__DSB();`         // Đảm bảo tất cả thay đổi bộ nhớ đã xong
    `__ISB();`         // Cập nhật lại pipeline để dùng cấu hình mới


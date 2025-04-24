/***************************************************************************
 * @file    baitap1.c
 * @brief   Định nghĩa và triển khai các hàm thao tác với mảng (array)
 * @details File này định nghĩa các hàm sử dụng thao tác với linked list bao gồm:
 *          khởi tạo mảng 1 chiều, 2 chiều, sắp xếp và tìm kiếm.
 * @version 1.0
 * @date    2025-04-16
 * @author  LongTruong
 ***************************************************************************/
/* ==================================================[ INCLUDE FILE ]====================================================*/
#include <stdio.h>              /**< Thư viện chứa hàm in ra màn hình    >**/
#include <stdlib.h>             /**< Thư viện chứa hàm malloc, free      >**/

/* =================================================[ TYPE DEFINITIONS ]==================================================*/

#define NOT_FOUNDED -1          /**< Kiểu trả về nếu không tim thấy      >**/

void (*sortType)(int*) = NULL;  /**< Con trỏ hàm chọn theo kiểu sắp xếp      >**/
int (*check)(int,int) = NULL;   /**< Con trỏ hàm chọn theo kiểu tìm kiếm     >**/

/* ==============================================[ FUNCTION INPLEMENTATION ]==============================================*/
/*================== [Nhập/in dữ liệu]=================*/
/**
 * @brief   Nhập phần tử mảng từ bàn phím
 * @param   arr   Con trỏ trỏ đến mảng.
 * @param   row   Số hàng của mảng 2 chiều.
 * @param   col   Số cột của mảng 2 chiều.
 *                Số phần tử của mảng 1 chiều.
 * @return  void
 **/
static void input_Data(int **arr, int row, int col);

/**
 * @brief   Hiển thị mảng ra cmd
 * @param   arr[]   Mảng cần hiển thị
 * @param   size    Kích thước mảng
 * @return  void
 **/
void print_Array(int arr[], int size);

/**
 * @brief   Hiển thị mảng ra cmd
 * @param   arr     Con trỏ chứa mảng cần hiển thị
 * @param   row     Kích thước hàng của mảng 2 chiều
 * @param   col     Kích thước cột của mảng 2 chiều
 * @return  void
 **/
void print_Array_by_Poiter(int **ptr, int row, int col);


/*============= [Khởi tạo/ giải phóng mảng]=============*/
/**
 * @brief   Khởi tạo và trả về mảng 1 chiều
 * @param   n     Kích thước của mảng
 * @return  int*  Con trỏ hàm khởi tạo
 **/
static int *create_Array(int n);

/**
 * @brief   Khởi tạo và trả về mảng 2 chiều
 * @param   row     Kích thước hàng của mảng 2 chiều
 * @param   col     Kích thước cột của mảng 2 chiều
 * @return  int*    Con trỏ hàm khởi tạo
 **/
static int **create_Array2chieu(int row, int col);


/**
 * @brief   Giải phóng mảng 2 chiều
 * @param   arr     Con trỏ chứa mảng cần giải phóng
 * @param   row     Kích thước hàng của mảng 2 chiều
 * @param   col     Kích thước cột của mảng 2 chiều
 * @return  void
 **/
static void free_Array2chieu(int **arr,int row, int col);


/*============= [Sắp xếp và Tìm kiếm mảng]=============*/
/**
 * @brief   Hàm biến đổi sắp xếp tăng
 * @param   count   Con trỏ phần tử cần biến đổi
 * @return  void
 **/
static void sortUp(int *count);

/**
 * @brief   Hàm biến đổi sắp xếp giảm
 * @param   count   Con trỏ phần tử cần biến đổi
 * @return  void
 **/
static void sortDown(int *count);

/**
 * @brief   Hàm so sánh tìm kiếm tăng
 * @param   a   phần tử cần so sánh
 * @param   b   phần tử cần so sánh
 * @return  int kết quả so sánh
 **/
static int checkUp(int a, int b);

/**
 * @brief   Hàm so sánh tìm kiếm giảm
 * @param   a   phần tử cần so sánh
 * @param   b   phần tử cần so sánh
 * @return  int kết quả so sánh
 **/
static int checkDown(int a, int b);

/**
 * @brief   Chọn chế độ sắp xếp và tìm kiếm tăng
 * @param   void   
 * @return  void
 **/
static void modeUp(void);

/**
 * @brief   Chọn chế độ sắp xếp và tìm kiếm giảm
 * @param   void   
 * @return  void
 **/
static void modeDown(void);

/**
 * @brief   Hàm lấy chữ số tại vị trí 'exp' (1, 10, 100, ...)
 * @param   num   Số cần lấy số
 * @param   exp   vị trí cần lấy số (hàng trăm, chục,...)
 * @return  int   số tại vị trí cần lấy
 **/
static int getDigit(int num, int exp);

/**
 * @brief   Hàm Counting Sort theo chữ số
 * @param   arr[]   Mảng cần sắp xếp
 * @param   n       Kích thước mảng
 * @param   exp     Vị trí lấy số sắp xếp theo
 * @return  void    
 **/
static void countingSort(int arr[], int n, int exp);

/**
 * @brief   Hàm Radix Sort chính
 * @param   arr[]   Mảng cần sắp xếp
 * @param   n       Kích thước mảng
 * @return  void    
 **/ 
void radixSort(int arr[], int n);

/**
 * @brief   Hàm đệ quy tìm kiếm nhị phân
 * @param   arr     Con trỏ mảng cần sắp xếp
 * @param   left    Phần tử bên trái cần kiểm tra
 * @param   right   Phần tử bên phải cần kiểm tra
 * @param   data    Giá trị cần tìm kiếm
 * @return  int    
 **/ 
static int searching(int *arr, int left, int right, int data);

/**
 * @brief   Hàm khởi tạo tìm kiếm nhị phân
 * @param   arr     Con trỏ mảng cần sắp xếp
 * @param   n       Kích thước mảng
 * @param   data    Giá trị cần tìm kiếm
 * @return  int    
 **/
int binarySearch(int *arr, int n, int data);

/**
 * @brief   Hàm triển khai và xử lý mảng 2 chiều
 * @param   void
 * @return  void    
 **/ 
void mang_2_Chieu();

/**
 * @brief   Hàm triển khai và xử lý mảng 1 chiều
 * @param   void
 * @return  void    
 **/ 
void mang_1_Chieu();

/*========================= [MAIN]========================*/
int main(){
    int soChieu = 1;
    do{
        if((soChieu != 1) && (soChieu != 2)){
            printf(" Chon sai vui long chon lai!\n");
        }
        printf(" Lua chon array can su dung: 1. Array 1 chieu  2. Array 2 chieu: ");
        scanf("%d", &soChieu);
    }while((soChieu != 1) && (soChieu != 2));
    
    switch (soChieu)
    {
    case 2:
        mang_2_Chieu();
        break;
    case 1:
    default:
        mang_1_Chieu();
        break;
    }
    return 0;
}


/*============== [Khởi tạo/ giải phóng mảng]==============*/
/**
 * @brief   Khởi tạo và trả về mảng 1 chiều
 * @param   n     Kích thước của mảng
 * @return  int*  Con trỏ hàm khởi tạo
 **/
static int *create_Array(int n){
    int *arr = (int *)malloc(n * sizeof(int)); 
    return (int *)arr;
}

/**
 * @brief   Khởi tạo và trả về mảng 2 chiều
 * @param   row     Kích thước hàng của mảng 2 chiều
 * @param   col     Kích thước cột của mảng 2 chiều
 * @return  int*    Con trỏ hàm khởi tạo
 **/
static int **create_Array2chieu(int row, int col){
    int **arr = (int **)malloc(row * sizeof(int *));
    for(int i = 0; i < row; i++){
        arr[i] = (int *)malloc(col * sizeof(int));
    }
    return (int **)arr;
}

/**
 * @brief   Giải phóng mảng 2 chiều
 * @param   arr     Con trỏ chứa mảng cần giải phóng
 * @param   row     Kích thước hàng của mảng 2 chiều
 * @param   col     Kích thước cột của mảng 2 chiều
 * @return  void
 **/
static void free_Array2chieu(int **arr,int row, int col){
    for(int i = 0; i < row; i++){
        free(arr[i]);
    }
    free(arr);
}


/*================= [Nhập/in dữ liệu]================*/
/**
 * @brief   Hiển thị mảng ra cmd
 * @param   arr[]   Mảng cần hiển thị
 * @param   size    Kích thước mảng
 * @return  void
 **/
void print_Array(int arr[], int size){
    for(int i = 0; i < size; i++){
        printf("arr[%d]= %d\t", i, arr[i]);
    }
}

/**
 * @brief   Hiển thị mảng ra cmd
 * @param   arr     Con trỏ chứa mảng cần hiển thị
 * @param   row     Kích thước hàng của mảng 2 chiều
 * @param   col     Kích thước cột của mảng 2 chiều
 * @return  void
 **/
void print_Array_by_Poiter(int **arr, int row, int col){
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            printf("arr[%d][%d] = %d \t", i, j, arr[i][j]);
            
        }
        printf("\n");
    }
}

/**
 * @brief   Nhập phần tử mảng từ bàn phím
 * @param   arr   Con trỏ trỏ đến mảng.
 * @param   row   Số hàng của mảng 2 chiều.
 * @param   col   Số cột của mảng 2 chiều.
 *                Số phần tử của mảng 1 chiều.
 * @return  void
 **/
static void input_Data(int **arr, int row, int col){
    if(row == 0){
        for(int j = 0; j < col; j++){
            printf("Nhap arr[%d]: ",j);
            scanf("%d",&(*arr)[j]);
        }
        return;
    }
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            printf("Nhap arr[%d][%d]: ", i, j);
            scanf("%d",&arr[i][j]);
        }
    }
}



/*============= [Sắp xếp và Tìm kiếm mảng]=============*/
/**
 * @brief   Hàm lấy chữ số tại vị trí 'exp' (1, 10, 100, ...)
 * @param   num   Số cần lấy số
 * @param   exp   vị trí cần lấy số (hàng trăm, chục,...)
 * @return  int   số tại vị trí cần lấy
 **/
static int getDigit(int num, int exp) {
    return (num / exp) % 10;
}

/**
 * @brief   Hàm biến đổi sắp xếp tăng
 * @param   count   Con trỏ phần tử cần biến đổi
 * @return  void
 **/
static void sortUp(int *count){
    for (int i = 1; i < 10; i++){
        count[i] += count[i - 1];
    }
}

/**
 * @brief   Hàm biến đổi sắp xếp giảm
 * @param   count   Con trỏ phần tử cần biến đổi
 * @return  void
 **/
static void sortDown(int *count){
    for (int i = 8; i >= 0 ; i--){
        count[i] += count[i + 1];
    }
}

/**
 * @brief   Hàm so sánh tìm kiếm tăng
 * @param   a   phần tử cần so sánh
 * @param   b   phần tử cần so sánh
 * @return  int kết quả so sánh
 **/
static int checkUp(int a, int b){
    return (a > b);
}

/**
 * @brief   Hàm so sánh tìm kiếm giảm
 * @param   a   phần tử cần so sánh
 * @param   b   phần tử cần so sánh
 * @return  int kết quả so sánh
 **/
static int checkDown(int a, int b){
    return (a < b);
}

/**
 * @brief   Chọn chế độ sắp xếp và tìm kiếm tăng
 * @param   void   
 * @return  void
 **/
static void modeUp(void){
    sortType = sortUp;
    check = checkUp;
}

/**
 * @brief   Chọn chế độ sắp xếp và tìm kiếm giảm
 * @param   void   
 * @return  void
 **/
static void modeDown(void){
    sortType = sortDown;
    check = checkDown;
}

/**
 * @brief   Hàm Counting Sort theo chữ số
 * @param   arr[]   Mảng cần sắp xếp
 * @param   n       Kích thước mảng
 * @param   exp     Vị trí lấy số sắp xếp theo
 * @return  void    
 **/
static void countingSort(int arr[], int n, int exp){
    int output[n];
    int count[10] = {0};

    // Đếm số lượng chữ số tại vị trí exp
    for (int i = 0; i < n; i++){
        count[getDigit(arr[i], exp)]++;
    }

    // Cộng dồn để xác định vị trí -> xác định theo Tăng dần or Giảm dần
    sortType(count);
    
    // Sắp xếp tạm vào output (đi từ cuối để đảm bảo ổn định)
    for (int i = n - 1; i >= 0; i--) {
        int digit = getDigit(arr[i], exp);
        output[--count[digit]] = arr[i];
    }

    // Copy lại vào arr
    for (int i = 0; i < n; i++){
        arr[i] = output[i];
    }
}

/**
 * @brief   Hàm Radix Sort chính
 * @param   arr[]   Mảng cần sắp xếp
 * @param   n       Kích thước mảng
 * @return  void    
 **/ 
void radixSort(int arr[], int n) {
    // Tìm số lớn nhất để biết có bao nhiêu chữ số
    int maxVal = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > maxVal){
            maxVal = arr[i];
        }     

    // Thực hiện Counting Sort cho mỗi chữ số
    for (int exp = 1; maxVal / exp > 0; exp *= 10)
        countingSort(arr, n, exp);
}

/**
 * @brief   Hàm đệ quy tìm kiếm nhị phân
 * @param   arr     Con trỏ mảng cần sắp xếp
 * @param   left    Phần tử bên trái cần kiểm tra
 * @param   right   Phần tử bên phải cần kiểm tra
 * @param   data    Giá trị cần tìm kiếm
 * @return  int    
 **/ 
static int searching(int *arr, int left, int right, int data){
    if(left > right){
        return NOT_FOUNDED;
    }

    int mid = (left + right) / 2;

    if(arr[mid] == data){
        return mid;
    }
    else if(check(arr[mid], data)){
        return searching(arr, left, mid - 1, data);
    }
    else{
        return searching(arr, mid + 1, right, data);
    }
}

/**
 * @brief   Hàm khởi tạo tìm kiếm nhị phân
 * @param   arr     Con trỏ mảng cần sắp xếp
 * @param   n       Kích thước mảng
 * @param   data    Giá trị cần tìm kiếm
 * @return  int    
 **/ 
int binarySearch(int *arr, int n, int data){ 
    return searching(arr, 0, n - 1, data);
}

/**
 * @brief   Hàm triển khai và xử lý mảng 2 chiều
 * @param   void
 * @return  void    
 **/ 
void mang_2_Chieu(){
    int row, col;
    printf("Khoi tao mang 2 chieu voi kich thuoc nhu sau:\n");
    printf("Nhap so hang: ");
    scanf("%d",&row);
    printf("Nhap so cot: ");
    scanf("%d",&col);

    int **arr = create_Array2chieu(row,col);

    input_Data(arr,row,col);
    print_Array_by_Poiter(arr,row,col);

    free_Array2chieu(arr, row, col);
}

/**
 * @brief   Hàm triển khai và xử lý mảng 1 chiều
 * @param   void
 * @return  void    
 **/ 
void mang_1_Chieu(){
    int size;
    int flag_sort = 1;
    int search_Data;
    printf("Khoi tao mang 1 chieu voi kich thuoc nhu sau:\n");
    printf("Nhap so phan tu: ");
    scanf("%d",&size);

    int *arr = create_Array(size);

    input_Data(&arr,0,size);
    print_Array(arr,size);

    do{
        if((flag_sort != 1) && (flag_sort != 2)){
            printf(" Chon sai vui long chon lai!\n");
        }
        printf("\nLua chon kieu sap xep: 1. Tang dan    2. Giam dan: ");
        scanf("%d", &flag_sort);
    }while((flag_sort != 1) && (flag_sort != 2));
    
    (flag_sort == 1) ? modeUp() : modeDown();

    radixSort(arr, size);

    printf("Mang sau khi sap xep:\n");
    print_Array(arr, size);

    printf("\nNhap so can tim kiem: \n");
    scanf("%d", &search_Data);

    int search = binarySearch(arr, size, search_Data);
    if(search == NOT_FOUNDED){
        printf("NOT FOUNDED\n");
    }
    else{
        printf("Pos %d: %d\n", search, search_Data);
    }

    free(arr);
}

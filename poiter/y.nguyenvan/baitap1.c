#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>

/**
 * @brief Định nghĩa kiểu callback cho các hàm so sánh.
 *        Các hàm này sẽ được sử dụng trong thuật toán sắp xếp.
 */
typedef bool (*callback)(int, int);

/**
 * @brief Hàm in ra mảng theo thứ tự tăng dần.
 */
void functionA(void)
{
    int array[5] = {1, 2, 3, 4, 5};
    for (int i = 0; i < 5; i++)
    {
        printf("%d\t ", array[i]);
    }
}

/**
 * @brief Hàm in ra mảng theo thứ tự giảm dần.
 */
void functionB(void)
{
    printf("\n");
    int array[5] = {1, 2, 3, 4, 5};
    for (int i = 4; i >= 0; i--)
    {
        printf("%d\t ", *(array + i));
    }
    printf("\n");
}

/**
 * @brief Tạo một ma trận động với số hàng và số cột cho trước.
 * @param  sizeRow: Số lượng hàng của ma trận.
 * @param  sizeCol: Số lượng cột của ma trận.
 * @retval Trả về con trỏ tới ma trận động đã được cấp phát bộ nhớ.
 */
int **createFunctionC(int sizeRow, int sizeCol)
{
    int **array = (int **)malloc(sizeRow * sizeof(int *));
    for (int i = 0; i < sizeRow; i++)
    {
        array[i] = (int *)malloc(sizeCol * sizeof(int));
    }
    return array;
}

/**
 * @brief Nhập giá trị vào ma trận động.
 * @param  array: Con trỏ tới ma trận cần nhập dữ liệu.
 * @param  sizeRow: Số lượng hàng của ma trận.
 * @param  sizeCol: Số lượng cột của ma trận.
 */
void inputFunctionC(int **array, int sizeRow, int sizeCol)
{
    for (int i = 0; i < sizeRow; i++)
    {
        for (int j = 0; j < sizeCol; j++)
        {
            scanf("%d", (array[i] + j));
        }
    }
}

/**
 * @brief In ma trận ra màn hình.
 * @param  array: Con trỏ tới ma trận cần in.
 * @param  sizeRow: Số lượng hàng của ma trận.
 * @param  sizeCol: Số lượng cột của ma trận.
 */
void logFunctionC(int **array, int sizeRow, int sizeCol)
{
    for (int i = 0; i < sizeRow; i++)
    {
        printf("\n");
        for (int j = 0; j < sizeCol; j++)
        {
            printf("%d\t", *(array[i] + j));
        }
    }
}

/**
 * @brief Hàm kiểm tra và giải phóng bộ nhớ của ma trận động.
 */
void functionC(void)
{
    int **array = createFunctionC(3, 4);
    if (array != NULL)
    {
        inputFunctionC(array, 3, 4);
        logFunctionC(array, 3, 4);
        for (int i = 0; i < 3; i++)
        {
            free(array[i]);
            array[i] = NULL;
        }
        free(array);
        array = NULL;
        if (array == NULL)
        {
            printf("Free Done");
        }
    }
    else
    {
        printf("Bug");
    }
    printf("\n");
}

/**
 * @brief Hàm so sánh để sắp xếp theo thứ tự tăng dần.
 * @param a: Phần tử đầu tiên.
 * @param b: Phần tử thứ hai.
 * @retval true nếu a > b, ngược lại trả về false.
 */
bool increase(int a, int b)
{
    return a > b;
}

/**
 * @brief Hàm so sánh để sắp xếp theo thứ tự giảm dần.
 * @param a: Phần tử đầu tiên.
 * @param b: Phần tử thứ hai.
 * @retval true nếu a < b, ngược lại trả về false.
 */
bool decrease(int a, int b)
{
    return a < b;
}

/**
 * @brief Hàm sắp xếp mảng bằng thuật toán Bubble Sort với hàm so sánh truyền vào.
 * @param function: Con trỏ đến hàm callback để so sánh hai phần tử.
 *         - Nếu muốn sắp xếp tăng dần, truyền increase.
 *         - Nếu muốn sắp xếp giảm dần, truyền decrease.
 */
void bubbleSort(callback function)
{
    int array[5] = {1, 3, 2, 5, 4};
    for (int i = 0; i < 4; i++)
    {
        for (int k = i + 1; k < 5; k++)
        {
            if (function(array[i], array[k]))
            {
                int swap = array[i];
                array[i] = array[k];
                array[k] = swap;
            }
        }
    }
    printf("\n");

    for (int i = 0; i < 5; i++)
    {
        printf("%d\t", array[i]);
    }
}
/**
 * @brief Em comment rõ hơn để anh dễ đọc nha !!!
 */
int main(void)
{

    functionC();          /* Cấp phát, nhập, in và giải phóng ma trận */
    functionA();          /* In mảng theo thứ tự tăng dần */
    functionB();          /* In mảng theo thứ tự giảm dần */
    bubbleSort(increase); /* Sắp xếp mảng theo thứ tự tăng dần */
    bubbleSort(decrease); /* Sắp xếp mảng theo thứ tự giảm dần */
}

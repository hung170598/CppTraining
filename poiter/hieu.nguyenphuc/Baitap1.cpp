#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

// Hàm 1: In mảng 1 chiều bình thường
void printArray(int arr[], int n) {
    printf("Mang binh thuong: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Hàm 2: In mảng 1 chiều dùng con trỏ
void printArrayPtr(int* arr, int n) {
    printf("Mang dung con tro: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", *(arr + i));
    }
    printf("\n");
}

// Hàm 3: Khởi tạo, nhập và in mảng 2 chiều dùng con trỏ cấp 2
void createAndPrint2DArray(int rows, int cols) {
    int** arr = (int**)malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        arr[i] = (int*)malloc(cols * sizeof(int));
    }

    printf("Nhap mang 2 chieu (%dx%d):\n", rows, cols);
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++) {
            printf("arr[%d][%d] = ", i, j);
            scanf("%d", &arr[i][j]);
        }

    printf("Mang 2 chieu:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++)
            printf("%d ", arr[i][j]);
        printf("\n");
    }

    // Giải phóng bộ nhớ
    for (int i = 0; i < rows; i++)
        free(arr[i]);
    free(arr);
}

// Hàm so sánh tăng dần
int ascending(int a, int b) {
    return a > b;
}

// Hàm so sánh giảm dần
int descending(int a, int b) {
    return a < b;
}

// Hàm 4: Sắp xếp mảng dùng con trỏ hàm
void sortArray(int* arr, int n, int (*compare)(int, int)) {
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (compare(arr[i], arr[j])) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
}

int main() {
    int arr[] = { 5, 2, 9, 1, 7 };
    int n = sizeof(arr) / sizeof(arr[0]);

    // Gọi hàm 1
    printArray(arr, n);

    // Gọi hàm 2
    printArrayPtr(arr, n);

    // Gọi hàm 3
    int rows = 2, cols = 3;
    createAndPrint2DArray(rows, cols);

    
    sortArray(arr, n, ascending);
    printf("Mang sau khi sap xep tang dan:\n");
    printArray(arr, n);

    
    sortArray(arr, n, descending);
    printf("Mang sau khi sap xep giam dan:\n");
    printArray(arr, n);

    return 0;
}

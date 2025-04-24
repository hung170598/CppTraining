#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void nhapMang(int a[], int n);
void xuatMang(int a[], int n);
void nhapMangPointer(int *a, int n);
void xuatMangPointer(int *a, int n);
int** createMatrix(int rows, int cols);
void inputMatrix(int **matrix, int rows, int cols);
void printMatrix(int **matrix, int rows, int cols);
void freeMatrix(int ***matrix, int rows);    
void bubleSort(int *a, int n);  
void selectionSort(int *a, int n);
void insertionSort(int *a, int n);
bool ascending(int a, int b);
bool descending(int a, int b);
void quickSort(int *a, int low, int high, int (*compare)(int, int));
int partition(int *a, int low, int high, int (*compare)(int, int));

int main(){
    int rows, cols;

    // Khởi tạo mảng
    printf("Nhap so hang: ");
    scanf("%d", &rows);
    printf("Nhap so cot: ");
    scanf("%d", &cols);
    int **matrix = createMatrix(rows, cols);
    printMatrix(matrix, rows, cols); // In mảng trước khi nhập giá trị
    
    // Nhập và in mảng
    inputMatrix(matrix, rows, cols);
    printMatrix(matrix, rows, cols);

    // Giải phóng bộ nhớ
    freeMatrix(&matrix, rows);
    printMatrix(matrix, rows, cols); // In lại mảng sau khi giải phóng bộ nhớ
    return 0;
}

void nhapMang(int a[], int n){
    for (int i = 0; i < n; i++){
        printf("Nhap phan tu a[%d]: ", i);
        scanf("%d", &a[i]);
    }
}

void xuatMang(int a[], int n){
    for (int i = 0; i < n; i++){
        printf("%d ", a[i]);
    }
    printf("\n");
}

void nhapMangPointer(int *a, int n){
    for (int i = 0; i < n; i++){
        printf("Nhap phan tu a[%d]: ", i);
        scanf("%d", &a[i]);
    }
}

void xuatMangPointer(int *a, int n){
    for (int i = 0; i < n; i++){
        printf("%d ", a[i]);
    }
    printf("\n");
}

int** createMatrix(int rows, int cols) {
    int **matrix = (int**)malloc(rows * sizeof(int*)); // Cấp phát mảng con trỏ hàng
    for (int i = 0; i < rows; i++) {
        matrix[i] = (int*)malloc(cols * sizeof(int));  // Cấp phát từng hàng
    }
    return matrix;
}

void inputMatrix(int **matrix, int rows, int cols) {
    printf("Nhap gia tri cho mang:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("matrix[%d][%d] = ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }
}

void printMatrix(int **matrix, int rows, int cols) {
    if (matrix == NULL) {
        printf("Matrix has been freed.\n");
        return;
    }
    printf("Mang 2D:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void freeMatrix(int ***matrix_ptr, int rows) {
    int **matrix = *matrix_ptr;
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);
    *matrix_ptr = NULL;  // Gán NULL cho con trỏ gốc
}

void bubleSort(int *a, int n){
    for (int i = 0; i < n - 1; i++){
        for (int j = 0; j < n - i - 1; j++){
            if (a[j] > a[j + 1]){
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}
void selectionSort(int *a, int n){
    for (int i = 0; i < n - 1; i++){
        int minIndex = i;
        for (int j = i + 1; j < n; j++){
            if (a[j] < a[minIndex]){
                minIndex = j;
            }
        }
        int temp = a[i];
        a[i] = a[minIndex];
        a[minIndex] = temp;
    }
}

void insertionSort(int *a, int n){
    for (int i = 1; i < n; i++){
        int key = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > key){
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
}

bool ascending(int a, int b) {
    return a <= b; // Sắp xếp tăng dần
}

bool descending(int a, int b) {
    return a > b; // Sắp xếp giảm dần
}

void quickSort(int *a, int low, int high, int (*compare)(int, int)){
    if (low < high){
        int pi = partition(a, low, high, compare);
        quickSort(a, low, pi - 1, compare);
        quickSort(a, pi + 1, high, compare);
    }
}
int partition(int *a, int low, int high, int (*compare)(int, int)){
    int pivot = a[high];
    int i = (low - 1);
    for (int j = low; j < high; j++){
        if (compare(a[j], pivot)){
            i++;
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }
    int temp = a[i + 1];
    a[i + 1] = a[high];
    a[high] = temp;
    return (i + 1);
}
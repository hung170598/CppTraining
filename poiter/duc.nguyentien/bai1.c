#include <stdio.h>
#include <stdlib.h>

// Ham nhap mang 
void nhapham(int n, int arr[]) {
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
}

// Ham xuat mang 
void xuatham(int n, int arr[]) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Con tro ham 
void xuathamcontro(int n, int arr[], int (*P)(int n)) {
    for (int i = 0; i < n; i++) {
        printf("%d ", P(arr[i]));
    }
    printf("\n");
}

// ham in mang dung con tro 
void printArray(int n, int *ptr) {
    for (int i = 0; i < n; i++) {
        printf("%d ", *(ptr + i));
    }
    printf("\n");
}

// Ham tao mang 2d 
int **creat2DArray(int rows, int cols) {
    int **arr = (int**)malloc(rows * sizeof(int*));
    if (arr == NULL) {
        printf("Loi cap phat bo nho!\n");
        exit(1);
    }
    for (int i = 0; i < rows; i++) {
        arr[i] = (int*)malloc(cols * sizeof(int));
        if (arr[i] == NULL) {
            printf("Loi cap phat bo nho!\n");
            exit(1);
        }
    }
    return arr;
}

// Ham nhap mang 2d 
void input2Darray(int **arr, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Nhap phan tu tai [%d][%d]: ", i, j);
            scanf("%d", &arr[i][j]);
        }
    }
}

// Ham in mang 2d 
void print2DArray(int **arr, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

// Ham giai phong bo nho 
void free2DArray(int **arr, int rows) {
    for (int i = 0; i < rows; i++) {
        free(arr[i]);
    }
    free(arr);
}

// Ham so sanh tang dan 
int compareAsc(int a, int b) {
    return a - b; // Tra ve lon hon 0 neu a > b; 
}

// Ham so sanh giam dan 
int compareDesc(int a, int b) {
    return b - a; // tra ve lon hon 0 neu b> a; 
}

// Ham sap xep su dung con tro ham
void sortArray(int n, int arr[], int (*compare)(int, int)) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (compare(arr[j], arr[j + 1]) > 0) {
                
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int n;
    printf("Nhap so phan tu cua mang:glich");
    scanf("%d", &n);
    int arr[n];
    
    printf("Nhap mang:\n");
    nhapham(n, arr);
    
    printf("Mang ban dau: ");
    xuatham(n, arr);
    
    // Sap xep tang dan 
    sortArray(n, arr, compareAsc);
    printf("Mang sau khi sap xep tang dan: ");
    xuatham(n, arr);
    
    // Sap xep giam dan 
    sortArray(n, arr, compareDesc);
    printf("Mang sau khi sap xep giam dan: ");
    xuatham(n, arr);
    
    // In mang bang con tro 
    printf("In mang bang con tro: ");
    printArray(n, arr);
    
    int rows, cols;
    printf("Nhap hang va cot: ");
    scanf("%d %d", &rows, &cols);
    
    int **arr1 = creat2DArray(rows, cols);
    input2Darray(arr1, rows, cols);
    printf("Mang 2D:\n");
    print2DArray(arr1, rows, cols);
    free2DArray(arr1, rows);
    
    return 0;
}
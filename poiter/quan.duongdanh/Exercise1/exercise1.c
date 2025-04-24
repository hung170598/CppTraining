#include <stdio.h>
#include <stdlib.h>

void printArray(int array[], int size) {
    for (int i = 0 ; i < size ; i++) {
        printf("array[%d] = %d\n", i, array[i]);
    }
}

void printArray_UsePointer(int array[], int size) {
    for (int i = 0 ; i < size ; i++) {
        printf("array[%d] = %d\n", i, *(array + i));
    }
}

void print_2D_Array(int rows, int cols) {
    int** arr = (int**)malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        arr[i] = (int*)malloc(cols * sizeof(int));
    }

    printf("Nhap mang 2 chieu [%d x %d]:\n", rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("arrayay[%d][%d] = ", i, j);
            scanf("%d", &arr[i][j]);
        }
    }

    printf("Mang 2 chieu:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d\t", arr[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < rows; i++) {
        free(arr[i]);
    }
    free(arr);
}

int ascending(int a, int b) {
    return a - b;
}

int descending(int a, int b) {
    return b - a;
}

void sortArray(int* array, int size, int (*cmp)(int, int)) {
    if (cmp == ascending) {
        printf("Mang sap xep tang dan:\n");
    }
    else {
        printf("Mang sap xep giam dan:\n");
    }
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (cmp(array[i], array[j]) > 0) {
                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
}
int main() {
    
    int a[7] = {1, 9, 3, 5, 11, 15, 19};
    int length = sizeof(a) / sizeof(a[0]);

    //printArray(a, length);
    //printArray_UsePointer(a, length);

    print_2D_Array(3,4);

    sortArray(a, length, descending);
    printArray(a, length);

    return 0;
}
#include "stdio.h"
#include "stdlib.h"
#define FOR(i, a, b) for(int i = a; i < b; i++)
#include "stdbool.h"
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
bool ascending(int a, int b) {
    return a > b;
}
bool descending(int a, int b) {
    return a < b;
}
void bubbleSort(int *a, int n, bool (*compare)(int, int)) {
    FOR(i, 0, n - 1) {
        FOR(j, 0, n - 1 - i) {
            if (compare(a[j], a[j + 1])) {
                swap(&a[j], &a[j + 1]);
            }
        }
    }
}
void showArray_use_functionPoiter(int *a, int n) {
    FOR(i, 0, n) {
        printf("%d ", a[i]);
    }
    printf("\n");
}
// -------------------------------------
void inputArray(int a[], int n){   
    // printf("Nhập giá trị mảng: ");
    FOR(i, 0, n){
        scanf("%d", &a[i]);
    }
}
void showArray(int a[], int n){
    // printf("Hiện thị mảng bình thường");
    FOR(i, 0, n){
        printf("%d ", a[i]);
    }    
}
void showArrayPointer(int* a, int n){
    // printf("Hiện thị mảng  sử dụng con trỏ: ");
    FOR(i, 0, n){
        printf("%d ", *(a + i));
    }    
}
void inputArray2_pointer(int** myArray2, int rows, int collums){
    FOR(i, 0, rows){
        FOR(j, 0, collums){
            scanf("%d", &myArray2[i][j]);            
        }
    }
}
void showArray2_pointer(int** myArray2, int rows, int collums){
    FOR(i, 0, rows){
        FOR(j, 0, collums){
            printf("%d ", myArray2[i][j]);            
        }
        printf("\n");
    }
}

int main(){
    // printf("Nhập số phần tử mảng bình thường: ");
    printf("Nhap N: ");
    int numArray; scanf("%d", &numArray);
    int myArray[numArray]; 
    inputArray(myArray, numArray);
    showArray(myArray, numArray);
    printf("\n");
    showArrayPointer(myArray, numArray);
    printf("\n");

    printf("sort");
    bubbleSort(myArray, numArray, ascending);
    printf("Sap xep tang dan: ");
    showArray_use_functionPoiter(myArray, numArray);

    bubbleSort(myArray, numArray, descending);
    printf("Sap xep giam dan: ");
    showArray_use_functionPoiter(myArray, numArray);

    printf("Nhap mang 2 chieu: ");
    int myRows, myCollums; 
    scanf("%d %d",&myRows, &myCollums);
    int **array2_pointer = NULL;
    array2_pointer = (int**)malloc(myRows * sizeof(int*));
    FOR(i, 0, myRows){
        *(array2_pointer + i) = (int*)malloc(myCollums * sizeof(int));
    }
    inputArray2_pointer(array2_pointer, myRows, myCollums);
    showArray2_pointer(array2_pointer, myRows, myCollums);

    FOR(i, 0, myRows){
        free(*(array2_pointer + i));
    }
    free(array2_pointer);

    return 0;

}
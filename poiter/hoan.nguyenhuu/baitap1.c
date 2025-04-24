#include <stdio.h>
#include <stdlib.h>

void inMangIndex(int a[], int n){
    for(int i = 0 ; i < n; i++){
       printf("%d ", a[i]);
    }
    printf("\n\n");
}

void inMangPtr(int *ptr, int n){
    for(int i = 0; i < n; i++){
        printf("%d ", *(ptr + i));
    }
    printf("\n\n");
}


void hamTangDan(int *a, int n){
    int temp = 0;
    for(int i = 0; i < n; i++){
        for(int j = i+1 ; j < n; j++){
            if (*(a+i) > *(a+j))
            {
                temp = *(a+i);
                *(a+i) = *(a+j);
                *(a+j) = temp;
            }
        }
    }
    printf("Mang tang dan: ");
    for(int i = 0; i < n; i++){
        printf("%d ", *(a + i));
    }
    printf("\n\n");
}

void hamGiamDan(int *a, int n){
    int temp = 0;
    for(int i = 0; i < n; i++){
        for(int j = i+1 ; j < n; j++){
            if (*(a+i) < *(a+j))
            {
                temp = *(a+i);
                *(a+i) = *(a+j);
                *(a+j) = temp;
            }
        }
    }
    printf("Mang giam dan: ");
    for(int i = 0; i < n; i++){
        printf("%d ", *(a + i));
    }
    printf("\n\n");
}

void mang2Chieu(int r, int c) {
    int **arr = (int**)malloc(r * sizeof(int*));
    for (int i = 0; i < r; i++) {
        arr[i] = (int*)malloc(c * sizeof(int));
    }

    printf("Nhap gia tri cho mang %d x %d:\n", r, c);
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            printf("arr[%d][%d] = ", i, j);
            scanf("%d", &arr[i][j]);
        }
    }

    printf("Mang vua nhap:\n");
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < r; i++) {
        free(arr[i]);
        arr[i] = NULL;
    }
    free(arr);
    arr = NULL;
    printf("\n");
}

int main(){
    int arr[5] = {4, 2, 5, 3, 1};
    int *ptr = arr;
    int length = sizeof(arr)/sizeof(arr[0]);
    inMangIndex(arr, length);
    inMangPtr(arr, length);
    mang2Chieu(2,3);
    hamTangDan(arr,length);
    hamGiamDan(arr,length);
}
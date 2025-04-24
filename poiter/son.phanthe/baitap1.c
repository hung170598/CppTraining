#include<stdio.h>
#include<stdlib.h>

void swap(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

void in(int a[], int n){
    printf("Mang binh thuong\n");
    for(int i = 0 ; i < n ; i++){
        printf("%d ",a[i]);
    }
    printf("\n");
}

void in1(int *a, int n){
    printf("Mang con tro\n");
    for(int i = 0 ; i < n ; i++){
        printf("%d ", *(a+i));
    }
    printf("\n");
}

void in2(int col, int row){
    int **a = (int **)malloc(row * sizeof(int*));
    for(int i = 0 ; i < row ; i++){
        a[i] = (int *)malloc(col * sizeof(int));
    }
    printf("Vui long nhap phan tu mang 2 chieu\n");
    for(int i = 0 ; i < row; i++){
        for(int j = 0 ; j < col ; j++){
            printf("a[%d][%d] = ",i,j);
            scanf("%d",&a[i][j]);
        }
    }

    for(int i = 0 ; i < row; i++){
        for(int j = 0 ; j < col ; j++){
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
    for(int i = 0 ; i < row ;i++){
        free(a[i]);
    }
    free(a);
    a= NULL;
}

void sosanh(int a[],int n,int(*f)(int x, int y)){
    for(int i = 0 ; i < n ; i++){
        for(int j = i+1 ; j < n; j++){
            if(f(a[i],a[j])){
                swap(&a[i],&a[j]);
            }
        }
    }
}

int tang(int x, int y){
    return x > y;
}

int giam(int x, int y){
    return x < y;
}

int main(){
    int n;
    scanf("%d", &n);
    int a[10005];
    for(int i = 0 ; i < n ; i ++){
        scanf("%d",&a[i]);
    }
    sosanh(a,n,tang);
    printf("Mang tang: ");
    in(a,n);
    sosanh(a,n,giam);
    printf("Mang giam: ");
    in1(a,n);
    printf("Mang 2 con tro\n");
    int row;
    printf("Vui long nhap hang: ");
    scanf("%d", &row);
    int col;
    printf("Vui long nhap cot: ");
    scanf("%d", &col);
    in2(col,row);
}
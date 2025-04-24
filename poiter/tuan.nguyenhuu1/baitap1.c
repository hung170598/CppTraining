/**********************************************************************
-------------------------------  Includes  ----------------------------
/**********************************************************************/
#include <stdio.h>
#include <stdlib.h>

/**********************************************************************
-------------------------------  APIs  ---------------------------------
/**********************************************************************/

/*Ham nhap mang 1 chieu*/
void importArray(int arr[], int sizeOfArray);

/*Ham in mang 1 chieu*/
void printArray(int arr[], int sizeOfArray);

/*Ham in mang 1 chieu dung con tro*/
void printArrayUsePointer(int *arr, int sizeOfArray);

/*Ham so sanh tang dan*/
int increase(int num1, int num2);

/*Ham so sanh giam dan*/
int decrease(int num1, int num2);

/*Ham sap xep mang 1 chieu*/
void sortArray(int arr[], int sizeOfArray, int (*cmp)(int, int));

/*Ham khoi tao, nhap, in mang 2 chieu*/
void creatMatrix(int ***arr, int row, int col);

/*Giai phong vung nho mang 2 chieu*/
void freeMatrix(int ***matrix, int row);


/**********************************************************************
-----------------------------  Main Program  --------------------------
**********************************************************************/
int main (void)
{
    int sizeOfArray = 0;
    int arr[100];
    int **matrix;
    int row, col;
    /*Thao tac mang 1 chieu*/
    printf("Nhap so luong phan tu: ");
    scanf("%d", &sizeOfArray);
    importArray(arr, sizeOfArray);
    printArray(arr, sizeOfArray);
    printArrayUsePointer(arr, sizeOfArray);
    sortArray(arr, sizeOfArray, increase);
    printf("Mang sau khi sap xep tang dan:\n");
    printArray(arr, sizeOfArray);
    sortArray(arr, sizeOfArray, decrease);
    printf("Mang sau khi sap xep giam dan:\n");
    printArray(arr, sizeOfArray);

    /*Thao tac mang 2 chieu*/
    printf("\nKhoi tao mang 2 chieu: \n");
    printf("Nhap so hang: ");
    scanf("%d", &row);
    printf("Nhap so cot: ");
    scanf("%d", &col);
    creatMatrix(&matrix, row, col);
    freeMatrix(&matrix, row);
}

/**********************************************************************
------------------------  Function Definitions  -----------------------
**********************************************************************/
void importArray(int arr[], int sizeOfArray)
{
    for(int i = 0; i < sizeOfArray; i++){
        printf("arr[%d] = ", i);
        scanf("%d", &arr[i]);
    }
}

void printArray(int arr[], int sizeOfArray)
{
    printf("In mang: \n");
    for (int i = 0; i < sizeOfArray; i++)
    {
        printf("arr[%d] = %d \n", i, arr[i]);
    }
}

void printArrayUsePointer(int *arr, int sizeOfArray)
{
    printf("In mang dung con tro: \n");
    for (int i = 0; i < sizeOfArray; i++)
    {
        printf("arr[%d] = %d \n", i, *(arr++));
    }
}

int increase(int num1, int num2){
    return num1 > num2;
}

int decrease(int num1, int num2)
{
    return num1 < num2;
}

void sortArray(int arr[], int sizeOfArray, int (*cmp)(int, int))
{
    int temp = 0;
    for(int i = 0; i < sizeOfArray-1; i++)
    {
        for(int j = 0; j < sizeOfArray-i-1; j++){
            if(cmp(arr[j], arr[j+1]))
            {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }

}

void creatMatrix(int ***arr, int row, int col)
{
    /*khoi tao mang 2 chieu*/
    *arr = (int **)malloc(row * sizeof(int*));
    for(int i = 0; i < row; i++)
    {
        (*arr)[i] = (int *)malloc(col * sizeof(int));
    }

    //nhap mang 2 chieu
    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < col; j++)
        {
            printf("arr[%d][%d] = ", i, j);
            scanf("%d", &(*arr)[i][j]);
        }
    }

    /*in mang 2 chieu*/
    printf("In mang 2 chieu \n");
    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < col; j++)
        {
            printf("%d   ",(*arr)[i][j]);
        }
        printf("\n");
    }
}

void freeMatrix(int ***matrix, int row)
{
    for(int i = 0; i < row; i ++)
    {
        free((*matrix)[i]);
    }
    free(*matrix);
    *matrix = NULL;
}
/**********************************************************************
-------------------------------  EOF  ---------------------------------
/**********************************************************************/

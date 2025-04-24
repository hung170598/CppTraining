#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void printArray(int a[], int n)
{
    for(int i=0; i<n; i++){
        printf("%d ",a[i]);
    }
    printf("\n");
}

void printArrayPointer(int *a, int n)
{
    for(int i=0; i<n; i++){
        printf("%d ",*(a+i));
    }
    printf("\n");
}

void printMatrix(int **a)
{
    int r, c;
    printf("Nhap so hang: ");
    scanf("%d", &r);
    printf("Nhap so cot: ");
    scanf("%d", &c);

    a = (int **)malloc(r * sizeof(int *));
    for(int i=0; i<r; i++){
        (a)[i] = (int *)malloc(c * sizeof(int));
    }

    printf("Nhap mang di anh: \n");
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            printf("a[%d][%d] = ",i, j);
            scanf("%d", &a[i][j]);
        }
    }

    printf("Mang vua nhap: \n");
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }

    for(int i=0; i<r; i++){
        free(a[i]);
    }
    free(a);
    a = NULL;
}

//Hoán vị 2 ptu
void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

bool asc(int a, int b)
{
    return a>b;
}

bool desc(int a, int b)
{
    return a<b;
}

//độ phức tạp tb O(nlogn), max O(n^2)
void quickSort(int a[],int left,int right, bool (* sort_func)(int, int))
{
    int l = left, r = right;
    //chọn ra ptu chốt (ở đây chọn ptu ở giữa)
    int pivot = a[(left+right)/2];

    do
    {
        //tăng l nếu a[l] nhỏ hơn phần tử chốt
        while (sort_func(pivot, a[l]))
            l++;
        //giảm r nếu a[r] lớn hơn phần tử chốt
        while (sort_func(a[r], pivot))
        {
            r--;
        }
        //khi kết thúc 2 vòng while a[l] và a[r] là 2 phần tử nghịch thế -> hoán vị cho nhau
        if(l<=r)
        {
            swap(&a[l],&a[r]);
            l++;
            r--;
        }
    }while (l<=r); //chỉ dừng khi l vượt quá r 

    //gọi đệ quy với dãy con bên trái
    if(left<r)
        quickSort(a,left,r, sort_func);
    //gọi đệ quy với dãy con bên phải 
    if(l<right)
        quickSort(a,l,right, sort_func);
}

int main()
{
    int a[7] = {1,100,6,78,9,31,20};
    printArray(a,sizeof(a)/ sizeof(a[0]));
    printArrayPointer(a, sizeof(a)/ sizeof(a[0]));
    printf("Sap xep tang dan: \n");
    quickSort(a, 0, sizeof(a)/ sizeof(a[0]) - 1, &asc);
    printArrayPointer(a, sizeof(a)/ sizeof(a[0]));

    printf("Sap xep giam dan: \n");
    quickSort(a, 0, sizeof(a)/ sizeof(a[0]) - 1, &desc);
    printArrayPointer(a, sizeof(a)/ sizeof(a[0]));

    int **b;
    int r, c;
    printMatrix(b);

    return 0;
}
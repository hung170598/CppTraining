/*******************************************************************************************************
 ** include
 ******************************************************************************************************/
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <conio.h>
#define number 10
/*******************************************************************************************************
 ** Prototype
 ******************************************************************************************************/
// Hàm in mảng một chiều
void print(int a[], int n);

// Hàm in mảng một chiều sử dụng con trỏ
void printuseptr(int a[], int n);

// Hàm khởi tạo mảng hai chiều động
int** init(int row, int col);

// Hàm nhập giá trị cho mảng hai chiều
void insert(int** ptr, int row, int col);

// Hàm in mảng hai chiều
void print_arr(int** ptr, int row, int col);

// Hàm so sánh giảm dần
bool dec(int a, int b);

// Hàm so sánh tăng dần
bool inc(int a, int b);

// Hàm hoán đổi giá trị
void swap(int* a, int* b);

// Hàm sắp xếp nổi bọt với hàm so sánh tùy chỉnh
void bubble_sort(int* a, int n, bool(*comparison)(int, int));

// Hàm giải phóng bộ nhớ của mảng hai chiều
void free_mem(int** ptr, int row);
/*******************************************************************************************************
 ** func
 ******************************************************************************************************/
void print(int a[], int n)
{
    for(int i =0; i<n; i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");
}
void printuseptr(int a[], int n)
{
    int * b;
    b =a;
    for(int i = 0; i <n; i++)
    {
        printf("%d ",*(b+i) );
    }
    printf("\n");
}
int** init (int row , int col)
{
    int **ptr = (int**) malloc(row * sizeof(int));
   
    if(ptr == NULL)
    {
        printf("ko dc bro");
    }
    
    for(int i=0; i<row ;i++)
    {
        ptr[i] = (int*)  malloc(col * sizeof(int));
        if((ptr[i]) == NULL)
        {
            printf("khong the cap phat bo nho dong 2");
        }
    }
    return ptr;
}
void insert(int ** ptr, int row , int col)
{
    for(int i = 0; i< row; i++)
    {

        for(int j = 0; j < col; j++)
        {
            scanf("%d",&ptr[i][j]);
        }
        
    }
    printf("\n");
}

void print_arr (int ** ptr,int row, int col)
{
    int cout = 0;
    
    for(int i = 0; i< row; i++)
    {
        
        for(int j = 0; j < col; j++)
        {
            printf("%-5d ", ptr[i][j]);
            cout++;
            if((cout % row)==0)
            {
                printf("\n");
            }
            
        }
        
    }
}
bool dec(int a, int b)
{
    return a<b;
}
bool inc(int a, int b)
{
    return a>b;
}
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void bubble_sort(int *a, int n, bool(*comparision)(int, int))
{
    
    for(int i =0; i<n ; i++)
    {
        for(int j=0; j< n-i-1; j++)
        {
            if(comparision(*(a + j),*(a + j + 1)))
            {
                swap((a+j),(a+j+1));
            }
            
        }
    }
    
}
char menu()
{
    char choice;
    
    
    printf("1: print array\n");
    printf("2: print array use poiter\n");
    printf("3: screen 2D array\n");
    printf("4: increse in sort\n");
    printf("5: decrease in sort\n");
    printf("6: exit\n");
    printf("your choice: ");
    fflush(stdin);
    scanf("%c", &choice);
    return choice;

}
/*******************************************************************************************************
 ** main
 ******************************************************************************************************/
int main()
{
    char choice;
    int *a;
    int c[number]= {3,2,4,6,5,7,9,8,1,0};
    int row= 0;
    int col= 0;
    int **ptr  ;
    a=c;
    do{
        
        system("cls");
        choice = menu();
        system("cls");
        
        switch(choice)
        {
            case '1':
                print(c,number);
                printf("Please enter to next step");
                getch();
                break;
            case '2':
                printuseptr(c,number);
                printf("Please enter to next step");
                getch();
                break;
            case '3':
                printf("Enter number row: \n");
                scanf("%d",&row);
                printf("Enter number collum: \n");
                scanf("%d",&col);
                printf("enter the elements: \n");
                ptr = init(row , col);
                insert(ptr,row,col);
                print_arr(ptr,row,col);
                for(int i=0; i< row ; i++)
                    {
                        free(ptr[i]);
                    }
                free(ptr);
                ptr = NULL;
                if(ptr = NULL);
                {
                    printf("Freed\n");
                }
                printf("Please enter to next step");
                getch();
                break;
            case '4':
                bubble_sort(a,number,inc);
                for(int i = 0; i< number; i++)
                {
                    printf("%d ", c[i]);
                }
                printf("\nPlease enter to next step");
                getch();
                break;
            case '5':
                bubble_sort(a,number,dec);
                for(int i = 0; i< number; i++)
                {
                    printf("%d ", c[i]);
                }
                printf("\nPlease enter to next step");
                getch();
                break;

        }
    }while(choice!= '6');
    

    

    return 0;
}

/*******************************************************************************************************
 ** EOF
 ******************************************************************************************************/
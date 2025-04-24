#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void normalArrayPrint(int array[], int array_len);
void pointerArrayPrint(int* array, int array_len);

int** twoDimensionArrayAllocate(int row, int column);
void twoDimensionArrayEnter(int **array,int row, int column);
void twoDimensionArrayDelete(int **array, int row);
void twoDimensionArrayPrint(int **array,int row, int column);

bool increaseCompare(int a, int b);
bool decreaseCompare(int a, int b);
void swapPosition(int* a, int* b);
void BubbleSort(int* a, int array_size,bool(*compare_funcPtr)(int,int));

int main()
{
    /* Dynamic Allocate and Two Dimension Array */
    int row, column;
    std::cout << "Enter row number of 2 dimension array: ";
    std::cin >> row;
    std::cout << "Enter column number of 2 dimension array: ";
    std::cin >> column;
    
    int**array=twoDimensionArrayAllocate(row,column);
    twoDimensionArrayEnter(array,row,column);
    twoDimensionArrayPrint(array,row,column);
    twoDimensionArrayDelete(array,row);

    /* Function Pointer */
    std::cout <<"Test for function pointer\n";
    int arraySize;
    std::cout <<"Enter array size:";
    std::cin >> arraySize;
    int* arrayToSort= new int[arraySize];
    std::cout <<"Enter member:";
    for(int i=0; i<arraySize; i++)
    {
        std::cin >> arrayToSort[i];
    }
    BubbleSort(arrayToSort,arraySize,decreaseCompare);
    std::cout << "Decreasing Sort:\n";
    pointerArrayPrint(arrayToSort,arraySize);
    
    BubbleSort(arrayToSort,arraySize,increaseCompare);
    std::cout << "Increase Sort:\n";
    pointerArrayPrint(arrayToSort,arraySize);

    delete[] arrayToSort;
    return 0;
}


void normalArrayPrint(int array[], int array_len)
{
    for(int i=0; i<array_len; i++)
    {
        std::cout << array[i]<<" ";
    }
    std::cout << std::endl;
}

void pointerArrayPrint(int* array, int array_len)
{
    for(int i=0; i<array_len; i++)
    {
        std::cout << *(array+i)<<" ";
    }
    std::cout << std::endl;
}

int** twoDimensionArrayAllocate(int row, int column)
{
    int** array = new int*[row];
    for(int i=0; i<row; i++)
    {
        array[i]= new int[column];
    }
    std::cout << "Allocated a 2 dimension array with "<< row<<" row and "<<column<<" column.\n";
    return array;
}

void twoDimensionArrayEnter(int **array,int row, int column)
{
    std::cout << "Enter array members: "<<std::endl;
    for(int i=0; i<row; i++)
    {
        for(int j=0; j<column; j++)
        {
            char str[100];
            memset(str,0,100);
            sprintf(str,"Enter member [%d][%d] : ",i,j);
            std::cout << str;
            std::cin >> array[i][j];
            std::cout <<std::endl;
        }
    }
}

void twoDimensionArrayDelete(int **array, int row)
{
    for(int i=0; i<row; i++)
    {
        delete[]((array)[i]);
    }
    delete[] array;
}

void twoDimensionArrayPrint(int **array,int row, int column)
{
    std::cout << "Array Print:"<<std::endl;
    for(int i=0; i<row; i++)
    {
        pointerArrayPrint(array[i],column);
        std::cout <<std::endl;
    }
}

bool increaseCompare(int a, int b)
{
    return a>b;
}

bool decreaseCompare(int a, int b)
{
    return a<b;
}

void swapPosition(int* a, int* b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}

void BubbleSort(int* a, int array_size,bool(*compare_funcPtr)(int,int))
{
    int i, j, temp;
    for (i = 0; i < (array_size - 1); ++i)
    {
        for (j = 0; j < array_size - 1 - i; ++j )
        {
            if (compare_funcPtr(a[j],a[j+1]))
            {
                swapPosition(&a[j],&a[j+1]);
            }
        }
    }
}   


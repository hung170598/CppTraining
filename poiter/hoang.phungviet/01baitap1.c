#include <stdio.h>
#include <stdlib.h>

/************* some macros */
#define ARR_LEN     10
/************* some typedef */

/************* functions prototypes */

void swap(int*, int*);
char ascending(int, int); 
char descending(int, int);

void printArr(int*, int);

void bubbleSort(int*, int len, char (*order)(int, int));
int** initMatrix(int, int);

void printMatrix(int**, int, int);
void scanMatrix(int**, int, int);
void freeMatrix(int***, int);



int main() {
    int arr[ARR_LEN] = {0};
    for(int i = 0; i < ARR_LEN; i++) {
        arr[i] = rand();
    }
    printf("Array: \n");
    printArr(arr, ARR_LEN);

    printf("Array after sorting in ascending order: \n");
    bubbleSort(arr, ARR_LEN, ascending);
    printArr(arr, ARR_LEN);

    printf("\n");

    int* pData = (int*) malloc(ARR_LEN * sizeof(int));
    for(int i = 0; i < ARR_LEN; i++) {
        *(pData + i) = rand();
    }

    printf("pointer as array: \n");
    printArr(pData, ARR_LEN);

    printf("Pointer as array after sorting in descending order: \n");
    bubbleSort(pData, ARR_LEN, descending);
    printArr(pData, ARR_LEN);
    free(pData);
    printf("\n");

    int** myMatrix = initMatrix(4, 5);

    printMatrix(myMatrix, 4, 5);
    scanMatrix(myMatrix, 4, 5);
    printMatrix(myMatrix, 4, 5);
    freeMatrix(&myMatrix, 4);

    return 0;
}


/************* functions definitions */

/**
 * to swap tưo int values
 */
void swap(int* a, int* b) {
    *a = *a ^ *b;
    *b = *a ^ *b;
    *a = *a ^ *b;
}

/**
 * @brief   check if 2 int variables in ascending order
 * @param   a int, first
 * @param   b int, second
 * @return  1 if a < b (ascending order) else 0 
 */
char ascending(int a, int b) {
    return (a < b);
}

/**
 * @brief   to check if 2 int variables in descending order
 * @param   a int, first
 * @param   b int, second
 * @return  1 if a > b (descending order) else 0
 */
char descending(int a, int b) {
    return (a > b);
}

/**
 * @brief   to print an array
 * @param   arr
 * @param   len  length of array
 * @return  none
 */
void printArr(int* arr, int len) {
    for(int i = 0; i < len; i++) {
        printf("%d ", *(arr + i));
    }
    printf("\n");
}

/**
 * @brief   to sort an array using bubble sort algorithm
 * @param   arr
 * @param   len  length of array
 * @param   order pointer to the order comparision function
 * @return  none
 */
void bubbleSort(int* arr, int len, char (*order)(int, int)) {
    for(int i = 0; i < len; i++) {
        for(int j = i + 1; j < len; j++) {
            if(order(*(arr + j), *(arr + i))) {
                swap((arr + j), (arr + i));
            }
        }
    }
}

/**
 * @brief   to print a matrix
 * @param   matrix
 * @param   row number of row
 * @param   col number of collum
 * @return  none
 */
void printMatrix(int** matrix, int row, int col) {
    for(int i = 0; i < row; i++) {
        printf("{");
        for(int j = 0; j < col; j++) {
            (j != col - 1) ? printf("%d, ", *(*(matrix + i) + j)) : printf("%d", *(*(matrix + i) + j));
        }
        printf("}\n");
    }
}

/**
 * @brief   to initialize a matrix (2D array), allow intering values
 * @param   row number of row
 * @param   col number of collum
 * @return  pointer to the matrix, allocated and must be freed after using || return NULL if failed
 */
int** initMatrix(int row, int col) {
    int** matrix = (int**) malloc(row * (sizeof(int*)));
    if(matrix == NULL) {
        return NULL;
    }

    for(int i = 0; i < row; i++) {
        *(matrix + i) = (int*) malloc(col * sizeof(int));
        if(*(matrix + i) == NULL) {
            for(int j = 0; j < i; j++) {
                free(*(matrix + j));
            }
            free(matrix);
            return NULL;
        }
    }
    return matrix;
}


/**
 * @brief   to scan matrix from terminal input
 * @param   matrix 
 * @param   row number of row
 * @param   col number of collum
 * @return  none
 */
void scanMatrix(int** matrix, int row, int col) {
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            printf("matrix[%d][%d]: ", i, j);
            scanf("%d", (*(matrix + i) + j));
        }
        printf("\n");
    }
}

/**
 * @brief   to free matrix after using
 * @param   pMatrix pointer to matrix
 * @param   row number of row
 * @param   col number of collum
 * @return  none
 */
void freeMatrix(int*** pMatrix, int row) {
    if (pMatrix == NULL || *pMatrix == NULL) {
        return;
    }

    for(int i = 0; i < row; i++) {
        free(*(*(pMatrix) + i));

        *(*(pMatrix) + i) = NULL;
    }

    free(*pMatrix);
    *pMatrix = NULL;
}


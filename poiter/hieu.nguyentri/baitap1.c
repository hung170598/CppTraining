#include<stdio.h>
#include<stdlib.h>

//Declare function pointer
typedef int (*compare) (int, int);

//Using preprocessor directive to choose function need runnning
#define ARRAY1D 1
#define ARRAY2D 2
#define SORT 3

#define CHOICE 1

//declare rpototype function
void InitArray(int *arr, int count);
void printArray(int *arr, int count);
void printPointerArray(int *arr, int count);
void Init2dArray(int **arr, int row, int col);
void Array2Dpointer(int **arr, int row, int col);
void SortPointerFunction(int *arr, int left, int right, compare cmp);
int Ascending(int x, int y);
int Descending(int x, int y);

int main(){
    #if (CHOICE == 1)
        printf("Enter the number elements of array: ");
        int count; scanf("%d", &count);

        int *arr = (int *)malloc(count * sizeof(int)); //Alloacate memory for array
        if(arr == NULL){
            printf("Alloacation failed!\n");
            return 1; //Exit
        };

        printf("Create a new array:\n");
        InitArray(arr, count); 

        printf("Print array using array notation:\n");
        printArray(arr, count);

        printf("\nPrintf array using pointer notation:\n");
        printPointerArray(arr, count);

        free(arr); //Free allocated memory
        arr = NULL; //Set pointer to NULL to avoid dangling pointer
    #elif (CHOICE == 2)
        printf("Enter row: ");
        int row; scanf("%d", &row);
        printf("Enter coL: ");
        int col; scanf("%d", &col);

        //allacta array 2d
        int **arr = (int **)malloc(row * sizeof(int));
        //check allocation **arr
        if(arr == NULL){
            printf("Allocation failed!\n");
            return 1; //Exit
        }

        for(int i = 0; i < row; i++){
            *(arr + i) = (int *)malloc(col * sizeof(int));
            if(*(arr + i) == NULL){
                printf("Allocation failed for row %d!\n", i + 1);
                for(int j = 0; j < i; j++){
                    free(*(arr + j));
                }
                free(arr);
                return 1;
            }
        }

        printf("Init array 2 dimensional: \n");
        Init2dArray(arr, row, col);

        printf("Display array typed:\n");
        Array2Dpointer(arr, row, col);

        //free sub array before free array outside
        for(int i = 0; i < row; i++){
            free(*(arr + i));
        }
        free(arr);
    #elif (CHOICE == 3)
        printf("Enter number elements of array: ");
        int count; scanf("%d", &count);

        int *arr = (int *) malloc (count * sizeof(int));
        if(arr == NULL){
            printf("Allocation failed!\n");
            return 1;
        }

        for(int i = 0; i < count; i++){
            printf("Element %d: ", i + 1);
            scanf("%d", (arr + i));
        }

        printf("Ascending Sort:\n");
        SortPointerFunction(arr, 0, count - 1, Ascending);
        printArray(arr, count);
        printf("\n--------------------------------\n");

        printf("Descending Sort:\n");
        SortPointerFunction(arr, 0, count - 1, Descending);
        printArray(arr, count);
        printf("\n");
    #endif
    return 0;
}

void InitArray(int *arr, int count){
    for(int i = 0; i < count; i++){
        printf("Enter element %d: ", i + 1);
        scanf("%d", (arr + i)); // Using pointer to browser array
    }
}

void printArray(int *arr, int count){
    for(int i = 0; i < count; i++){
        printf("%d ", arr[i]); //Using array notation
    }
}

void printPointerArray(int *arr, int count){
    for(int i = 0; i < count; i++){
        printf("%d ", *(arr + i)); //Using pointer notation
    }
}

void Init2dArray(int **arr, int row, int col){
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            printf("Enter element [%d][%d]: ", i, j);
            scanf("%d", (*(arr + i) + j));
        }
    }
}

void Array2Dpointer(int **arr, int row, int col){
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            printf("%d ", *(*(arr +i ) + j));
        }
        printf("\n");
    }
}

void SortPointerFunction(int *arr, int left, int right, compare cmp){
    if(left >= right){
        return;
    }

    int mid = left + (right - left)/2; //find element middle
    int i = left, j = right;

    while(i <= j){
        while(cmp(arr[i], arr[mid]) < 0) i++;
        while(cmp(arr[j], arr[mid]) > 0) j--;

        if(i <= j){
            int tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
            i++;
            j--;
        }
    }

    //recursive to browser all element
    if(left < j){
        SortPointerFunction(arr, left, j, cmp);
    }
    if(i < right){
        SortPointerFunction(arr, i, right, cmp);
    }
}

int Ascending(int x, int y){
    return x > y ? 1 : (x < y ? -1 : 0);
    /*
        return positive => x > y => swap
        return negative or 0 => x < y => keep the same 
    */
}

int Descending(int x, int y){
    return x < y ? 1: (x > y ? -1 : 0);
    /*
        return positive or 0=> y > x => keep the same
        return negative => y < x => swap 
    */
}
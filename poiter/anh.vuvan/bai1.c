#include <stdio.h>
#include <stdlib.h>
/**********************************************************
 * prototype 
 */
void screen_normal_array(int arr[],int n);
void screen_array_use_pointer(int *arr, int n);
void screen_array_use_allocate_memory();
void arrange_number_increasing(int arr[],int n);
void arrange_number_decreasing(int arr[],int n);
/***********************************************************
 * variable
 */
int main() {
    int n;
    printf("Enter number of array: ");
    scanf("%d",&n);
    int arr[n];
    for (int i = 0 ; i < n ; i++){
        printf("arr[%d]: ",i);
        scanf("%d",&arr[i]);
    }    

    screen_normal_array(arr,n);
    printf("\n");
    screen_array_use_pointer(arr,n);
    printf("\n");
    screen_array_use_allocate_memory();
    
    void (*func_line[2])(int arr[], int n); 
    func_line[0] = arrange_number_increasing;
    func_line[1] = arrange_number_decreasing;
    func_line[0](arr,n);
    func_line[1](arr,n);
    return 0;
}

/*************************************************************
 * code 
 */
void screen_normal_array(int arr[],int n ){
    for (int i = 0 ; i < n ; i++){
        printf("%d ",arr[i]);
    }
}

void screen_array_use_pointer(int *arr, int n){
    for (int i = 0 ; i < n ; i++){
        printf("%d ",*(arr + i));
    }
}

void screen_array_use_allocate_memory(){
    int n , m;
    printf("Enter number of two dimensions array: ");
    scanf("%d %d",&n,&m);
    int **arr = (int**)malloc(n * sizeof(int*));
    for (int i = 0 ; i < n ; i++){
        arr[i] = (int*)malloc(m * sizeof(int));
    }

    for (int i = 0 ; i < n ; i++){
        for (int j = 0 ; j < m ; j++){
            printf("arr[%d][%d] = ",i,j);
            scanf("%d",&arr[i][j]);
        }
    }
    for (int i = 0 ; i < n ; i++){
        for (int j = 0 ; j < m ; j++){
            printf("%d ",arr[i][j]);
        }
    }
    for (int i = 0 ; i < m ; i++){
        free(arr[i]);
        arr[i] = NULL;
    }
    free(arr);
    arr = NULL;

}

void arrange_number_increasing(int arr[], int n){
    for (int i = 0; i < n - 1; i++){
        for (int j = 0; j < n - i - 1; j++){
            if (arr[j] > arr[j + 1]){
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    for (int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void arrange_number_decreasing(int arr[], int n){
    for (int i = 0; i < n - 1; i++){
        for (int j = 0; j < n - i - 1; j++){
            if (arr[j] < arr[j + 1]){
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    for (int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

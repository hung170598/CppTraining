#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void _fgets(char *str, int size, FILE *stream) {
  char c;
  fgets(str, size, stream);
  if (str[strlen(str) - 1] == '\n') {
    str[strlen(str) - 1] = '\0';
  } else {
    while ((c = getchar()) != '\n' && c != EOF)
      ;
  }
}

void printArray(int arr[], int size) {
  printf("Array (normal): ");
  for (int i = 0; i < size; ++i) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

void printArrayPointer(int *arr, int size) {
  printf("Array (pointer): ");
  for (int i = 0; i < size; ++i) {
    printf("%d ", *(arr + i));
  }
  printf("\n");
}

void handle2DArray() {
  int rows, cols;
  char inp[15];
  printf("Enter number of rows: ");
  _fgets(inp, sizeof(inp), stdin);
  rows = strtol(inp, NULL, 10);

  printf("Enter number of columns: ");
  _fgets(inp, sizeof(inp), stdin);
  cols = strtol(inp, NULL, 10);

  // // Dynamically allocate memory for 2D array
  // int **arr = (int **)malloc(rows * sizeof(int *));
  // for (int i = 0; i < rows; ++i) {
  //   arr[i] = (int *)malloc(cols * sizeof(int));
  // }

  int arr[rows][cols];

  printf("Enter values for the 2D array:\n");
  for (int i = 0; i < rows; ++i) {
    for (int j = 0; j < cols; ++j) {
      printf("arr[%d][%d]: ", i, j);
      _fgets(inp, sizeof(inp), stdin);
      arr[i][j] = strtol(inp, NULL, 10);
    }
  }

  printf("2D Array:\n");
  for (int i = 0; i < rows; ++i) {
    for (int j = 0; j < cols; ++j)
      printf("%d\t", arr[i][j]);
    printf("\n");
  }
}

int ascending(int a, int b) { return a > b; }
int descending(int a, int b) { return a < b; }
void sortArray(int *arr, int size, int (*cmp)(int, int)) {
  for (int i = 0; i < size - 1; ++i) {
    for (int j = i + 1; j < size; ++j) {
      if (cmp(arr[i], arr[j])) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
      }
    }
  }
}

void testSorting(int arr[], int size) {
  printf("Original array: ");
  printArray(arr, size);

  int *arr2 = (int *)malloc(size * sizeof(int));
  memcpy(arr2, arr, size * sizeof(int));

  printf("Sorted ascending: ");
  sortArray(arr2, size, ascending);
  printArray(arr2, size);

  memcpy(arr2, arr, size * sizeof(int));
  printf("Sorted descending: ");
  sortArray(arr2, size, descending);
  printArray(arr2, size);

  free(arr2);
}

int main() {
  char inp[5];
  int choice;
  int arr[50] = {2, 4, 1, 3, 5};
  int arr_len = 5;

  while (1) {
    printf("\n===== Pointer exercise =====\n");
    printf("1. Print array (normal)\n");
    printf("2. Print array (pointer)\n");
    printf("3. Handle 2D array (double pointer)\n");
    printf("4. Sort array (function pointer)\n");
    printf("5. Initialize array\n");
    printf("Enter your choice: ");
    _fgets(inp, sizeof(inp), stdin);

    if (inp[1] == '\0') {
      choice = inp[0] - '0';
    } else {
      printf("Invalid option. Exiting program.\n");
      break;
    }

    switch (choice) {
    case 1:
      printArray(arr, arr_len);
      break;
    case 2:
      printArrayPointer(arr, arr_len);
      break;
    case 3:
      handle2DArray();
      break;
    case 4:
      testSorting(arr, arr_len);
      break;
    case 5:
      printf("Enter array size: ");
      _fgets(inp, sizeof(inp), stdin);
      arr_len = strtol(inp, NULL, 10);

      printf("Enter array elements\n");
      for (int i = 0; i < arr_len; ++i) {
        printf("arr[%d]: ", i);
        _fgets(inp, sizeof(inp), stdin);
        arr[i] = strtol(inp, NULL, 10);
      }
      printf("Array initialized: ");
      for (int i = 0; i < arr_len; ++i) {
        printf("%d ", arr[i]);
      }
      printf("\n");
      break;
    default:
      printf("Invalid option. Exiting program.\n");
      return 0;
    }
  }
  return 0;
}
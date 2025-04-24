#include "stack.h"
#include <stdio.h>

int main() {
  Stack stack;
  initStack(&stack, 50);

  printf("Pushing elements onto the stack:\n");
  for (int i = 0; i < 5; i++) {
    push(&stack, i);
    printf("Pushed: %d\n", i);
  }

  printf("\nPopping elements from the stack:\n");
  while (!isStackEmpty(&stack)) {
    int value = pop(&stack);
    printf("Popped: %d\n", value);
  }

  return 0;
}
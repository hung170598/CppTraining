#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

void initStack(Stack *stack, int size) {
  stack->top = -1;
  stack->size = size;
  stack->arr = (int *)malloc(stack->size * sizeof(int));
}

inline int isStackEmpty(Stack *stack) { return stack->top == -1; }

inline int isFull(Stack *stack) { return stack->top == stack->size - 1; }

void push(Stack *stack, int item) {
  if (isFull(stack)) {
    printf("Stack overflow\n");
    return;
  }
  stack->top++;
  stack->arr[stack->top] = item;
}

int pop(Stack *stack) {
  if (isStackEmpty(stack)) {
    printf("Stack underflow\n");
    return -1; // Return an error value
  }
  return stack->arr[stack->top--];
}

int top(Stack *stack) {
  if (isStackEmpty(stack)) {
    printf("Stack is empty\n");
    return -1; // Return an error value
  }
  return stack->arr[stack->top];
}

void freeStack(Stack *stack) { free(stack->arr); }
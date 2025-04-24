#ifndef STACK_H
#define STACK_H

typedef struct Stack {
    int *arr;
    int top;
    int size;
} Stack;

void initStack(Stack* stack, int size);
int isFull(Stack* stack);
int isStackEmpty(Stack* stack);
void push(Stack* stack, int item);
int pop(Stack* stack);
int top(Stack* stack);
void freeStack(Stack* stack);

#endif // STACK_H
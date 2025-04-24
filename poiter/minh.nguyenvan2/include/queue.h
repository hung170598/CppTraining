#ifndef QUEUE_H
#define QUEUE_H

#include <stdbool.h>

// Define the structure for a queue node
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Define the structure for the queue
typedef struct Queue {
    Node* front;
    Node* rear;
    int size;
} Queue;

// Function prototypes
Queue* createQueue();
void enqueue(Queue* queue, int data);
int dequeue(Queue* queue);
int peek(Queue* queue);
bool isQueueEmpty(Queue* queue);
void clearQueue(Queue* queue);
void destroyQueue(Queue* queue);

#endif // QUEUE_H
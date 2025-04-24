#include <stdio.h>
#include "queue.h"

int main() {
    Queue* queue = createQueue();

    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);

    printf("Front element: %d\n", peek(queue));
    printf("Dequeued: %d\n", dequeue(queue));
    printf("Dequeued: %d\n", dequeue(queue));

    enqueue(queue, 40);
    printf("Front element: %d\n", peek(queue));

    destroyQueue(queue);
    return 0;
}
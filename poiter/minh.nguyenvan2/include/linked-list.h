#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdbool.h>

// Define the structure for a linked list node
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Define the structure for the linked list
typedef struct LinkedList {
    Node* head;
    int size;
} LinkedList;

// Function prototypes
LinkedList* createLinkedList();
void insertAtHead(LinkedList* list, int data);
void insertAtTail(LinkedList* list, int data);
bool deleteNode(LinkedList* list, int data);
bool searchNode(LinkedList* list, int data);
void printList(LinkedList* list);
void clearList(LinkedList* list);
void destroyLinkedList(LinkedList* list);

#endif // LINKED_LIST_H
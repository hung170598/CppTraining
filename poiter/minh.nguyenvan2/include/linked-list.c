#include <stdio.h>
#include <stdlib.h>
#include "linked-list.h"

// Create a new linked list
LinkedList* createLinkedList() {
    LinkedList* list = (LinkedList*)malloc(sizeof(LinkedList));
    list->head = NULL;
    list->size = 0;
    return list;
}

// Insert a node at the head of the list
void insertAtHead(LinkedList* list, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = list->head;
    list->head = newNode;
    list->size++;
}

// Insert a node at the tail of the list
void insertAtTail(LinkedList* list, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (list->head == NULL) {
        list->head = newNode;
    } else {
        Node* temp = list->head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    list->size++;
}

// Delete a node with the given data
bool deleteNode(LinkedList* list, int data) {
    Node* temp = list->head;
    Node* prev = NULL;

    while (temp != NULL && temp->data != data) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        return false; // Node not found
    }

    if (prev == NULL) {
        list->head = temp->next; // Node to delete is the head
    } else {
        prev->next = temp->next;
    }

    free(temp);
    list->size--;
    return true;
}

// Search for a node with the given data
bool searchNode(LinkedList* list, int data) {
    Node* temp = list->head;
    while (temp != NULL) {
        if (temp->data == data) {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

// Print the linked list
void printList(LinkedList* list) {
    Node* temp = list->head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Clear all nodes in the list
void clearList(LinkedList* list) {
    Node* temp = list->head;
    while (temp != NULL) {
        Node* next = temp->next;
        free(temp);
        temp = next;
    }
    list->head = NULL;
    list->size = 0;
}

// Destroy the linked list and free memory
void destroyLinkedList(LinkedList* list) {
    clearList(list);
    free(list);
}
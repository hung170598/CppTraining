#include <stdio.h>
#include "linked-list.h"

int main() {
    LinkedList* list = createLinkedList();

    insertAtHead(list, 10);
    insertAtHead(list, 20);
    insertAtTail(list, 30);

    printf("Linked List: ");
    printList(list);

    printf("Search for 20: %s\n", searchNode(list, 20) ? "Found" : "Not Found");
    printf("Delete 20: %s\n", deleteNode(list, 20) ? "Success" : "Failure");

    printf("Linked List after deletion: ");
    printList(list);

    destroyLinkedList(list);
    return 0;
}
#include <stdio.h>
#include <stdlib.h>

// Define a structure for a circular linked list node
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node with the given data
struct Node* newNode(int data) {
    // Allocate memory for the new node
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    // Check if memory allocation was successful
    if (temp == NULL) {
        exit(EXIT_FAILURE);
    }
    // Initialize the new node
    temp->data = data;
    temp->next = NULL;
    return temp;
}

// Function to insert a node with the given data at the end of the circular linked list
void insertEnd(struct Node** head, int data) {
    // Create a new node
    struct Node* newNodePtr = newNode(data);

    // If the list is empty, set the new node as the head and make it point to itself
    if (*head == NULL) {
        *head = newNodePtr;
        newNodePtr->next = *head;
    }
    // If the list is not empty, find the last node and insert the new node after it
    else {
        struct Node* last = (*head)->next;
        while (last->next != *head)
            last = last->next;
        last->next = newNodePtr;
        newNodePtr->next = *head;
    }
}

// Function to delete the first occurrence of a node with the given key value from the circular linked list
void deleteNode(struct Node** head, int key) {
    // If the list is empty, return
    if (*head == NULL)
        return;

    // Initialize pointers for traversing the list
    struct Node *temp = *head, *prev = NULL;

    // Traverse the list until the key is found or until we reach the end of the list
    while (temp->data != key) {
        // If we reach the end of the list without finding the key, return
        if (temp->next == *head) {
            return;
        }
        // Update pointers for the next iteration
        prev = temp;
        temp = temp->next;
    }

    // If the node to be deleted is the only node in the list
    if (temp == *head && temp->next == *head) {
        free(temp);
        *head = NULL;
    }
    // If the node to be deleted is the head node
    else if (temp == *head) {
        struct Node* last = *head;
        while (last->next != *head)
            last = last->next;
        *head = (*head)->next;
        last->next = *head;
        free(temp);
    }
    // If the node to be deleted is in the middle or end of the list
    else {
        prev->next = temp->next;
        free(temp);
    }
}

// Function to display the elements of the circular linked list
void displayList(struct Node* head) {
    // Initialize a temporary pointer to traverse the list
    struct Node* temp = head;
    // If the list is not empty, traverse and print its elements
    if (head != NULL) {
        do {
            printf("%d ", temp->data);
            temp = temp->next;
        } while (temp != head);
    }
    // If the list is empty, print "Empty"
    else {
        printf("Empty");
    }
    printf("\n");
}

// Main function to execute the program
int main() {
    // Initialize the head pointer of the circular linked list
    struct Node* head = NULL;
    char command;
    int data;

    // Continue taking input commands until 'E' (End) command is encountered
    while (1) {
        scanf(" %c", &command);
        if (command == 'I') {
            // Insert command: Read data and insert it at the end of the list
            scanf("%d", &data);
            insertEnd(&head, data);
        } else if (command == 'D') {
            // Delete command: Read data and delete the node with that data from the list
            scanf("%d", &data);
            deleteNode(&head, data);
        } else if (command == 'E') {
            // End command: Display the list and exit the program
            displayList(head);
            break;
        }
    }

    return 0;
}

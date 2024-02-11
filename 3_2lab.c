//puwanut theeranuluk 66070503477
#include<stdio.h>
#include<stdlib.h>

// Define a structure for a node in a singly linked list
struct Node {
    int data;           // Data stored in the node
    struct Node* next;  // Pointer to the next node in the list
};

// Function to insert a new node with given data after a given previous node
void insertAfter(struct Node* prev_node, int new_data) {
    if (prev_node == NULL) {  // If the previous node is NULL, return
        return;
    }
    // Allocate memory for the new node
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    // Set the data and next pointer of the new node
    new_node->data = new_data;
    new_node->next = prev_node->next;
    // Update the next pointer of the previous node to point to the new node
    prev_node->next = new_node;
}

// Function to insert a new node with given data before the node with a specific key
void insertBefore(struct Node** head_ref, int key, int new_data) {
    // Allocate memory for the new node
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    // Set the data of the new node
    new_node->data = new_data;
    // Initialize a temporary pointer to traverse the list
    struct Node* temp = *head_ref;
    // If the key matches the data of the head node, insert before it
    if (temp->data == key) {
        new_node->next = *head_ref;
        *head_ref = new_node;
        return;
    }
    // Traverse the list until the key is found or the end is reached
    while (temp->next != NULL && temp->next->data != key) {
        temp = temp->next;
    }
    // If the key is not found, free the allocated memory for the new node and return
    if (temp->next == NULL) {
        free(new_node);
        return;
    }
    // Insert the new node before the node with the key
    new_node->next = temp->next;
    temp->next = new_node;
}

// Function to print the elements of the linked list
void printList(struct Node* node) {
    // Traverse the list and print each node's data
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
}

// Main function
int main() {
    int n;
    scanf("%d", &n);  // Read the number of elements in the list
    struct Node* head = NULL;  // Initialize head pointer to NULL
    struct Node* tail = NULL;  // Initialize tail pointer to NULL

    // Loop to read data and create nodes for the linked list
    for (int i = 0; i < n; ++i) {
        int data;
        scanf("%d", &data);  // Read the data for the node
        // Allocate memory for the new node
        struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
        // Set the data and next pointer of the new node
        new_node->data = data;
        new_node->next = NULL;
        // If the list is empty, set both head and tail to the new node
        if (head == NULL) {
            head = new_node;
            tail = new_node;
        } else {
            // Otherwise, append the new node to the end of the list
            tail->next = new_node;
            tail = tail->next;
        }
    }

    char mode;
    // Loop to process commands until 'E' is entered
    while (scanf(" %c", &mode) == 1 && mode != 'E') {
        int key, data;
        scanf("%d %d", &key, &data);  // Read the key and data for the command
        if (mode == 'A') {
            // If mode is 'A', find the node with the key and insert data after it
            struct Node* temp = head;
            while (temp != NULL && temp->data != key) {
                temp = temp->next;
            }
            if (temp != NULL) {
                insertAfter(temp, data);
            }
        } else if (mode == 'B') {
            // If mode is 'B', insert data before the node with the key
            insertBefore(&head, key, data);
        }
    }

    // Print the final list
    printList(head);
    return 0;
}

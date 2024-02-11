//puwanut theeranuluk 66070503477
#include <stdio.h>
#include <stdlib.h>

// Define a structure for a node in a singly linked list
struct Node {
    int data;           // Data stored in the node
    struct Node* next;  // Pointer to the next node in the list
};

// Function to delete the first node of the linked list
void deleteFirst(struct Node** head) {
    if (*head == NULL)  // If the list is empty, return
        return;
    // Store the current head node
    struct Node* temp = *head;
    // Update the head pointer to point to the next node
    *head = (*head)->next;
    // Free the memory allocated for the original head node
    free(temp);
}

// Function to delete the last node of the linked list
void deleteLast(struct Node** head) {
    if (*head == NULL)  // If the list is empty, return
        return;
    if ((*head)->next == NULL) {  // If there's only one node in the list
        // Free the memory allocated for the single node and set head to NULL
        free(*head);
        *head = NULL;
        return;
    }
    // Traverse the list until the second last node
    struct Node* temp = *head;
    while (temp->next->next != NULL)
        temp = temp->next;
    // Free the memory allocated for the last node and set its next pointer to NULL
    free(temp->next);
    temp->next = NULL;
}

// Function to delete the first occurrence of a node with a given value
void deleteValue(struct Node** head, int value) {
    if (*head == NULL)  // If the list is empty, return
        return;
    if ((*head)->data == value) {  // If the value matches the data of the head node
        // Store the current head node
        struct Node* temp = *head;
        // Update the head pointer to point to the next node
        *head = (*head)->next;
        // Free the memory allocated for the original head node
        free(temp);
        return;
    }
    // Traverse the list until the node with the given value is found
    struct Node* temp = *head;
    while (temp->next != NULL && temp->next->data != value)
        temp = temp->next;
    if (temp->next == NULL)  // If the value is not found, return
        return;
    // Store the node to be deleted
    struct Node* del = temp->next;
    // Update the next pointer of the previous node to skip the node to be deleted
    temp->next = temp->next->next;
    // Free the memory allocated for the node to be deleted
    free(del);
}

// Function to print the elements of the linked list
void printList(struct Node* head) {
    if (head == NULL) {  // If the list is empty, print "none"
        printf("none\n");
        return;
    }
    // Traverse the list and print each node's data
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    int n;
    scanf("%d", &n);  // Read the number of elements in the list
    struct Node* head = NULL;  // Initialize head pointer to NULL
    struct Node* tail = NULL;  // Initialize tail pointer to NULL

    // Loop to read data and create nodes for the linked list
    for (int i = 0; i < n; ++i) {
        int value;
        scanf("%d", &value);  // Read the data for the node
        // Allocate memory for the new node
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        // Set the data and next pointer of the new node
        newNode->data = value;
        newNode->next = NULL;
        // If the list is empty, set both head and tail to the new node
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            // Otherwise, append the new node to the end of the list
            tail->next = newNode;
            tail = newNode;
        }
    }

    char mode;
    // Loop to process commands until 'E' is entered
    while (scanf(" %c", &mode) == 1 && mode != 'E') {
        if (mode == 'F') {
            // If mode is 'F', delete the first node
            deleteFirst(&head);
        } else if (mode == 'L') {
            // If mode is 'L', delete the last node
            deleteLast(&head);
        } else if (mode == 'N') {
            int value;
            scanf("%d", &value);  // Read the value to be deleted
            // If mode is 'N', delete the first occurrence of the value
            deleteValue(&head, value);
        }
    }
    // Print the final list
    printList(head);

    // Free the memory allocated for all nodes in the list
    while (head != NULL) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}

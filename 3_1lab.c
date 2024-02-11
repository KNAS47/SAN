//puwanut theeranuluk 66070503477
#include <stdio.h>
#include <stdlib.h>

// Structure for a node in the linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to insert a new node at the beginning of the linked list
void insertAtBeginning(struct Node** head_ref, int new_data) {
    // Allocate memory for the new node
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    // Assign data to the new node
    new_node->data = new_data;
    // Set the next of the new node to the current head
    new_node->next = *head_ref;
    // Move the head to point to the new node
    *head_ref = new_node;
}

// Function to insert a new node at the end of the linked list
void insertAtEnd(struct Node** head_ref, int new_data) {
    // Allocate memory for the new node
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    // Set data for the new node
    new_node->data = new_data;
    // Set next of new node to NULL as it will be the last node
    new_node->next = NULL;
    
    // If the linked list is empty, make the new node as the head
    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }
    
    // Traverse to the last node of the linked list
    struct Node* last = *head_ref;
    while (last->next != NULL)
        last = last->next; 
    // Attach the new node to the last node
    last->next = new_node;
}

// Function to print the linked list
void printLinkedList(struct Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
}

int main() {
    int n, option, data;
    struct Node* head = NULL;

    // Input the number of elements in the linked list
    scanf("%d", &n);
    // Validate if the input is valid
    if (n <= 0) {
        printf("Invalid\n");
        return 0;
    }

    // Input whether to insert at the beginning or end
    scanf("%d", &option);
    // Validate if the input is valid
    if (option != 1 && option != 2) {
        printf("Invalid\n");
        return 0;
    }

    // Input the elements and insert them into the linked list
    for (int i = 0; i < n; i++) {
        scanf("%d", &data);
        // Insert at the beginning if option is 1, otherwise insert at the end
        if (option == 1)
            insertAtBeginning(&head, data);
        else
            insertAtEnd(&head, data);
    }

    // Print the linked list
    printLinkedList(head);

    return 0;
}

//puwanut theeranuluk 66070503477
#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* newNode(int data) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

// Function to find the last remaining number in the circular table
int findLastRemaining(int size, int step, int arr[]) {
    struct Node* head = newNode(arr[0]);
    struct Node* prev = head;
    // Create the circular linked list
    for (int i = 1; i < size; i++) {
        prev->next = newNode(arr[i]);
        prev = prev->next;
    }
    prev->next = head; // Make the linked list circular

    struct Node* current = head;
    struct Node* prevNode = NULL;
    while (current->next != current) {
        // Skip step count
        for (int i = 1; i < step; i++) {
            prevNode = current;
            current = current->next;
        }
        // Remove the current node
        prevNode->next = current->next;
        struct Node* temp = current;
        current = current->next;
        free(temp);
    }
    // Return the last remaining node's data
    int result = current->data;
    free(current); // Free the last remaining node
    return result;
}

int main() {
    int size, step;
    scanf("%d %d", &size, &step);
    int arr[size];
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
    printf("%d\n", findLastRemaining(size, step, arr));
    return 0;
}

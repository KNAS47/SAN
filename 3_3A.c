//puwanut theeranuluk 66070503477
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Function to reverse a linked list from a specified start point to an end point
Node* reverse(Node* head, int start, int end) {
    Node *prev = NULL, *current = head, *next = NULL;
    int count = 0;
    
    // Traverse the list until the start point
    while (count < start) {
        prev = current;
        current = current->next;
        count++;
    }
    
    // Connection node is the node at start - 1 position
    // Tail node is the node at start position
    Node *connection = prev, *tail = current;
    
    // Reverse the nodes from start to end
    while (count <= end) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
        count++;
    }
    
    // If connection node is not NULL, connect it to the new start node
    // Else update the head of the list
    if (connection != NULL) {
        connection->next = prev;
    } else {
        head = prev;
    }
    
    // Connect the tail node to the current node
    tail->next = current;
    return head;
}

int main() {
    Node* head = NULL;
    Node* temp = NULL;
    char input[50];
    
    // Create a linked list from the user's input
    while (scanf("%s", input) && strcmp(input, "END") != 0) {
        Node* node = malloc(sizeof(Node));
        node->data = atoi(input);
        node->next = NULL;
        
        if (head == NULL) {
            head = temp = node;
        } else {
            temp->next = node;
            temp = temp->next;
        }
    }
    
    int start, end;
    scanf("%d %d", &start, &end);
    
    // Reverse the linked list from start to end
    head = reverse(head, start - 1, end - 1);
    
    // Print the reversed linked list
    temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    
    return 0;
}

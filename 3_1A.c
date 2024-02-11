//puwanut theeranuluk 66070503477
#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int id;
    int score;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int id, int score) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->id = id;
    newNode->score = score;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a new node at the end of the linked list
void insertNode(struct Node** head_ref, int id, int score) {
    struct Node* newNode = createNode(id, score);
    if (*head_ref == NULL) {
        *head_ref = newNode;
        return;
    }
    struct Node* lastNode = *head_ref;
    while (lastNode->next != NULL) {
        lastNode = lastNode->next;
    }
    lastNode->next = newNode;
}

// Function to swap two nodes
void swap(struct Node* a, struct Node* b) {
    int temp_id = a->id;
    int temp_score = a->score;
    a->id = b->id;
    a->score = b->score;
    b->id = temp_id;
    b->score = temp_score;
}

// Function to sort the linked list
void sortLinkedList(struct Node* head, int mode) {
    if (head == NULL || head->next == NULL) return;

    struct Node* ptr;
    struct Node* lptr = NULL;
    int swapped;

    do {
        swapped = 0;
        ptr = head;

        while (ptr->next != lptr) {
            if ((mode == 0 && ptr->id > ptr->next->id) || (mode == 1 && ptr->score > ptr->next->score)) {
                swap(ptr, ptr->next);
                swapped = 1;
            }
            ptr = ptr->next;
        }
        lptr = ptr;
    } while (swapped);
}

// Function to print the scores in the linked list
void printScores(struct Node* head) {
    struct Node* ptr = head;
    while (ptr != NULL) {
        printf("%d ", ptr->score);
        ptr = ptr->next;
    }
}

// Function to free memory allocated for the linked list
void freeLinkedList(struct Node* head) {
    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    int size, id, score, mode;
    struct Node* head = NULL;

    // Input size of the linked list
    scanf("%d", &size);

    // Input the data (id and score) for each student
    for (int i = 0; i < size; ++i) {
        scanf("%d %d", &id, &score);
        insertNode(&head, id, score);
    }

    // Input mode for sorting
    scanf("%d", &mode);

    // Sort the linked list based on the mode
    sortLinkedList(head, mode);

    // Print the sorted scores
    printScores(head);
    printf("\n");

    // Free memory allocated for the linked list
    freeLinkedList(head);

    return 0;
}

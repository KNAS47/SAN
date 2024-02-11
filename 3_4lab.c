#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INT_MIN -99
#define INT_MAX 99

typedef struct Node {
    int value;
    struct Node* next;
    struct Node* prev;
} Node;

Node* listHead = NULL;
Node* listTail = NULL;

int size = 0;
int k = 0;
int search[100];

void insertNode(int value) {
    Node* newNode = malloc(sizeof(Node));
    if (newNode == NULL) {
        exit(1);
    }
    newNode->value = value;
    newNode->next = NULL;
    newNode->prev = NULL;

    if (listHead == NULL) {
        listHead = listTail = newNode;
    } else {
        newNode->prev = listTail;
        listTail->next = newNode;
        listTail = newNode;
    }
    size++;
}

void deleteNode(int key) {
    Node* current = listHead;
    while (current != NULL) {
        if (current->value == key) {
            Node* prevNode = current->prev;
            Node* nextNode = current->next;

            if (prevNode != NULL) {
                prevNode->next = nextNode;
            } else {
                listHead = nextNode;
            }

            if (nextNode != NULL) {
                nextNode->prev = prevNode;
            } else {
                listTail = prevNode;
            }

            free(current);
            size--;
            return;
        }
        current = current->next;
    }
}

void searchNodes(int key) {
    Node* current = listHead;
    while (current != NULL) {
        if (current->value == key) {
            search[k++] = (current->prev == NULL) ? INT_MIN : current->prev->value;
            search[k++] = (current->next == NULL) ? INT_MIN : current->next->value;
            return;
        }
        current = current->next;
    }
    search[k++] = INT_MAX;
    search[k++] = INT_MAX;
}

void printList() {
    for (int j = 0; j < k; j++) {
        if (search[j] == INT_MIN) {
            printf("NULL");
        } else if (search[j] == INT_MAX) {
            printf("none");
            j++;
        } else {
            printf("%d", search[j]);
        }
        if (j & 1) {
            printf("\n");
        } else {
            printf(" ");
        }
    }

    if (size == 0) {
        printf("none");
    }

    Node* current = listHead;
    while (current != NULL) {
        printf("%d ", current->value);
        current = current->next;
    }

    printf("\n");

    if (size == 0) {
        printf("none");
    }

    current = listTail;
    while (current != NULL) {
        printf("%d ", current->value);
        current = current->prev;
    }
}

int main() {
    while (1) {
        char mode[4];
        int value;

        scanf("%s", mode);

        if (strcmp(mode, "END") == 0) {
            break;
        } else if (strcmp(mode, "ADD") == 0) {
            scanf("%d", &value);
            insertNode(value);
        } else if (strcmp(mode, "DEL") == 0) {
            scanf("%d", &value);
            deleteNode(value);
        } else {
            scanf("%d", &value);
            searchNodes(value);
        }
    }

    printList();

    return 0;
}

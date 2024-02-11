#include <stdio.h>
#include <stdlib.h>

void printArray(int arr[], int size);
int* insertArray(int arr[], int* size, int index, int value);
int* deleteArray(int arr[], int* size, int index);
int* mergeArray(int arr1[], int* size1, int arr2[], int* size2);

int main() {
    int n1, n2;
    scanf("%d", &n1);
    int* arr1 = malloc(n1 * sizeof(int));
    for (int i = 0; i < n1; i++) {
        scanf("%d", &arr1[i]);
    }

    scanf("%d", &n2);
    int* arr2 = malloc(n2 * sizeof(int));
    for (int i = 0; i < n2; i++) {
        scanf("%d", &arr2[i]);
    }

    int insertIndex, insertValue, deleteIndex;
    scanf("%d %d %d", &insertIndex, &insertValue, &deleteIndex);

    arr1 = insertArray(arr1, &n1, insertIndex, insertValue);
    arr1 = deleteArray(arr1, &n1, deleteIndex);
    arr1 = mergeArray(arr1, &n1, arr2, &n2);

    free(arr1);
    free(arr2);

    return 0;
}

int* insertArray(int arr[], int* size, int index, int value) {
    if (index < 0 || index > *size) {
        printf("Index out of bounds\n");
        return arr;
    }

    (*size)++;
    arr = realloc(arr, *size * sizeof(int));
    for (int i = *size - 1; i > index; i--) {
        arr[i] = arr[i - 1];
    }

    arr[index] = value;
    printArray(arr, *size);

    return arr;
}

int* deleteArray(int arr[], int* size, int index) {
    if (index < 0 || index >= *size) {
        printf("Index out of bounds\n");
        return arr;
    }

    for (int i = index; i < *size - 1; i++) {
        arr[i] = arr[i + 1];
    }

    (*size)--;
    arr = realloc(arr, *size * sizeof(int));
    printArray(arr, *size);

    return arr;
}

int* mergeArray(int arr1[], int* size1, int arr2[], int* size2) {
    int newSize = *size1 + *size2;
    arr1 = realloc(arr1, newSize * sizeof(int));
    for (int i = 0; i < *size2; i++) {
        arr1[*size1 + i] = arr2[i];
    }

    printArray(arr1, newSize);

    return arr1;
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

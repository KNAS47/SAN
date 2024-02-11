#include <stdio.h>

void bubbleSort(int *array, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            if (array[i] > array[j]) {
                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
}

int main() {
    int sizeA;

    // Input size of array A
    scanf("%d", &sizeA);

    // Input elements of array A
    int arrA[sizeA];
    for (int i = 0; i < sizeA; i++) {
        scanf("%d", &arrA[i]);
    }

    // Call the bubbleSort function to sort array A
    bubbleSort(arrA, sizeA);

    // Display the sorted array A
    printf("Sorted Array A: ");
    for (int i = 0; i < sizeA; i++) {
        printf("%d ", arrA[i]);
    }

    return 0;
}

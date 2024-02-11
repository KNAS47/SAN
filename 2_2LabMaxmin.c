// puwanut theeranuluk 66070503477
#include <stdio.h>
#include <stdlib.h>

void findMax(int *array, int n, int *max, int *maxIndex) {
    *max = array[0];
    *maxIndex = 0;

    for (int i = 1; i < n; i++) {
        if (array[i] > *max) {
            *max = array[i];
            *maxIndex = i;
        }
    }
}

void findMin(int *array, int n, int *min, int *minIndex) {
    *min = array[0];
    *minIndex = 0;

    for (int i = 1; i < n; i++) {
        if (array[i] < *min) {
            *min = array[i];
            *minIndex = i;
        }
    }
}

void printResult(int max, int maxIndex, int min, int minIndex) {
    printf("%d %d\n", max, maxIndex);
    printf("%d %d\n", min, minIndex);
}

int main() {
    int n;
    scanf("%d", &n);

    int *array = malloc(n * sizeof(int));
    if (array == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        scanf("%d", &array[i]);
    }

    int max, min, maxIndex, minIndex;
    findMax(array, n, &max, &maxIndex);
    findMin(array, n, &min, &minIndex);

    printResult(max, maxIndex, min, minIndex);

    free(array);
    return 0;
}

#include <stdio.h>
#include <stdlib.h>

int main() {
    int size;
    scanf("%d", &size);

    int *arr = (int *)malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    int start, end, step;
    scanf("%d %d %d", &start, &end, &step);

    if (step == 0 || size == 0 || start == end) {
        printf("empty");
        free(arr);
        return 0;
    }

    if (start < -size) start = -size;
    if (end < -size) end = -size;
    if (start < 0) start += size;
    if (end < 0) end += size;
    if (end > size) end = size;

    int isIncreasing = (start < end && step > 0);

    int flag = 0;
    if (isIncreasing) {
        for (int i = start; i < end; i += step) {
            printf("%d ", arr[i]);
            flag = 1;
        }
    } else {
        if (step > 0) step *= -1;
        if (start > size) start = size - 1;
        for (int i = start; i > end; i += step) {
            printf("%d ", arr[i]);
            flag = 1; 
        }
    }

    if (!flag) {
        printf("empty");
    }

    free(arr);
    return 0;
}

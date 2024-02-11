// puwanut theeranuluk 66070503477
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);

    int *array = malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        scanf("%d", array + i);
    }

    int n2;
    scanf("%d", &n2);

    if (n2 == 0) {
        for (int i = 0; i < n; i = i + 2) {
            printf("%d ", *(array + i));
        }
    } else {
        if (n == 1) { 
            printf("none");
        } else {
            for (int i = 1; i < n; i = i + 2) {
                printf("%d ", *(array + i));
            }
        }
    }

    free(array);
    return 0;
}

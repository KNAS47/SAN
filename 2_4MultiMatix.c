//puwanut theeranuluk 66070503477
#include <stdio.h>
#include <stdlib.h>

void readMatrix(int *matrix, int rows, int cols) {
    for (int i = 0; i < rows * cols; i++) {
        scanf("%d", &matrix[i]);
    }
}

void printMatrix(int *matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i * cols + j]);
        }
        printf("\n");
    }
}

int main() {
    int m1, n1, m2, n2;

    scanf("%d %d", &m1, &n1);

    int *A = malloc(m1 * n1 * sizeof(int));
    readMatrix(A, m1, n1);

    scanf("%d %d", &m2, &n2);

    if (n1 != m2) {
        printf("Not Compatible\n");
        free(A);
        return 0;
    }

    int *B = malloc(m2 * n2 * sizeof(int));
    readMatrix(B, m2, n2);

    int *C = malloc(m1 * n2 * sizeof(int));

    for (int i = 0; i < m1; i++) {
        for (int j = 0; j < n2; j++) {
            int sum = 0;
            for (int k = 0; k < n1; k++) {
                sum += A[i * n1 + k] * B[k * n2 + j];
            }
            C[i * n2 + j] = sum;
        }
    }


    printMatrix(C, m1, n2);

    free(A);
    free(B);
    free(C);

    return 0;
}

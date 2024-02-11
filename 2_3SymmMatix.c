//puwanut theeranuluk 66070503477
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void transpose(int *mat, int *trans, int r, int c) {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            trans[j * r + i] = mat[i * c + j];
        }
    }
}

bool symmetric(int *mat, int r, int c) {
    int *trans = malloc(r * c * sizeof(int));

    transpose(mat, trans, r, c);

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (mat[i * c + j] != trans[i * c + j]) {
                free(trans);
                return false;
            }
        }
    }

    free(trans);
    return true;
}

bool skewSymmetric(int *mat, int r, int c) {
    int *trans = malloc(r * c * sizeof(int));

    transpose(mat, trans, r, c);

    for (int i = 0; i < r * c; i++) {
        if (mat[i] != -trans[i]) {
            free(trans);
            return false;
        }
    }

    free(trans);
    return true;
}

int main() {
    int r, c;
    scanf("%d %d", &r, &c);

    int *m = malloc(r * c * sizeof(int));

    for (int i = 0; i < r * c; i++) {
        scanf("%d", &m[i]);
    }

    bool s = symmetric(m, r, c);
    bool ss = skewSymmetric(m, r, c);

    if (s && ss)
        printf("The matrix is symmetric\n");
    else if (s)
        printf("The matrix is symmetric\n");
    else if (ss)
        printf("The matrix is skew-symmetric\n");
    else
        printf("None\n");

    free(m);

    return 0;
}

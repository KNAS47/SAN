//puwanut theeranuluk 66070503477
#include <stdio.h>
#define MAX 100

void printSpiral(int arr[MAX][MAX], int m, int n) {
    int i, k = 0, l = 0;

    while (k < m && l < n) {
        for (i = l; i < n; ++i) {
            printf("%d ", arr[k][i]);
        }
        k++;

        for (i = k; i < m; ++i) {
            printf("%d ", arr[i][n - 1]);
        }
        n--;

        if (k < m) {
            for (i = n - 1; i >= l; --i) {
                printf("%d ", arr[m - 1][i]);
            }
            m--;
        }

        if (l < n) {
            for (i = m - 1; i >= k; --i) {
                printf("%d ", arr[i][l]);
            }
            l++;
        }
    }
}

int main() {
    int arr[MAX][MAX];
    int m, n, i, j;

    scanf("%d %d", &m, &n);

    for (i = 0; i < m; ++i) {
        for (j = 0; j < n; ++j) {
            scanf("%d", &arr[i][j]);
        }
    }

    printSpiral(arr, m, n);

    return 0;
}

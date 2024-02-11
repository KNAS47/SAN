// puwanut theeranuluk 66070503477
#include <stdio.h>
#include <stdlib.h>

int main() {
    int rows, cols;
    scanf("%d %d", &rows, &cols);
    
    if (rows != cols) {
        printf("ERROR\n");
        return 0;
    }
    
    int *matrix = (int *)malloc(rows * cols * sizeof(int));
    
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix[i * cols + j]);
        }
    }
    
    int primary_sum = 0, secondary_sum = 0;
    
    for (int i = 0; i < rows; i++) {
        primary_sum += matrix[i * cols + i];
    }
    
    for (int i = 0; i < rows; i++) {
        secondary_sum += matrix[i * cols + (rows - i - 1)];
    }
    
    printf("Primary: %d\n", primary_sum);
    printf("Secondary: %d\n", secondary_sum);
    
    free(matrix);
    
    return 0;
}

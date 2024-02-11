//puwanut theeranuluk 66070503477
#include <stdio.h>
#include <stdlib.h>

int minJumps(int arr[], int n) {
    if (n <= 1)
        return 0;

    if (arr[0] == 0)
        return -1; 

    int maxReach = arr[0]; 
    int steps = arr[0]; 
    int jumps = 1;

    for (int i = 1; i < n; i++) {
        if (i == n - 1)
            return jumps; 

        maxReach = (i + arr[i] > maxReach) ? i + arr[i] : maxReach;
        steps--;

        if (steps == 0) {
            jumps++;
            if (i >= maxReach)
                return -1;
            steps = maxReach - i;
        }
    }

    return -1; 
}

int main() {
    int n;
    scanf("%d", &n);

    int *arr = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int result = minJumps(arr, n);
    if (result != -1)
        printf("%d\n", result);
    else
        printf("Not Possible\n");

    free(arr);
    return 0;
}

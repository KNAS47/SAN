#include <stdio.h>

void printArr(int n, int arr[])
{
    // insert code here
}

int getSet(int size, int *arr, int m, int n)
{
    /*
    inset code of getting the set and return the size of the set
    where the members in set are in the range of m to n if it's not, print "empty" and return 0
    */
}

void genUniverse(int m, int n, int *u)
{

    /*
    insert code here
    where
    m is the starting point of the universe
    n is the ending point of the universe
    u is the array of the universe
    by the members in set of universe are in the range of m to n and increment by 1
    */
}

void Union(int sizeA, int sizeB, int A[], int B[])
{
    // insert code here
}

void Intersection(int sizeA, int sizeB, int A[], int B[])
{
    // insert code here
}

void Difference(int sizeA, int sizeB, int A[], int B[])
{
    // insert code here
}

int main()
{
    int m, n;
    scanf("%d %d", &m, &n);

    int u[n - m + 1];
    genUniverse(m, n, u);

    int sizeA;
    scanf("%d", &sizeA);
    int A[sizeA];
    // call getSet function to get the set A

    int sizeB;
    scanf("%d", &sizeB);
    int B[sizeB];
    // call getSet function to get the set B

    // Union
    Union(sizeA, sizeB, A, B);

    // Intersection
    Intersection(sizeA, sizeB, A, B);

    // Difference (A-B)
    Difference(sizeA, sizeB, A, B);

    // Difference (B-A)
    Difference(sizeB, sizeA, B, A);

    // Complement (U-A)
    Difference(n - m + 1, sizeA, u, A);

    // Complement (U-B)
    Difference(n - m + 1, sizeB, u, B);

    return 0;
}

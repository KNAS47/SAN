// puwanut theeranuluk 66070503477
#include <stdio.h>
#include <stdlib.h>
#define MAX 1000000

double sum(double *arr, int n)
{
    double s = 0;
    for (int i = 0; i < n; i++)
    {
        s += arr[i];
    }
    return s;
}
double difference(double *arr, int n)
{
    double s = 0;
    for (int i = 0; i < n; i++)
    {
        s -= arr[i];
    }
    return s;
}

int main()
{
  char c;
  scanf("%c", &c);
  double *arr1 = (double*)calloc(MAX, sizeof(double));

  for (int i = 0; i < MAX; i++)
  {
      arr1[i] = i + 1;
  }
  double *arr2 = (double*)malloc(MAX * sizeof(double));
  for (int i = 0; i < MAX; i++)
  {
      arr2[i] = i + 1;
  }
  double s = sum(arr1, MAX);
  double m = difference(arr2, MAX);
  printf("%.0lf \n", s);
  printf("%.0lf \n", m);

  free(arr1);
  free(arr2);

  return 0;
}
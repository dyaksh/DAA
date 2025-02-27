// sumofsubsets

#include <stdio.h>
#define MAX 100
int n, m;
int arr[MAX];
int x[MAX];
void sumOfSubsets(int k, int s, int r)
{
    int i;
    x[k] = 1;
    if (s + arr[k] == m)
    {
        for (i = 0; i < n; i++)
        {
            printf("%d ", x[i]);
        }
        printf("\n");
    }
    // include
    else if (s + arr[k] + arr[k + 1] <= m)
    {
        sumOfSubsets(k + 1, s + arr[k], r - arr[k]);
    }
    // not include
    if (s + arr[k + 1] <= m && s + r - arr[k] >= m)
    {
        x[k] = 0;
        sumOfSubsets(k + 1, s, r - arr[k]);
    }
}
int main()
{
    int i, t;
    t = 0;
    printf("Number of elements : ");
    scanf("%d", &n);
    printf("Enter the elements : ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
        t += arr[i];
        x[i] = 0;
    }
    printf("Sum : ");
    scanf("%d", &m);
    sumOfSubsets(0, 0, t);
}

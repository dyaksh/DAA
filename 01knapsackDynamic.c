/* Greedy
#include <stdio.h>


void simple_fill(int n, int c[], int v[], int W) {
    int cur_w = W;
    float tot_v = 0;
    int i, maxi;
    int used[n];

    for (i = 0; i < n; ++i)
        used[i] = 0;

    while (cur_w > 0) {
        maxi = -1;
        for (i = 0; i < n; ++i) {
            if ((used[i] == 0) && ((maxi == -1) || ((float)v[i] / c[i] > (float)v[maxi] / c[maxi]))) {
                maxi = i;
            }
        }
        used[maxi] = 1;
        cur_w -= c[maxi];
        tot_v += v[maxi];
        if (cur_w >= 0) {
            printf("Added object %d (%d$, %dKg) completely in the bag. Space left: %d.\n", maxi + 1, v[maxi], c[maxi], cur_w);
        } else {
            printf("Added %d%% (%d$, %dKg) of object %d in the bag.\n", (int)((1 + (float)cur_w / c[maxi]) * 100), v[maxi], c[maxi], maxi + 1);
            tot_v -= v[maxi];
            tot_v += (1 + (float)cur_w / c[maxi]) * v[maxi];
        }
    }

    printf("Total value in the bag: %.2f$\n", tot_v);
}

int main() {
    int n, W;

    printf("Enter the number of objects: ");
    scanf("%d", &n);

    int c[n], v[n];

    printf("Enter the weights of objects:\n");
    for (int i = 0; i < n; ++i) {
        scanf("%d", &c[i]);
    }

    printf("Enter the values of objects:\n");
    for (int i = 0; i < n; ++i) {
        scanf("%d", &v[i]);
    }

    printf("Enter the maximum capacity of the knapsack: ");
    scanf("%d", &W);

    simple_fill(n, c, v, W);

    return 0;
}
*/
// dynamic

#include <stdio.h>
#include <stdlib.h>

// Function to find the maximum of two integers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Function to solve the 0/1 knapsack problem using dynamic programming
int knapsack(int W, int wt[], int val[], int n) {
    int i, w;
    int dp[n + 1][W + 1];

    // Build dp[][] in bottom-up manner
    for (i = 0; i <= n; i++) {
        for (w = 0; w <= W; w++) {
            if (i == 0 || w == 0)
                dp[i][w] = 0;
            else if (wt[i - 1] <= w)
                dp[i][w] = max(val[i - 1] + dp[i - 1][w - wt[i - 1]], dp[i - 1][w]);
            else
                dp[i][w] = dp[i - 1][w];
        }
    }

    return dp[n][W];
}

int main() {
    int *val, *wt;
    int W, n;

    // Input the number of items
    printf("Enter the number of items: ");
    scanf("%d", &n);

    // Allocate memory for arrays
    val = (int *)malloc(n * sizeof(int));
    wt = (int *)malloc(n * sizeof(int));

    // Input the values and weights of items
    printf("Enter the values of items:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &val[i]);
    }

    printf("Enter the weights of items:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &wt[i]);
    }

    // Input the maximum weight capacity
    printf("Enter the maximum weight capacity: ");
    scanf("%d", &W);

    // Solve the knapsack problem and print the result
    printf("Maximum value that can be obtained: %d\n", knapsack(W, wt, val, n));

    // Free allocated memory
    free(val);
    free(wt);

    return 0;
}


#include <stdio.h>

// Function to calculate the nth Fibonacci number using greedy approach
int fibonacciGreedy(int n) {
    if (n <= 1)
        return n;
    int a = 0, b = 1;
    for (int i = 2; i <= n; i++) {
        int temp = a + b;
        a = b;
        b = temp;
    }
    return b;
}

// Function to calculate the nth Fibonacci number using dynamic programming approach
int fibonacciDynamic(int n) {
    int fib[n + 1];
    fib[0] = 0;
    fib[1] = 1;
    for (int i = 2; i <= n; i++)
        fib[i] = fib[i - 1] + fib[i - 2];
    return fib[n];
}

int main() {
    int n;
    printf("Enter the value of n: ");
    scanf("%d", &n);
    printf("Using greedy approach, the %dth Fibonacci number is: %d\n", n, fibonacciGreedy(n));
    printf("Using dynamic programming approach, the %dth Fibonacci number is: %d\n", n, fibonacciDynamic(n));
    return 0;
}

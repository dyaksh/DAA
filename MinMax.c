#include <stdio.h>

// Function to find the minimum and maximum elements in an array
void findMinMax(int arr[], int n, int *min, int *max) {
    // Initialize min and max with the first element of the array
    *min = arr[0];
    *max = arr[0];

    // Traverse the array and update min and max accordingly
    for (int i = 1; i < n; i++) {
        if (arr[i] < *min) {
            *min = arr[i];
        }
        if (arr[i] > *max) {
            *max = arr[i];
        }
    }
}

int main() {
    int n;

    // Take input for the size of the array
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int arr[n];

    // Take input for the elements of the array
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int min, max;

    // Find the minimum and maximum elements
    findMinMax(arr, n, &min, &max);

    printf("Minimum element: %d\n", min);
    printf("Maximum element: %d\n", max);

    return 0;
}

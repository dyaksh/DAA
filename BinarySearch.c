#include <stdio.h>

// Function to perform binary search
int binarySearch(int arr[], int size, int target) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        // Check if target is present at mid
        if (arr[mid] == target) {
            return mid;
        }

        // If target is greater, ignore the left half
        if (arr[mid] < target) {
            left = mid + 1;
        }
        // If target is smaller, ignore the right half
        else {
            right = mid - 1;
        }
    }

    // Target is not present in the array
    return -1;
}

int main() {
    int n, target;

    // Take input for the size of the array
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int arr[n];

    // Take input for the elements of the array
    printf("Enter the elements of the array in sorted order:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Take input for the target value
    printf("Enter the target value to search: ");
    scanf("%d", &target);

    // Perform binary search
    int result = binarySearch(arr, n, target);

    // Output the result
    if (result != -1) {
        printf("Element found at index %d\n", result);
    } else {
        printf("Element not found in the array\n");
    }

    return 0;
}

//Worst Case: 𝑂 ( log ⁡ 𝑛 )
//Average Case: 𝑂 ( log ⁡ 𝑛 )
//Best Case: 𝑂 ( 1 )
//Space Complexity 0(1)
//Another program
#include <stdlib.h>
#include <stdio.h>

int binarySearch(int arr[], int low, int high, int searchElement) {
    int mid = (low + high) / 2;

    if(arr[mid] == searchElement)
        return mid;
    else if(searchElement > arr[mid] && mid > 0)
        binarySearch(arr, mid + 1, high, searchElement); // call on right part
    else if(searchElement < arr[mid] && mid > 0)
        binarySearch(arr, low, mid - 1, searchElement); // call on left part
    else
        return -1;
}

int main() {

    int numElements, searchElement;
    printf("Enter the number of elements in sorted manner : ");
    scanf("%d", &numElements);

    int array[numElements];

    for (int i = 0; i < numElements; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &array[i]);
    }

    printf("Search Element : ");
    scanf("%d", &searchElement);

    int resultIndex = binarySearch(array, 0, numElements - 1, searchElement);
    if(resultIndex != -1)
        printf("Element %d found at index %d", array[resultIndex], resultIndex);
    else
        printf("Element %d not found !", searchElement);
    return 0;
}

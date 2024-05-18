#include <stdio.h>
#include <stdlib.h>

// Structure to represent an item
struct Item {
    int value;
    int weight;
};

// Function to compare items based on their value per unit weight (value/weight)
int compare(const void *a, const void *b) {
    double ratio_a = (double)(((struct Item *)a)->value) / (((struct Item *)a)->weight);
    double ratio_b = (double)(((struct Item *)b)->value) / (((struct Item *)b)->weight);
    if (ratio_a > ratio_b) {
        return -1; // Higher ratio comes first
    } else if (ratio_a < ratio_b) {
        return 1; // Lower ratio comes first
    } else {
        return 0;
    }
}

// Function to solve the fractional knapsack problem
double fractionalKnapsack(int capacity, struct Item items[], int n) {
    // Sort items based on their value per unit weight
    qsort(items, n, sizeof(items[0]), compare);

    int currentWeight = 0; // Current weight in knapsack
    double finalValue = 0.0; // Final value of items selected

    // Iterate through all items
    for (int i = 0; i < n; i++) {
        // If adding the entire item is possible, add it and update remaining capacity
        if (currentWeight + items[i].weight <= capacity) {
            currentWeight += items[i].weight;
            finalValue += items[i].value;
        }
        // Otherwise, add a fraction of the item and break the loop
        else {
            int remainingWeight = capacity - currentWeight;
            finalValue += items[i].value * ((double)remainingWeight / items[i].weight);
            break;
        }
    }

    return finalValue;
}

int main() {
    int n, capacity;

    // Take input for the number of items and knapsack capacity
    printf("Enter the number of items: ");
    scanf("%d", &n);
    printf("Enter the knapsack capacity: ");
    scanf("%d", &capacity);

    struct Item items[n];

    // Take input for the value and weight of each item
    printf("Enter the value and weight of each item:\n");
    for (int i = 0; i < n; i++) {
        printf("Item %d:\n", i + 1);
        printf("Value: ");
        scanf("%d", &items[i].value);
        printf("Weight: ");
        scanf("%d", &items[i].weight);
    }

    // Solve the fractional knapsack problem
    double maxValue = fractionalKnapsack(capacity, items, n);

    // Print the maximum value
    printf("Maximum value in the knapsack: %.2lf\n", maxValue);

    return 0;
}


// Another
#include <stdio.h>
#define ITEMS 5

int P[ITEMS], W[ITEMS];
double PW[ITEMS], ratio[ITEMS], X[ITEMS];
int kCapacity;

void calcPW() {
	int i;
	for (i = 0; i < ITEMS; i++)
		PW[i] = (double) P[i] / W[i];
}

void sortPW() {
	int i, j;
	double temp;
	for (i = 0; i < ITEMS; i++)
		for (j = i + 1; j < ITEMS; j++)
			if (PW[i] < PW[j]) {
				temp = PW[i];
				PW[i] = PW[j];
				PW[j] = temp;
				temp = P[i];
				P[i] = P[j];
				P[j] = temp;
				temp = W[i];
				W[i] = W[j];
				W[j] = temp;
			}
}


double FractionalKnapsack() {

	int U = kCapacity, i = 0;
	double value = 0;

	while (i <= ITEMS && U != 0) {

		if (W[i] <= U) {
			X[i] = 1;
			value += P[i];
			U -= W[i];
		} else {

			X[i] = (double) U / W[i];
			value += (double) X[i] * P[i];
			U = 0;
		}
		i++;
	}
	return value;
}

int main() {
	int i;
	double maxProfit;
	printf("\nEnter the profits and weights of the items: ");
	for (i = 0; i < ITEMS; i++)
		scanf("%d %d", &P[i], &W[i]);
	printf("\nEnter the capacity of the knapsack: ");
	scanf("%d", &kCapacity);
	calcPW();
	sortPW();
	maxProfit = FractionalKnapsack();
	printf("\nThe max profit is: %.2f in the ratio:\n", maxProfit);

	for (i = 0; i < ITEMS; i++)
		printf("%.2f: %d\n", X[i], P[i]);
	return 0;
}

/* using Dynamic programing
#include <stdio.h>
#include <stdlib.h>

// Function to find the minimum number of coins required to make a given amount
int minCoins(int coins[], int numCoins, int amount) {
    // Create a table to store the minimum number of coins required for each amount
    int dp[amount + 1];
    dp[0] = 0; // Base case: 0 coins required to make amount 0

    // Initialize all other values as infinite
    for (int i = 1; i <= amount; i++) {
        dp[i] = INT_MAX;
    }

    // Create a table to store the combination of coins for each amount
    int coinsUsed[amount + 1][numCoins];
    for (int i = 0; i <= amount; i++) {
        for (int j = 0; j < numCoins; j++) {
            coinsUsed[i][j] = 0;
        }
    }

    // Iterate through all coins and calculate minimum number of coins required for each amount
    for (int i = 0; i < numCoins; i++) {
        for (int j = coins[i]; j <= amount; j++) {
            if (dp[j - coins[i]] != INT_MAX && dp[j - coins[i]] + 1 < dp[j]) {
                dp[j] = dp[j - coins[i]] + 1;
                // Update the coins used for this amount
                for (int k = 0; k < numCoins; k++) {
                    coinsUsed[j][k] = coinsUsed[j - coins[i]][k];
                }
                coinsUsed[j][i]++;
            }
        }
    }

    // Print the combination of coins that achieves the minimum
    printf("Combination of coins to achieve minimum:\n");
    for (int i = 0; i < numCoins; i++) {
        printf("%d: %d\n", coins[i], coinsUsed[amount][i]);
    }
    printf("\n");

    // Print all possible combinations of coins
    printf("All possible combinations:\n");
    for (int i = 0; i <= amount; i++) {
        if (dp[i] != INT_MAX) {
            printf("Amount: %d, Coins: ", i);
            for (int j = 0; j < numCoins; j++) {
                printf("%d:%d ", coins[j], coinsUsed[i][j]);
            }
            printf("\n");
        }
    }
    printf("\n");

    return dp[amount]; // Return the minimum number of coins required to make the given amount
}

int main() {
    int numCoins, amount;

    // Take input for the number of coins and the amount to make change for
    printf("Enter the number of coins: ");
    scanf("%d", &numCoins);
    int coins[numCoins];

    // Input the values of each coin
    printf("Enter the values of each coin:\n");
    for (int i = 0; i < numCoins; i++) {
        scanf("%d", &coins[i]);
    }

    printf("Enter the amount to make change for: ");
    scanf("%d", &amount);

    // Find and print the minimum number of coins required to make the given amount
    int min = minCoins(coins, numCoins, amount);
    if (min == INT_MAX) {
        printf("It is not possible to make change for the given amount using the given coins.\n");
    } else {
        printf("Minimum number of coins required: %d\n", min);
    }

    return 0;
}


// greedy approach
*/
#include <stdio.h>
#include <stdlib.h>

// Function to find the minimum number of coins required using a greedy approach
int minCoinsGreedy(int coins[], int numCoins, int amount) {
    // Sort the coins in descending order
    for (int i = 0; i < numCoins - 1; i++) {
        for (int j = i + 1; j < numCoins; j++) {
            if (coins[i] < coins[j]) {
                int temp = coins[i];
                coins[i] = coins[j];
                coins[j] = temp;
            }
        }
    }

    int coinCount = 0; // Initialize the count of coins used
    int coinPossibility[numCoins]; // Array to store the possibility of each coin used
    int coinSum[numCoins]; // Array to store the sum of each coin used

    // Initialize coinPossibility and coinSum arrays
    for (int i = 0; i < numCoins; i++) {
        coinPossibility[i] = 0;
        coinSum[i] = 0;
    }

    int i = 0; // Index to iterate through the sorted coins array

    // Greedily select coins until the target amount is reached
    while (amount > 0 && i < numCoins) {
        if (coins[i] <= amount) {
            int numCoinsUsed = amount / coins[i];
            coinCount += numCoinsUsed; // Update the count of coins used
            amount -= numCoinsUsed * coins[i]; // Update the remaining amount
            coinPossibility[i] = numCoinsUsed; // Update the possibility of this coin used
            coinSum[i] = numCoinsUsed * coins[i]; // Update the sum of this coin used
        }
        i++; // Move to the next coin denomination
    }

    // Print the coins used along with their possibility and sum
    printf("Coins used and their possibility and sum:\n");
    for (int i = 0; i < numCoins; i++) {
        if (coinPossibility[i] > 0) {
            printf("Coin %d: Possibility=%d, Sum=%d\n", coins[i], coinPossibility[i], coinSum[i]);
        }
    }
    printf("\n");

    return coinCount; // Return the count of coins used
}

int main() {
    int numCoins, amount;

    // Take input for the number of coins and the amount to make change for
    printf("Enter the number of coins: ");
    scanf("%d", &numCoins);
    int coins[numCoins];

    // Input the values of each coin
    printf("Enter the values of each coin:\n");
    for (int i = 0; i < numCoins; i++) {
        scanf("%d", &coins[i]);
    }

    printf("Enter the amount to make change for: ");
    scanf("%d", &amount);

    // Find and print the minimum number of coins required to make the given amount
    int min = minCoinsGreedy(coins, numCoins, amount);
    printf("Minimum number of coins required (greedy approach): %d\n", min);

    return 0;
}

#include <stdio.h>
#include <stdlib.h>

// Structure to represent a job
struct Job {
    int id;      // Job ID
    int deadline; // Deadline
    int profit;  // Profit
};

// Function to compare jobs based on their profits (in non-increasing order)
int compare(const void *a, const void *b) {
    return (((struct Job *)b)->profit - ((struct Job *)a)->profit);
}

// Function to find the maximum profit job sequence with deadlines
void jobSchedulingWithDeadline(struct Job jobs[], int n) {
    // Sort jobs based on their profits (in non-increasing order)
    qsort(jobs, n, sizeof(jobs[0]), compare);

    int maxDeadline = 0;
    for (int i = 0; i < n; i++) {
        if (jobs[i].deadline > maxDeadline) {
            maxDeadline = jobs[i].deadline;
        }
    }

    // Array to store the result (job sequence)
    int result[maxDeadline];
    for (int i = 0; i < maxDeadline; i++) {
        result[i] = -1; // Initialize result array with -1
    }

    int totalProfit = 0;
    int count = 0; // Number of jobs scheduled
    // Iterate through all jobs
    for (int i = 0; i < n; i++) {
        // Find a slot for the current job (within its deadline)
        for (int j = jobs[i].deadline - 1; j >= 0; j--) {
            if (result[j] == -1) {
                result[j] = jobs[i].id;
                totalProfit += jobs[i].profit;
                count++;
                break;
            }
        }
    }

    // Print the job sequence and total profit
    printf("Job Sequence with Deadlines: ");
    for (int i = 0; i < maxDeadline; i++) {
        if (result[i] != -1) {
            printf("%d ", result[i]);
        }
    }
    printf("\nTotal Profit: %d\n", totalProfit);
}

int main() {
    int n;

    // Take input for the number of jobs
    printf("Enter the number of jobs: ");
    scanf("%d", &n);

    struct Job jobs[n];

    // Take input for each job's deadline and profit
    printf("Enter the deadline and profit of each job:\n");
    for (int i = 0; i < n; i++) {
        printf("Job %d:\n", i + 1);
        printf("Deadline: ");
        scanf("%d", &jobs[i].deadline);
        printf("Profit: ");
        scanf("%d", &jobs[i].profit);
        jobs[i].id = i + 1; // Assign unique job IDs
    }

    // Find the maximum profit job sequence with deadlines
    jobSchedulingWithDeadline(jobs, n);

    return 0;
}

#include <stdio.h>
#include <stdlib.h>

// Structure to represent a job
struct Job {
    int id;      // Job ID
    int profit;  // Profit
};

// Function to compare jobs based on their profits (in non-increasing order)
int compare(const void *a, const void *b) {
    return (((struct Job *)b)->profit - ((struct Job *)a)->profit);
}

// Function to find the maximum profit job sequence without considering deadlines
void jobSchedulingWithoutDeadline(struct Job jobs[], int n) {
    // Sort jobs based on their profits (in non-increasing order)
    qsort(jobs, n, sizeof(jobs[0]), compare);

    int totalProfit = 0;

    // Print the job sequence and total profit
    printf("Job Sequence without Deadlines: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", jobs[i].id);
        totalProfit += jobs[i].profit;
    }
    printf("\nTotal Profit: %d\n", totalProfit);
}

int main() {
    int n;

    // Take input for the number of jobs
    printf("Enter the number of jobs: ");
    scanf("%d", &n);

    struct Job jobs[n];

    // Take input for each job's profit
    printf("Enter the profit of each job:\n");
    for (int i = 0; i < n; i++) {
        printf("Job %d: ", i + 1);
        scanf("%d", &jobs[i].profit);
        jobs[i].id = i + 1; // Assign unique job IDs
    }

    // Find the maximum profit job sequence without considering deadlines
    jobSchedulingWithoutDeadline(jobs, n);

    return 0;
}

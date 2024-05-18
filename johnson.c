#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;   // Job id
    int mt;   // Machine time
    char mn;  // Machine name ('A' or 'B')
} Job;

void swap(Job* a, Job* b) {
    Job temp = *a;
    *a = *b;
    *b = temp;
}

int compare(const void* a, const void* b) {
    Job* jobA = (Job*)a;
    Job* jobB = (Job*)b;
    return jobA->mt - jobB->mt;
}

void JohnsonJobs(Job arr[], int n, int ans[]) {
    qsort(arr, 2 * n, sizeof(Job), compare);

    int l = 0, r = n - 1;
    for (int i = 0; i < 2 * n; i++) {
        if (arr[i].mn == 'A') {
            ans[l] = arr[i].id;
            l++;
        } else {
            ans[r] = arr[i].id;
            r--;
        }
    }
}

int main() {
    int n;
    printf("Enter number of jobs: ");
    scanf("%d", &n);

    Job arr[2 * n];
    printf("Enter job no \t Machine 1 time \t Machine 2 time\n");
    for (int i = 0; i < n; i++) {
        printf("Seq %d ==\n", i + 1);
        int id, mta, mtb;
        printf("Job ID: ");
        scanf("%d", &id);
        printf("Machine A time: ");
        scanf("%d", &mta);
        printf("Machine B time: ");
        scanf("%d", &mtb);

        arr[2 * i].id = id;
        arr[2 * i].mt = mta;
        arr[2 * i].mn = 'A';
        arr[2 * i + 1].id = id;
        arr[2 * i + 1].mt = mtb;
        arr[2 * i + 1].mn = 'B';
    }

    int ans[n];
    JohnsonJobs(arr, n, ans);

    printf("The order of jobs by Johnson are: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", ans[i]);
    }
    printf("\n");

    return 0;
}
/*
Enter number of jobs: 3
Enter job no     Machine 1 time     Machine 2 time
Seq 1 ==
Job ID: 1
Machine A time: 4
Machine B time: 3
Seq 2 ==
Job ID: 2
Machine A time: 2
Machine B time: 1
Seq 3 ==
Job ID: 3
Machine A time: 6
Machine B time: 5

The order of jobs by Johnson are: 2 1 3
*/

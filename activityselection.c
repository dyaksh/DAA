#include<stdio.h>

int start[50], end[50], n;

void sort() {
    int tempS = 0, tempE = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (end[j] > end[j + 1]) {
                tempE = end[j];
                end[j] = end[j + 1];
                end[j + 1] = tempE;
                tempS = start[j];
                start[j] = start[j + 1];
                start[j + 1] = tempS;
            }
        }
    }
}

void ActivitySelection() {
    int selected = 0, count = 0;
    for (int i = 0; i < n; i++) {
        if (start[i] >= selected) {
            printf("Taking %d->%d\n", start[i], end[i]);
            selected = end[i];
            count++;
        }
    }
    printf("\nTotal Activities selected: %d\n", count);
}

int main() {
    printf("Enter the number of activities: ");
    scanf("%d", &n);

    printf("Enter start times of activities: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &start[i]);
    }

    printf("Enter end times of activities: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &end[i]);
    }

    sort();
    ActivitySelection();
    return 0;
}

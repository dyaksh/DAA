#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void computeLPSArray(char *pat, int M, int *lps) {
    int len = 0; // Length of the previous longest prefix suffix
    lps[0] = 0; // lps[0] is always 0

    int i = 1;
    while (i < M) {
        if (pat[i] == pat[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
}

void KMPSearch(char *pat, char *txt) {
    int M = strlen(pat);
    int N = strlen(txt);

    int *lps = (int *)malloc(sizeof(int) * M);
    computeLPSArray(pat, M, lps);

    int i = 0; // Index for txt[]
    int j = 0; // Index for pat[]
    while (i < N) {
        if (pat[j] == txt[i]) {
            j++;
            i++;
        }
        if (j == M) {
            printf("Pattern found at index %d\n", i - j);
            j = lps[j - 1];
        } else if (i < N && pat[j] != txt[i]) {
            if (j != 0)
                j = lps[j - 1];
            else
                i = i + 1;
        }
    }

    free(lps);
}

int main() {
    char txt[100];
    char pat[100];

    printf("Enter the text: ");
    scanf("%s", txt);
    printf("Enter the pattern: ");
    scanf("%s", pat);

    KMPSearch(pat, txt);
    return 0;
}
/*
#include<stdio.h>
#include<string.h>

char T[50], P[50]; // Arrays to store the text and pattern
int pie[50]; // Array to store the pie values

// Function to compute the pie values (partial match table)
void Compute_prefix() {
    int m = strlen(P), k = 0; // m is the length of the pattern

    pie[0] = 0; // pie[0] is always 0

    // Loop to compute pie values for each position in the pattern
    for (int q = 1; q < m; q++) {
        while (k > 0 && P[k] != P[q]) {
            k = pie[q]; // Move to the next position using the previous pie value
        }
        if (P[k] == P[q]) {
            k++; // Increment k if characters match
        }
        pie[q] = k; // Store the pie value for the current position
    }

    // Print the computed pie values for debugging
    printf("Pie:\n");
    for (int i = 0; i < m; i++) {
        printf("%d ", pie[i]);
    }
}

// Function to perform the Knuth-Morris-Pratt algorithm
void KMP() {
    int m, n;
    n = strlen(T); // Length of the text
    m = strlen(P); // Length of the pattern

    int q = 0; // Current state in the finite automaton

    // Loop to scan through the text for occurrences of the pattern
    for (int i = 0; i < n; i++) {
        while (q > 0 && P[q] != T[i]) {
            q = pie[q - 1]; // Move to the next state using the pie value
        }
        if (P[q] == T[i]) {
            q++; // Increment q if characters match
        }
        if (q == m) {
            printf("Pattern occurs at shift: %d\n", i - m + 1); // Pattern found, print the starting position
            q = pie[q - 1]; // Move to the next state using the pie value
        }
    }
}

// Main function
void main() {
    printf("\nEnter the text to be checked: ");
    scanf("%s", T);
    printf("\nEnter the pattern to be checked: ");
    scanf("%s", P);

    Compute_prefix(); // Compute pie values for the pattern
    KMP(); // Perform pattern matching using Knuth-Morris-Pratt algorithm
}
*/

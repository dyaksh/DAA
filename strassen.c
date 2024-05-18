#include <stdio.h>

void strassen(int n, int A[n][n], int B[n][n], int C[n][n]) {
    if (n == 1) {
        C[0][0] = A[0][0] * B[0][0];
        return;
    }

    int newSize = n / 2;
    int A11[newSize][newSize], A12[newSize][newSize], A21[newSize][newSize], A22[newSize][newSize];
    int B11[newSize][newSize], B12[newSize][newSize], B21[newSize][newSize], B22[newSize][newSize];
    int C11[newSize][newSize], C12[newSize][newSize], C21[newSize][newSize], C22[newSize][newSize];
    int P1[newSize][newSize], P2[newSize][newSize], P3[newSize][newSize], P4[newSize][newSize], P5[newSize][newSize], P6[newSize][newSize], P7[newSize][newSize];
    int temp1[newSize][newSize], temp2[newSize][newSize];

    // Divide matrices A and B into 4 submatrices
    for (int i = 0; i < newSize; i++) {
        for (int j = 0; j < newSize; j++) {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + newSize];
            A21[i][j] = A[i + newSize][j];
            A22[i][j] = A[i + newSize][j + newSize];

            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + newSize];
            B21[i][j] = B[i + newSize][j];
            B22[i][j] = B[i + newSize][j + newSize];
        }
    }

    // Compute the 7 products
    strassen(newSize, A11, B11, temp1);
    strassen(newSize, A12, B21, temp2);
    matrixAddition(newSize, temp1, temp2, C11);

    strassen(newSize, A11, B12, temp1);
    strassen(newSize, A12, B22, temp2);
    matrixAddition(newSize, temp1, temp2, C12);

    strassen(newSize, A21, B11, temp1);
    strassen(newSize, A22, B21, temp2);
    matrixAddition(newSize, temp1, temp2, C21);

    strassen(newSize, A21, B12, temp1);
    strassen(newSize, A22, B22, temp2);
    matrixAddition(newSize, temp1, temp2, C22);

    // Combine the 4 submatrices to get the result matrix
    for (int i = 0; i < newSize; i++) {
        for (int j = 0; j < newSize; j++) {
            C[i][j] = C11[i][j];
            C[i][j + newSize] = C12[i][j];
            C[i + newSize][j] = C21[i][j];
            C[i + newSize][j + newSize] = C22[i][j];
        }
    }
}

void matrixAddition(int n, int A[n][n], int B[n][n], int C[n][n]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}

void printMatrix(int n, int mat[n][n]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d\t", mat[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int V;
    printf("Enter the size of the matrices: ");
    scanf("%d", &V);

    int A[V][V], B[V][V], C[V][V];

    printf("Enter elements of matrix A:\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            scanf("%d", &A[i][j]);
        }
    }

    printf("Enter elements of matrix B:\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            scanf("%d", &B[i][j]);
        }
    }

    strassen(V, A, B, C);

    printf("Matrix A:\n");
    printMatrix(V, A);
    printf("\nMatrix B:\n");
    printMatrix(V, B);
    printf("\nMatrix C (A * B) using Strassen's algorithm:\n");
    printMatrix(V, C);

    return 0;
}

#include <stdio.h>

void strassen(int n, int A[n][n], int B[n][n], int C[n][n]) {
    if (n == 1) {
        C[0][0] = A[0][0] * B[0][0];
        return;
    }
    int half = n / 2;
    int A11[half][half], A12[half][half], A21[half][half], A22[half][half];
    int B11[half][half], B12[half][half], B21[half][half], B22[half][half];
    int C11[half][half], C12[half][half], C21[half][half], C22[half][half];
    int M1[half][half], M2[half][half], M3[half][half], M4[half][half];
    int M5[half][half], M6[half][half], M7[half][half];
    int temp1[half][half], temp2[half][half];

    // Divide A into A11, A12, A21, A22 and B into B11, B12, B21, B22
    for (int i = 0; i < half; i++) {
        for (int j = 0; j < half; j++) {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + half];
            A21[i][j] = A[i + half][j];
            A22[i][j] = A[i + half][j + half];
            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + half];
            B21[i][j] = B[i + half][j];
            B22[i][j] = B[i + half][j + half];
        }
    }

    // M1 = (A11 + A22) * (B11 + B22)
    for (int i = 0; i < half; i++) {
        for (int j = 0; j < half; j++) {
            temp1[i][j] = A11[i][j] + A22[i][j];
            temp2[i][j] = B11[i][j] + B22[i][j];
        }
    }
    strassen(half, temp1, temp2, M1);

    // M2 = (A21 + A22) * B11
    for (int i = 0; i < half; i++) {
        for (int j = 0; j < half; j++) {
            temp1[i][j] = A21[i][j] + A22[i][j];
        }
    }
    strassen(half, temp1, B11, M2);

    // M3 = A11 * (B12 - B22)
    for (int i = 0; i < half; i++) {
        for (int j = 0; j < half; j++) {
            temp1[i][j] = B12[i][j] - B22[i][j];
        }
    }
    strassen(half, A11, temp1, M3);

    // M4 = A22 * (B21 - B11)
    for (int i = 0; i < half; i++) {
        for (int j = 0; j < half; j++) {
            temp1[i][j] = B21[i][j] - B11[i][j];
        }
    }
    strassen(half, A22, temp1, M4);

    // M5 = (A11 + A12) * B22
    for (int i = 0; i < half; i++) {
        for (int j = 0; j < half; j++) {
            temp1[i][j] = A11[i][j] + A12[i][j];
        }
    }
    strassen(half, temp1, B22, M5);

    // M6 = (A21 - A11) * (B11 + B12)
    for (int i = 0; i < half; i++) {
        for (int j = 0; j < half; j++) {
            temp1[i][j] = A21[i][j] - A11[i][j];
            temp2[i][j] = B11[i][j] + B12[i][j];
        }
    }
    strassen(half, temp1, temp2, M6);

    // M7 = (A12 - A22) * (B21 + B22)
    for (int i = 0; i < half; i++) {
        for (int j = 0; j < half; j++) {
            temp1[i][j] = A12[i][j] - A22[i][j];
            temp2[i][j] = B21[i][j] + B22[i][j];
        }
    }
    strassen(half, temp1, temp2, M7);

    // C11 = M1 + M4 - M5 + M7
    for (int i = 0; i < half; i++) {
        for (int j = 0; j < half; j++) {
            C11[i][j] = M1[i][j] + M4[i][j] - M5[i][j] + M7[i][j];
        }
    }

    // C12 = M3 + M5
    for (int i = 0; i < half; i++) {
        for (int j = 0; j < half; j++) {
            C12[i][j] = M3[i][j] + M5[i][j];
        }
    }

    // C21 = M2 + M4
    for (int i = 0; i < half; i++) {
        for (int j = 0; j < half; j++) {
            C21[i][j] = M2[i][j] + M4[i][j];
        }
    }

    // C22 = M1 - M2 + M3 + M6
    for (int i = 0; i < half; i++) {
        for (int j = 0; j < half; j++) {
            C22[i][j] = M1[i][j] - M2[i][j] + M3[i][j] + M6[i][j];
        }
    }

    // Combine C11, C12, C21, C22 into C
    for (int i = 0; i < half; i++) {
        for (int j = 0; j < half; j++) {
            C[i][j] = C11[i][j];
            C[i][j + half] = C12[i][j];
            C[i + half][j] = C21[i][j];
            C[i + half][j + half] = C22[i][j];
        }
    }
}

void printMatrix(int n, int matrix[n][n]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int n;
    printf("Enter the size of the matrix (must be a power of 2): ");
    scanf("%d", &n);

    int A[n][n], B[n][n], C[n][n];

    printf("Enter elements of matrix A:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &A[i][j]);
        }
    }

    printf("Enter elements of matrix B:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &B[i][j]);
        }
    }

    strassen(n, A, B, C);

    printf("Resultant matrix C:\n");
    printMatrix(n, C);

    return 0;
}


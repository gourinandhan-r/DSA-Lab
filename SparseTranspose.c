#include <stdio.h>

int main() {
    int rows, cols;

    printf("Enter number of rows and columns: ");
    scanf("%d %d", &rows, &cols);

    int matrix[rows][cols];

    printf("Enter elements of the matrix:\n");
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            scanf("%d", &matrix[i][j]);

    // Count non-zero elements
    int count = 0;
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            if (matrix[i][j] != 0)
                count++;

    // Sparse matrix representation
    int sparse[count + 1][3];
    sparse[0][0] = rows;
    sparse[0][1] = cols;
    sparse[0][2] = count;

    int k = 1;
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            if (matrix[i][j] != 0) {
                sparse[k][0] = i;
                sparse[k][1] = j;
                sparse[k][2] = matrix[i][j];
                k++;
            }

    // Transpose
    int transpose[count + 1][3];
    transpose[0][0] = sparse[0][1];
    transpose[0][1] = sparse[0][0];
    transpose[0][2] = sparse[0][2];

    k = 1;
    for (int i = 0; i < cols; i++)
        for (int j = 1; j <= count; j++)
            if (sparse[j][1] == i) {
                transpose[k][0] = sparse[j][1];
                transpose[k][1] = sparse[j][0];
                transpose[k][2] = sparse[j][2];
                k++;
            }

    // Display original sparse matrix
    printf("\nOriginal Sparse Matrix (Row Col Val):\n");
    for (int i = 0; i <= count; i++)
        printf("%d\t%d\t%d\n", sparse[i][0], sparse[i][1], sparse[i][2]);

    // Display transpose
    printf("\nTranspose Sparse Matrix (Row Col Val):\n");
    for (int i = 0; i <= count; i++)
        printf("%d\t%d\t%d\n", transpose[i][0], transpose[i][1], transpose[i][2]);

    return 0;
}

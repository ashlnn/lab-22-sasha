#include <stdio.h>

#define ROWS 3
#define COLS 6

int main() {
    FILE *inputFile = fopen("vhid.txt", "r");
    FILE *outputFile = fopen("exit.txt", "w");

    if (inputFile == NULL || outputFile == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    int matrix[ROWS][COLS];
    int sumVector[ROWS] = {0};

    // Reading the matrix from the file
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            fscanf(inputFile, "%d", &matrix[i][j]);
        }
    }

    // Calculating sum of positive elements for each row
    for (int i = 0; i < ROWS; i++) {
        int sum = 0;
        for (int j = 0; j < COLS; j++) {
            if (matrix[i][j] > 0) {
                sum += matrix[i][j];
            }
        }
        sumVector[i] = sum;
    }

    // Writing the vector to the output file
    for (int i = 0; i < ROWS; i++) {
        fprintf(outputFile, "%d ", sumVector[i]);
    }

    fclose(inputFile);
    fclose(outputFile);

    return 0;
}

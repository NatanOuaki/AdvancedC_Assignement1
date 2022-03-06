#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#define N 4
int path_exists(int matrix[][N], int rows, int cols);
int main() {
    int matrix[][N] = { {1,0,0,1},{0,1,1,0},{0,1,0,1},{0,0,0,1} };
    int rows = 0, cols = 0;
    int success = path_exists(matrix, 0, 0);
    if (success)
        printf("Success, path exists :)");
    else
        printf("Failure, path doesn't exist :(");
}
int path_exists(int matrix[][N], int rows, int cols) {
    static int check;
    if (rows == N - 1 && cols == N - 1) // halting condition.
        return 1;
    if (matrix[rows + 1][cols] == 1) {  // checks num below
        check = path_exists(matrix, rows + 1, cols);  // if 1, continue path.
        if (check == 1) {  // if path successful keep returning, else check another path 
            return 1;
        }
    }
    if (matrix[rows][cols + 1] == 1) {  // checks the num on the right
        check = path_exists(matrix, rows, cols + 1);  // continue
        if (check == 1) {
            return 1;
        }
    }
    if (matrix[rows + 1][cols + 1] == 1) {  // checks the num on right of num below
        check = path_exists(matrix, rows + 1, cols + 1); // continue
        if (check == 1) {
            return 1;
        }
    }
    else {  // return fail, if no paths available
        return 0;
    }
}

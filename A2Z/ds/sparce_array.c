// Two representation methods -> 1. 2. 
#include <stdio.h>

int main() {
    int i, j, k = 0;

    int sparse_array[4][4] = {
        {1, 0, 0, 0},
        {0, 0, 4, 0},
        {0, 9, 0, 0},
        {0, 0, 0, 0}
    };

    int rows = 4, cols = 4;
    int non_zero_count = 0;

    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            if (sparse_array[i][j] != 0) {
                non_zero_count++;
            }
        }
    }

    int** coord_form = (int**)malloc(non_zero_count * sizeof(int*));
    for(i = 0; i < non_zero_count; i++){
        coord_form[i] = (int*)malloc(3 * sizeof(int));
    }

    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            if (sparse_array[i][j] != 0) {
                coord_form[k][0] = i;
                coord_form[k][1] = j;
                coord_form[k][2] = sparse_array[i][j];
                k++;
            }
        }
    }

    printf("Row Col Value\n");
    for (i = 0; i < non_zero_count; i++) {
        for (j = 0; j < 3; j++) {
            printf("%d ", coord_form[i][j]);
        }
        printf("\n");
    }

    return 0;
}

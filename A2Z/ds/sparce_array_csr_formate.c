#include <stdio.h>

int main()
{
    int i, j, count = 0;

    int sparce_array[3][4] = {
        {1, 0, 0, 0},
        {0, 2, 0, 0},
        {0, 0, 0, 3}};

    printf("Sparce Array: \n");
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 4; j++)
        {
            if (sparce_array[i][j] != 0)
                count += 1;
            printf("%d ", sparce_array[i][j]);
        }
        printf("\n");
    }

    int *val = (int *)malloc(count * sizeof(int));
    int *row = (int *)malloc(count * sizeof(int));
    int *col = (int *)malloc(count * sizeof(int));

    int itr = 0;
    for(i = 0; i < 3; i++){
        for(j = 0; j < 4; j++){
            if(sparce_array[i][j] != 0){
                val[itr] = sparce_array[i][j];
                row[itr] = i;
                col[itr] = j;
                itr+=1;
            }
        }
    }

    printf("\n Values: ");
    for(i = 0; i < itr; i++){
        printf("%d ", val[i]);
    }

    printf("\n Rows: ");

    for(i = 0; i < itr; i++){
        printf("%d ", row[i]);
    }

    printf("\n Cols: ");

    for(i = 0; i < itr; i++){
        printf("%d ", col[i]);
    }
}
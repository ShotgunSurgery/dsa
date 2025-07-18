#include<stdio.h>

sparce_convert(int mat[][]){
	size_t rows = sizeof(mat) / sizeof(mat[0]);
	size_t cols = sizeof(mat) / sizeof(mat[0][0]);
	
	int i,j;
	for(i = 0; i < rows; i++){
		for(j = 0; j < cols; j++){
			if(mat[i][j] == 0){
				
			}	
		}
	}|
}

int main(){
	int mat[3][3] = { 
		{1,0,0},
		{0,0,3},
		{0,5,0},
	};


	printf("The original array is: \n");
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			printf("%d ", mat[i][j]);
		}
		printf("\n");
	}

	printf("Converting to sparce array");
	sparce_convert(int* mat); 
}


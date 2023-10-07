#include <stdbool.h>
#include <stdio.h>

#include <stdlib.h>
const int N = 3;
const int M = 3;

void freeMem(int **array);
void fillData(int **array);
void display(int row, int col, int content);
void displayData(int **array);
bool allocateMem(int ***array);
bool allocateEachCell(int **array);

int main(void){
	int **array = NULL;

	if (!allocateMem(&array)){
		printf("ERROR: Can't allocate memory\n");
		exit(1);
	}

	// allocate more memory space for each cell
	if (!allocateEachCell(array)){
		printf("ERROR: Can't allocate more mem for each cell\n");
		exit(1);
	}

	// fill 2d array with numbers 
	
	fillData(array);

	// then display the 2d array
	displayData(array);

	// free each cell
	freeMem(array);

	// free the array 
	free(array);
	array = NULL;
	return(0);
}
void freeMem(int **array){
	for(int row = 0; row < N; row++){
		free(array[row]);			
		array[row] = NULL;		
	}
	
	
}
void display(int row, int col, int content){
	printf("row: %d col: %d content: %d\n", row, col, content);
}

void fillData(int **array){
	for(int row = 0; row < N; row++){
		for(int col = 0; col < M; col++){
		
			array[row][col] = col;			
			
		}
	}
}
void displayData(int **array){
	for(int row = 0; row < N; row++){
		for(int col = 0; col < M; col++){
		
			display(row, col, array[row][col]);			
			
		}
	}
	
	
}
bool allocateMem(int ***array){
	// So, you pass a pointer to the pointer (int **array) so that you can update it within the function and have the change reflected outside.
	bool isallocate = false;
	*array = malloc(sizeof(int *) * N);
	if (*array != NULL){
		isallocate = true;
	}

	return isallocate;
}

bool allocateEachCell(int **array){

	bool isallocate = true;
	for(int row = 0; row < N; row++){
		array[row] = malloc(sizeof(int) * M);
		if (array[row] == NULL){
			isallocate = false;
			break;
		}
	}
	
	return isallocate;
}


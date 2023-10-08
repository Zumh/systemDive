#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
 * copy all the data from array[][] to a new data[][]
 * then display them
 * 
 */
// if you have #define N 3 at the top of your code, every instance of N will be replaced with 3 before the code is compiled. So your code will effectively become
// const int need to be compile and that is why we cannot use it for constant
#define N 3 
#define M 30

void displayData(char **data, int rows);
void fillData(char *words[], char **data, int rows, int cols);
bool allocate(char ***data, int rows, int cols);
void removeData(char **data, int rows);
int main(void) {
	char *words[N] = {
		"Hello world",
		"this is poem",
		"end"
	};

	
	// display words 
	displayData(words, N);
	//display(words, N);

	// here we goint to copy to another data
	char **data = NULL;

	// allocate memory for each row and strings
	if(!allocate(&data, N, M)){
		printf("ERROR: can't allocate\n");
		exit(1);
	}

	fillData(words, data, N, M);

	displayData(data, N);
	
	// free them here
	removeData(data, N);

	free(data);
	data = NULL;
	return(0);
}

void removeData(char **data, int rows){
	for(int row = 0; row < rows; row++){
		free(data[row]);
	}
}

void displayData(char **data, int rows){
	for(int row = 0; row < rows; row++){
		printf("%s\n", data[row]);
	}
}

void fillData(char *words[], char **data, int rows, int cols){
	for(int row = 0; row < rows; row++){
		// we can use strncpy for copying this
		strncpy(data[row], words[row], strlen(words[row]) + 1);
	}	
}

bool allocate(char ***data, int rows, int cols){
	// we dereference the third pointer so that we can take rows size memory space
	*data = (char **) malloc(sizeof(char*) * rows);

	if (*data == NULL){
		return false;
	}

	// allocate for each cell
	for (int row = 0; row < rows; row++){
		// still referencing and traverse each row to allocate more memory space
		(*data)[row] = (char *)malloc(sizeof(char) * cols);
		if ((*data)[row] == NULL){
			return false;
		}
	}
	
	return true;
}

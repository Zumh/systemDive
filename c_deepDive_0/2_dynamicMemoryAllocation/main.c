#include <stdlib.h>
#include <stdio.h>
// we assign numbers to the array 
void fill_array(int *array, int size);	
int main(void){
	// herer we have apointer that we can use for array
	int *array;
	int size = 10;
	// allocate memory for the array 
	array = (int*) malloc(sizeof(int) * size);
	// check if it is null pointer 
	if (array == NULL){
		// if we have nothig in the array we print error and exit
		printf("error no more memory left\n");
		exit(1);
	}

	// here if we allocate memory successfull then we can call the fill array
	fill_array(array, size);
	// then we can print numbers that we fill
	for(int index = 0; index < size; index++){
		printf("numbers : %d\n", array[index]);
	}

	// we have to free the memory here otherwise we can have problem;
	// we free array from heap data allocation
	// then assign NULL to this array
	free(array);
	array = NULL;

	// this is a good practice way to manage memory

	return (0);
}

void fill_array(int *array, int size){

	for(int index = 0; index < size; index++) {
		
		array[index] = index;

	}
}

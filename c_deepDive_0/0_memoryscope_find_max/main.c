#include <stdio.h>
// global integer 
int global = 0;

// defined function for finding max value
int findMax(int n1, int n2);
int change(int amt);
int main(void) {
	// get the user input as number and find the max
	int number = 0;
	
	scanf("%d", &number);
	
	global = 20;
	
	printf("global: %d input number: %d\n", global, number);
	int result = findMax(global, number);

	printf("global: %d max value result: %d\n", global, result);

	result = change(10);

	printf("global: %d max value result: %d\n", global, result);
	
	return(0);
}

int change(int amt){
	int val;

	// change local value
	val = global;

	// change global value
	global += amt;
	// we return local value here
	return val;
}

int findMax(int n1, int n2){

	// compare and return the max
	if (n1 < n2){
		n1 = n2;
	}
	return n1;
}

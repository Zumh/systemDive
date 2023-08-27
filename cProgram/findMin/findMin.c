#include <stdio.h>
int find_min(int arr[], int len){

    	//write your code here
	int minValue = arr[0];
	for(int index = 0; index < len; index++){
		if (minValue > arr[index]){
			minValue = arr[index];
		}
	}
	return minValue;
}

int main(void){
    int test[5] = {1,4,2,3,5};
    int test2[6] = {0,5,-3,3,11,1};
    int test3[4] = {0,0,4,-1};

    printf("The minimum in test is: %d (should be 1)\n", find_min(test,5));
    printf("The minimum in test2 is: %d (should be -3)\n", find_min(test2,6));
    printf("The minimum int test3 is: %d (should be -1)\n", find_min(test3,4));
    return 0;
}

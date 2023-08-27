#include <stdio.h>
int fib(int number){
	if (number <= 1) {
		return number;
	} else {
		return fib(number - 1) + fib(number - 2);
		
	}


}
int main(void){
	int number = 5;
	int result = 0;
	for(int count = 1; count <= number; count++){
		result = fib(count);
	
		printf("%d\n", result);
	}
	return 0;
}

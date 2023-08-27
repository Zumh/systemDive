#include <stdio.h>
int fib(int number){
	if (number <= 0){
		return 0;
	else if (number == 1) {
		return 1;
	} else {
		return fib(number - 1) + fib(number - 1);
	}
	printf("%d\n", number);
}
int main(void){
	int number = 5;
	int result = 0;
	result = fib(number);
	printf("%d", result);
	return 0;
}

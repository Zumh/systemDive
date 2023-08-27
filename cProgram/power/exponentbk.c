#include <stdio.h>
int exponent(int number, int exp){
	if ( exp == 1){
		return number;
	}
	return number + exponent(number, exp - 1);
}
int main(void) {
	int number = 4;
	int result = 0;
	result = exponent(number);
	printf("%d\n", result);
	return 0;
}

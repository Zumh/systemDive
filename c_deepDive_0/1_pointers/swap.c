#include <stdio.h>
// swap
void swap(int *first, int *second){
	int temp = *first;
	*first = *second;
	*second = temp;
}
int main(void){
	int a = 3;
	int b = 4;

	printf("%d %d\n", a, b);
	
	swap(&a, &b);

	printf("%d %d\n", a, b);
	return 0;

}

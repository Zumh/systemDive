#include <stdio.h>
// This program simply change value of integer that get it from user input
// Then we see how a global variable and local variable work
int changeValue(int globalValue);
int globalValue;
int main(void) {
    // we declare variable that will allow us to get user input
    int number = 0;   
    int localValue = 0;
    scanf("%d", &number);
    printf("Before change:\n    Local value: %d Global value: %d\n", localValue, globalValue);
    // change the value 
    localValue = changeValue(number);
    printf("After change:\n Local value: %d Global value: %d\n", localValue, globalValue);
    return 0;
}

int changeValue(int currentInput) {
    //global value increment 
    globalValue = currentInput;

    // we increment currentInput and return
    currentInput += 10;

    return currentInput;

}


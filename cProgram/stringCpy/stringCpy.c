#include <stdio.h>
#include <string.h>
int string_copy(char source[], char destination[]){
    //write your code here
    strcpy(destination, source);

    return strlen(destination);
}

int main(void){
    // write test cases here!
    char source[20] = "hello world";
    char destination[20];
    string_copy(source, destination);
    printf("%s\n", destination);
    printf("%ld %ld\n", strlen(source), strlen(destination));
    return 0;
}

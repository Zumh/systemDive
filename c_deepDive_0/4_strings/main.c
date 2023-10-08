#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 3 
#define M 30

char* catString(char** data, int rows);
void displayData(char **data, int rows);
void fillData(char *words[], char **data, int rows, int cols);
bool allocate(char ***data, int rows, int cols);
void removeData(char **data, int rows);

bool findWord(char **data, char *word, int rows, int *foundIndex);
int main(void) {
    char *words[N] = {
        "Hellos world",
        "this is poem",
        "endo"
    };
    printf("#### Before modifing data ####\n");
    displayData(words, N);

    printf("\n\n");

    char **data = NULL;

    if (!allocate(&data, N, M)) {
        printf("ERROR: can't allocate\n");
        exit(1);
    }

    fillData(words, data, N, M);

    printf("#### After copy data ####\n");
    displayData(data, N);
    printf("\n\n");

    printf("#### After concatenate string ####\n");
    char* concatStr = catString(data, N);
    if (concatStr == NULL){
        printf("ERROR: Memory error\n");
    } else {
        printf("%s\ntotalLength: %ld\n", concatStr, strlen(concatStr));
        free(concatStr);
    }


    printf("\n\n");
    printf("#### After finding word ####\n");
    int foundIndex = 0;
    char *word = "poem";
    if(!findWord(data, word, N, &foundIndex)){
    	printf("this %s word is found %d\n", word, foundIndex);
    }
    
    removeData(data, N);
    free(data);

    return 0;
}

bool findWord(char **data, char *word, int rows, int *foundIndex){
	int resultIndex = 0;

	for(int row = 0; row < rows; row++){
		printf("%s ", data[row]);
	}	
	printf("%s\n", word);

	return true;
}
char* catString(char** data, int rows){
    char *result = NULL;
    int totalLength = 0;

    for(int row = 0; row < rows; row++){
        totalLength += strlen(data[row]); 
    }

    // we add extra 1 for null termination
    result = (char*) malloc(sizeof(char) * (totalLength + 1));

    if (result == NULL){
        return NULL; // Memory allocation failed
    }

    result[0] = '\0'; // Ensure the result string is empty

    for(int row = 0; row < rows; row++){
        strcat(result, data[row]);
        if (row < rows - 1) {
            strcat(result, " ");
        }
    }

    return result;
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
        strncpy(data[row], words[row], cols-1); // Ensure null terminator
        data[row][cols-1] = '\0'; // Add null terminator if needed
    }   
}

bool allocate(char ***data, int rows, int cols){
    *data = (char **) malloc(sizeof(char*) * rows);

    if (*data == NULL){
        return false;
    }

    for (int row = 0; row < rows; row++){
        (*data)[row] = (char *) malloc(sizeof(char) * cols);

        if ((*data)[row] == NULL){
            return false;
        }
    }

    return true;
}

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "Header.h"


int main(void) {
        FILE* f = fopen("file4.txt", "r+");
        if (f == NULL) {
            printf("Error opening file\n");
            exit(0);
        }
        
        Node* node = loadTreeFromFile(f);
      

        fclose(f);
        printf("Answer the questions with yes or no.\n");
        game(node);


        f = fopen("file4.txt", "w+");
        if (f == NULL) {
            printf("Error opening file\n");
            exit(0);
        }
        saveTreeToFile(node, f);
        fclose(f);
        free(node);

	return 0;
}
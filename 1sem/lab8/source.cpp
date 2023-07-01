#include <stdio.h>
#include <stdlib.h>
#include<malloc.h>

int stringLength(char* str) {
    int i = 0;
    while (str[i] != '\0')
        i++;
    return i;
}
int longestString(char* str) {
  
    int count = 0;
    int flag = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] != ' ' && flag == 0) {
                count += 1;
                flag = 1;
        }
        else
            if (str[i] == ' ') flag = 0;
    }
    return count;
}
void outputString(char** str, int argc) {
    for (int i = 0; i < argc - 1; i++)
        printf("%s\n", str[i]);
}

//метод вставок
void insertionSort(char** str, int argc) {
    char* value;
    int k, j;
    for (int i = 1; i < argc-1 ; i++)
    {
        k = longestString(str[i]);
        value = str[i];
        for (j = i - 1; j >= 0 && longestString(str[j])> k; j--)
            str[j + 1] = str[j];
        str[j + 1] = value;
    }

}
void fre(char** str, int argc) {
    for (int i = 0; i < argc - 1; i++)
        free(str[i]);
    free(str);
}
void inputString(char*** str, int argc, char** argv)
{
    if (argc == 1)
    {
        printf("There is no string arguments ");
        exit(1);
    }
    *str = (char**)calloc((argc - 1), sizeof(char*));
    for (int i = 1; i < argc; i++)
    {
        int length = stringLength(argv[i]);
        (*str)[i - 1] = (char*)malloc(length + 1 * sizeof(char));
        for (int j = 0; j < length; j++)
        {
            (*str)[i - 1][j] = argv[i][j];
        }
        (*str)[i - 1][length] = '\0';
    }
}

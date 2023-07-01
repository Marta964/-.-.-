#include<stdio.h>
#include"Header.h"
int main(int argc, char** argv)
{
    printf("%s", argv[0]);
    char** str;
    inputString(&str,argc, argv);
    printf("Strings array:\n");
    outputString(str, argc);

    insertionSort(str,argc);
    printf("Sorted strings array:\n");
    outputString(str, argc);

    fre(str, argc);
    return 0;
}
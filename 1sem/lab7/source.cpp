#include<stdio.h>
#include <stdlib.h>
#include<malloc.h>

char* getString() {
    int n = 256;
    char* str = (char*)calloc(n, sizeof(char));
    char ch;
    int pos = 0;
    printf("Enter string: ");
    while (1) {
        ch = getchar();
        if (ch == '\n') {
            str[pos] = '\0';
            str = (char*)realloc(str, (pos + 1) * sizeof(char));
            return str;
        }
        str[pos] = ch;
        pos++;
        if (pos == 256)
            str = (char*)realloc(str, (pos + 1) * sizeof(char));
    }
}
int stringLength(char* str) {
    int len = 0;
    while (str[len] != '\0')
        len++;
    return len;
}
int chooseTask() {
    int p;
    printf("choose the task number: 1 or 2\n");
    while (scanf_s("\n%d", &p) != 1 || p < 0 || p>2 || getchar() != '\n') {
        printf("Input error.Try again.\n");
        rewind(stdin);
    }
    return p;
}
void task1(char* str,int len) {
    int i = 0;
    while (str[i] != '\0')
    {
        if (str[i] <= 'Z' && str[i] >= 'A') {
            str[i] += 32;
        }
        else if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] -= 32;
        }
        i++;
    }
}
int enterN() {
    int n;
    printf("enter n: ");
    while (scanf_s("\n%d", &n) != 1 || n < 0 || getchar() != '\n') {
        printf("Input error.Try again.\n");
        rewind(stdin);
    }
    return n;
}


void task2(char* str, int len) {
    int n = enterN();
    if (n > len) {
        int k = n - len;
        for (int i = 0;i < n;i++) {
            len++;
            str = (char*)realloc(str, (len+1) * sizeof(char));

            for (int j = len-1;j >= 0;j--) {
                str[j + 1] = str[j];
            }
            str[0] = '.';
           
        }
    }
   
    if (n < len) {
        int k = len - n;
        for (int i = 0;i < k;i++) {
            for (int j = 0;j < len;j++)
                str[j] = str[j + 1];
        }
       len--;
        str = (char*)realloc(str, (len-1) * sizeof(char));
    }
    

}
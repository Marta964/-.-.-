#include<stdio.h>
#include"header.h"
#include<time.h>
#include<stdlib.h>


int main(void) {

    char* str = getString();
    int len = stringLength(str);
  //  printf("%d\n",len);
    
    int p = chooseTask();
    void (*task[2])(char*, int) = {task1,task2};
    task[p-1](str,len);
   
    //len = stringLength(str);
   // printf("%d\n", len);
    printf("string=%s\n", str);
    free(str);
    return 0;
}
  
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "Header.h"


int main(void) {

    char fileout[] = "f3.bmp";

    char filename[256];
    printf("Enter BMP file name: ");
    scanf("%s", filename);
  
   
    BMPFile* bmpf = readBmpFile(filename);
    if (bmpf == NULL)

        return 1;
   
    while (1) {
        int a;
        printf("Choose task\n1. Grayscale\n2. Gamma correction\n3. Median filter\n4. negative\n5. Exit\n");
        while (!scanf("%d", &a) || a > 5 || a < 1 || getchar() != '\n') {
            printf("Wrong input! Enter again:");
            rewind(stdin);
        }

        switch (a) {
        case 1:grayscale(bmpf);
            break;
        case 2: gammaCorrection(bmpf);
            break;
        case 3:medianFilter(bmpf);
            break;
        case 4:negative(bmpf);
            break;
        case 5:return 1;
            break;
        }
        writeBMPFile(bmpf, fileout);

        printf("\n");

    }

    free(bmpf);
}

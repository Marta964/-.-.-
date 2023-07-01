#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include<math.h>

#include "Header.h"


void readPixels(BMPFile* bmpf, char* filename) {

    int width = bmpf->infoHeader->width;
    int height = bmpf->infoHeader->height;
    int padding = (4 - (width *3 ) % 4) % 4; 
    unsigned int offset = bmpf->fileHeader->offset;

    FILE* f = fopen(filename, "rb");
    if (f == NULL) {
        printf("Error opening file");
        return NULL;
    }
    fseek(f, offset, SEEK_SET);

    unsigned char* pixels = malloc(width * height * 3);

    for (int row = 0; row < height; row++) {
        fread(&pixels[row * (width * 3)], sizeof(unsigned char) * 3, width, f);

        unsigned char pb;
        for (int p = 0; p < padding; p++) {
            fread(&pb, sizeof(unsigned char), 1, f);
        }
    }

    fclose(f);
    bmpf->pixels = pixels;
}

BMPFile* readBmpFile(char* filename) { 
    BMPFile* bmpf = malloc(sizeof(BMPFile));
    BMPHeader* fileHeader;
    DIBHeader* infoHeader;
    

    FILE* f = fopen(filename, "rb");
    if (f == NULL) {
        printf("Error opening file");
        return NULL;
    }

    fileHeader = malloc(sizeof(BMPHeader));
    fread(fileHeader, sizeof(BMPHeader), 1, f);

    if (fileHeader->signature[0] == 'B' && fileHeader->signature[1] == 'M') {
        infoHeader = malloc(sizeof(DIBHeader));
        fread(infoHeader, sizeof(DIBHeader), 1, f);
    }
    else {
        printf("The file is not suiteble for the proram.");
        return NULL;
    }
    fclose(f);

    bmpf->fileHeader = fileHeader;
    bmpf->infoHeader = infoHeader;

    readPixels(bmpf, filename);
    return bmpf;
}

void writeBMPFile(BMPFile* bmpf, char* fileout) {
    FILE* f = fopen(fileout, "wb");
    if (f == NULL) {
        printf("Error opening file");
        return NULL;
    }

    int width = bmpf->infoHeader->width;
    int height = bmpf->infoHeader->height;

    int padding = (4 - (width * 3) % 4) % 4;

    fwrite(bmpf->fileHeader, sizeof(BMPHeader), 1, f);
    fwrite(bmpf->infoHeader, sizeof(DIBHeader), 1, f);

    unsigned char* pixels = bmpf->pixels;

    for (int row = 0; row < height; row++) {
        fwrite(&pixels[row * (width * 3)], sizeof(unsigned char) * 3, width, f);

        for (int p = 0; p < padding; p++) {
            unsigned char null = 0;
            fwrite(&null, sizeof(unsigned char), 1, f);
        }
    }

    fclose(f);
}



void gammaCorrection(BMPFile* bmpf) {

    float gamma;
    printf("Input gamma coefficient:");
    scanf_s("%f", &gamma);

    int width = bmpf->infoHeader->width;
    int height = bmpf->infoHeader->height;
    for (int row = 0; row < height; row++) {
        for (int col = 0; col < width; col++) {
            Pixel* pixel = (Pixel*)&(bmpf->pixels[row * (width * 3) + (col * 3)]);

            pixel->b = pow(pixel->b / 255.0, gamma) * 255.0;
            pixel->g = pow(pixel->g / 255.0, gamma) * 255.0;
            pixel->r = pow(pixel->r / 255.0, gamma) * 255.0;
        }
    }
}

void grayscale(BMPFile* bmpf) {
    int width = bmpf->infoHeader->width;
    int height = bmpf->infoHeader->height;

    for (int row = 0; row < height; row++) {
        for (int col = 0; col < width; col++) {
            Pixel* pixel = (Pixel*)&(bmpf->pixels[row * (width * 3) + (col * 3)]);
           
            int n = 0.3 * pixel->r + 0.6 * pixel->g + 0.1 * pixel->b;
            pixel->b = n;
            pixel->g = n;
            pixel->r = n;
      
        }
    }

}

void medianFilter(BMPFile* bmpf) {
    Pixel* pixel[9];
    int width = bmpf->infoHeader->width;
    int height = bmpf->infoHeader->height;

    for (int i = 1; i < height - 1; i++) {
        for (int j = 1; j < width - 1; j++) {
            int count = 0;
            for (int k = -1; k <= 1; k++) {
                for (int l = -1; l <= 1; l++) {
                    pixel[count] = (Pixel*)&(bmpf->pixels[(i + k) * (width * 3) + ((j + l) * 3)]);
                    count++;
                }
            }
            for (int k = 0; k < 9; k++) {
                for (int l = k + 1; l < 9; l++) {
                    if (pixel[k]->r > pixel[l]->r) {
                        Pixel* t = pixel[k];
                        pixel[k] = pixel[l];
                        pixel[l] = t;
                    }
                }
            }

            Pixel* p = (Pixel*)&(bmpf->pixels[i * (width * 3) + (j * 3)]);
            p->r = pixel[4]->r;
            p->g = pixel[4]->g;
            p->b = pixel[4]->b;

        }

    }
  
}

void negative(BMPFile* bmpf) {
    int width = bmpf->infoHeader->width;
    int height = bmpf->infoHeader->height;

    for (int row = 0; row < height; row++) {
        for (int col = 0; col < width; col++) {
            Pixel* pixel = (Pixel*)&(bmpf->pixels[row * (width * 3) + (col * 3)]);

           
            pixel->b = 255- pixel->b;
            pixel->g = 255 - pixel->g;
            pixel->r = 255 - pixel->r;

        }
    }


}

//#ifndef BMP_READER_H
//#define BMP_READER_H

#pragma once

#pragma pack(push,1)                 //выравнивание в один байт
typedef struct {

    unsigned char signature[2];
    unsigned int fileSize;
    unsigned short reserved1;
    unsigned short reserved2;
    unsigned int offset;
} BMPHeader;

typedef struct {

    unsigned int infoheaderSize;
    int width;
    int height;
    unsigned short colorPlanes;
    unsigned short bitsPerPixel;
    unsigned int compressionMethod;
    unsigned int imageSize;
    unsigned int hres;
    unsigned int vres;
    unsigned int colorPalette;
    unsigned int importantColors;
} DIBHeader;

#pragma pop

typedef struct {
    BMPHeader* fileHeader;
    DIBHeader* infoHeader;
    unsigned char* pixels;
} BMPFile;

typedef struct {
    unsigned char b;
    unsigned char g;
    unsigned char r;
} Pixel;





BMPFile* readBmpFile(char* filename);

void readPixels(BMPFile* bmpf, char* filename);

void writeBMPFile(BMPFile* bmpf, char* fileout);


void medianFilter(BMPFile* bmpf);

void grayscale(BMPFile* bmpf);

void negative(BMPFile* bmpf);

void gammaCorrection(BMPFile* bmpf);


//#endif
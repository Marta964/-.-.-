#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct word {
	char name[40];
	int number;
	int size;
}word;



size_t sizeOfFile(FILE* f);

word** frequencyOfEachWord(word** w, int* size, char* fileName);

void sort(word* w, int size);

//char* findLongestWord(word* w, int size);

//char* findShortestWord(word* w, int size);




void compress(char* fileName);

void decompress(char* filename);
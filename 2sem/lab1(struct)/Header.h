#pragma once
struct time;
enum data;
struct movie;
int sizeOfStruct();
void printStruct(struct movie** film, int size);
void freeStruct(struct movie** film, int size);
void delet(struct movie** film, int* size);
void filling(struct movie** film, int size);
int c(struct movie** film, int i, int j, int fs);
int c2(struct movie** film, int i, int fs, int ss);
void sorting(struct movie** film, int size);

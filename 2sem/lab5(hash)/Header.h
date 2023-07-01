#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include<ctype.h>

#define MAX_WORD_LENGTH 256
#define MAX_CACHE_SIZE 3

typedef struct Node {
    char* key;
    char* value;
    struct Node* prev;
    struct Node* next;
}Node;

typedef struct CacheList {
    Node* head;
    Node* tail;
}CacheList;

typedef struct Cache {
    int size;
    int capacity;
    Node** table;
    CacheList* list;
}Cache;



void findIPByDomain(Cache* cache);

void addDns();

unsigned int hashFunction(const char* str);  

Cache* createCache(int capacity); 

void addToCache(Cache* cache, const char* key, const char* value);

char* searchIPFromCache(Cache* cache, char* key);  

char* findDomainFromFile(Cache* cache, FILE* file, char* key, int* addNew);

void printCache(Cache* cache);

void freeCache(Cache* cache); 

int checkIPValidation(const char* ip); 

void findDNSbyIP(Cache *cache);

void print_DNS(const char* IPAddress, FILE* file,Cache* cache);


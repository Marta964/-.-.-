#pragma once
typedef struct Node {

    char* data;
    struct Node* yes;
    struct Node* no;

} Node;



Node* createNode(char* data);

Node* loadTreeFromFile(FILE* f);

void saveTreeToFile(Node* node, FILE* f);

Node* addObject(Node* node);

void game(Node* node);


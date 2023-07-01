#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include "Header.h"


Node* createNode(char* data) {

    Node* node = (Node*)malloc(sizeof(Node));
    node->data = (char*)malloc(strlen(data) + 1);
    strncpy_s(node->data, strlen(data) + 2, data, strlen(data) + 1);
    //strcpy(node->data, data);
   // node->data = _strdup(data);
    node->yes = NULL;
    node->no = NULL;

    return node;
}

Node* loadTreeFromFile(FILE* f) {
   
    char data[100];
    fgets(data, sizeof(data), f);
    data[strlen(data) - 1] = '\0';

    if (data[0] == '!') return NULL;
   
    Node* node = createNode(data);
   
    node->yes = loadTreeFromFile(f);
    node->no = loadTreeFromFile(f);
   
    return node;

}

void saveTreeToFile(Node* node, FILE* f) {
    if (node == NULL) {
        fputs("!\n", f);
        return;
    }

    fputs(node->data, f);
    fputs("\n", f);
    saveTreeToFile(node->yes, f);
    saveTreeToFile(node->no, f);

}

Node* addObject(Node* node) {
    printf("What was it?\n");
    char newObject[20];
    scanf("%s", newObject);

    printf("What is the difference between %s and %s\n", newObject, node->data);
    char q[50];
    scanf("%s", q);

    Node* new_node;

    new_node = createNode(q);
    new_node->yes = createNode(newObject);
    new_node->no = createNode(node->data);
    /*node->yes = createNode(newObject);
    node->no = createNode(node->data);
    node->data = NULL;
    strcpy(node->data, q);
    //node = createNode(q);
    Node* yesNode = createNode(newObject);
    Node* noNode = createNode(node->data);
    node->data = _strdup(q);
    node->yes = yesNode;
    node->no = noNode;

    //Node* newNode = createNode(q);
    //newNode->yes = createNode(newObject);





    printf("What it is?\n");
    char res[100];
    gets(res);

    printf("What is the difference?\n");
    char data[100];
    gets(data);

    Node* new_node;
   
    new_node= createNode(data);
    new_node->yes = createNode(res);
    return new_node;*/
    return new_node;
}

void game(Node* node) {
    char answer[5];
    while (node->yes != NULL && node->no != NULL) {
       printf("%s?\n", node->data);
       //gets(answer, sizeof(answer), stdin);
       gets(answer);

        if (strncmp(answer, "yes",3) == 0)
            node = node->yes;
        else
            node = node->no;
    }
   
    printf("\nIs it %s?\n", node->data);
    gets(answer);

    if (strncmp(answer, "yes",3) == 0)
        printf("I guessed it!");
    else {
        printf("What was it?\n");
        char newObject[20];
        gets(newObject);

        printf("What is the difference between %s and %s\n", newObject, node->data);
        char q[50];
        gets(q);



        node->no = createNode(node->data);
        node->yes = createNode(newObject);
        strcpy(node->data, q);
    }

}


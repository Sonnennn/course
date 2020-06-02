#pragma once
#ifndef STRUCT_H
#define STRUCT_H

#include "stdio.h"
#include "string.h"
#include "stdlib.h"

typedef struct Node {
    int id;
    char *name;
    char *type;
    int weight;
    float calories;
    float micro[3];
    struct Node *next; // указатель на следующий узел
    struct Node *prev;// указатель на предыдущий узел

} Node;
typedef struct Head {
    int cnt;
    Node *first;
    Node *last;
} Head;
#endif

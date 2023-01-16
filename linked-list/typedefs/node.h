#ifndef node_h
#define node_h

#include <stdio.h>
#include <stdbool.h>

typedef struct node {
    int number;
    bool initialized;
    struct node *next;
}
node;

#endif

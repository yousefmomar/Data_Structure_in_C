#ifndef RING_H
#define RING_H
#include<stdlib.h>

typedef struct ring_node
{
    int data;
    struct ring_node *pNext;
}vertix;

vertix *ptr=NULL;

vertix* createVertix(int data);
void addVertix(int data);
void print_ring();
int delete_vertix(int index);

#endif
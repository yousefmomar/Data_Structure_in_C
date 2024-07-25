#ifndef QUEUE_H
#define QUEUE_H

typedef struct Queue_node
{
    int data;
    struct Queue_node *pNext;
}Queue;

Queue *p_last,*p_first;

Queue* createQueue_node(int data);
void pushQ(int data);
int popQ();
void printQ();

#endif
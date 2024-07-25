#ifndef STACK_H
#define STACK_H

typedef struct Stack_node
{
    int data;
    struct Stack_node *pNext;
}taba2;

typedef struct SS
{
    taba2* pTop;
}Stack;


taba2* createStack_node(int data);
void push(int data,Stack* ptr);
int pop(Stack*);
void printStack(Stack*);
void Sort_Ascend_stack(Stack*);
Stack* createStack(void);

#endif
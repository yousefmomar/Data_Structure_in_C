#include<stdio.h>
#include<stdlib.h>

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
Stack* createStack(void);



int main(void)
{
    Stack* S=createStack();
    push(1,S);
    push(9,S);
    push(7,S);
    push(2,S);
    push(6,S);

    printStack(S);
    printf("\nStack after sorting\n==========================\n");
    Sort_Ascend_stack(S);
    printStack(S);

    return 0;
}
Stack* createStack(void)
{
    Stack* S=(Stack*)malloc(sizeof(taba2));
    if(S!=NULL)
    {
        S->pTop=NULL;
    }
    return S;
}
taba2* createStack_node(int data)
{
    taba2 *pNode=(taba2*)malloc(sizeof(taba2));
    if(pNode != NULL)
    {
        pNode->data=data;
        pNode->pNext=NULL;
    }
    return pNode;
}
void push(int data,Stack* ptr)
{
    taba2 *pNode=createStack_node(data);
    if(pNode!=NULL)
    {
        pNode->pNext=ptr->pTop;
        ptr->pTop=pNode;
    }
    
}
int pop(Stack* ptr)
{
   if(ptr==NULL)
    {
        printf("Stack is empty!!");
        return 404;
    }

    taba2* pCur=ptr->pTop;
    int data;

    ptr->pTop=ptr->pTop->pNext;
    data=pCur->data;
    free(pCur);

    return data;
}
void printStack(Stack* ptr)
{
    taba2 *pCur=ptr->pTop;
    for(int i=0;pCur!=NULL;pCur=pCur->pNext,i++)
    {
        printf("node(%d) = %d\n",i,pCur->data);
    }
}


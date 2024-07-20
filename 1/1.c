#include<stdio.h>
#include<stdlib.h>

typedef struct Stack_node
{
    int data;
    struct Stack_node *pNext;
}taba2;

taba2* createStack_node(int data);
void push(int data);
int pop();
void printStack();

taba2 *pTop=NULL;

int main()
{
    push(10);
    push(9);
    push(8);
    push(7);
    push(6);
    push(5);
    push(4);
    push(3);
    push(2);
    push(1);
    printStack();

    printf("\nStack after POP\n===================\n");
    pop();
    printStack();

    return 0;
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
void push(int data)
{
    taba2 *pNode=createStack_node(data);
    if(pNode!=NULL)
    {
        pNode->pNext=pTop;
        pTop=pNode;
    }
    
}
int pop()
{
   if(pTop==NULL)
    {
        printf("Stack is empty!!");
        return 404;
    }

    taba2* pCur=pTop;
    int data;

    pTop=pTop->pNext;
    data=pCur->data;
    free(pCur);

    printf("\npoped data = %d\n",data);

    return data;
}
void printStack()
{
    taba2 *pCur=pTop;
    for(int i=0;pCur!=NULL;pCur=pCur->pNext,i++)
    {
        printf("node(%d) = %d\n",i,pCur->data);
    }
}
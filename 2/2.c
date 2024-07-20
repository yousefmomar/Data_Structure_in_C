#include<stdio.h>
#include<stdlib.h>

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

int main()
{
    pushQ(1);
    printQ();

    printf("\nQueue after pop\n======================\n");
    popQ();
    printQ();

    printf("\nQueue after another push\n======================\n");
    pushQ(2);
    pushQ(3);
    pushQ(4);
    pushQ(5);
    pushQ(6);
    pushQ(7);
    printQ();

    popQ();
    printQ();


    return 0;
}
Queue* createQueue_node(int data)
{
    Queue* pNode=(Queue*)malloc(sizeof(Queue));
    if (pNode!= NULL)
    {
        pNode->data=data;
        pNode->pNext=NULL;
    }
    return pNode;
}
void pushQ(int data)
{
    Queue* pNode=createQueue_node(data);
    if(p_last==NULL || p_first==NULL)
    {
        p_last=p_first=pNode;
    }
    else
    {
        p_last->pNext=pNode;
        p_last=pNode;
    }
}
int popQ()
{
    int data;
    if(p_last==NULL)
    {
        printf("The Queue is empty!!\n");
        return 404;
    }
    else
    {
        Queue* pCur=p_first;
        p_first=p_first->pNext;
        data=pCur->data;

        if(p_first==NULL)
            p_last=NULL;

        printf("\npoped data = %d \n",data);

        free(pCur);

        return data;
    }
    
}
void printQ()
{
    Queue *pCur=p_first;
    for(int i=0;pCur!=NULL;pCur=pCur->pNext,i++)
    {
        printf("node(%d) = %d\n",i,pCur->data);
    }
}



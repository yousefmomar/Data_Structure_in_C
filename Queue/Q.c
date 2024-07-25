#include<stdio.h>
#include<stdlib.h>
#include"/Users/yousefmahmoud/Desktop/Studying/Embedded_Diploma_AMIT/Codes_in_class/Data_Structure/Libraries/Q.h"

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



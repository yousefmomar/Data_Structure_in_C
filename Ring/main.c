#include<stdio.h>
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

int main(void)
{
    addVertix(1);
    addVertix(2);
    addVertix(3);
    addVertix(4);
    addVertix(5);
    print_ring();

    int data=delete_vertix(4);
    printf("\nRing after delete\n=======================\n");
    print_ring();

    return 0;
}
vertix* createVertix(int data)
{
    vertix* pNode=(vertix*)malloc(sizeof(vertix));
    if(pNode!=NULL)
    {
        pNode->data=data;
        pNode->pNext=NULL;
    }
    return pNode;
}
void addVertix(int data)
{
    vertix* pNode=createVertix(data);
    if(pNode!=NULL)
    {
        if(ptr==NULL)
        {
            ptr=pNode;
        }
        else if(ptr->pNext==NULL)
        {
            ptr->pNext=pNode;
            pNode->pNext=ptr;
        }
        else
        {
            vertix* pCur=ptr->pNext;
            pNode->pNext=pCur;
            ptr->pNext=pNode;
        }
    }
    
}
void print_ring()
{
    printf("Node(0) = %d\n",ptr->data);
    vertix* pCur=ptr->pNext;

    for(int i=1;pCur!=ptr;pCur=pCur->pNext,i++)
    {
        printf("Node(%d) = %d\n",i,pCur->data);
    }
}
int delete_vertix(int index)
{
    vertix* pCur=ptr;
    int data;

    if(index==0)
    {
        for(;pCur->pNext!=ptr;pCur=pCur->pNext)
        {}
        vertix* temp=ptr;
        pCur->pNext=ptr->pNext;
        ptr=ptr->pNext;
        data=temp->data;
        free(temp);

        return data;
    }
    else if (index==1)
    {
        pCur=pCur->pNext;
        ptr->pNext=pCur->pNext;
        data=pCur->data;
        free(pCur);

        return data;

    }   
    else
    {
        vertix* pIndex=ptr;
        int count=0;
        vertix *pCount=ptr;

        while (pCount->pNext != ptr)
        {
            pCount=pCount->pNext;
            count++;
        }

        if(index>count)
        {
            printf("Node does not exist!!\n");
            return 404;
        }
        else
        {
            for(;index>0;index--)
            {
                pIndex=pIndex->pNext;
            }
            for(;pCur->pNext!=pIndex;pCur=pCur->pNext)
            {}
            pCur->pNext=pIndex->pNext;
            data=pIndex->data;
            free(pIndex);

            return data;
        }
        
    }
}
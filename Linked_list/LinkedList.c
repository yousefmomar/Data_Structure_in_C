#include"/Users/yousefmahmoud/Desktop/Studying/Embedded Diploma AMIT/My libraries/LinkedList.h"
#include<stdlib.h>
#include<stdio.h>

node *pFirst,*pLast;

node* CreateNode (int data)
{
    node* pNode=(node*)malloc(sizeof(node));

    if(pNode != NULL)
    {
        pNode->data=data;
        pNode->pNext=NULL;
        pNode->pPrev=NULL;
    }

    return pNode;
}
void AddBackNode (int data)
{
    node* pNode=CreateNode(data);
    if(pNode!= NULL){
        if(pFirst == NULL)
        {
            pFirst=pLast=pNode;
        }
        else
        {
            pNode->pNext=pLast;
            pLast->pPrev=pNode;
            pLast=pNode;  
        }
    }
    
}
void AddFrontNode (int data)
{
    node* pNode=CreateNode(data);
    if(pNode!=NULL){
        if(pFirst == NULL)
        {
            pFirst=pLast=pNode;
        }
        else
        {
            pNode->pPrev=pFirst;
            pFirst->pNext=pNode;
            pFirst=pNode;  
        }
    }
    
}

int insertNode (int data, int index)
{
    
    if (index==0)
    {
        AddFrontNode(data);
    }
    else
    {
        node* pCur=pFirst;
        
        for (; index>0; index--)
        {
            pCur=pCur->pPrev;
            if (pCur == NULL)
            {
                AddBackNode(data);
                return 0;
            }
            
        }

        node* pNode=CreateNode(data);

        if(pNode!=NULL){
            pNode->pNext=pCur->pNext;
            pCur->pNext->pPrev=pNode;
            pNode->pPrev=pCur;
            pCur->pNext=pNode;
        }
        
    }
    
}
void printList(void)
{
    node* pCur=pFirst;
    for (int i=0; pCur!=NULL; pCur=pCur->pPrev)
    {
        printf("node(%d) = %d\n",i++,pCur->data);
    }
}

int deleteNode (int index)
{
    int data;
    node* pCur=pFirst;

    if (index==0)
    {
        pFirst=pFirst->pPrev;
        data=pFirst->pNext->data;

        printf("deleted data = %d\n",data);

        
        free(pFirst->pNext);
        pFirst->pNext=NULL;
        return data;
    }
    else
    {
        int count=0;
        node *pCount=pFirst;

        while (pCount->pPrev != NULL)
        {
            pCount=pCount->pPrev;
            count++;
        }

        if(index>count)
        {
            printf("\nNode does not exist!!");
            return -1;
        }
        else if (index==count)
        {
            pLast=pLast->pPrev;
            data=pLast->pPrev->data;

            printf("deleted data = %d\n",data);

            free(pLast->pPrev);
            pLast->pPrev=NULL;
            return data;
        }
        else
        {
            for (; index>0; index--)
            {
                pCur=pCur->pPrev;
            }
            pCur->pNext->pPrev=pCur->pPrev;
            pCur->pPrev->pNext=pCur->pNext;
            pCur->pNext=pCur->pPrev=NULL;

            data=pCur->data;
            free(pCur);
            return data;
        }
        

    }
}
void swapNode(int index1, int index2)
{
    int count=0;
        node *pCount=pFirst;
        node *pCur1=pFirst;
        node *pCur2=pFirst;
        node *temp=CreateNode(0);


        while (pCount->pPrev != NULL)
        {
            pCount=pCount->pPrev;
            count++;
        }

        if(index1>count || index2>count)
            printf("\nNode does not exist!!");
        else if(index1==(index2-1))
        {
            for (; index1>0; index1--)
            {
                pCur1=pCur1->pPrev;
            }

            for (; index2>0; index2--)
            {
                pCur2=pCur2->pPrev;
            }

            if (pCur1==pFirst && pCur2!=pLast)
            {
                pFirst=pCur2;
                pCur1->pNext=pCur2;
                pCur1->pPrev=pCur2->pPrev;
                pCur2->pPrev->pNext=pCur1;
                pFirst->pPrev=pCur1;
                pFirst->pNext=NULL;
            }
            else if (pCur2==pLast && pCur1!=pFirst)
            {
                pLast=pCur1;
                pCur2->pPrev=pCur1;
                pCur2->pNext=pCur1->pNext;
                pCur1->pNext->pPrev=pCur2;
                pLast->pNext=pCur2;
                pLast->pPrev=NULL;
            }
            else if (pCur1->pNext==NULL && pCur2->pPrev==NULL)
            {
                pCur1->pNext=pCur2;
                pCur2->pPrev=pCur1;
                pCur2->pNext=NULL;
                pCur1->pPrev=NULL;
                pFirst=pCur2;
                pLast=pCur1;
            }
            else
            {
                pCur1->pPrev=pCur2->pPrev;
                pCur2->pNext=pCur1->pNext;
                pCur1->pNext->pPrev=pCur2;
                pCur1->pNext=pCur2;
                pCur2->pPrev->pNext=pCur1;
                pCur2->pPrev=pCur1;
            }
        }
        else
        {
            for (; index1>0; index1--)
            {
                pCur1=pCur1->pPrev;
            }

            for (; index2>0; index2--)
            {
                pCur2=pCur2->pPrev;
            }

            if(pCur1==pFirst && pCur2!=pLast)
            {   
                pCur2->pNext->pPrev=pCur1; //middle pointers
                pCur1->pPrev->pNext=pCur2;

                pCur2->pPrev->pNext=pCur1; //outer pointers

                temp->pPrev=pCur1->pPrev;
                pCur1->pPrev=pCur2->pPrev;
                pCur2->pPrev=temp->pPrev;
                
                temp->pNext=pCur1->pNext;
                pCur1->pNext=pCur2->pNext;
                pCur2->pNext=NULL;

                pFirst=pCur2;
                free(temp);
                temp=NULL;  
               
            }
            else if (pCur2==pLast && pCur1!=pFirst)
            {
                pCur2->pNext->pPrev=pCur1; //middle pointers
                pCur1->pPrev->pNext=pCur2;

                pCur1->pNext->pPrev=pCur2; //outer pointers

                temp->pPrev=pCur1->pPrev;
                pCur1->pPrev=pCur2->pPrev;
                pCur2->pPrev=temp->pPrev;
                
                temp->pNext=pCur1->pNext;
                pCur1->pNext=pCur2->pNext;
                pCur2->pNext=temp->pNext;

                pLast=pCur1;
                free(temp);
                temp=NULL;
            }
            else if (pCur1==pFirst && pCur2==pLast)
            {
                pCur2->pNext->pPrev=pCur1; //middle pointers
                pCur1->pPrev->pNext=pCur2;

                temp->pPrev=pCur1->pPrev;
                pCur1->pPrev=pCur2->pPrev;
                pCur2->pPrev=temp->pPrev;
                
                temp->pNext=pCur1->pNext;
                pCur1->pNext=pCur2->pNext;
                pCur2->pNext=temp->pNext;

                pFirst=pCur2;
                pLast=pCur1;
                free(temp);
                temp=NULL;
            }
            else 
            {
                pCur2->pNext->pPrev=pCur1; //middle pointers
                pCur1->pPrev->pNext=pCur2;

                pCur2->pPrev->pNext=pCur1;
                pCur1->pNext->pPrev=pCur2; //outer pointers

                temp->pPrev=pCur1->pPrev;
                pCur1->pPrev=pCur2->pPrev;
                pCur2->pPrev=temp->pPrev;
                
                temp->pNext=pCur1->pNext;
                pCur1->pNext=pCur2->pNext;
                pCur2->pNext=temp->pNext;

                pLast=pCur1;
                free(temp);
                temp=NULL;
            }
            
            
        }
}
void ReverseList()
{
    node *pCnt=pFirst;
    int index1,index2,count=0;
    while (pCnt->pPrev != NULL)
        {
            pCnt=pCnt->pPrev;
            count++;
        }

    index1=0;
    index2=count;
    while(index1<index2)
    {
        swapNode(index1,index2);
        index1++;
        index2--;
        if(index1==index2)
            break; 
    }
    
}

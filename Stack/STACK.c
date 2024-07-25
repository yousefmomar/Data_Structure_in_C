#include<stdio.h>
#include<stdlib.h>
#include"/Users/yousefmahmoud/Desktop/Studying/Embedded_Diploma_AMIT/Codes_in_class/Data_Structure/Libraries/STACK.h"


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
   if(ptr->pTop==NULL)
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

  
void Sort_Ascend_stack(Stack* ptr) {
    if (ptr == NULL || ptr->pTop == NULL) {
        return; // No need to sort an empty stack
    }

    Stack* sortedStack = createStack();

    while (ptr->pTop != NULL) {
        // Pop the top element from the original stack
        int temp = pop(ptr);

        // While the sorted stack is not empty and the top element of sorted stack
        // is greater than temp, move elements back to the original stack
        while (sortedStack->pTop != NULL && sortedStack->pTop->data > temp) {
            push(pop(sortedStack), ptr);
        }

        // Push the temp into the sorted stack
        push(temp, sortedStack);
    }

    // Move the elements back from the sorted stack to the original stack
    while (sortedStack->pTop != NULL) {
        push(pop(sortedStack), ptr);
    }

    // Free the sorted stack
    free(sortedStack);
}

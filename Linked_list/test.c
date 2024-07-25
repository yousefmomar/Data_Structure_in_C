#include<stdio.h>
#include<stdlib.h>
#include"/Users/yousefmahmoud/Desktop/Studying/Embedded Diploma AMIT/My libraries/LinkedList.h"

extern node *pFirst,*pLast;
int main() {

    AddFrontNode(1); 
    AddBackNode(2);
    AddBackNode(3);
    AddBackNode(4);
    AddBackNode(5);
    AddBackNode(6);
    AddBackNode(7);
    AddBackNode(8);
    AddBackNode(9);
    AddBackNode(10);
    printList();

    printf("\nList after delete\n===============\n");  
    
    int data=deleteNode(7);
    printList();
    printf("\nDeleted data = %d\n",data);

    return 0;
}


#include<stdio.h>
#include<stdlib.h>
#include"/Users/yousefmahmoud/Desktop/Studying/Embedded_Diploma_AMIT/Codes_in_class/Data_Structure/Libraries/STACK.h"


int main(void)
{
    Stack* S=createStack();
    push(1,S);
    push(4,S);
    push(7,S);
    push(5,S);
    push(10,S);

    printStack(S);
    printf("\nStack after sorting\n==========================\n");
    Sort_Ascend_stack(S);
    printStack(S);

    return 0;
}

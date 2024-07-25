#include<stdio.h>
#include<stdlib.h>
#include"/Users/yousefmahmoud/Desktop/Studying/Embedded_Diploma_AMIT/Codes_in_class/Data_Structure/Libraries/Q.h"


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

#include<stdio.h>
#include<stdlib.h>
#include"/Users/yousefmahmoud/Desktop/Studying/Embedded_Diploma_AMIT/Codes_in_class/Data_Structure/Libraries/RING.h"

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

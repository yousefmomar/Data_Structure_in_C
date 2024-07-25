#ifndef LINKEDLIST_H
#define LINKEDLIST_H
typedef struct person {
    int data;
    struct person *pNext;
    struct person *pPrev;
}node;

node* CreateNode (int data);
void AddBackNode (int data);
void AddFrontNode (int data);
int insertNode (int data, int index);
void printList(void);
int deleteNode (int index);
void swapNode(int index1, int index2);
void ReverseList();


#endif  
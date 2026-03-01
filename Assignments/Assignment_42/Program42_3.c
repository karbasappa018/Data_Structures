/*
    Write a program which returns addition of all element from singly linear
    linked list.

    Function Prototype :

    int Addition( PNODE Head);

    Input linked list : |10|->|20|->|30|->|40|
    Output : 100

*/

#include<stdio.h>
#include<stdlib.h>

#define true 1
#define false 0

typedef int BOOL;

struct node
{
    int Data;
    struct node* Next;
};

typedef struct node NODE;
typedef struct node * PNODE;
typedef struct node ** PPNODE;

void InsertFirst(PPNODE Head, int No)
{
    PNODE newn = NULL;

    newn = (PNODE)malloc(sizeof(NODE));

    newn->Data = No;
    newn->Next = NULL;

    if(*Head== NULL)
    {
        *Head = newn;
    }
    else
    {
        newn->Next = *Head;
        *Head = newn;
    }
}

void Display(PNODE Head)
{
    while(Head != NULL)
    {
        printf("| %d |->",Head->Data);
        Head = Head->Next;
    }

    printf("NULL\n");
}

int Addition(PNODE Head)
{
     int iSum = 0;
     
    while(Head != NULL)
    {
        
        iSum = iSum + Head->Data;
        Head = Head->Next;
    }

    return iSum;
}



int main()
{
    PNODE First = NULL;
    int iRet = 0;

    InsertFirst(&First,70);
    InsertFirst(&First,30);
    InsertFirst(&First,50);
    InsertFirst(&First,40);
    InsertFirst(&First,30);
    InsertFirst(&First,20);
    InsertFirst(&First,10);

    Display(First);

    
    iRet =  Addition(First);

    printf("Addition: %d\n:",iRet);




}
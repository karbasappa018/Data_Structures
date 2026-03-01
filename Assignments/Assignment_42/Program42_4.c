/*
    Write a program which return largest element from singly linear linked
    list.

    Function Prototype :

    int Maximum( PNODE Head)

    Input linked list : |110|->|230|->|320|->|240|


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

int Maximum(PNODE Head)
{
     int iMax = 0;
     
    while(Head != NULL)
    {
        
        if(Head->Data > iMax)
        {
            iMax = Head->Data;
        }
        Head = Head->Next;
    }

    return iMax;
}



int main()
{
    PNODE First = NULL;
    int iRet = 0;

    InsertFirst(&First,640);
    InsertFirst(&First,240);
    InsertFirst(&First,20);
    InsertFirst(&First,230);
    InsertFirst(&First,110);
    
    Display(First);

    
    iRet =  Maximum(First);

    printf("Maximum: %d\n:",iRet);




}
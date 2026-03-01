/*
    Write a program which search last occurrence of particular element from
    singly linear linked list.
    Function should return position at which element is found.

    Function Prototype :

    int SearchLastOcc( PNODE Head, int no );

    Input linked list : |10|->|20|->|30|->|40|->|50|->|30|->|70|
    Input element : 30
    Output : 6


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
    while(Head!= NULL)
    {
        printf("| %d |->",Head->Data);
        Head = Head->Next;
    }

    printf("NULL\n");
}

int SearchLastOcc(PNODE Head,int No)
{
     int index = 0;
     int lastOcc = 0;
    while(Head != NULL)
    {
        index ++;
        if(Head->Data == No)
        {
            lastOcc = index;
        }

        Head = Head->Next;
    }

    return lastOcc;
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

    
    iRet =  SearchLastOcc(First,30);

    printf("Last Occurance: %d\n:",iRet);




}
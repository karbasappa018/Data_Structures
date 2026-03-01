/*
    Write a program which returns addition of all even element from singly
    linear linked list.

    Function Prototype :

    int AdditionEven( PNODE Head)

    Input linked list : |11|->|28|->|17|->|41|->|6|->|89|

    Output : 52

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

int AdditionEven(PNODE Head)
{
    int iSum = 0;
    while(Head != NULL)
    {
        

        if((Head->Data) > 0)
        {
            if((Head->Data) % 2 == 0)
            {
                iSum = iSum + (Head->Data);
            }  
        }

        Head = Head->Next;
    }

    return iSum;
}



int main()
{
    PNODE First = NULL;
    int iRet = 0;
    
    InsertFirst(&First,41);
    InsertFirst(&First,32);
    InsertFirst(&First,20);
    InsertFirst(&First,11);
    
    
    Display(First);

    
    iRet = AdditionEven(First);

    printf("Addition of even elements: %d\n",iRet);

    




}
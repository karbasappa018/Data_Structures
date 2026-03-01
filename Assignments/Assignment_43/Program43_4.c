/*
    Write a program which return second maximum element from singly linear
    linked list.

    Function Prototype :

    int SecMaximum( PNODE Head)

    Input linked list : |110|->|230|->|320|->|240|
    Output : 240

    
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

int SecMaximum(PNODE Head)
{
    int iMax = Head->Data;
    int iSecMax = Head->Data;
    int iMin = Head->Data;
    PNODE temp = Head;

    while(Head != NULL)
    {
        
        if(Head->Data > iMax)
        {
            iMax = Head->Data;
        }

        if(Head->Data < iMin)
        {
            iMin = Head->Data;
        }
        
        
        Head = Head->Next;
    }

    Head = temp;

    while(Head != NULL)
    {
        if(Head->Data >iMin && Head->Data <iMax)
        {
            if(Head->Data > iSecMax)
            {
                iSecMax = Head->Data;
            }
           
        }

        Head= Head->Next;
    }


    return iSecMax;
}



int main()
{
    PNODE First = NULL;
    int iRet = 0;
    
    InsertFirst(&First,240);
    InsertFirst(&First,320);
    InsertFirst(&First,230);
    InsertFirst(&First,110);
    
    
    Display(First);

    
    iRet = SecMaximum(First);

    printf("Second Maximum Element: %d\n",iRet);

    




}
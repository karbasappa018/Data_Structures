/*/
    Write a program which search first occurrence of particular element from
    singly linear linked list.
    Function should return position at which element is found.

    Function Prototype :

    int SearchFirstOcc( PNODE Head , int no );

    Input linked list : |10|->|20|->|30|->|40|->|50|->|30|->|70|
    Input element : 30

    Output : 3

*/

#include<stdio.h>
#include<stdlib.h>

#define TRUE 1;
#define FALSE 0;

typedef int BOOL;

struct node
{
    int Data ;
    struct node *Next;
};

typedef struct node NODE;
typedef struct node * PNODE;
typedef struct node ** PPNODE;

void InsertFirst(PPNODE Head,int no)
{
    PNODE newn = NULL;

    newn = (PNODE)malloc(sizeof(NODE));

    newn->Data = no;
    newn->Next = NULL;

    if(*Head == NULL)
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

int SearchFirstOcc(PNODE Head, int no)
{
    int index = 0;

    while(Head != NULL)
    {
        index++;
        if(Head ->Data == no)
        {
            return index;
        }
        Head = Head->Next;
    }
}

int main()
{
    PNODE First = NULL;
    int iRet = 0;

    InsertFirst(&First,70);
    InsertFirst(&First,30);
    InsertFirst(&First,40);
    InsertFirst(&First,50);
    InsertFirst(&First,30);
    InsertFirst(&First,20);
    InsertFirst(&First,10);

    Display(First);



    iRet = SearchFirstOcc(First,30);

    printf("%d\n",iRet);

    Display(First);

   
    




    return 0;
}
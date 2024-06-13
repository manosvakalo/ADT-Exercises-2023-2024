#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define StackLimit 20


typedef int StackElementType;
typedef struct  {
    int Top;
    StackElementType Element[StackLimit];
} StackType;

void CreateStack(StackType *Stack);
bool EmptyStack(StackType Stack);
bool FullStack(StackType Stack);
void Push(StackType *Stack, StackElementType Item);
void Pop(StackType *Stack, StackElementType *Item);
void TraverseStack(StackType Stack);
void FilterStack(StackType *Stack,StackElementType n);

int main()
{
    StackType Stack;
    CreateStack(&Stack);
    int plithos,number,popelmnt;
    printf("Dvse to plithos twn stoixeivn ");
    scanf("%d",&plithos);
    for(int i=0;i<plithos;i++)
    {
        printf("Dvse to %do stoixeio:",i+1);
        scanf("%d",&number);
        Push(&Stack,number);
    }
    printf("Dvse to stoixeio gia diagrafi ");
    scanf("%d",&popelmnt);
    FilterStack(&Stack,popelmnt);


    return 0;
}

void CreateStack(StackType *Stack)
{
    Stack -> Top = -1;
}

bool EmptyStack(StackType Stack)

{
    return (Stack.Top == -1);
}

bool FullStack(StackType Stack)

{
    return (Stack.Top == (StackLimit - 1));
}

void Push(StackType *Stack, StackElementType Item)
{
    if (!FullStack(*Stack)) {
        Stack -> Top++;
        Stack -> Element[Stack -> Top] = Item;
    } else
        printf("Full Stack...");
}

void Pop(StackType *Stack, StackElementType *Item)

{
    if (!EmptyStack(*Stack)) {
        *Item = Stack -> Element[Stack -> Top];
        Stack -> Top--;
    } else
        printf("Empty Stack...");
}







void TraverseStack(StackType Stack)
{
    int i;
    printf("plithos sto stack %d\n",Stack.Top+1);
    for (i=0;i<=Stack.Top;i++) {
        printf("%d, ",Stack.Element[i]);
    }
    printf("\n");
}

void FilterStack(StackType *Stack,StackElementType n)
{
    StackType TempStack;
    CreateStack(&TempStack);
    StackElementType poppedel;
    TraverseStack(*Stack);
    while(!EmptyStack(*Stack))
    {




            Pop(Stack,&poppedel);
            TraverseStack(*Stack);
            if(poppedel == n)
            {
                TraverseStack(TempStack);
                break;
            }
            Push(&TempStack,poppedel);

            TraverseStack(TempStack);


    }
    while(!EmptyStack(TempStack))
    {
        Pop(&TempStack,&poppedel);
        Push(Stack,poppedel);
        TraverseStack(TempStack);
        TraverseStack(*Stack);
    }
    TraverseStack(*Stack);

}


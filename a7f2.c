#include <stdio.h>
#include <stdbool.h>

#define StackLimit 25


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
StackElementType GetNthElementA(StackType *Stack,int n);
StackElementType GetNthElementB(StackType *Stack,int n);


int main()
{
    StackType EvenStack;
    CreateStack(&EvenStack);
    int n;

    for(int i=2;i<=50;i+=2)Push(&EvenStack,i);
    printf("dvse n: ");
    do{
    scanf("%d",&n);
    }while(n<0 || n>25);
    printf("Nth element with GetNthElementA = %d\n", GetNthElementA(&EvenStack,n));
    TraverseStack(EvenStack);
    printf("Nth element with GetNthElementB = %d\n", GetNthElementB(&EvenStack,n));
    TraverseStack(EvenStack);


    return 0;
}



void TraverseStack(StackType Stack)
{
    int i;
    printf("plithos sto stack %d\n",Stack.Top+1);
    for (i=0;i<=Stack.Top;i++) {
        printf("%d ",Stack.Element[i]);
    }
    printf("\n");
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
void CreateStack(StackType *Stack)

{
    Stack -> Top = -1;

}

StackElementType GetNthElementA(StackType *Stack,int n)
{
    return Stack->Element[Stack->Top-n+1];
}

StackElementType GetNthElementB(StackType *Stack,int n)
{
    StackType TempStack;
    CreateStack(&TempStack);
    StackElementType nelemnt = Stack->Element[Stack->Top-n+1];
    int i=0;
    while(!EmptyStack(*Stack))
    {
        if(Stack->Element[i] < nelemnt){
        Push(&TempStack,Stack->Element[i]);
        Pop(Stack,&Stack->Element[i]);
        }
        else{
            Pop(Stack,&Stack->Element[i]);
        }

    }
    i=0;
    while(!EmptyStack(TempStack))
    {
        Push(Stack,TempStack.Element[i]);
        Pop(&TempStack,&TempStack.Element[i]);
    }

    return nelemnt;
}





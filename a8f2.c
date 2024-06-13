#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define StackLimit 50


typedef char StackElementType;
typedef struct  {
    int Top;
    StackElementType Element[StackLimit];
} StackType;

void CreateStack(StackType *Stack);
bool EmptyStack(StackType Stack);
void Push(StackType *Stack, StackElementType Item);
void Pop(StackType *Stack, StackElementType *Item);
bool FullStack(StackType Stack);

int main()
{
    StackType inverted;
    char ch,inch;
    CreateStack(&inverted);

    bool pushed=false;

    do{

        scanf("%c",&ch);
        while(getchar() != '\n');

        if(ch != 'C' && ch != '#'){
                Push(&inverted,ch);
                pushed=true;

        }
        else{

            if(ch == 'C')break;
        }
        }while(ch != '#');
       /* if(found && pushed)*/
        int rounds;
       do{
            if(ch == '#')break;
            scanf("%c",&inch);
            while(getchar() != '\n');

            rounds = inverted.Top;
            if(inch != '#' && inch == inverted.Element[inverted.Top])
            {
                if(inverted.Top>=-1){
                rounds--;
                Pop(&inverted,&ch);

                }

            }
            else{

                if(inch != '#')rounds--;
                break;
            }
        }while(ch != '#');



    if(pushed){
    if(rounds!= -1){printf("FALSE\n");return 0;}
    if(EmptyStack(inverted)){printf("TRUE\n");return 0;}
    }

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

bool FullStack(StackType Stack)

{
    return (Stack.Top == (StackLimit - 1));
}



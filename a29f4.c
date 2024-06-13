
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
typedef float StackElementType;
typedef struct StackNode *StackPointer;
typedef struct StackNode
{
	StackElementType Data;
    StackPointer Next;
} StackNode;

void CreateStack(StackPointer *Stack);
bool EmptyStack(StackPointer Stack);
void Push(StackPointer *Stack, StackElementType Item);
void Pop(StackPointer *Stack, StackElementType *Item);
void TraverseStack(StackPointer Stack);
void platform(StackPointer *Stack,float weight,int value,bool extract);


int main()
{

    StackPointer AStack;
    float storage = 10.0,weight;
    int value;
    CreateStack(&AStack);
    Push(&AStack,3);
    Push(&AStack,2);
    Push(&AStack,1);
    Push(&AStack,0.5);
    Push(&AStack,0.4);
    TraverseStack(AStack);

    printf("Give the weight: ");
    scanf("%f",&weight);

    printf("Give the value: ");
    scanf("%d",&value);

    float sum = weight;

    while(weight>=0)
    {
        bool extract = false;
        platform(&AStack,weight,value,extract);
        if(extract)
        {
            sum += weight;
        }
        if(sum>10)break;

        printf("Give the weight: ");
        scanf("%f",&weight);
        if(weight<0)break;
        printf("Give the value: ");
        scanf("%d",&value);

    }
    printf("Truck\n");
    TraverseStack(AStack);

    return 0;
}
void platform(StackPointer *Stack,float weight,int value,bool extract)
{

    StackPointer CurrPtr,TempStack;
    float cost = 0.0;
    CreateStack(&TempStack);
    int exports = 0;
    float expItem;

   if (EmptyStack(*Stack))
   {
   	    printf("EMPTY Stack\n");
    }
   else
   {
   	    CurrPtr = *Stack;
         while ( CurrPtr!=NULL )
        {
      	     if(weight > CurrPtr->Data)
             {
                 cost += CurrPtr->Data *300;
                 exports++;
             }
             CurrPtr = CurrPtr->Next;
        }
        if(cost< value*weight)
        {

            for(int i=0;i<exports;i++)
            {
                Pop(Stack,&expItem);
                Push(&TempStack,expItem);


                extract = true;
            }
            printf("Platform\n");
            TraverseStack(TempStack);

            Push(Stack,weight);

            printf("Truck\n");
            TraverseStack(*Stack);

            while(!EmptyStack(TempStack))
            {
                Pop(&TempStack,&expItem);
                Push(Stack,expItem);
            }

        }
   }




}

void TraverseStack(StackPointer Stack)
{
	StackPointer CurrPtr;

   if (EmptyStack(Stack))
   {
   	    printf("EMPTY Stack\n");
    }
   else
   {
   	    CurrPtr = Stack;
         while ( CurrPtr!=NULL )
        {
      	     printf("%.1f \n", CurrPtr->Data);
             CurrPtr = CurrPtr->Next;
        }
   }
    printf("\n");
}



void CreateStack(StackPointer *Stack)
/* ����������: ���������� ��� ���� ����������� ������.
   ����������: ��� ���� ����������� ������, Stack
*/
{
	*Stack = NULL;
}

bool EmptyStack(StackPointer Stack)
/* �������:     ��� ����������� ������, Stack.
   ����������:  ������� �� � Stack ����� ����.
   ����������:  TRUE �� � ������ ����� ����, FALSE �����������
*/
{
	return (Stack==NULL);
}

void Push(StackPointer *Stack, StackElementType Item)
/* �������:    ��� ����������� ������ ��� � ������ ��� �������������� ��� ���
                ������ Stack ��� ��� �������� Item.
   ����������: ������� ���� ������ ��� ������������ �������, �� �������� Item.
   ����������: ��� ������������� ����������� ������
*/
{
	StackPointer TempPtr;

    TempPtr= (StackPointer)malloc(sizeof(struct StackNode));
    TempPtr->Data = Item;
    TempPtr->Next = *Stack;
    *Stack = TempPtr;
}

void Pop(StackPointer *Stack, StackElementType *Item)
/* �������:    ��� ����������� ������ ��� � ������ ��� �������������� ��� ��� ������ Stack.
   ����������: ������� ��� ��� ������ ��� ������������ �������,
                �� � ������ ��� ����� ����, �� �������� Item.
   ����������: ��� ������������� ����������� ������ ��� �� �������� Item.
   ������:     ������ ����� �������, �� � ����������� ������ ����� ����
*/
{
    StackPointer TempPtr;

    if (EmptyStack(*Stack)) {
   	    printf("EMPTY Stack\n");
    }
   else
   {
        TempPtr = *Stack;
        *Item=TempPtr->Data;
        *Stack = TempPtr->Next;
        free(TempPtr);
    }
}




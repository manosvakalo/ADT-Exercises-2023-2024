#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int ListElementType;
typedef struct ListNode *ListPointer;
typedef struct ListNode
{
	ListElementType Data;
    ListPointer Next;
} ListNode;

void CreateList(ListPointer *List);
bool EmptyList(ListPointer List);
void LinkedInsert(ListPointer *List, ListElementType Item, ListPointer PredPtr);
void LinkedDelete(ListPointer *List, ListPointer PredPtr);
void LinkedTraverse(ListPointer List);
void LinearSearch(ListPointer List, ListElementType Item, ListPointer *PredPtr, bool *Found);
void OrderedLinearSearch(ListPointer List, ListElementType Item, ListPointer *PredPtr, bool *Found);

void LinkedTraverse(ListPointer List);

int main()
{
    ListPointer Alist;

    CreateList(&Alist);
    int n,i,number;
    printf("DWSE TO PLH8OS TWN STOIXEIWN THS LISTAS: ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("DWSE TON ARITHMO GIA EISAGWGI STHN ARXH THS LISTAS: ");
        scanf("%d",&number);
        LinkedInsert(&Alist,number,NULL);

    }

    LinkedTraverse(Alist);
    printf("DVSE TON ARITHMO GIA EISAGOGH STO TELOS THS LISTAS: ");
    scanf("%d",&number);
    ListPointer lastNode = Alist;
    while (lastNode->Next != NULL) {
        lastNode = lastNode->Next;
    }
    LinkedInsert(&Alist,number,lastNode);
    LinkedTraverse(Alist);

    return 0;
}


void CreateList(ListPointer *List)
/*           :                                      .
            :                      List
*/
{
	*List = NULL;
}

bool EmptyList(ListPointer List)
/*        :                                List                            .
            :                                          .
            : True                           false
*/
{
	return (List==NULL);
}

void LinkedInsert(ListPointer *List, ListElementType Item, ListPointer PredPtr)
/*        :                                 List                            ,
                                       Item                 PredPtr.
             :                   ,                 Item,
                                                              PredPtr
                                                    ,
                     PredPtr                (NULL).
            :
                                          List.
*/
{
	ListPointer TempPtr;

   TempPtr= (ListPointer)malloc(sizeof(struct ListNode));
   TempPtr->Data = Item;
	if (PredPtr==NULL) {
        TempPtr->Next = *List;
        *List = TempPtr;
    }
    else {
        TempPtr->Next = PredPtr->Next;
        PredPtr->Next = TempPtr;
    }
}

void LinkedDelete(ListPointer *List, ListPointer PredPtr)
/*        :                                 List
                                 PredPtr.
             :
                                                               PredPtr
                                           ,      PredPtr                ,
                                               .
             :
                                          List.
         :                                                              .
*/
{
    ListPointer TempPtr;

    if (EmptyList(*List))
   	    printf("EMPTY LIST\n");
   else
   {
   	    if (PredPtr == NULL)
        {
      	      TempPtr = *List;
              *List = TempPtr->Next;
        }
        else
        {
      	     TempPtr = PredPtr->Next;
             PredPtr->Next = TempPtr->Next;
        }
        free(TempPtr);
    }
}

void LinkedTraverse(ListPointer List)
/*        :                                 List                            .
             :
                                                            .
             :                                        .
*/
{
	ListPointer CurrPtr;

   if (EmptyList(List))
   	    printf("EMPTY LIST\n");
   else
   {
   	    CurrPtr = List;
   	    //printf("%-16s\t%-4s\t%-16s\n", "CurrPtr","Data","Next");
         while ( CurrPtr!=NULL )
        {
             printf("%d ",(*CurrPtr).Data);
             CurrPtr = CurrPtr->Next;
        }
   }
   printf("\n");
}

void LinearSearch(ListPointer List, ListElementType Item, ListPointer *PredPtr, bool *Found)
/*        :                                List                            .
            :
                                                               Item.
            :                                 Found       true,   CurrPtr
                                           Item       PredPtr
                        nil                            .
                                                    Found       false.
*/
{
    ListPointer CurrPtr;

    CurrPtr = List;
    *PredPtr=NULL;
   *Found= false;
    while (!(*Found) && CurrPtr!=NULL)
    {
         if (CurrPtr->Data==Item )
         	*Found = true;
         else
         {
         	*PredPtr = CurrPtr;
            CurrPtr = CurrPtr->Next;
         }
	}
}

void OrderedLinearSearch(ListPointer List, ListElementType Item, ListPointer *PredPtr, bool *Found)

{
   ListPointer CurrPtr;
   bool DoneSearching;

   CurrPtr = List;
   *PredPtr = NULL;
   DoneSearching = false;
   *Found = false;
   while (!DoneSearching && CurrPtr!=NULL )
    {
         if (CurrPtr->Data>=Item )
         {
         	DoneSearching = true;
         	*Found = (CurrPtr->Data==Item);
         }
         else
         {
         	*PredPtr = CurrPtr;
            CurrPtr = CurrPtr->Next;
         }
	}
}







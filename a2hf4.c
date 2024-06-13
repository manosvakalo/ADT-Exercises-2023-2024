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
void dltevry2(ListPointer *List);
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

    printf("Initial List\n");
    LinkedTraverse(Alist);
    dltevry2(&Alist);
    printf("Final List\n");
    LinkedTraverse(Alist);

    return 0;
}


void dltevry2(ListPointer *List)
{
    int rounds = 0;
    ListPointer PredPtr = NULL, CurrPtr = *List;

    while (CurrPtr != NULL)
    {
        rounds++;
        if (rounds % 2 == 0)
        {
            if (PredPtr == NULL)
            {
                *List = CurrPtr->Next;
            }
            else
            {
                PredPtr->Next = CurrPtr->Next;
            }
            ListPointer NextPtr = CurrPtr->Next;
            free(CurrPtr);
            CurrPtr = NextPtr;
        }
        else
        {
            PredPtr = CurrPtr;
            CurrPtr = CurrPtr->Next;
        }
    }
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








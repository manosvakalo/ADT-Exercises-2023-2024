#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
typedef struct{
    char name[40];
    int total;

} ListElementType;
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
void ReadInput(ListPointer *List);
void LinkedTraverse(ListPointer List);
void BlackList(ListPointer initialList,ListPointer *BlackList);
int main()
{
    ListPointer Alist,Black;
    CreateList(&Black);
    CreateList(&Alist);
    ReadInput(&Alist);
    printf("INITIAL LIST\n");
    LinkedTraverse(Alist);
    BlackList(Alist,&Black);
    printf("BLACK LIST\n");
    LinkedTraverse(Black);




    return 0;
}

void BlackList(ListPointer initialList,ListPointer *BlackList)
{
    ListPointer CurrPtr = initialList ;


    while(CurrPtr != NULL)
    {
        if((*CurrPtr).Data.total < 0)
        {
            LinkedInsert(BlackList,(*CurrPtr).Data,NULL);
        }
        ListPointer NextPtr = CurrPtr->Next;
        free(CurrPtr);
        CurrPtr= NextPtr;

    }


}



void ReadInput(ListPointer *List)
{
    FILE *input;
    input = fopen("I4F4.DAT","r");
    if(input == NULL )
    {
        printf("Error opening file, terminating...");
        exit(1);
    }
    int nscans,i=0;
    char termch;
    ListElementType Item;
    while(true)
    {
        nscans = fscanf(input,"%39[^,],%d%c",Item.name,&Item.total,&termch);
        if(nscans == EOF)break;
        if(nscans != 3)
        {
            printf("Error in line %d, terminating...",i+1);
            exit(1);
        }
        i++;
        LinkedInsert(List,Item,NULL);
    }
    fclose(input);

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
             printf("%s %d\n",(*CurrPtr).Data.name,(*CurrPtr).Data.total);
             CurrPtr = CurrPtr->Next;
        }
   }
   printf("\n");
}

/*void LinearSearch(ListPointer List, ListElementType Item, ListPointer *PredPtr, bool *Found)

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
}*/

/*void OrderedLinearSearch(ListPointer List, ListElementType Item, ListPointer *PredPtr, bool *Found)

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
*/








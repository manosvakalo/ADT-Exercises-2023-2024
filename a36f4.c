#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define NumberOfNodes 10

#define NilValue -1

typedef struct{
   int grade;
   int am;
}ListElementType;

typedef int ListPointer;

typedef struct {
    ListElementType Data;
    ListPointer  Next;
} NodeType;

void InitializeStoragePool(NodeType Node[], ListPointer *FreePtr);
void CreateList(ListPointer *List);
bool EmptyList(ListPointer List);
bool FullList(ListPointer FreePtr);
void GetNode(ListPointer *P, ListPointer *FreePtr, NodeType Node[]);
void ReleaseNode(NodeType Node[NumberOfNodes], ListPointer P, ListPointer *FreePtr);
void Insert(ListPointer *List, NodeType Node[],ListPointer *FreePtr, ListPointer PredPtr, ListElementType Item);
void Delete(ListPointer *List, NodeType Node[], ListPointer *FreePtr, ListPointer PredPtr);
void TraverseLinked(ListPointer List, NodeType Node[]);

void printAll(ListPointer List, ListPointer FreePtr, NodeType Node[]);

int main()
{
    NodeType Node[NumberOfNodes];
    ListPointer Alist,FreePtr,PredPtr=NilValue; //*freeptr:δεικτης που δειχνει στην επομενη κενη θεση,predptr:δεικτης που δειχνει στον προηγουμενο κομβο
    ListElementType AnItem;
    int i;


    InitializeStoragePool(Node,&FreePtr);
    CreateList(&Alist);

    printAll(Alist, FreePtr,Node);
    TraverseLinked(Alist,Node);

    for(i=0;i<5;i++)
    {
        printf("DWSE am:");
        scanf("%d",&AnItem.am);
        printf("DWSE mark:");
        scanf("%d",&AnItem.grade);
        Insert(&Alist,Node,&FreePtr,PredPtr,AnItem);
    }

    printAll(Alist, FreePtr,Node);
    TraverseLinked(Alist,Node);

    printf("DWSE TH 8ESH TOY PROHGOYMENO STOIXEIOY GIA DIAGRAFH:");
    scanf("%d",&PredPtr);

    Delete(&Alist,Node,&FreePtr,PredPtr);

    printAll(Alist, FreePtr,Node);
    TraverseLinked(Alist,Node);




    return 0;
}

void InitializeStoragePool(NodeType Node[], ListPointer *FreePtr)
{
   int i;

    for (i=0; i<NumberOfNodes-1;i++)
    {
        Node[i].Next=i+1;
        Node[i].Data.am=-1;
        Node[i].Data.grade=-1;    /* δεν είναι αναγκαίο η απόδοση αρχικής τιμής στο πεδίο των δεδομένων, βοηθάει στην εκτύπωση */
    }
    Node[NumberOfNodes-1].Next=NilValue;
    Node[NumberOfNodes-1].Data.am=-1;
    Node[NumberOfNodes-1].Data.grade=-1;
    *FreePtr=0;
}

void CreateList(ListPointer *List)
{
  *List=NilValue;
}

bool EmptyList(ListPointer List)
{
  return (List==NilValue);
}

bool FullList(ListPointer FreePtr)
{
  return (FreePtr == NilValue);
}

void GetNode(ListPointer *P, ListPointer *FreePtr, NodeType Node[])
{
  *P = *FreePtr;
  if (!FullList(*FreePtr))
    *FreePtr =Node[*FreePtr].Next;
}

void ReleaseNode(NodeType Node[], ListPointer P, ListPointer *FreePtr)

{
  Node[P].Next =*FreePtr;
  Node[P].Data.am = -1;
  Node[P].Data.grade = -1;

  *FreePtr =P;
}

void Insert(ListPointer *List, NodeType Node[],ListPointer *FreePtr, ListPointer PredPtr, ListElementType Item)
{
  ListPointer TempPtr;
  GetNode(&TempPtr,FreePtr,Node);
  if (!FullList(TempPtr)) {
    if (PredPtr==NilValue)
    {
        Node[TempPtr].Data =Item;
        Node[TempPtr].Next =*List;
        *List =TempPtr;
    }
    else
      {
        Node[TempPtr].Data =Item;
        Node[TempPtr].Next =Node[PredPtr].Next;
        Node[PredPtr].Next =TempPtr;
      }
}
  else
    printf("Full List ...\n");
}

void Delete(ListPointer *List, NodeType Node[], ListPointer *FreePtr, ListPointer PredPtr)
{
  ListPointer TempPtr ;

  if (!EmptyList(*List)) {
    if (PredPtr == NilValue)
    {
        TempPtr =*List;
        *List =Node[TempPtr].Next;
    }
    else
      {
        TempPtr =Node[PredPtr].Next;
        Node[PredPtr].Next =Node[TempPtr].Next;
      }
      ReleaseNode(Node,TempPtr,FreePtr);
  }
  else
    printf("Empty List ...\n");
}

void TraverseLinked(ListPointer List, NodeType Node[])
{
  ListPointer CurrPtr;

  if (!EmptyList(List))
  {
      CurrPtr =List;
      while (CurrPtr != NilValue)
      {
          printf("(%d: %d,%d->%d) ",CurrPtr,Node[CurrPtr].Data.am,Node[CurrPtr].Data.grade, Node[CurrPtr].Next);
          CurrPtr=Node[CurrPtr].Next;
       }
       printf("\n");
   }
  else printf("Empty List ...\n");
}

void printAll(ListPointer List, ListPointer FreePtr, NodeType Node[])
{
    int i;
    printf("1o STOIXEIO LISTAS=%d, 1H FREE POSITION=%d\n", List, FreePtr);
    printf("H STORAGE POOL EXEI TA EJHS STOIXEIA\n");
    for (i=0;i<NumberOfNodes;i++)
        printf("(%d: %d,%d->%d) ",i,Node[i].Data.am,Node[i].Data.grade, Node[i].Next);
    printf("\n");
}

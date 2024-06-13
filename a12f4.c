// QueueADT.h
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef struct{
    char name[15];
    char last_name[15];
    int phone;
    int ticket;

} QueueElementType;
typedef struct QueueNode *QueuePointer;

typedef struct QueueNode
{
	QueueElementType Data;
    QueuePointer Next;
} QueueNode;

typedef struct
{
    QueuePointer Front;
    QueuePointer Rear;
} QueueType;

void CreateQ(QueueType *Queue);
bool EmptyQ(QueueType Queue);
void AddQ(QueueType *Queue, QueueElementType Item);
void RemoveQ(QueueType *Queue, QueueElementType *Item);
void TraverseQ(QueueType Queue);


int main()
{
    QueueType AQueue;
    CreateQ(&AQueue);
    QueueElementType AnItem,Item;
    int n;


    printf("DWSE TO PLITHOS TWN ATOMWN: ");
    scanf("%d",&n);
    getchar();
    for(int i=0;i<n;i++)
    {

        printf("DWSE ONOMA ");
        fgets(AnItem.name,15,stdin);
        AnItem.name[strcspn(AnItem.name, "\n")] = '\0';
        printf("DWSE EPITHETO ");
        fgets(AnItem.last_name,15,stdin);
        AnItem.last_name[strcspn(AnItem.last_name, "\n")] = '\0';
        printf("DWSE THLEFWNO");
        scanf("%d",&AnItem.phone);
        printf("DWSE TYPOS EISITHRIOY(0=olokliro, 1=miso): ");
        scanf("%d",&AnItem.ticket);
        getchar();
        AddQ(&AQueue,AnItem);
    }
    printf("Initial Queue\n");
    TraverseQ(AQueue);
    printf("DWSE ARITHMO ELEYTHERWN THESEWN: ");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        RemoveQ(&AQueue,&Item);
    }
    printf("Final Queue\n");
    TraverseQ(AQueue);






    return 0;
}



void CreateQ(QueueType *Queue)
/* Λειτουργία: Δημιουργεί μια κενή συνδεδεμένη ουρά.
   Επιστρέφει: Μια κενή συνδεδεμένη ουρά
*/
{
	Queue->Front = NULL;
	Queue->Rear = NULL;
}

bool EmptyQ(QueueType Queue)
/* Δέχεται:    Μια συνδεδεμένη ουρά.
   Λειτουργία: Ελέγχει αν η συνδεδεμένη ουρά είναι κενή.
   Επιστρέφει: True αν η ουρά είναι κενή, false  διαφορετικά
*/
{
	return (Queue.Front==NULL);
}

void AddQ(QueueType *Queue, QueueElementType Item)
/* Δέχεται:    Μια συνδεδεμένη ουρά Queue και ένα  στοιχείο Item.
   Λειτουργία: Προσθέτει το στοιχείο Item στο τέλος της συνδεδεμένης ουράς Queue.
   Επιστρέφει: Την τροποποιημένη ουρά
*/
{
	QueuePointer TempPtr;

    TempPtr= (QueuePointer)malloc(sizeof(struct QueueNode));
    TempPtr->Data = Item;
    TempPtr->Next = NULL;
    if (Queue->Front==NULL)
        Queue->Front=TempPtr;
    else
        Queue->Rear->Next = TempPtr;
    Queue->Rear=TempPtr;
}

void RemoveQ(QueueType *Queue, QueueElementType *Item)
/* Δέχεται:    Μια συνδεδεμένη ουρά.
   Λειτουργία: Αφαιρεί το στοιχείο Item από την  κορυφή της συνδεδεμένης ουράς,
                αν δεν είναι  κενή.
   Επιστρέφει: Το στοιχείο Item και την τροποποιημένη συνδεδεμένη ουρά.
   Έξοδος:     Μήνυμα κενής ουράς, αν η ουρά είναι  κενή
*/
{
    QueuePointer TempPtr;

    if (EmptyQ(*Queue)) {
   	    printf("EMPTY Queue\n");
    }
   else
   {
        TempPtr = Queue->Front;
        *Item=TempPtr->Data;
        Queue->Front = Queue->Front->Next;
        free(TempPtr);
        if (Queue->Front==NULL) Queue->Rear=NULL;
    }
}
void TraverseQ(QueueType Queue)
{
	QueuePointer CurrPtr;

   if (EmptyQ(Queue))
    {
   	    printf("EMPTY Queue\n");
    }
   else
   {
   	    CurrPtr = Queue.Front;
         while ( CurrPtr!=NULL )
        {
      	     printf("%s, %s, %d, %d \n", CurrPtr->Data.name,CurrPtr->Data.last_name,CurrPtr->Data.phone,CurrPtr->Data.ticket);
             CurrPtr = CurrPtr->Next;
        }
   }
    printf("\n");
}





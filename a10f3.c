#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

#define QueueLimit 20

typedef int QueueElementType;

typedef struct {
	int Front, Rear;
	QueueElementType Element[QueueLimit];
} QueueType;

void CreateQ(QueueType *Queue);
bool EmptyQ(QueueType Queue);
bool FullQ(QueueType Queue);
void RemoveQ(QueueType *Queue, QueueElementType *Item);
void AddQ(QueueType *Queue, QueueElementType Item);
void TraverseQ(QueueType Queue);
void removeadd(QueueType *Queue,int number);

int main()
{
    QueueType EvenQ,OddQ;
    CreateQ(&EvenQ);
    CreateQ(&OddQ);
    for(int i=0;i<19;i+=2)
    {
        AddQ(&EvenQ,i);
        AddQ(&OddQ,i+1);
    }
    printf("EvenQueue\n");
    TraverseQ(EvenQ);
    printf("OddQueue\n");
    TraverseQ(OddQ);
    printf("Give number of items = ");
    int n;
    scanf("%d",&n);
    removeadd(&EvenQ,n);
    printf("EvenQueue\n");
    TraverseQ(EvenQ);
    printf("Give number of items = ");
    scanf("%d",&n);
    removeadd(&OddQ,n);
    printf("OddQueue\n");
    TraverseQ(OddQ);


    return 0;
}











void CreateQ(QueueType *Queue)

{
	Queue->Front = 0;
	Queue->Rear = 0;
}

bool EmptyQ(QueueType Queue)

{
	return (Queue.Front == Queue.Rear);
}

bool FullQ(QueueType Queue)

{
	return ((Queue.Front) == ((Queue.Rear +1) % QueueLimit));
}

void RemoveQ(QueueType *Queue, QueueElementType *Item)

{
	if(!EmptyQ(*Queue))
	{
		*Item = Queue ->Element[Queue -> Front];
		Queue ->Front  = (Queue ->Front + 1) % QueueLimit;
	}
	else
		printf("Empty Queue\n");
}

void AddQ(QueueType *Queue, QueueElementType Item)

{
	if(!FullQ(*Queue))
	{
		Queue ->Element[Queue ->Rear] = Item;
		Queue ->Rear = (Queue ->Rear + 1) % QueueLimit;
	}
	else
		printf("Full Queue\n");
}

void TraverseQ(QueueType Queue)
{
	int current;
	if (!EmptyQ(Queue)) {
        current = Queue.Front;
	    while (current != Queue.Rear) {
            printf("%d ", Queue.Element[current]);
		  current = (current + 1) % QueueLimit;
	   }
	   printf("\n");
    }
    else printf("Empty Queue\n");
}

void removeadd(QueueType *Queue,int number)
{
    for(int i=0;i<number;i++)
    {
        QueueElementType popel;
        RemoveQ(Queue,&popel);
        AddQ(Queue,popel);
    }
}

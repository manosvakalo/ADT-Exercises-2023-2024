#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

#define QueueLimit 8

typedef char QueueElementType;

typedef struct {
	int Front, Rear;
	QueueElementType Element[QueueLimit];
} QueueType;

void CreateQ(QueueType *Queue);
bool EmptyQ(QueueType Queue);
bool FullQ(QueueType Queue);
void RemoveQ(QueueType *Queue, QueueElementType *Item);
void AddQ(QueueType *Queue, QueueElementType Item);
QueueElementType minElement(QueueType *Queue);
QueueElementType maxElement(QueueType *Queue);
void TraverseQ(QueueType Queue);


int main()
{
    QueueType Que;
    int i=1;
    CreateQ(&Que);
    while(i<QueueLimit)
    {
        printf("Dwse stoixeio:");
        char item;
        scanf("%c",&item);
        AddQ(&Que,item);
        getchar();
        i++;
    }
    TraverseQ(Que);
    printf("Min: %c, Max: %c\n",minElement(&Que),maxElement(&Que));
    TraverseQ(Que);


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

QueueElementType minElement(QueueType *Queue)
{
    QueueElementType popel,temp[QueueLimit];
    int i=0;


    QueueElementType minel= Queue->Element[Queue->Front];
    while(!EmptyQ(*Queue))
    {
        RemoveQ(Queue,&popel);

        if(popel<minel)minel = popel;

        temp[i]= popel;
        i++;

    }
    for(i=0;i<7;i++)AddQ(Queue,temp[i]);




    return minel;
}
QueueElementType maxElement(QueueType *Queue)
{
    QueueElementType popel,temp[QueueLimit];
    int i=0;


    QueueElementType maxel= Queue->Element[Queue->Front];
    while(!EmptyQ(*Queue))
    {
        RemoveQ(Queue,&popel);

        if(popel>maxel)maxel = popel;

        temp[i]= popel;
        i++;

    }
    for(i=0;i<7;i++)AddQ(Queue,temp[i]);




    return maxel;
}
void TraverseQ(QueueType Queue) {
	int current;
	if (!EmptyQ(Queue)) {
        current = Queue.Front;
	    while (current != Queue.Rear) {
            printf("%c ", Queue.Element[current]);
		  current = (current + 1) % QueueLimit;
	   }
	   printf("\n");
    }
    else printf("Empty Queue\n");
}



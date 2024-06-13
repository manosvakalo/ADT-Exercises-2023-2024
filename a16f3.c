
#include <stdbool.h>
#include <stdlib.h>

#include <stdio.h>
#include <string.h>
#define QueueLimit 20  //το όριο μεγέθους της ουράς

typedef struct
{
    char name[21];
    float price;
    int weight;
    char date[11];
} QueueElementType;

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
QueueElementType getfront(QueueType Queue);


void CreateQ(QueueType *Queue);
bool EmptyQ(QueueType Queue);
bool FullQ(QueueType Queue);
void RemoveQ(QueueType *Queue, QueueElementType *Item);
void AddQ(QueueType *Queue, QueueElementType Item);
void readInput(QueueType *Queue);
void removeExpiredProducts(QueueType *Queue);




int main()
{
    QueueType AQueue;
    CreateQ(&AQueue);
    readInput(&AQueue);
    printf("Products in Queue:\n");
    TraverseQ(AQueue);
    removeExpiredProducts(&AQueue);
    printf("Products in Queue:\n");
    TraverseQ(AQueue);



    return 0;
}
QueueElementType getfront(QueueType Queue)
{
    return Queue.Element[Queue.Front];
}
void removeExpiredProducts(QueueType *Queue)
{

    char key[11];
    printf("Give Date:");
    fgets(key,11,stdin);
    QueueElementType item = getfront(*Queue);
    while(!EmptyQ(*Queue))
    {
        printf("Front Item= %s, %.2f, %d, %s\n",item.name,item.price,item.weight,item.date);
        if(strcmp(item.date,key) <= 0){
        RemoveQ(Queue,&item);

        item = getfront(*Queue);
        }
        else break;
    }

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



void readInput(QueueType *Queue)
{
    FILE *input = fopen("product.dat","r");
    if(input == NULL){
            printf("error opening file");exit(1);}

    int i=0;
    char tch;
    QueueElementType Element;
    while(true)
{
    int nscan = fscanf(input, "%20[^,],%f,%d,%s%c",
                       Element.name,
                       &Element.price,
                       &Element.weight,
                       Element.date,&tch);
    if(nscan == EOF)break;
    if (nscan != 5 || tch != '\n')
    {
            printf("Problem in line %d, terminating...\n", i);
            exit(1);
        }


    AddQ(Queue,Element);
    i++;
}

    fclose(input);
}
void TraverseQ(QueueType Queue) {
	int current;
	if (!EmptyQ(Queue)) {
        current = Queue.Front;
	    while (current != Queue.Rear) {
            printf("%s, %.2f, %d, %s\n", Queue.Element[current].name,Queue.Element[current].price,Queue.Element[current].weight,Queue.Element[current].date);
		  current = (current + 1) % QueueLimit;
	   }
	   printf("\n");
    }
    else printf("Empty Queue\n");
}



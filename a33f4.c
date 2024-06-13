
#include <stdbool.h>
#define ListLimit 50
#include <stdio.h>
#include <stdlib.h>
#define ListLimit 50


typedef struct{
int am;
char name[21];
}ListElementType;

typedef struct {
    int Size;
    ListElementType Element[ListLimit];
} ListType;

void CreateList(ListType *List);
bool EmptyList(ListType List);
bool FullList(ListType List);
void Insert(ListType *List, ListElementType Item, int Pos);
void Delete(ListType *List, int Pos);
void TraverseList(ListType List);
int search(ListType List,ListElementType Item);


int main()
{
    ListType AList;
    CreateList(&AList);
    int i,pos=-1;
    ListElementType AnItem;
    for(i=0;i<3;i++)
    {
        printf("Dvse AM:");
        scanf("%d",&AnItem.am);
        getchar();
        printf("Dvse Name:");
        gets(AnItem.name);
        Insert(&AList,AnItem,pos);
        pos++;
    }
    TraverseList(AList);
    printf("Dvse AM:");
    scanf("%d",&AnItem.am);
    pos = search(AList,AnItem);
    if(pos!= -1)
    {
        Delete(&AList,pos);
    }
    TraverseList(AList);

    return 0;
}

int search(ListType List,ListElementType Item)
{
    int pos=-1,i=0;
    bool found=false;
    if(!EmptyList(List)){

        while(i<List.Size && !found)
        {
            if(Item.am == List.Element[i].am)
            {
                found =true;
                pos=i;
            }

            i++;
        }

    }
    return pos;


}





void CreateList(ListType *List)
/* Λειτουργία: Δημιουργεί μια κενή λίστα.
   Επιστρέφει: Μια κενή λίστα
*/
{
    List -> Size = 0;
}

bool EmptyList(ListType List)
/* Δέχεται:    Μια λίστα List.
   Λειτουργία: Ελέγχει αν η λίστα List είναι κενή.
   Επιστρέφει: True αν η λίστα List είναι άδεια, false διαφορετικά
*/
{
    return (List.Size == 0);
}

bool FullList(ListType List)
/* Δέχεται:    Μια λίστα List.
   Λειτουργία: Ελέγχει αν η λίστα List είναι γεμάτη.
   Επιστρέφει: True αν η λίστα List είναι γεμάτη, false διαφορετικά
*/
{
    return (List.Size == (ListLimit));
}

void Insert(ListType *List, ListElementType Item, int Pos)
/* Δέχεται:    Μια λίστα List, το στοιχείο Item και τη θέση Pos μέσα στη λίστα.
   Λειτουργία: Εισάγει, στη λίστα List, αν δεν είναι γεμάτη, μετά τη θέση Pos
                το στοιχείο Item.
   Επιστρέφει: Την τροποποιημένη λίστα List.
   Εξοδος:     Mήνυμα γεμάτης λίστας, αν η λίστα List είναι γεμάτη
*/
{
    int i;
    if (FullList(*List))
        printf("Full list...\n");
    else
    {
        for (i=List->Size-1; i>=Pos+1;i--)
            List->Element[i+1] = List ->Element[i];
        List->Element[Pos+1]=Item;
        List->Size++;
    }
}

void Delete(ListType *List, int Pos)
/* Δέχεται:    Μια λίστα List.
   Λειτουργία: Διαγράφει από τη λίστα List, αν δεν είναι κενή,
                το στοιχείο που βρίσκεται στη θέση Pos.
   Επιστρέφει: Την τροποποιημένη λίστα List.
   Έξοδος:     Μήνυμα κενής λίστας, αν η λίστα List είναι κενή

*/
{
    int i;
    if (EmptyList(*List))
        printf("Empty list...\n");
    else
    {
        for (i=Pos; i<List->Size-1; i++)
            List->Element[i] = List ->Element[i+1];
        List->Size--;
    }
}

void TraverseList(ListType List)
/* Δέχεται:    Μια λίστα List.
   Λειτουργία: Κάνει διάσχιση της λίστα List, αν δεν είναι κενή.
   Έξοδος:     Εξαρτάται από την επεξεργασία
*/
{
    int i;
    if (EmptyList(List))
      	printf("Empty List\n");
    else
    {
        printf("\nPlithos stoixeiwn sth lista %d\n",List.Size);
        for (i=0;i<List.Size;i++)
            printf("%d, %s\n",List.Element[i].am,List.Element[i].name);
        printf("\n");
    }
}


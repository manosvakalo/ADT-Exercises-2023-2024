#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define ListLimit 50    //ενδεικτικό μέγεθος λίστας. Επανορίζεται ανάλογα με την εφαρμογή

typedef struct{
    int am;
    char name[21];
} ListElementType;    /*τύπος δεδομένων για τα στοιχεία της λίστας. ενδεικτικά επιλέχθηκε ο τύπος int.
                                Επανορίζεται ανάλογα με την εφαρμογή */
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

bool search(ListType List, ListElementType key, int *Pos);

int main()
{
    int i,Pos;
    ListType AList;
    CreateList(&AList);
    ListElementType key;

    for(i=0;i<3;i++)
    {
        printf("DWSE AM : ");
        scanf("%d", &key.am);
        printf("DWSE Name: ");
        scanf("%s", key.name);
        if (!search(AList, key, &Pos))
        {
            Insert(&AList, key, Pos);
        }
    }
    TraverseList(AList);

    printf("DWSE AM : ");
    scanf("%d", &key.am);
    if (search(AList,key,&Pos))
    {
        printf("%d, %s\n", AList.Element[Pos+1].am, AList.Element[Pos+1].name);
    }
    else
    {
        printf("Not found\n");
    }

    printf("DWSE AM : ");
    scanf("%d", &key.am);
    if (search(AList,key,&Pos))
    {
        Delete(&AList,Pos+1);
    }
    TraverseList(AList);

    return 0;
}

bool search(ListType List, ListElementType key, int *Pos)
{
    int i = 0;
    *Pos=-1;
    while (i < List.Size && List.Element[i].am < key.am)
    {
        *Pos = i;
        i++;
    }

    if (i < List.Size && List.Element[i].am == key.am)
        return true;
    else
        return false;
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
            printf("%d, %s\n",List.Element[i].am, List.Element[i].name);
        printf("\n");
    }
}

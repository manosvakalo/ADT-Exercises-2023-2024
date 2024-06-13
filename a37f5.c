#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
typedef struct
{
    int employee_code;
    char name[21];
} BinTreeElementType;                   /*ο τύπος των στοιχείων του ΔΔΑ είναι
                                        τύπου struct */
typedef struct BinTreeNode *BinTreePointer;
typedef struct BinTreeNode {
    BinTreeElementType Data;
    BinTreePointer LChild, RChild;
} BinTreeNode;

void CreateBST(BinTreePointer *Root);
bool EmptyBST(BinTreePointer Root);
void BSTInsert(BinTreePointer *Root, BinTreeElementType Item);
void BSTSearch(BinTreePointer Root, BinTreeElementType KeyValue, bool *Found, BinTreePointer *LocPtr);
void BSTSearch2(BinTreePointer Root, BinTreeElementType KeyValue, bool *Found,
    BinTreePointer *LocPtr, BinTreePointer *Parent);
void BSTDelete(BinTreePointer *Root, BinTreeElementType KeyValue);
void InorderTraversal(BinTreePointer Root);
void BuildBst(BinTreePointer *Tree1,BinTreePointer *Tree2,BinTreePointer *Tree3);
void ReadData(BinTreePointer *Tree,int code);


int main()
{
    /* Declarations and Tree Building*/
    BinTreePointer OfficeTree,WorkersTree,RepresentTree;
    CreateBST(&OfficeTree);
    CreateBST(&WorkersTree);
    CreateBST(&RepresentTree);

    /*Calling of 1st function to build the 3 trees*/
    BuildBst(&OfficeTree,&WorkersTree,&RepresentTree);
    /*Printing the contents of trees*/
    InorderTraversal(OfficeTree);
    InorderTraversal(WorkersTree);
    InorderTraversal(RepresentTree);

    /*Calling ReadData for the 2 Employees*/
    printf("office employees\n");
    ReadData(&OfficeTree,1);
    printf("factory employees\n");
    ReadData(&WorkersTree,2);
    printf("sales representatives\n");
    ReadData(&RepresentTree,3);

    /*Printing the contents of trees*/
    InorderTraversal(OfficeTree);
    InorderTraversal(WorkersTree);
    InorderTraversal(RepresentTree);



    return 0;
}

void ReadData(BinTreePointer *Tree,int code)
{
    BinTreeElementType Item;
    Item.employee_code = code;
    for(int i =0; i<2;i++)
    {
        printf("Give employee name:");
        fgets(Item.name,20,stdin);
        size_t len = strlen(Item.name);
        if (len > 0 && Item.name[len - 1] == '\n')
        {
        Item.name[len - 1] = '\0';
        }
        BSTInsert(Tree,Item);
    }


}


void BuildBst(BinTreePointer *Tree1,BinTreePointer *Tree2,BinTreePointer *Tree3)
{

    BinTreeElementType InputItem;
    FILE *input;
    char terch;
    input = fopen("i37f5.txt","r");
    if(input == NULL)
    {
        printf("error opening file...");
        exit(1);
    }

    int nscans,i=0;
    while(true)
    {
        nscans = fscanf(input,"%40[^,], %d%c",InputItem.name,&InputItem.employee_code,&terch);

        if(nscans == EOF) break;
        if(nscans != 3 || terch != '\n')
        {
            printf("error in line %d...",i+1);
            exit(1);
        }
        if(InputItem.employee_code == 1 )BSTInsert(Tree1,InputItem);
        else if(InputItem.employee_code == 2 )BSTInsert(Tree2,InputItem);
        else BSTInsert(Tree3,InputItem);

    }
    fclose(input);
}

void CreateBST(BinTreePointer *Root)
/* Λειτουργία: Δημιουργεί ένα κενό ΔΔΑ.
   Επιστρέφει:  Τον μηδενικό δείκτη(NULL) Root
*/
{
    *Root = NULL;
}

bool EmptyBST(BinTreePointer Root)
/* Δέχεται:   Ενα ΔΔα με το Root να δείχνει στη ρίζα του.
  Λειτουργία: Ελέγχει αν το ΔΔΑ είναι κενό.
  Επιστρέφει: true αν το ΔΔΑ είναι κενό και false διαφορετικά
*/
{   return (Root==NULL);
}

void BSTInsert(BinTreePointer *Root, BinTreeElementType Item)
/* Δέχεται:     Ένα ΔΔΑ με το δείκτη Root να δείχνει στη ρίζα του και ένα στοιχείο Item.
   Λειτουργία:  Εισάγει το στοιχείο Item στο ΔΔΑ.
   Επιστρέφει: Το τροποποιημένο ΔΔΑ με τον δείκτη Root να δείχνει στη ρίζα του
*/
{
    BinTreePointer LocPtr, Parent;
    bool Found;

    LocPtr = *Root;
    Parent = NULL;
    Found = false;
    while (!Found && LocPtr != NULL) {
        Parent = LocPtr;
        if (strcmp(Item.name,LocPtr ->Data.name)<0)
            LocPtr = LocPtr ->LChild;
        else if (strcmp(Item.name,LocPtr ->Data.name)>0)
            LocPtr = LocPtr ->RChild;
        else
            Found = true;
    }
    if (Found)
        printf("TO STOIXEIO EINAI HDH STO DDA\n");
    else {
        LocPtr = (BinTreePointer)malloc(sizeof (struct BinTreeNode));
 //       LocPtr ->Data = Item;
        LocPtr ->Data.employee_code = Item.employee_code;
        strcpy(LocPtr ->Data.name,Item.name);
        LocPtr ->LChild = NULL;
        LocPtr ->RChild = NULL;
        if (Parent == NULL)
            *Root = LocPtr;
        else if (strcmp(Item.name, Parent ->Data.name)<0)
            Parent ->LChild = LocPtr;
        else
            Parent ->RChild = LocPtr;
    }
}

void BSTSearch(BinTreePointer Root, BinTreeElementType KeyValue, bool *Found, BinTreePointer *LocPtr)
/* Δέχεται:    Ένα ΔΔΑ με το δείκτη Root να δείχνει στη ρίζα του και μια τιμή KeyValue.
   Λειτουργία: Αναζητά στο ΔΔΑ έναν κόμβο με τιμή KeyValue στο πεδίο κλειδί του.
   Επιστρέφει: Η Found έχει τιμή true και ο δείκτης LocPtr δείχνει στον κόμβο που
                περιέχει την τιμή KeyValue, αν η αναζήτηση είναι επιτυχής.
                Διαφορετικά η Found έχει τιμή false
*/
{
    bool stop;

    *LocPtr = Root;
    stop = false;
    while (!stop && *LocPtr != NULL)
    {
        if (strcmp(KeyValue.name, (*LocPtr)->Data.name)<0)
            *LocPtr = (*LocPtr)->LChild;
        else
            if (strcmp(KeyValue.name,(*LocPtr)->Data.name)>0)
                *LocPtr = (*LocPtr)->RChild;
            else stop = true;
    }
   *Found=stop;
}

void BSTSearch2(BinTreePointer Root, BinTreeElementType KeyValue, bool *Found,
    BinTreePointer *LocPtr, BinTreePointer *Parent)
/* Δέχεται:    Ένα ΔΔΑ με το δείκτη Root να δείχνει στη ρίζα του και μια τιμή KeyValue.
   Λειτουργία: Αναζητά στο ΔΔΑ έναν κόμβο με τιμή KeyValue στο πεδίο κλειδί του
                και τον πατέρα του κόμβου αυτού.
   Επιστρέφει: Η Found έχει τιμή true, ο δείκτης LocPtr δείχνει στον κόμβο που
                περιέχει την τιμή KeyValue και ο Parent δείχνει στον πατέρα
                αυτού του κόμβου, αν η αναζήτηση είναι επιτυχής.
                Διαφορετικά η Found έχει τιμή false.
*/
{
    bool stop;
    BinTreePointer TempParent;

    *LocPtr = Root;
    TempParent=NULL;
    stop = false;
    while (!stop && *LocPtr != NULL)
    {
        if (KeyValue.employee_code < (*LocPtr)->Data.employee_code) {
            TempParent=*LocPtr;
            *LocPtr = (*LocPtr)->LChild;
        }
        else
            if (KeyValue.employee_code > (*LocPtr)->Data.employee_code) {
                TempParent=*LocPtr;
                *LocPtr = (*LocPtr)->RChild;
            }
            else stop = true;
    }
   *Found=stop;
   *Parent=TempParent;
}

void BSTDelete(BinTreePointer *Root, BinTreeElementType KeyValue)
/* Δέχεται:  Ένα ΔΔΑ με το δείκτη Root να δείχνει στη ρίζα του και μια τιμή KeyValue.
  Λειτουργία: Προσπαθεί να βρει έναν κόμβο στο ΔΔΑ που να περιέχει την τιμή
                KeyValue στο πεδίο κλειδί του τμήματος δεδομένων του και,
                αν τον βρει, τον διαγράφει από το ΔΔΑ.
  Επιστρέφει: Το τροποποιημένο ΔΔΑ με τον δείκτη Root να δείχνει στη ρίζα του.
*/
{

   BinTreePointer
   R,
   n,                   //δείχνει στον κόμβο που περιέχει την τιμή KeyValue *)
   Parent,              // πατέρας του n ή του nNext
   nNext,               // ενδοδιατεταγμένος επόμενος του n
   SubTree;             // δείκτης προς υποδέντρο του n
   bool Found;       // true AN TO ΣΤΟΙΧΕΙΟ KeyValue EINAI ΣΤΟΙΧΕΟ ΤΟΥ ΔΔΑ *)

     R=*Root;
     BSTSearch2(R, KeyValue, &Found , &n, &Parent);
     if (!Found)
        printf("TO STOIXEIO DEN EINAI STO DDA\n");
     else {
          if (n->LChild != NULL && n->RChild != NULL)
          {  // κόμβος προς διαγραφή με δύο παιδιά
                 //Βρες τον ενδοδιατεταγμένο επόμενο και τον πατέρα του
                 nNext = n->RChild;
                 Parent = n;
                 while (nNext->LChild !=NULL)  //* DIASXISH PROS TA ARISTERA *)
                 {
                      Parent = nNext;
                      nNext = nNext->LChild;
                 }
                /* Αντιγραφή των περιεχομένων του nNext στον n και
                αλλαγή του n ώστε να δείχνει στον επόμενο */
                n->Data = nNext->Data;
                n = nNext;
          } //Συνεχίζουμε με την περίπτωση που ο κόμβος έχει το πολύ 1 παιδί
          SubTree = n->LChild;
          if (SubTree == NULL)
             SubTree = n->RChild;
          if (Parent == NULL)                 //* 8A DIAGRAFEI H RIZA *)
             *Root = SubTree;
          else if (Parent->LChild == n)
                  Parent->LChild = SubTree;
               else
                   Parent->RChild = SubTree;
          free(n);
     }
}

void InorderTraversal(BinTreePointer Root)
/* Δέχεται:    Ένα δυαδικό δέντρο με το δείκτη Root να δείχνει στην ρίζα του.
   Λειτουργία: Εκτελεί ενδοδιατεταγμένη διάσχιση του δυαδικού δέντρου και
                επεξεργάζεται κάθε κόμβο ακριβώς μια φορά.
   Εμφανίζει: Το περιεχόμενο του κόμβου, και εξαρτάται από το είδος της επεξεργασίας
*/
{
    if (Root!=NULL) {
        InorderTraversal(Root->LChild);
        printf("%s %d\n",Root->Data.name,Root->Data.employee_code);
        InorderTraversal(Root->RChild);
    }
}




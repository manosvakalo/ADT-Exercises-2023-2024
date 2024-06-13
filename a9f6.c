#include <ctype.h>
#include <string.h>
#include <stdbool.h>

#define HMax 11             /*   το μέγεθος του πίνακα κατακερματισμού HashTable
                                ενδεικτικά ίσο με 5 */
#define VMax 30             /*το μέγεθος της λίστας εγγραφών,
                                ενδεικτικά ίσο με 30 */
#define EndOfList -1

#include <stdio.h>

typedef struct{

int service;
int cost;
} ListElementType;  /*τύπος δεδομένων για τα στοιχεία της λίστας
                               * ενδεικτικά τύπου int, επανορίζεται ανάλογα με την εφαρμογή*/
typedef int KeyType;           // το κλειδί  τύπου int

typedef struct {
	KeyType RecKey;
	ListElementType Data;
	int Link;
} ListElm;

typedef struct  {
	int HashTable[HMax];   // πίνακας κατακερματισμού κλειδιών με τους αριθμοδείκτες προς τις υπολίστες συνωνύμων
    int Size;                // πλήθος εγγραφών της λίστας List
	int SubListPtr;          // αριθμοδείκτης το 1ο συνώνυμο μιας υπολίστας συνωνύμων
    int StackPtr;           // αριθμοδείκτης προς την 1η ελεύθερη θέση της λίστας εγγραφών List
	ListElm List[VMax];
} HashListType;

void CreateHashList(HashListType *HList);
int HashKey(KeyType Key);
bool FullHashList(HashListType HList);
void SearchSynonymList(HashListType HList,KeyType KeyArg,int *Loc,int *Pred);
void SearchHashList(HashListType HList,KeyType KeyArg,int *Loc,int *Pred);
void AddRec(HashListType *HList,ListElm InRec);
void DeleteRec(HashListType *HList,KeyType DelKey);
void Print_HashList(HashListType HList);
void DataInput(HashListType *Hash);
int HashedKey(char *name);
void SearchVisit(HashListType Hash);



int main()
{

    HashListType Dentist;
    CreateHashList(&Dentist);

    DataInput(&Dentist);

    Print_HashList(Dentist);

    SearchVisit(Dentist);






    return 0;
}


void SearchVisit(HashListType Hash)
{

    char ch,name[30];
    int SearchKey;
    int Pos = -1,Pred=-1;
    const char *service[3]={"Whitening","Cleaning","Extraction"};
    printf("\n4. SEARCH FOR A VISIT\n");
    do
            {
   	            printf("Enter user's name: ");
                scanf("%s", name);
                SearchKey = HashedKey(name);
                SearchHashList(Hash,SearchKey,&Pos,&Pred);
                if(Pos != -1)
                {
                    printf("user: %d, Service: %s, Amount Paid: %d\n",SearchKey,service[(Hash.List[Pos].Data.service)-1],Hash.List[Pos].Data.cost);
                }
                else printf("DEN YPARXEI EGGRAFH ME KLEIDI %s",name);
                printf("\nContinue Y/N: ");
                do
                {
      	             scanf("%c", &ch);
                } while (toupper(ch)!= 'N' && toupper(ch)!= 'Y');
            } while (toupper(ch)!='N');




}




int HashedKey(char *name)
{
    int key = 0;
                int position = 1; // To track the actual position of the character excluding spaces
                for (int i = 0; name[i] != '\0'; i++)
                {
                    int value;
                    if (name[i] == ' ')
                    {
                        continue; // Skip spaces
                    } else if (name[i] >= 'A' && name[i] <= 'Z')
                    {
                        value = name[i] - 'A' + 1;
                    } else if (name[i] >= 'a' && name[i] <= 'z')
                    {
                        value = name[i] - 'a' + 33;
                    } else
                    {
                        continue; // Skip non-alphabetical characters
                    }
                key += value * position;
                position++;
                }
                return key;
}


void DataInput(HashListType *Hash)
{
    ListElm AnItem;
    char name[50];
    char ch;

    printf("2. ENTER VISITS\n");
    do
            {
   	            printf("Enter user's name: ");
                scanf("%s", name);

                AnItem.RecKey = HashedKey(name);
                getchar();
                printf("Service (1-Whitening, 2-Cleaning, 3-Extraction):  ");
                scanf("%d",&AnItem.Data.service);
                printf("Ammount paid: ");
                scanf("%d",&AnItem.Data.cost);
                AddRec(Hash, AnItem);
                printf("\nContinue Y/N: ");
                do
                {
      	             scanf("%c", &ch);
                } while (toupper(ch)!= 'N' && toupper(ch)!= 'Y');
            } while (toupper(ch)!='N');


}

void Print_HashList(HashListType HList)
{
   int i, SubIndex;



          printf("3. DENTIST USERS:\n");
            for (i=0; i<HMax;i++)


          for (i=0; i<HMax;i++)
          {
              if(HList.HashTable[i] != EndOfList)
            {
                printf("Synonyms, collision at position: %d\n",i);
                SubIndex = HList.HashTable[i];
                while(SubIndex != EndOfList)
                {
                printf("%d: [%d, %d, %d, %d]\n",SubIndex,HList.List[SubIndex].RecKey,HList.List[SubIndex].Data.service,
                       HList.List[SubIndex].Data.cost,HList.List[SubIndex].Link);
                       SubIndex = HList.List[SubIndex].Link;
                }
            //printf("\n");
            }
              SubIndex = HList.HashTable[i];

          }


}







int HashKey(KeyType Key)
/* Δέχεται:    Την τιμή Key ενός κλειδιού.
   Λειτουργία: Βρίσκει την τιμή κατακερματισμού HValue για το κλειδί Key.
   Επιστρέφει: Την τιμή κατακερματισμού HValue
*/
{
	/*σε περίπτωση που το KeyType δεν είναι ακέραιος
	θα πρέπει να μετατρέπεται κατάλληλα το κλειδί σε αριθμό*/
	return Key%HMax;
}

void CreateHashList(HashListType *HList)
/* Λειτουργία: Δημιουργεί μια δομή HList.
   Επιστρέφει: Την δομή HList
*/
{
	int index;

	HList->Size=0;           //ΔΗΜΙΟΥΡΓΕΙ ΜΙΑ ΚΕΝΗ ΛΙΣΤΑ
	HList->StackPtr=0;       //ΔΕΙΚΤΗς ΣΤΗ ΚΟΡΥΦΗ ΤΗΣ ΣΤΟΙΒΑΣ ΤΩΝ ΕΛΕΥΘΕΡΩΝ ΘΕΣΕΩΝ

    /*ΑΡΧΙΚΟΠΟΙΕΙ ΤΟΝ ΠΙΝΑΚΑ HashTable ΤΗΣ ΔΟΜΗΣ HList ΩΣΤΕ ΚΑΘΕ ΣΤΟΙΧΕΙΟΥ ΤΟΥ
        ΝΑ ΕΧΕΙ ΤΗ ΤΙΜΗ EndOfList (-1)*/
	for (index=0;index<HMax;index++)
	{
		HList->HashTable[index]=EndOfList;
    }
     //Δημιουργία της στοίβας των ελεύθερων θέσεων στη λίστα HList

	for(index=0;index < VMax-1;index++)
	{
		HList->List[index].Link=index+1;
	}
	HList->List[index].Link=EndOfList;
}

bool FullHashList(HashListType HList)
/* Δέχεται:    Μια δομή HList.
   Λειτουργία: Ελέγχει αν η λίστα List της δομής HList είναι γεμάτη.
   Επιστρέφει: TRUE αν η λίστα List είναι γεμάτη, FALSE διαφορετικά.
*/
{
	return(HList.Size==VMax);
}

void SearchSynonymList(HashListType HList,KeyType KeyArg,int *Loc,int *Pred)
/* Δέχεται:     Μια δομή HList και μια τιμή κλειδιού KeyArg.
    Λειτουργία: Αναζητά μια εγγραφή με κλειδί KeyArg στην υπολίστα συνωνύμων.
    Επιστρέφει: Τη θέση Loc της εγγραφής και τη θέση Pred της προηγούμενης
                εγγραφής στην υπολίστα
*/
{
	int Next;
	Next=HList.SubListPtr;
	*Loc=-1;
	*Pred=-1;
	while(Next!=EndOfList)
	{
		if (HList.List[Next].RecKey==KeyArg)
		{
			*Loc=Next;
			Next=EndOfList;
		}
		else
		{
			*Pred=Next;
			Next=HList.List[Next].Link;
		}
	}
}
void SearchHashList(HashListType HList,KeyType KeyArg,int *Loc,int *Pred)
/* Δέχεται:     Μια δομή HList και μια τιμή κλειδιού KeyArg.
    Λειτουργία: Αναζητά μια εγγραφή με κλειδί KeyArg στη δομή HList.
    Επιστρέφει: Τη θέση Loc της εγγραφής και τη θέση Pred της
                προηγούμενης εγγραφής της υπολίστας στην οποία ανήκει.
                Αν δεν υπάρχει εγγραφή με κλειδί KeyArg τότε Loc=Pred=-1
*/
{
	int HVal;
	HVal=HashKey(KeyArg);
    if (HList.HashTable[HVal]==EndOfList)
	{
		*Pred=-1;
		*Loc=-1;
	}
	else
	{
		HList.SubListPtr=HList.HashTable[HVal];
		SearchSynonymList(HList,KeyArg,Loc,Pred);
	}
}

void AddRec(HashListType *HList,ListElm InRec)
/* Δέχεται:    Μια δομή HList και μια εγγραφή InRec.
   Λειτουργία: Εισάγει την εγγραφή InRec στη λίστα List, αν δεν είναι γεμάτη,
                και ενημερώνει τη δομή HList.
   Επιστρέφει: Την τροποποιημένη δομή HList.
   Έξοδος:     Μήνυμα γεμάτης λίστας, αν η List είναι γεμάτη, διαφορετικά,
                αν υπάρχει ήδη εγγραφή με το ίδιο κλειδί,
                εμφάνιση αντίστοιχου μηνύματος
*/
{
	int Loc, Pred, New, HVal;

   // New=0;
	if(!(FullHashList(*HList)))
	{
		Loc=-1;
		Pred=-1;
		SearchHashList(*HList,InRec.RecKey,&Loc,&Pred);
		if(Loc==-1)
		{
			HList->Size=HList->Size +1;
			New=HList->StackPtr;
			HList->StackPtr=HList->List[New].Link;
			HList->List[New]=InRec;
			if (Pred==-1)
			{
			    HVal=HashKey(InRec.RecKey);
                HList->HashTable[HVal]=New;
				HList->List[New].Link=EndOfList;
			}
			else
			{
                HList->List[New].Link=HList->List[Pred].Link;
				HList->List[Pred].Link=New;
			}
		}

		else
		{
			printf("YPARXEI HDH EGGRAFH ME TO IDIO KLEIDI \n");
		}
	}
	else
	{
		printf("Full list...");
	}
}
void DeleteRec(HashListType *HList,KeyType DelKey)
/* DEXETAI:    TH DOMH (HList) KAI To KLEIDI (DelKey) THS EGGRAFHS
               POY PROKEITAI NA DIAGRAFEI
   LEITOYRGIA: DIAGRAFEI, THN EGGRAFH ME KLEIDI (DelKey) APO TH
               LISTA (List), AN YPARXEI ENHMERWNEI THN DOMH HList
   EPISTREFEI: THN TROPOPOIHMENH DOMH (HList)
   EJODOS:     "DEN YPARXEI EGGRAFH ME KLEIDI" MHNYMA
*/
{
	int Loc, Pred, HVal;

	SearchHashList(*HList,DelKey,&Loc,&Pred);
	if(Loc!=-1)
	{
		if(Pred!=-1)
		{
			HList->List[Pred].Link=HList->List[Loc].Link;
		}
		else
		{
			HVal=HashKey(DelKey);
		    HList->HashTable[HVal]=HList->List[Loc].Link;
		}
		HList->List[Loc].Link=HList->StackPtr;
		HList->StackPtr=Loc;
		HList->Size=HList->Size -1;
	}
	else
	{
		printf("DEN YPARXEI  EGGRAFH ME KLEIDI %d \n",DelKey);
	}
}

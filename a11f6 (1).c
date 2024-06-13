#include <ctype.h>
#include <stdio.h>
#include <stdbool.h>
#define HMax 7              /*   �� ������� ��� ������ ��������������� HashTable                                ���������� ��� �� 5 */
#define VMax 10             /*�� ������� ��� ������ ��������,                                ���������� ��� �� 30 */
#define EndOfList -1        /* ������ ��� ����������� �� ����� ��� ������
                                ��� ��� ���� ��������� ��������� */

typedef int ListElementType;  /*����� ��������� ��� �� �������� ��� ������
                               * ���������� ����� int, ������������ ������� �� ��� ��������*/
typedef int KeyType;           // �� ������  ����� int

typedef struct {
	KeyType RecKey;
	ListElementType Data;
	int Link;
} ListElm;

typedef struct  {
	int HashTable[HMax];   // ������� ��������������� �������� �� ���� ������������� ���� ��� ��������� ���������
    int Size;                // ������ �������� ��� ������ List
	int SubListPtr;          // ������������� �� 1� �������� ���� ��������� ���������
    int StackPtr;           // ������������� ���� ��� 1� �������� ���� ��� ������ �������� List
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
void menu(int *choice);
void PrintPinakes(HashListType HList);

int main(){
   int choice;
   char ch;
   HashListType HList;
   ListElm AnItem;
   KeyType AKey;
   int Loc, Pred;

   CreateHashList(&HList);
   do
   {
   	menu(&choice);
      switch(choice)
      {
      	case 1:	do
            {
   	            printf("Enter the key for insertion in the Hash: ");
                scanf("%d", &AnItem.RecKey);
                printf("Enter the data for insertion in the Hash: ");
                scanf("%d", &AnItem.Data);
                AddRec(&HList, AnItem);
                printf("Continue Y/N: ");
                do
                {
      	             scanf("%c", &ch);
                } while (toupper(ch)!= 'N' && toupper(ch)!= 'Y');
            } while (toupper(ch)!='N');
            break;
         case 2: printf("Enter a number for deleting in the Hash: ");
                 scanf("%d", &AKey);
                 DeleteRec(&HList, AKey);
         		 break;
         case 3:   printf("Enter a number for searching in the Hash: ");
                    scanf("%d", &AKey);
                    SearchHashList( HList,AKey,&Loc,&Pred);
         			if ( Loc != -1)
                        printf("EGGRAFH [%d, %d, %d]\n",HList.List[Loc].RecKey,HList.List[Loc].Data,HList.List[Loc].Link);
                    else
                        printf("DEN YPARXEI EGGRAFH ME KLEIDI %d\n", AKey);
         			break;
        case 4: Print_HashList(HList);
         			break;
        case 5: PrintPinakes(HList);
         			break;
		}
   } while (choice!=6);

	return 0;
}


void Print_HashList(HashListType HList)
{
   int i, SubIndex;

     printf("HASHLIST STRUCTURE with SYNONYM CHAINING\n");
     printf("========================================\n");

          printf("PINAKAS DEIKTWN STIS YPO-LISTES SYNWNYMWN EGGRAFWN:\n");
            for (i=0; i<HMax;i++)
              printf("%d| %d\n",i,HList.HashTable[i]);

          printf("OI YPO-LISTES TWN SYNWNYMWN EGGRAFWN:\n");
          for (i=0; i<HMax;i++)
          {
              SubIndex = HList.HashTable[i];
              if(SubIndex != -1)
              while ( SubIndex != EndOfList )
              {
                   printf("%d:[%d, %d, %d]",SubIndex,HList.List[SubIndex].RecKey,HList.List[SubIndex].Data,HList.List[SubIndex].Link);
                   printf(" -> ");
                   SubIndex = HList.List[SubIndex].Link;
               } //* while *)
             printf("TELOS % dHS YPO-LISTAS\n", i);
          }

          printf("H STOIBA TWN ELEY8ERWN 8ESEWN THS LISTAS:\n");
          SubIndex = HList.StackPtr;
          while ( SubIndex != EndOfList )
          {
                printf("%d <= ",SubIndex);
                SubIndex = HList.List[SubIndex].Link;
          }
          printf("TELOS\n");

          printf("MEGE8OS THS LISTAS = %d\n", HList.Size);
          printf("========================================\n");
}

void menu(int *choice)
{
    printf("                  MENOY                  \n");
    printf("-------------------------------------------------\n");
    printf("1. EISAGWGH EGGRAFHS\n");
    printf("2. DIAGRAFH EGGRAFHS\n");
    printf("3. ANAZHTHSH EGGRAFHS\n");
    printf("4. EMFANISH DOMHS\n");
    printf("5. EMFANISH PINAKWN (BOH8HTIKH\n");
    printf("6. EXIT\n");
    printf("CHOICE: ");
    do
    {
    	scanf("%d", choice);
    } while (*choice<1 && *choice>6);
}

void PrintPinakes(HashListType HList)
{
    int i;
	printf("Hash table\n");
	for (i=0; i<HMax;i++)
              printf("%d| %d\n",i,HList.HashTable[i]);

	printf("Hash List\n");
    for (i=0;i<VMax;i++)
	   printf("%d) %d, %d\n",i,HList.List[i].RecKey,HList.List[i].Link);
	printf("\n");
}

int HashKey(KeyType Key)
/* �������:    ��� ���� Key ���� ��������.
   ����������: ������� ��� ���� ��������������� HValue ��� �� ������ Key.
   ����������: ��� ���� ��������������� HValue
*/
{
	/*�� ��������� ��� �� KeyType ��� ����� ��������
	�� ������ �� ������������ ��������� �� ������ �� ������*/
	return Key%HMax;
}

void CreateHashList(HashListType *HList)
/* ����������: ���������� ��� ���� HList.
   ����������: ��� ���� HList
*/
{
	int index;

	HList->Size=0;           //���������� ��� ���� �����
	HList->StackPtr=0;       //������� ��� ������ ��� ������� ��� ��������� ������

    /*����������� ��� ������ HashTable ��� ����� HList ���� ���� ��������� ���
        �� ���� �� ���� EndOfList (-1)*/
	for (index=0;index<HMax;index++)
	{
		HList->HashTable[index]=EndOfList;
    }
     //���������� ��� ������� ��� ��������� ������ ��� ����� HList

	for(index=0;index < VMax-1;index++)
	{
		HList->List[index].Link=index+1;
	}
	HList->List[index].Link=EndOfList;
}

bool FullHashList(HashListType HList)
/* �������:    ��� ���� HList.
   ����������: ������� �� � ����� List ��� ����� HList ����� ������.
   ����������: TRUE �� � ����� List ����� ������, FALSE �����������.
*/
{
	return(HList.Size==VMax);
}

void SearchSynonymList(HashListType HList,KeyType KeyArg,int *Loc,int *Pred)
/* �������:     ��� ���� HList ��� ��� ���� �������� KeyArg.
    ����������: ������� ��� ������� �� ������ KeyArg ���� �������� ���������.
    ����������: �� ���� Loc ��� �������� ��� �� ���� Pred ��� ������������
                �������� ���� ��������
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
/* �������:     ��� ���� HList ��� ��� ���� �������� KeyArg.
    ����������: ������� ��� ������� �� ������ KeyArg ��� ���� HList.
    ����������: �� ���� Loc ��� �������� ��� �� ���� Pred ���
                ������������ �������� ��� ��������� ���� ����� ������.
                �� ��� ������� ������� �� ������ KeyArg ���� Loc=Pred=-1
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
/* �������:    ��� ���� HList ��� ��� ������� InRec.
   ����������: ������� ��� ������� InRec ��� ����� List, �� ��� ����� ������,
                ��� ���������� �� ���� HList.
   ����������: ��� ������������� ���� HList.
   ������:     ������ ������� ������, �� � List ����� ������, �����������,
                �� ������� ��� ������� �� �� ���� ������,
                �������� ����������� ���������
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



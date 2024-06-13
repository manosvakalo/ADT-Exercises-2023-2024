#include <ctype.h>
#include <string.h>
#include <stdbool.h>

#define HMax 5              /*   �� ������� ��� ������ ��������������� HashTable
                                ���������� ��� �� 5 */
#define VMax 30             /*�� ������� ��� ������ ��������,
                                ���������� ��� �� 30 */
#define EndOfList -1

#include <stdio.h>

typedef struct{
int code;
char full_name[20];
} ListElementType;  /*����� ��������� ��� �� �������� ��� ������
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

int main()
{
    HashListType Library;
    ListElm AnItem;
    char ch;
    const char* positions[4] = { "postgraduate student","PhD student","Professor","External user"};
    CreateHashList(&Library);


    do
            {
   	            printf("Enter user's key: ");
                scanf("%d", &AnItem.RecKey);
                getchar();
                printf("Enter user's name: ");
                fgets(AnItem.Data.full_name,19,stdin);
                AnItem.Data.full_name[strcspn(AnItem.Data.full_name, "\n")] = '\0';
                printf("Enter user's position  (1 = postgraduate student, 2 = PhD student, 3 = Professor, 4 = External user): ");
                scanf("%d",&AnItem.Data.code);
                AddRec(&Library, AnItem);
                printf("\nContinue Y/N: ");
                do
                {
      	             scanf("%c", &ch);
                } while (toupper(ch)!= 'N' && toupper(ch)!= 'Y');
            } while (toupper(ch)!='N');

            Print_HashList(Library);

            int flag;
            printf("Enter user's key for searching in the Hash: ");
            scanf("%d",&flag);
            int Pos = -1, PredPos;

            SearchHashList(Library,flag,&Pos,&PredPos);
            if(Pos != -1)
            {
                printf("%d, %s, %s\n",Library.List[Pos].RecKey,Library.List[Pos].Data.full_name,
                       positions[Library.List[Pos].Data.code]);
            }
            else printf("There is no user with code %d\n",flag);

            printf("Enter user's key for deleting in the Hash: ");
            scanf("%d",&flag);
            DeleteRec(&Library,flag);

            Print_HashList(Library);






    return 0;
}

void Print_HashList(HashListType HList)
{
   int i, SubIndex;
    const char *positions[4] = { "postgraduate student","PhD student","Professor","External user"};


          printf("LIBRARY USERS:\n");
            for (i=0; i<HMax;i++)


          for (i=0; i<HMax;i++)
          {
              if(HList.HashTable[i] != EndOfList)
            {
                printf("Synonyms, collision at position: %d\n",i);
                SubIndex = HList.HashTable[i];
                while(SubIndex != EndOfList)
                {
                printf("%d: [%d, %s, %s]\n",SubIndex,HList.List[SubIndex].RecKey,HList.List[SubIndex].Data.full_name,
                       positions[HList.List[SubIndex].Data.code - 1]);
                       SubIndex = HList.List[SubIndex].Link;
                }
            //printf("\n");
            }
              SubIndex = HList.HashTable[i];

          }


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


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define ListLimit 50    //���������� ������� ������. ������������ ������� �� ��� ��������

typedef struct{
    int am;
    char name[21];
} ListElementType;    /*����� ��������� ��� �� �������� ��� ������. ���������� ���������� � ����� int.
                                ������������ ������� �� ��� �������� */
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
/* ����������: ���������� ��� ���� �����.
   ����������: ��� ���� �����
*/
{
    List -> Size = 0;
}

bool EmptyList(ListType List)
/* �������:    ��� ����� List.
   ����������: ������� �� � ����� List ����� ����.
   ����������: True �� � ����� List ����� �����, false �����������
*/
{
    return (List.Size == 0);
}

bool FullList(ListType List)
/* �������:    ��� ����� List.
   ����������: ������� �� � ����� List ����� ������.
   ����������: True �� � ����� List ����� ������, false �����������
*/
{
    return (List.Size == (ListLimit));
}

void Insert(ListType *List, ListElementType Item, int Pos)
/* �������:    ��� ����� List, �� �������� Item ��� �� ���� Pos ���� ��� �����.
   ����������: �������, ��� ����� List, �� ��� ����� ������, ���� �� ���� Pos
                �� �������� Item.
   ����������: ��� ������������� ����� List.
   ������:     M����� ������� ������, �� � ����� List ����� ������
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
/* �������:    ��� ����� List.
   ����������: ��������� ��� �� ����� List, �� ��� ����� ����,
                �� �������� ��� ��������� ��� ���� Pos.
   ����������: ��� ������������� ����� List.
   ������:     ������ ����� ������, �� � ����� List ����� ����

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
/* �������:    ��� ����� List.
   ����������: ����� �������� ��� ����� List, �� ��� ����� ����.
   ������:     ��������� ��� ��� �����������
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

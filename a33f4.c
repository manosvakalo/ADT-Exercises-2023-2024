
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
            printf("%d, %s\n",List.Element[i].am,List.Element[i].name);
        printf("\n");
    }
}


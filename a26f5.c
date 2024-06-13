#include <stdbool.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct {
    int am;
    char name[20];
    char surname[20];
    int year;
    float grade;
    char sex;
}student;
typedef struct
{
    int am;
    int line;
} BinTreeElementType;
typedef struct BinTreeNode *BinTreePointer;
typedef struct BinTreeNode {
    BinTreeElementType Data;
    BinTreePointer LChild, RChild;
} BinTreeNode;

void CreateBST(BinTreePointer *Root);
bool BSTEmpty(BinTreePointer Root);
void RecBSTInsert(BinTreePointer *Root, BinTreeElementType Item);
void RecBSTSearch(BinTreePointer Root, BinTreeElementType KeyValue, bool *Found, BinTreePointer *LocPtr);
void RecBSTDelete(BinTreePointer *Root, BinTreeElementType KeyValue);
void RecBSTInorder(BinTreePointer Root);
void RecBSTPreorder(BinTreePointer Root);
void RecBSTPostorder(BinTreePointer Root);
int BuildBST(BinTreePointer *Root);
void writeNewStudents(BinTreePointer *Root, int *size);
void SearchStudent(BinTreePointer Root);
void printStudentsWithGrade(float theGrade);

int main()
{
    BinTreePointer Students;
    CreateBST(&Students);

    printf("Q1. build BST from a file\n");
    int size = BuildBST(&Students);

    printf("Q2. print the size of the BST\n");
    printf("size=%d\n",size);
    printf("Nodes of BST\n");
    RecBSTInorder(Students);

    printf("\nQ3. Write new students, update file and BST\n");
    writeNewStudents(&Students,&size);

    printf("Q4. Print the size and BST\n");
    printf("size=%d\n",size);
    printf("Nodes of BST\n");
    RecBSTInorder(Students);

    printf("\nQ5. Search for a student\n");
    SearchStudent(Students);

    printf("Q6. Print size and BST\n");
    printf("size=%d\n",size);
    printf("Nodes of BST\n");
    RecBSTInorder(Students);

    printf("\nQ7. Print students with grades >= given grade\n");
    float grade;
    printf("Give the grade: ");
    scanf("%f",&grade);
    printStudentsWithGrade(grade);




    return 0;
}

void printStudentsWithGrade(float theGrade)
{
    FILE *checkFile;
    student StudentData;
    checkFile = fopen("foitites.dat","r");
    int nscans;
    while(true){
    if(checkFile == NULL)
    {
        printf("error opening file");
        exit(1);
    }
    char termch;
               nscans = fscanf(checkFile,"%d,%19[^,],%19[^,],%c,%d,%f%c",&StudentData.am,StudentData.name,StudentData.surname,
                &StudentData.sex,&StudentData.year,&StudentData.grade,&termch);

    if(nscans == EOF)break;
    if(nscans != 7 || termch != '\n')
    {
        printf("Error fetching data");
        exit(1);
    }
    if(StudentData.grade > theGrade)printf("%d,%s,%s,%c,%d,%.1f\n",StudentData.am,StudentData.name,StudentData.surname,
                StudentData.sex,StudentData.year,StudentData.grade);

}
}

void SearchStudent(BinTreePointer Root)
{
    BinTreeElementType studinfo;
    bool found;
    BinTreePointer Pos;
    student StudentData;

    printf("Give student's code? ");
    scanf("%d",&studinfo.am);
    RecBSTSearch(Root,studinfo,&found,&Pos);
    if(found)
    {
        FILE *data;
        data = fopen("foitites.dat","r");
        if(data == NULL)
        {
            printf("Error opening file");
            exit(1);

        }

        int nscans;
        studinfo.line=0;
        while(true)
        {
            char termch;
               nscans = fscanf(data,"%d,%19[^,],%19[^,],%c,%d,%f%c",&StudentData.am,StudentData.name,StudentData.surname,
                &StudentData.sex,&StudentData.year,&StudentData.grade,&termch);

                                if(nscans != 7 || termch != '\n')
                                {
                                    printf("Error fetching data");
                                    exit(1);
                                }


              if(studinfo.line == Pos->Data.line){
                    printf("%d,%s,%s,%c,%d,%.1f\n",StudentData.am,StudentData.name,StudentData.surname,
                    StudentData.sex,StudentData.year,StudentData.grade);
                    fclose(data);
                    break;
                    }
            studinfo.line++;

        }

    }
    else{
        printf("Student %d Not Found",studinfo.am);
    }


}


void writeNewStudents(BinTreePointer *Root, int *size)
{

        BinTreeElementType studentDDAData;
        student studinfo;
        char ch;
        FILE *new_input;
        new_input = fopen("foitites.dat","a");
        bool found;
        BinTreePointer pos;
        do{

            do{printf("Give Student's AM? ");
            scanf("%d",&studentDDAData.am);
            RecBSTSearch(*Root,studentDDAData,&found,&pos);
            if(found)printf("Code already in BST\n");
            }while(found);
            printf("Give Student surname? ");
            scanf("%s",studinfo.surname);
            getchar();
            printf("Give Student name? ");
            scanf("%s",studinfo.name);
            getchar();
            printf("Give Student sex F/M? ");
            scanf("%c",&studinfo.sex);
            printf("Give Student's registration year? ");
            scanf("%d",&studinfo.year);
            printf("Give Student's grade? ");
            scanf("%f",&studinfo.grade);
            studentDDAData.line = *size;
            RecBSTInsert(Root,studentDDAData);
            printf("size=%d\n",*size+1);
            (*size)++;
            fprintf( new_input,"%d,%s,%s,%c,%d,%.1f\n",studentDDAData.am,studinfo.name,studinfo.surname,
                    studinfo.sex,studinfo.year,studinfo.grade);
            printf("\n");
            printf("Continue Y/N: ");
            do{
                    scanf("%c", &ch);
                } while (toupper(ch)!= 'N' && toupper(ch)!= 'Y');
                } while (toupper(ch)!='N');
                fclose(new_input);

}





void CreateBST(BinTreePointer *Root)
/*           :                        .
             :                     (NULL) Root
*/
{
    *Root = NULL;
}

int BuildBST(BinTreePointer *Root)
{
    int nodes,nscans;
    FILE *input;
    input = fopen("foitites.dat","r");
    if(input == NULL)
    {
        printf("error reading file,terminating...");
        exit(1);
    }
    nodes = 0;
    BinTreeElementType AnItem;
    char name[20],surnmame[20],sex,termch;
    float grade;
    int year;
    while(true)
    {

        nscans = fscanf(input,"%d,%19[^,],%19[^,],%c,%d,%f%c",&AnItem.am,surnmame,name,&sex,&year,&grade,&termch);
        if(nscans == EOF)break;
        if(nscans != 7)
        {
            printf("error");
            exit(1);
        }
        AnItem.line = nodes;
        nodes++;
        RecBSTInsert(Root,AnItem);
    }
    fclose(input);


    return nodes;
}
bool BSTEmpty(BinTreePointer Root)

{
    return (Root==NULL);
}
void RecBSTSearch(BinTreePointer Root, BinTreeElementType KeyValue,
                    bool *Found, BinTreePointer *LocPtr)
/*        :                         Root                                      KeyValue.
             :                                    KeyValue                     .
             :   Found           true               LocPtr
                                  KeyValue,                              .
                              Found           false
*/
{
    if (BSTEmpty(Root))
        *Found=false;
    else
        if (KeyValue.am < Root->Data.am)
            RecBSTSearch(Root->LChild, KeyValue, &(*Found), &(*LocPtr));
        else
            if (KeyValue.am > Root->Data.am)
                RecBSTSearch(Root->RChild, KeyValue, &(*Found), &(*LocPtr));
            else
                {
                    *Found = true;
                    *LocPtr=Root;
                }
}

void RecBSTDelete(BinTreePointer *Root, BinTreeElementType KeyValue)
/*        :                       Root                                      KeyValue.
             :
                KeyValue                                                ,
                           ,                         .
            :                                    Root                        .
*/
{

   BinTreePointer TempPtr;          //* true AN TO STOIXEIO KeyValue EINAI STOIXEIO TOY DDA *)

    if (BSTEmpty(*Root))          //*                 KeyValue              *)
        printf("TO STOIXEIO DEN BRE8HKE STO DDA\n");
     else
         //*                                                      KeyValue
          if (KeyValue.am < (*Root)->Data.am)
             RecBSTDelete(&((*Root)->LChild), KeyValue);       //*                    *
          else
            if (KeyValue.am > (*Root)->Data.am)
                  RecBSTDelete(&((*Root)->RChild), KeyValue);   //*                 *
            else                                       //* TO KeyValue                             *)
                if ((*Root)->LChild ==NULL)
                 {
                      TempPtr = *Root;
                      *Root = (*Root)->RChild;      //*                         *)
                      free(TempPtr);
                 }
                else if ((*Root)->RChild == NULL)
                   {
                        TempPtr = *Root;
                        *Root = (*Root)->LChild;      //*                    ,               *)
                        free(TempPtr);
                   }
                   else                               //*      2        *)
                   {
                        //*            INORDER              *)
                        TempPtr = (*Root)->RChild;
                        while (TempPtr->LChild != NULL)
                              TempPtr = TempPtr->LChild;
                        /*
                                                                        */
                        (*Root)->Data = TempPtr->Data;
                        RecBSTDelete(&((*Root)->RChild), (*Root)->Data);
                   }
}

void RecBSTInorder(BinTreePointer Root)
/*        :                                    Root                         .
             :
                                                         .
            :                          ,
*/
{
    if (Root!=NULL) {
    //    printf("L");
        RecBSTInorder(Root->LChild);
        printf("(%d, %d), ",Root->Data.am,Root->Data.line);
    //    printf("R");
        RecBSTInorder(Root->RChild);
    }
   // printf("U");
}

void RecBSTPreorder(BinTreePointer Root)
/*        :                                    Root                         .
             :
                                                         .
            :                          ,
*/
{
    if (Root!=NULL) {
        printf("%d ",Root->Data);
       // printf("L");
        RecBSTPreorder(Root->LChild);
      //  printf("R");
        RecBSTPreorder(Root->RChild);
    }
   // printf("U");
}

void RecBSTPostorder(BinTreePointer Root)
/*        :                                    Root                         .
             :
                                                         .
            :                          ,
*/
{
    if (Root!=NULL) {
      //  printf("L");
        RecBSTPostorder(Root->LChild);
     //   printf("R");
        RecBSTPostorder(Root->RChild);
        printf("%d ",Root->Data);
    }
   // printf("U");
}

void RecBSTInsert(BinTreePointer *Root, BinTreeElementType Item)
/*        :                          Root                                          Item.
             :                      Item        .
             :                                    Root
*/
{
    if (BSTEmpty(*Root)) {
        (*Root) = (BinTreePointer)malloc(sizeof (struct BinTreeNode));
        (*Root) ->Data = Item;
        (*Root) ->LChild = NULL;
        (*Root) ->RChild = NULL;
    }
    else
        if (Item.am < (*Root) ->Data.am)
            RecBSTInsert(&(*Root) ->LChild,Item);
        else if (Item.am > (*Root) ->Data.am)
            RecBSTInsert(&(*Root) ->RChild,Item);
        else
            printf("TO STOIXEIO EINAI HDH STO DDA\n");
}








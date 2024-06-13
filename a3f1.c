#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#define megisto_plithos 26

typedef enum {
    FALSE, TRUE
} boolean;

typedef boolean typos_synolou[megisto_plithos];
typedef int stoixeio_synolou;

void Katholiko(typos_synolou synolo);
void displayset(typos_synolou set,char word[]);
boolean Melos(stoixeio_synolou stoixeio, typos_synolou synolo);
void Dimiourgia(typos_synolou synolo);
void Eisagogi(stoixeio_synolou stoixeio, typos_synolou synolo);
boolean IsaSynola(typos_synolou s1, typos_synolou s2);
boolean Yposynolo(typos_synolou s1, typos_synolou s2);
void EnosiSynolou(typos_synolou s1, typos_synolou s2, typos_synolou enosi);
void TomiSynolou(typos_synolou s1, typos_synolou s2, typos_synolou tomi);
void DiaforaSynolou(typos_synolou s1, typos_synolou s2, typos_synolou diafora);



int main(void)
{

    char set_gen[megisto_plithos]="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    /*dilvseis ton set*/
    typos_synolou catholic_set,S,T,enosi,tomi,diafora;

    /*entoles diaxeirisis synolovn*/
    /*a*/
    Katholiko(catholic_set);
    displayset(catholic_set,set_gen);
    /*b*/
    Dimiourgia(S);
    Dimiourgia(T);
    int i;
    for(i=0;set_gen[i]<='D';i++)Eisagogi(i,S);
    for(i=0;set_gen[i]<='I';i+=2)Eisagogi(i,T);
    displayset(S,set_gen);
    displayset(T,set_gen);
    /*c*/
    if(IsaSynola(S,T))
    printf("ISA SYNOLA\n");
    else printf("NOT ISA SYNOLA\n");
    if(Yposynolo(S,T))printf("S YPOSYNOLO T\n");else printf("Not S YPOSYNOLO T\n");
    if(Yposynolo(T,S))printf("T YPOSYNOLO S\n");else printf("Not T YPOSYNOLO S\n");
    /*d*/
    EnosiSynolou(S,T,enosi);
    displayset(enosi,set_gen);
    /*e*/
    TomiSynolou(S,T,tomi);
    displayset(tomi,set_gen);
    /*f*/
    DiaforaSynolou(S,T,diafora);
    displayset(diafora,set_gen);

    return 0;
}

void Katholiko(typos_synolou synolo)
{
    stoixeio_synolou i;

    for (i = 0; i < megisto_plithos; i++)
        synolo[i] = TRUE;
}

void displayset(typos_synolou set,char word[])
{
	stoixeio_synolou i;

	for (i=0;i < megisto_plithos;i++)
	{
		if(Melos(i,set))
			printf(" %c",word[i]);
	}
	printf("\n");
}

boolean Melos(stoixeio_synolou stoixeio, typos_synolou synolo)
{
    return synolo[stoixeio];
}
void Dimiourgia(typos_synolou synolo)
{
    stoixeio_synolou i;

    for (i = 0; i < megisto_plithos; i++)
        synolo[i] = FALSE;
}
void Eisagogi(stoixeio_synolou stoixeio, typos_synolou synolo)
{
    synolo[stoixeio] = TRUE;
}
boolean IsaSynola(typos_synolou s1, typos_synolou s2)
{
    stoixeio_synolou i;
    boolean isa;

    isa = TRUE;
    i=0;
    while (i < megisto_plithos && isa)
        if (Melos(i,s1) != Melos(i,s2))
            isa = FALSE;
        else
            i++;
    return isa;
}

boolean Yposynolo(typos_synolou s1, typos_synolou s2)
{
    stoixeio_synolou i;
    boolean yposyn;

    yposyn = TRUE;
    i=0;
    while (i < megisto_plithos && yposyn)
        if (Melos(i, s1) && !Melos(i, s2))
            yposyn = FALSE;
        else
            i++;
    return yposyn;
}
void EnosiSynolou(typos_synolou s1, typos_synolou s2, typos_synolou enosi)
{
    stoixeio_synolou i;

    for (i = 0; i < megisto_plithos; i++)
        enosi[i] = Melos(i, s1) || Melos(i, s2);
}
void TomiSynolou(typos_synolou s1, typos_synolou s2, typos_synolou tomi)
{
    stoixeio_synolou i;

    for (i = 0; i < megisto_plithos; i++)
        tomi[i] = Melos(i, s1) && Melos(i, s2);
}
void DiaforaSynolou(typos_synolou s1, typos_synolou s2, typos_synolou diafora)
{
    stoixeio_synolou i;

    for (i = 0; i < megisto_plithos; i++)
        diafora[i] = Melos(i, s1) && (!Melos(i, s2));
}





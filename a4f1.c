#include <stdio.h>
#include <stdbool.h>

#define megisto_plithos 60

 typedef enum {
    FALSE, TRUE
} boolean;

typedef boolean typos_synolou[megisto_plithos];
typedef int stoixeio_synolou;

void Dimiourgia(typos_synolou synolo);
void Eisagogi(stoixeio_synolou stoixeio, typos_synolou synolo);
boolean isPrime(int n);
void displayset(typos_synolou set);
boolean Melos(stoixeio_synolou stoixeio, typos_synolou synolo);
void TomiSynolou(typos_synolou s1, typos_synolou s2, typos_synolou tomi);
void EnosiSynolou(typos_synolou s1, typos_synolou s2, typos_synolou enosi);
void DiaforaSynolou(typos_synolou s1, typos_synolou s2, typos_synolou diafora);

int main()
{
    typos_synolou perittoi,protoi,protoikaiperittoi,enosiprotoiperittoi,perittoinotprotoi,symplprotoi;



    int i;
    /*a*/
    printf("SYNOLO PERITTWN ARITHMWN\n");
    Dimiourgia(perittoi);
    for(i=1;i<megisto_plithos;i+=2)Eisagogi(i,perittoi);
    displayset(perittoi);
    /*b*/
    printf("SYNOLO PRWTWN ARITHMWN\n");
    Dimiourgia(protoi);
    for(i=2;i<megisto_plithos;i++)
    {
        if(isPrime(i))Eisagogi(i,protoi);
    }
    displayset(protoi);
    /*c*/
    printf("TOMH SYNOLOU PERITTWN KAI PRWTWN\n");
    Dimiourgia(protoikaiperittoi);
    TomiSynolou(perittoi,protoi,protoikaiperittoi);
    displayset(protoikaiperittoi);
    /*d*/
    printf("ENWSH SYNOLOU PERITTWN KAI PRWTWN\n");
    Dimiourgia(enosiprotoiperittoi);
    EnosiSynolou(protoi,perittoi,enosiprotoiperittoi);
    displayset(enosiprotoiperittoi);
    /*e*/
    printf("PERITTOI POY DEN EINAI PRWTOI\n");
    Dimiourgia(perittoinotprotoi);
    for(i=1;i<=megisto_plithos;i+=2)if(Melos(i,perittoi) && !Melos(i,protoi))Eisagogi(i,perittoinotprotoi);
    displayset(perittoinotprotoi);
    /*f*/
    printf("SYMPLHRWMA PRWTWN\n");
    Dimiourgia(symplprotoi);
    for(i=0;i<=megisto_plithos;i++)if(!Melos(i,protoi))Eisagogi(i,symplprotoi);
    displayset(symplprotoi);






    return 0;
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

boolean isPrime(int n)
{
    bool prime = true;
    int i;
    for(i=2;i<n;i++)if(n%i == 0)prime=false;
    return prime;
}

void displayset(typos_synolou set)
{
	stoixeio_synolou i;

	for (i=0;i < megisto_plithos;i++)
	{
		if(Melos(i,set))
			printf(" %d",i);
	}
	printf("\n");
}
boolean Melos(stoixeio_synolou stoixeio, typos_synolou synolo)
{
    return synolo[stoixeio];
}
void TomiSynolou(typos_synolou s1, typos_synolou s2, typos_synolou tomi)
{
    stoixeio_synolou i;

    for (i = 0; i < megisto_plithos; i++)
        tomi[i] = Melos(i, s1) && Melos(i, s2);
}

void EnosiSynolou(typos_synolou s1, typos_synolou s2, typos_synolou enosi)
 {
    stoixeio_synolou i;

    for (i = 0; i < megisto_plithos; i++)
        enosi[i] = Melos(i, s1) || Melos(i, s2);
}
void DiaforaSynolou(typos_synolou s1, typos_synolou s2, typos_synolou diafora)
{
    stoixeio_synolou i;

    for (i = 0; i < megisto_plithos; i++)
        diafora[i] = Melos(i, s1) && (!Melos(i, s2));
}





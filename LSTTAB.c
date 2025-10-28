#include <stdlib.h>
#include <stdio.h>
#include "LSTPRIM.H"

LISTE listeCreer(void) {

LISTE L;
L = (LISTE) malloc(sizeof(laStruct));
if(!L) {

printf(" \nProblème de mémoire") ;
exit(0) ;
}
L->lg = 0;
return(L);
}

LISTECrypt listeCryptCreer(void) {

LISTECrypt L;
L = (LISTECrypt) malloc(sizeof(laStructCrypt));
if(!L) {

printf(" \nProblème de mémoire") ;
exit(0) ;
}
L->lg = 0;
return(L);
}

void listeDetruire(LISTE L){
int i;
for(i = 1;i <= L->lg; i++)

elementDetruire(L->elements[i]);

free(L);
}

void listeintDetruire(LISTECrypt L){
int i,j;
for(i = 1;i <= L->lg; i++){
    for(j = 0;j <= Max_Long; j++)
        elementintDetruire(L->elements[i][j]);
}
free(L);
}

int inserer (LISTE L, ELEMENT e, int pos) {
int i;
int succee=1;

if (estSaturee(L)){

printf ("\nListe saturée");
succee=0;}

else {

if ((pos < 1) || (pos > L->lg + 1)) {
printf ("\nPosition invalide");
succee=0;
}
else {

for(i = L->lg; i>= pos; i--)
    elementAffecter(&L->elements[i+1],L->elements[i]);

elementAffecter(&L->elements[pos], e);
(L->lg)++;
}

}
return(succee);
}

int supprimer (LISTE L, int pos ) {
int i;
int succee=1;
if (estVide(L)) {

printf ("\nListe vide");
succee=0;}

else {

if ((pos < 1) || (pos > L->lg)) {

printf ("\nPosition invalide");
succee=0;}

else {

elementDetruire(L->elements[pos]);
for(i=pos;i<=L->lg;i++)

elementAffecter(&L->elements[i],L->elements[i+1]);

(L->lg)--;
}

}
return(succee);
}

ELEMENT recuperer(LISTE L, int pos) {
ELEMENT elt= elementCreer();
if (estVide(L))

printf ("\nListe vide");

else {

if ((pos < 1) || (pos > L->lg))

printf ("\nPosition invalide");

else

elt=(L->elements[pos]);

}

return(elt);
}

long long int recuperercrypt(LISTECrypt L, int i,int j) {
long long int elt= elementCryptCreer();
if (estVide(L))

printf ("\nListe vide");

else {

if ((i < 1) || (i > L->lg))

printf ("\nPosition invalide");

else

elt=(L->elements[i][j]);

}

return(elt);
}


int listeComparer (LISTE L1,LISTE L2 )
{
int test= 1;
int i=1;
if (listeTaille(L1) != listeTaille(L2)) test= 0;
while ((i<=listeTaille(L1)) && (test)) {
if (elementComparer(recuperer(L1,i),recuperer(L2,i))!=0)
test=0;
i++;
}
return test;
}

void listeAfficher(LISTE L) {
int i;
for(i = 1; i <= L->lg; i++)

elementAfficher(L->elements[i]);

}


LISTE listeCopier(LISTE L){

LISTE LR = listeCreer();

int i;
ELEMENT elt;

for(i = 1;i <= L->lg; i++) {
elt=elementCreer();
elementCopier(&elt, recuperer(L,i));
inserer(LR, elt, i);
}
return LR;
}

int estVide(LISTE L) {
return (L->lg == 0);
}

int estSaturee(LISTE L) {
return (L->lg == MAX_PR);
}

int listeTaille(LISTE L) {
return (L->lg);
}

int listeTaille1(LISTECrypt L) {
return (L->lg);
}

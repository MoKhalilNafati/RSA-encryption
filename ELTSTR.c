#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ELTPRIM.H"

ELEMENT elementCreer (void) {
ELEMENT L;
L = (ELEMENT) malloc(sizeof(phrase));
return L;
}

long long int elementCryptCreer (void) {
long long int L;
L = (long long int*) malloc(sizeof(long long int));
return L;
}

void elementDetruire (ELEMENT elt) {
free (elt);
}
void elementintDetruire (long long int elt) {
free (elt);
}
void elementLire(ELEMENT* elt){
    printf("donner une chaine :");
    scanf("%s",elt);
}
void elementAfficher(ELEMENT elt){
    printf("%s\n",elt);
}

void elementCryptAfficher(long long int elt){
    printf("%i\n",elt);
}


void elementAffecter(ELEMENT* e1, ELEMENT e2){
    *e1 = e2;
}
void elementCopier(ELEMENT* e1, ELEMENT e2){
    strcpy(*e1,e2);
}
int elementComparer(ELEMENT e1, ELEMENT e2) {
    return (e1-e2);
}


ELEMENTPile elementPileCreer (int a,int b) {
ELEMENTPile L;
L = (ELEMENTPile) malloc(sizeof(couple));
L->n = a;
L->d_or_e = b;
return L;
}
void elementPileDetruire (ELEMENTPile elt) {
free (elt);
}
void elementPileLire(ELEMENTPile* elt){
    printf("donner n :");
    scanf("%i",&(*elt)->n);
    printf("donner d ou e :");
    scanf("%i",&(*elt)->d_or_e);

}
void elementPileAfficher(ELEMENTPile elt){
    printf("\n%i    ",elt->n);
    printf("%i\n",elt->d_or_e);

}
void elementPileAffecter(ELEMENTPile* e1, ELEMENTPile e2){
    *e1 = e2;
}
void elementPileCopier(ELEMENTPile* e1, ELEMENTPile e2){
    (*e1)->n = e2->n;
    (*e1)->d_or_e = e2->d_or_e;
}
int elementPileComparer(ELEMENTPile e1, ELEMENTPile e2) {
    return (e1->n)-(e2->n);
}

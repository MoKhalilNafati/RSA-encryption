#include <stdlib.h>
#include <stdio.h>

#include "PILEPRIM.H"


Pile PileCreer(void) {
Pile P;
P = (Pile) malloc(sizeof(laStructP));
if(!P) {

printf(" \nProblème de mémoire") ;

}
else P->Sommet = 0;
return(P);

}
void PileDetruire(Pile P){
int i;
for(i = 1; i <= P->Sommet; i++)

elementPileDetruire(P->elements[i]);

free(P);
}

void PileAfficher(Pile P) {
int i;
for(i = P->Sommet; i >= 1; i--)

elementPileAfficher(P->elements[i]);

}

int EstVide(Pile P) {
return (P->Sommet == 0);
}

int EstSaturee(Pile P) {
return (P->Sommet == MAX_PR);
}

int PileTaille(Pile P) {
return (P->Sommet);
}

int Empiler (Pile P, ELEMENTPile e) {
int succes=1;

if (EstSaturee(P)){

printf ("\n Pile saturée");
succes=0;}

else
{
(P->Sommet)++;
elementPileAffecter(&P->elements[P->Sommet], e);

}
return(succes);
}

ELEMENTPile Depiler (Pile P ) {
ELEMENTPile elt = elementPileCreer(0,0);
if (EstVide(P)) {

printf ("\n Pile vide");
}

else {

elementPileCopier(&elt, (P->elements)[P->Sommet]);
elementPileDetruire(P->elements[P->Sommet]);
(P->Sommet)--;
}
return (elt);
}

ELEMENTPile Sommet (Pile P) {

ELEMENTPile elt= elementPileCreer(0,0);
if (EstVide(P))

printf (" \n Pile vide");

else

elt = (P->elements[P->Sommet]);

return(elt);
}

Pile PileCopier (Pile P){

Pile PR = PileCreer();

int i;
ELEMENTPile elt;

for(i =1; i <= P->Sommet; i++) {
elt=elementPileCreer(0,0);
elementPileCopier(&elt, P->elements[i]);
Empiler(PR, elt);
}
return PR;
}

int PileComparer (Pile P1, Pile P2 )
{
int test= 1;
int i=P1->Sommet;

if (PileTaille(P1) != PileTaille(P2)) test= 0;

while ((i>=1) && (test)) {
if (elementPileComparer(P1->elements[i], P2->elements[i])!=0)
test=0;
i--;
}

return test;
}

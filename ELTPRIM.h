#ifndef ELTPRIM_H_INCLUDED
#define ELTPRIM_H_INCLUDED

#include "ELTSDD.h"

void elementLire(ELEMENT *);

void elementAffecter(ELEMENT*, ELEMENT);

void elementCopier(ELEMENT *, ELEMENT) ;

int elementComparer(ELEMENT, ELEMENT);

ELEMENT elementCreer(void) ;

long long int elementCryptCreer (void);

void elementDetruire (ELEMENT);

void elementintDetruire(long long int);

void elementAfficher(ELEMENT);

void elementCryptAfficher(long long int);


void elementPileLire(ELEMENTPile *);

void elementPileAffecter(ELEMENTPile*, ELEMENTPile);

void elementPileCopier(ELEMENTPile *, ELEMENTPile) ;

int elementPileComparer(ELEMENTPile, ELEMENTPile);

ELEMENTPile elementPileCreer(int a,int b) ;

void elementPileDetruire (ELEMENTPile);

#endif // ELTPRIM_H_INCLUDED

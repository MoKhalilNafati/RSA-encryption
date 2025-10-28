#ifndef LSTPRIM_H_INCLUDED
#define LSTPRIM_H_INCLUDED

#include "ELTPRIM.H"
#include "LSTSDD.H"

LISTE listeCreer(void);
LISTECrypt listeCryptCreer(void);
void listeDetruire(LISTE);
void listeintDetruire(LISTECrypt);
int estVide(LISTE);
int estSaturee(LISTE);
int listeTaille(LISTE);
int listeTaille1(LISTECrypt);
ELEMENT recuperer(LISTE, int);
long long int recuperercrypt(LISTECrypt, int,int);
int inserer(LISTE, ELEMENT,int);
int supprimer(LISTE, int);
void listeAfficher(LISTE);
void listeCryptAfficher(LISTECrypt);
LISTE listeCopier(LISTE);
int listeComparer(LISTE, LISTE);

#endif // LSTPRIM_H_INCLUDED

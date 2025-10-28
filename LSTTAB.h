#ifndef LSTTAB_H_INCLUDED
#define LSTTAB_H_INCLUDED

#include "ELTPRIM.H"
#define Max_Long 100
typedef struct {
ELEMENT elements[MAX_PR];
int lg;
} laStruct,*LISTE;

typedef struct {
long long int elements[MAX_PR][Max_Long];
int lg;
} laStructCrypt,*LISTECrypt;

#endif // LSTTAB_H_INCLUDED

#ifndef LIST_LOMBA_H_INCLUDED
#define LIST_LOMBA_H_INCLUDED
#include <iostream>
#include <cstdlib>
using namespace std;

#define next(P) P->next
#define first2(L2) L2.first2
#define info(P) P->info

typedef string infotype;
typedef struct elmlist_lomba *address_lomba;

struct elmlist_lomba{
    infotype info;
    address_lomba next;
};

struct List_lomba{
    address_lomba first2;
};

void createLomba(List_lomba &L2);
address_lomba allocate(string champ);
void deallocate(address_lomba &P);
address_lomba findElem(List_lomba L2, string champ);
void viewLomba(List_lomba L2);
/* insert lomba pakee insert first */
void insertLomba(List_lomba &L2, string champ);
void deleteFirst(List_lomba &L2, address_lomba &P);
void deleteLast(List_lomba &L2, address_lomba &P);
void deleteLomba(List_lomba &L2,address_lomba &P);


#endif // LIST_LOMBA_H_INCLUDED

#ifndef LIST_PESERTA_H_INCLUDED
#define LIST_PESERTA_H_INCLUDED
#include <iostream>
#include <string>

using namespace std;

#define first(L) ((L).first)
#define next(P) P->next
#define info(P) P->info
#define prev(P) P->prev
#define last(L) ((L).last)

typedef struct peserta infotype1;
typedef struct elmlist_peserta *address_peserta;

struct peserta{
    string nama;
    string nim;
    int angkatan;
};

struct elmlist_peserta {
    infotype1 info;
    address_peserta next;
    address_peserta prev;
};

struct List_peserta {
    address_peserta first;
    address_peserta last;
};

// eksekusi di peserta
void createList(List_peserta &L);
address_peserta alokasi(string name, string id, int angktn);
void dealokasi(address_peserta &P);
void insertFirst(List_peserta &L, string name, string id, int angktn);
void insertLast(List_peserta &L, string name, string id, int angktn);
void tambahurut(List_peserta &L, string name, string id, int angktn);
address_peserta findElm(List_peserta L, string x);
void printInfo(List_peserta L);
address_peserta findElm(List_peserta L, string name);
void deletePeserta(List_peserta &L,address_peserta &p);




#endif // LIST_PESERTA_H_INCLUDED

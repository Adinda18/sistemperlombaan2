#ifndef RELASI_H_INCLUDED
#define RELASI_H_INCLUDED
#include "list_lomba.h"
#include "list_peserta.h"
#include "relasi.h"

#include <iostream>
using namespace std;

#define next(P) P->next
#define first3(L) L.first3
#define child(P) P->child
#define parent(P) P->parent

typedef struct elmlist_relasi *address_relasi;

struct elmlist_relasi{
    address_relasi next;
    address_lomba child;
    address_peserta parent;
};

struct List_relasi{
    address_relasi first3;
};

void createRelasi(List_relasi &L3);
address_relasi alloRelasi(address_peserta P, address_lomba C);
address_relasi findElmn(List_relasi L3, address_peserta P, address_lomba C);
void showRelasiParentToChild(List_relasi &L3);
void showRelasiChildToParent(List_relasi &L3);
void insertAkhir(List_relasi &L3, address_relasi P);
void deleteRelasiPeserta(List_relasi &L3, address_peserta &P);
void deleteRelasiLomba(List_relasi &L3,address_lomba &P);
void PesertaLombaTertentu(List_relasi &L3, string cariLomba);
void LombaPesertaTertentu(List_relasi &L3, string id);
string Peserta_DikitLomba(List_peserta L1,List_lomba L2, List_relasi L3);
string kejuaraan_popular(List_peserta L1, List_lomba L2, List_relasi L3);


#endif // RELASI_H_INCLUDED

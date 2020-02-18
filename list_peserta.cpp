#include "list_peserta.h"
#include "relasi.h"
void createList(List_peserta &L)
{
    first(L) = NULL;
    last(L) = NULL;
}

address_peserta alokasi(string name, string id, int angkt)
{
    address_peserta P;
    P = new elmlist_peserta;
    info(P).nama = name;
    info(P).nim = id;
    info(P).angkatan = angkt;
    next(P) = NULL;
    prev(P) = NULL;
    return P;
}

void dealokasi(address_peserta &P)
{
    delete P;
};

void insertFirst(List_peserta &L, string name, string id, int angktn)
{
    address_peserta P = alokasi(name, id, angktn);
    if ((first(L) == NULL) && (last(L) ==NULL))
    {
        first(L) = P;
        last(L) = P;
    }
    else
    {
        next(P) = first(L);
        prev(first(L)) = P;
        first(L) = P;
    }
}

void insertLast(List_peserta &L, string name, string id, int angktn)
{
    address_peserta P = alokasi(name, id, angktn);
    if (first(L)== NULL)
    {
        first(L)=P;
        last(L)=P;
    }
    else
    {
        address_peserta q = last(L);
        next(q)=P;
        prev(P)=q;
        last(L)=q;
    }
};
// urut dari angkatan tua
void tambahurut(List_peserta &L, string name, string id, int angktn)
{
    if ((first(L)==NULL) || (angktn <= info(first(L)).angkatan))
    {
        insertFirst(L, name, id, angktn);
    }
    else if (angktn >= info(last(L)).angkatan)
    {
        insertLast(L, name, id, angktn);
    }
    else
    {
        address_peserta q = first(L);
        while ((q != NULL) && (angktn > info(next(q)).angkatan))
        {
            q=next(q);
        }
        address_peserta p = alokasi(name, id, angktn);
        prev(p)=q;
        next(p)=next(q);
        prev(next(p))=p;
        next(q)=p;
    }

};

void printInfo(List_peserta L)
{
    address_peserta P = first(L);
    if ((first(L) == NULL) && (last(L)=NULL))
    {
        cout << "List Peserta Kosong" << endl;
    }
    else
    {
        int i = 0;
        while (P != NULL)
        {
            i = i + 1;
            cout << "Data Peserta ke-" << i << " : " << endl;
            cout << "Nama : " << info(P).nama <<endl;
            cout << "NIM : " <<info(P).nim <<endl;
            cout << "Angkatan : " << info(P).angkatan <<endl;
            cout << endl;
            P = next(P);
        }
    }
}

address_peserta findElm(List_peserta L, string id)
{
    /**
    * IS : List_parent L mungkin kosong
    * FS : mengembalikan elemen dengan info nim = x.nim,
    * FS : mengembalikan elemen dengan info = x,
           mengembalikan Nil jika tidak ditemukan
    */
    address_peserta P = first(L);
    while ((P != NULL) && (info(P).nim != id))
    {
        P = next(P);
    }
    if (P != NULL )
    {
        return P;
    }
    else
    {
        return NULL;
    }
}
void deletePeserta(List_peserta &L,address_peserta &p)
{
    if (p==last(L))
    {
        last(L)=prev(p);
        next(prev(p))=NULL;
    }
    else if ((p == last(L)) && (p == first(L)))
    {
        first(L)=NULL;
        last(L)=NULL;
    }
    else
    {
        next(prev(p))=next(p);
        prev(next(p))=prev(p);
    }
    next(p) = NULL;
    prev(p) = NULL;
}




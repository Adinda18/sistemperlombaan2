#include "relasi.h"

using namespace std;
#include <iostream>
#include <string>

void createRelasi(List_relasi &L3)
{
    first3(L3) = NULL;
}

address_relasi alloRelasi(address_peserta P, address_lomba C)
{
    address_relasi Q = new elmlist_relasi;
    child(Q) = C;
    parent(Q) = P;
    next(Q) = NULL;
    return Q;
}

address_relasi findElmn(List_relasi L3, address_peserta P, address_lomba C)
{
    address_relasi Q = first3(L3);
    while(Q!= NULL)
    {
        if ((parent(Q)==P) && (child(Q)==C))
        {
            return Q;
        }
        else
        {
            Q = next(Q);
        }
    }
    return(Q);
}

void deleteRelasiPeserta(List_relasi &L3, address_peserta &P)
{
    address_relasi Q=first3(L3);
    address_relasi C;
        while ((Q!=NULL))
        {
            C = next(Q);
            if (parent(C)==P)
            {
                next(Q)=next(C);
                delete C;
            }
            else if (Q==first3(L3) && parent(Q)==P)
            {
                C = Q;
                first3(L3)=next(C);
                next(C)=NULL;
                delete C;
            }
            Q=next(Q);
        }

}
void deleteRelasiLomba(List_relasi &L3,address_lomba &P)
{
    address_relasi Q=first3(L3);
    address_relasi C;
        while ((Q!=NULL))
        {
            C = next(Q);
            if (child(C)==P)
            {
                next(Q)=next(C);
                delete C;
            }
            else if (Q==first3(L3) && child(Q)==P)
            {
                C = Q;
                first3(L3)=next(C);
                next(C)=NULL;
                delete C;
            }
            Q=next(Q);
        }

}

void insertAkhir(List_relasi &L3, address_relasi P)
{
    address_relasi Q = first3(L3);
    if (first3(L3)==NULL)
    {
        first3(L3) = P;
    }
    else
    {
        while(((Q) != NULL)&&(next(Q)!=NULL))
        {
            Q = next(Q);
        }
        next(Q) = P;
    }

}

void showRelasiParentToChild(List_relasi &L3)
{
    address_relasi P = first3(L3);
    int i = 1;
    while (P!=NULL)
    {
        cout<<i<<". ( "<< info(parent(P)).nim <<" )"<<" "<<info(parent(P)).nama<<" mengikuti lomba " << info(child(P))<<endl;
        P= next(P);
        i=i+1;
    }
}

void showRelasiChildToParent(List_relasi &L3)
{
    address_relasi P = first3(L3);
    while (P!=NULL)
    {
        cout <<info(child(P)) << " diikuti oleh " << info(parent(P)).nama <<endl;
        P= next(P);
    }
}

void PesertaLombaTertentu(List_relasi &L3, string cariLomba)
{
    address_relasi Q = first3(L3);
    int i = 1;
    while (Q !=NULL)
    {
        if (info(child(Q)) == cariLomba)
        {
            cout << "Peserta ke- "<<i<<" : " << info(parent(Q)).nama <<endl;
            i = i+1;
        }
        Q = next(Q);
    }
}

void LombaPesertaTertentu(List_relasi &L3, string id)
{
    address_relasi Q = first3(L3);
    int i = 1;
    while (Q != NULL)
    {
        if (info(parent(Q)).nim==id)
        {
            cout << "Lomba ke- "<<i<<" : "<< info(child(Q)) << endl;
            i = i+1;
        }
        Q = next(Q);
    }
}
string kejuaraan_popular(List_peserta L1, List_lomba L2, List_relasi L3)
{
    if (first3(L3) != NULL)
    {
        address_lomba P = first2(L2);
        address_relasi Q;
        string lombaFav;
        int b = 0;
        while (next(P) != first2(L2))
        {
            int jum = 0;
            Q = first3(L3);
            while (Q != NULL)
            {
                if (child(Q)== P)
                {
                    jum = jum+1;
                    if (b <jum )
                    {
                        b = jum;
                        lombaFav = info(child(Q));
                    }
                }
                Q = next(Q);
            }
            P =next(P);
        }
        if (next(P) == first2(L2))
        {
            int jum = 0;
            Q = first3(L3);
            while (Q != NULL)
            {
                if (child(Q)== P)
                {
                    jum = jum+1;
                    if (b <jum )
                    {
                        b = jum;
                        lombaFav = info(child(Q));
                    }
                }
                Q = next(Q);
            }
        }
        return lombaFav;
    }
    else
    {
        return "Belum ada peserta pada kejuaraan apapun";
    }
}

string Peserta_DikitLomba(List_peserta L1, List_lomba L2, List_relasi L3)
{
    if (first3(L3) != NULL)
    {
        address_peserta P = first(L1);
        address_relasi Q;
        string apatis;
        int b = 0;
        while (next(P) != NULL)
        {
            int jum = 0;
            Q = first3(L3);
            while (Q != NULL)
            {
                if (parent(Q)== P)
                {
                    jum = jum+1;
                    if (b==0)
                    {
                        b = jum;
                        apatis = info(parent(Q)).nama;
                    }
                }
                else
                {
                    if (b > jum)
                    {
                        b=jum;
                        apatis = info(parent(Q)).nama;
                    }
                }
                Q = next(Q);
            }
            P =next(P);
        }
        if (next(P)==NULL)
        {
            int jum = 0;
            Q = first3(L3);
            while (Q != NULL)
            {
                if (parent(Q)== P)
                {
                    jum = jum+1;
                    if (b==0)
                    {
                        b = jum;
                        apatis = info(parent(Q)).nama;
                    }
                }
                else
                {
                    if (b > jum)
                    {
                        b=jum;
                        apatis = info(parent(Q)).nama;
                    }
                }
                Q = next(Q);
            }
        }
        return apatis;
    }
    else
    {
        return "Tidak ada";
    }
}


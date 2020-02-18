#include "list_lomba.h"
#include "relasi.h"

void createLomba(List_lomba &L2)
{
    first2(L2) = NULL;
}

address_lomba allocate(string champ)
{
    address_lomba P;
    P = new elmlist_lomba;
    info(P) = champ;
    next(P) = NULL;

    return P;
}

void deallocate(address_lomba &P)
{
    delete P;
}

address_lomba findElem(List_lomba L2, string champ)
{
    if (first2(L2) != NULL)
    {
        address_lomba P = first2(L2);
        if (info(P) == champ)
        {
            return P;
        }
        else
        {
            P = next(P);
            while ((P != first2(L2)) && (info(P) != champ))
            {
                P = next(P);
            }
            if (P != first2(L2))
            {
                return P;
            }
            else
            {
                return NULL;
            }
        }
    }
    else
    {
        return NULL;
    }
}
void viewLomba(List_lomba L2)
{
    if (first2(L2) != NULL)
    {
        address_lomba P = first2(L2);
        int i =1;
        cout << i<< ". Kejuaraan : " << info(P) <<endl;
        P = next(P);
        while (P != first2(L2))
        {
            i=i+1;
            cout << i<< ". Kejuaraan : " << info(P) <<endl;
            P=next(P);
        }
    }
    else
    {
        cout << "List Perlombaan Masih Kosong"<<endl;
    }
}

/* insert lomba pakee insert first */
void insertLomba(List_lomba &L2, string champ)
{
    address_lomba P = allocate(champ);
    if(first2(L2) == NULL)
    {
        first2(L2) = P;
        next(P) = P;
    }
    else
    {
        address_lomba Q = first2(L2);
        while(next(Q) != first2(L2))
        {
            Q = next(Q);
        }
        next(P) = first2(L2);
        next(Q) = P;
        first2(L2) = P;
    }
}

void deleteFirst(List_lomba &L2, address_lomba &P)
{
    if (first2(L2) == NULL)
    {
        P = NULL;
    }
    else if (next(first2(L2)) == first2(L2))
    {
        P = first2(L2);
        first2(L2) = NULL;
        next(P) = NULL;
    }
    else
    {
        address_lomba Q = first2(L2);
        while (next(Q) != first2(L2))
        {
            Q = next(Q);
        }
        P = next(Q);
        first2(L2) = next(P);
        next(Q) = first2(L2);
        next(P) = NULL;
    }
}

void deleteLast(List_lomba &L2, address_lomba &P)
{
    if (first2(L2) == NULL)
    {
        P = NULL;
    }
    else if (next(first2(L2)) == first2(L2))
    {
        P = first2(L2);
        first2(L2) = NULL;
        next(P) = NULL;
    }
    else
    {
        address_lomba Q = first2(L2);
        while (next(Q) != first2(L2))
        {
            P = Q;
            Q =next(Q);
        }
        next(P) = next(Q);
        next(Q) = NULL;
    }
}

void deleteLomba(List_lomba &L2,address_lomba &P)
{
        if (P == first2(L2))  //bisa jadi dia first sendiri atau ramean, bis jd first pas ramean
        {
            deleteFirst(L2, P);
        }
        else if (next(P) == first2(L2))
        {
            deleteLast(L2, P);
        }
        else
        {
            address_lomba Q = first2(L2);
            while (next(Q) != P)
            {
                Q = next(Q);
            }
            next(Q) = next(P);
            next(P) = NULL;
        }
    }

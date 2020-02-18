#include <iostream>
#include <string>
#include "list_lomba.h"
#include "list_peserta.h"
#include "relasi.h"
#include <conio.h>

using namespace std;

int main()
{
    List_peserta L1;
    List_lomba L2;
    List_relasi L3;
    createList(L1);
    createLomba(L2);
    createRelasi(L3);
    int pilih = 0;
    string nama,nim;
    int angkatan;
    char jawab;

    string lomba;
    while (pilih==0)
    {
        cout<<"=================================================================="<<endl;
        cout<<"                     Daftar Kejuaraan Mahasiswa                   "<<endl;
        cout<<"=================================================================="<<endl;
        cout<<"========================== OFFERED MENU =========================="<<endl;
        cout<<"1. Tambah Mahasiswa."<<endl;
        cout<<"2. Tambah Kejuaraan."<<endl;
        cout<<"3. Menambahkan Peserta pada Kejuaraan."<<endl;
        cout<<"4. Hapus Peserta."<<endl;
        cout<<"5. Hapus Kejuaraan."<<endl;
        cout<<"6. Tampil Data."<<endl;
        cout<<"7. Tampil Data Kejuaraan Tertentu"<<endl;
        cout<<"8. Kejuaraan Tertentu."<<endl;

        cout<<"9. Data Kejuaraan Terpopuler dan paling sedikit."<<endl;
        cout<<endl;
        cout<<"Silahkan pilih: ";
        cin>>pilih;
        system("CLS");
        switch (pilih)
        {
        case 1:
            cout<<"Anda akan memasukkan mahasiswa ke sistem [Y/y]"<<endl;
            cin>>jawab;
            cout<<endl;
            while ((jawab=='y') || (jawab=='Y'))
            {
                system("CLS");
                cout<<"NIM: ";
                cin>>nim;
                cout<<"Nama: ";
                cin>>nama;
                cout<<"Angkatan: ";
                cin>>angkatan;
                system("CLS");
                address_peserta p;
                p=findElm(L1,nim);
                if(p==NULL)
                {
                    tambahurut(L1,nama,nim,angkatan);
                    cout<<"Siswa berhasil ditambahkan."<<endl;
                    printInfo(L1);

                }
                else
                {
                    cout<<"Siswa sudah terdaftar."<<endl;
                }
                cout<<endl;
                cout<<"Apakah anda ingin memasukan data peserta lagi? [y/Y]"<<endl;
                cin>>jawab;
                cout<<endl;
            }
            if ((jawab!='Y') || (jawab!='y'))
            {
                system("CLS");
                pilih=0;
            }
            break;
        case 2:
            cout<<"Anda akan menambahkan perlombaan ke sistem [Y/y]"<<endl;
            cin>>jawab;
            cout<<endl;
            while ((jawab=='y') || (jawab=='Y'))
            {
                system("CLS");
                cout<<"Nama Perlombaan: ";
                cin>>lomba;
                system("CLS");
                address_lomba p = findElem(L2,lomba);
                if(p==NULL)
                {
                    insertLomba(L2,lomba);
                    cout<<"Perlombaan berhasil ditambahkan."<<endl;
                    viewLomba(L2);
                }
                else
                {
                    cout<<"Perlombaan sudah terdaftar "<<endl;
                }
                cout<<endl;
                cout<<"apakah anda ingin memasukan data perlombaan lagi ? [y/Y] "<<endl;
                cin>>jawab;
                cout<<endl;
            }
            system("CLS");
            pilih=0;
            break;
        case 3:
            if ((first(L1)!= NULL)&&(first2(L2)!= NULL))
            {
                cout<<"Apakah anda ingin memasukan peserta ke perlombaan?[y/Y]"<<endl;
                cin>>jawab;
                system("CLS");
                while ((jawab=='y')||(jawab=='Y'))
                {
                    cout<<"========== NAMA - NAMA PENDAFTAR LOMBA =========="<<endl;
                    printInfo(L1);
                    cout<<endl;
                    cout<<"===== DAFTAR KEJUARAAN YANG DISELENGGARAKAN ====="<<endl;
                    viewLomba(L2);
                    cout<<endl;
                    cout<<"================================================"<<endl;
                    cout<<"Pilih nim yang akan mengikuti lomba :"<<endl;
                    cin>>nim;
                    cout<<"Pilih perlombaan yang anda inginkan:"<<endl;
                    cin>>lomba;
                    address_peserta a=findElm(L1,nim);
                    address_lomba b=findElem(L2,lomba);
                    if (a==NULL)
                    {
                        cout<<"NIM tersebut tidak ada dalam data."<<endl<<endl;
                    }
                    if (b==NULL)
                    {
                        cout<<"Lomba tersebut tidak ada dalam data."<<endl<<endl;
                    }
                    if ((a!=NULL)&&(b!=NULL))
                    {
                        address_relasi C = findElmn(L3, a, b);
                        if (C!=NULL)
                        {
                            cout <<"Peserta dengan nim tersebut sudah didaftarkan pada lomba ini."<<endl;
                        }
                        else
                        {
                            address_relasi D = alloRelasi(a,b);
                            insertAkhir(L3,D);
                            cout<<"Proses berhasil."<<endl;
                            cout<<endl;
                            cout<<"=============================================================="<<endl;
                            system("CLS");
                        }
                        showRelasiParentToChild(L3);
                    }
                    cout<<"apakah anda ingin memasukan lagi peserta ke perlombaan?[Y/y]"<<endl;
                    cin>>jawab;
                    system("CLS");
                }
                pilih=0;
            }
            else
            {
                pilih=0;
                cout<<"silahkan isi peserta atau perlombaan terlebih dahulu."<<endl;
            }
            break;
        case 4:
            cout<<"apakah anda ingin menghapus data peserta"<<endl;
            cin>>jawab;
            while((jawab=='y')||(jawab=='Y'))
            {
                cout<<"====================================================="<<endl;
                cout<<"  Data Keseluruhan Peserta & Perlombaan yang Diikuti  "<<endl;
                showRelasiParentToChild(L3);
                cout<<"Masukkan nim peserta yang akan dihapus data-datanya: "<<endl;
                cin>>nim;
                address_peserta p = findElm(L1,nim);
                if (p!=NULL)
                {
                    deleteRelasiPeserta(L3,p);
                    deletePeserta(L1,p);
                    cout<<"penghapusan data berhasil"<<endl;
                    if(first(L1) != NULL)
                    {
                        showRelasiParentToChild(L3);
                    }
                    else
                    {
                        pilih=0;
                    }
                }
                else
                {
                    cout<<"data kosong"<<endl;
                }
                cout<<"apakah anda ingin menghapus peserta lain ?"<<endl;
                cin>>jawab;
            }
            pilih=0;
            break;
        case 5:
            while((jawab=='y')||(jawab=='Y'))
            {
                cout<<"====================================================="<<endl;
                cout<<"  Data Keseluruhan Peserta & Perlombaan yang Diikuti  "<<endl;
                showRelasiParentToChild(L3);
                cout<<"Masukkan nama perlombaan yang akan dihapus datanya: "<<endl;
                cin>>lomba;
                address_lomba q;
                q=findElem(L2,lomba);
                if (q!=NULL)
                {
                    deleteRelasiLomba(L3,q);
                    deleteLomba(L2,q);
                    cout<<"penghapusan data berhasil"<<endl;
                    if (first2(L2)!=NULL)
                    {
                        showRelasiParentToChild(L3);
                    }
                    else
                    {
                        cout<<"data kosong"<<endl;
                    }
                     cout<<"apakah anda ingin menghapus peserta lain ?"<<endl;
                    cin>>jawab;
                }

                    pilih=0;
                break;
            case 6:
                cout<<"====================================================="<<endl;
                cout<<"  Data Keseluruhan Peserta & Perlombaan yang Diikuti  "<<endl;
                showRelasiParentToChild(L3);
                break;
            case 7:
                cout<<"==========================================================="<<endl;
                cout<<"====== Data Orang yang Mengikuti Perlombaan Tertentu ======"<<endl;
                cout<<endl;
                cout<<endl;
                cout<<"Masukkan kejuaraan yang akan ditampilkan para pesertanya: "<<endl;
                cin>>lomba;
                PesertaLombaTertentu(L3, lomba);
                break;
            case 8:
                cout<<"==========================================================="<<endl;
                cout<<"======= Data Perlombaan yang Diikuti Orang Tertentu ======="<<endl;
                cout<<endl;
                cout<<endl;
                cout<<"Masukkan NIM peserta yang akan ditampilkan perlombaannya : "<<endl;
                cin>>nim;
                LombaPesertaTertentu(L3, nim);
                break;
            case 9:
                cout<<"==========================================================="<<endl;
                cout<<"============= Kejuaraan yang Paling Diminati ============="<<endl;
                cout<<endl;
                cout<<endl;
                string m=kejuaraan_popular(L1,L2,L3);
                cout<<endl;
                cout<<endl;
                cout<<"==========================================================="<<endl;
                cout<<"============= Kejuaraan yang Paling Sedikit Diminati ============="<<endl;
                string n=Peserta_DikitLomba(L1,L2,L3);
                break;
            }
        }
        return 0;
    }
}

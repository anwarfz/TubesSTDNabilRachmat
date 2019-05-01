#include <iostream>
#include "TUBES.h"
using namespace std;

// nabil anwar fauzi bagian main.cpp

int main()
{
    cout<<("----------------------------------------------")<<endl;
    cout<<("--------Nabil-------------------Rachmat-------")<<endl;
    cout<<("================ Selamat Datang ==============")<<endl;
    cout<<("================  Di Instagram  ==============")<<endl;
    cout<<("----------------------------------------------")<<endl;
    cout<<("----------------------------------------------")<<endl;
    cout<<("| Log In                                      ")<<endl;
    cout<<("|  Username : ");
    string nama;
    cin>> nama;
    cout<<endl;
    cout<<endl;
    cout<<endl;
    cout<< "Hi "<<nama<< " ^_^"<<endl;
    cout<<"Apa Yang Ingin Anda Lakukan : "<<endl;
    cout<<endl;
// nabil anwar fauzi bagian main.cpp
    int pil;
    listfoto F;
    listuser U;
    infotypefoto FoBar;
    infotypefoto Foto;
    infotypeuser UsBar;
    infotypeuser Userr;
    CreateListFoto(F);
    CreateListUser(U);
    address P;
    // nabil anwar fauzi bagian main.cpp
    do{
        cout<<"  1.Menambah Foto Baru"<<endl;
        cout<<"  2.Menambah Teman Baru"<<endl;
        cout<<"  3.Menghubungkan Foto dengan Teman"<<endl;
        cout<<"  4.Menghapus Foto"<<endl;
        cout<<"  5.Menghapus Teman"<<endl;
        cout<<"  6.Menampilkan Semua Foto Dengan Tag-nya"<<endl;
        cout<<"  7.Menampilkan Foto Yang Memiliki Tag Terbanyak"<<endl;
        cout<<"  8.Menampilkan Teman dengan Tag Terbanyak"<<endl;
        cout<<"  9.Menampilkan Teman-Teman DiFoto Tertentu"<<endl;
        cout<<"  0.Exit"<<endl;
        cin>>pil;
        switch(pil){
        case 1:
            cout << "   Nama Foto Baru: ";
            cin >> FoBar;
            InsertFoto(F,AlokasiFoto(FoBar));
            break;
        case 2:
            cout << "   Nama Teman Baru: ";
            cin >> UsBar;
            InsertUser(U,AlokasiUser(UsBar));
            break;
        case 3:
            cout << "   Foto Yang Ingin Dihubungkan: ";
            cin >> Foto;
            P = CariFoto(Foto,F);
            cout << "   User Yang Ingin Dihubungkan: ";
            cin >> Userr;
            InsertRelasi(relasi(P),AlokasiRelasi(CariUser(Userr,U)));
            break;
        case 4:
            cout << "   Nama foto yang ingin di hapus: ";
            cin >> Foto;
            DeleteFoto(F, Foto);
            break;
        case 5:
            cout << "   Nama teman yang ingin di hapus: ";
            cin >> Userr;
            DeleteUser(U, Userr);
            break;
        case 6:
            cout << "   Berikut foto beserta orang yang di TAG " << endl;
            PrintAllFoto(F);
            cout << endl << endl;
            break;
        case 7:
            cout << "   Ini adalah foto dengan TAG terbanyak " << endl << "   ";
            PrintFotoTagTerbanyak(F);
            break;
        case 8:
            cout << "   Ini adalah user yang banyak di tag orang wkwkwk " << endl << "   ";
            PrintUserTagTerbanyak(U,F);
            break;
        case 9:
            cout << "   Ini adalah semua user yang yang ada di foto " << endl << "masukan foto yang ingin ditampilkan" << endl;

            cin >> Foto;
            PrintAllUserDalamSatuFoto(F,Foto);
            break;
        }
        // nabil anwar fauzi bagian main.cpp
    }while (pil != 0);


    return 0;
}


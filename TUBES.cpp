#include "TUBES.h"

void CreateListFoto(listfoto &L){// rachmat dwi putra

    first(L) = NULL;
}

void CreateListRelasi(listrelasi &L){ // rachmat dwi putra

    first(L) = NULL;
}

void CreateListUser(listuser &L){ // rachmat dwi putra

    first(L) = NULL;
}

address AlokasiFoto(infotypefoto X){ // rachmat dwi putra

    address P = new elmlistfoto;
    info(P) = X;
    next(P) = NULL;
    CreateListRelasi(relasi(P));
    return P;
}

address_user AlokasiUser(infotypeuser X){ // rachmat dwi putra

    address_user P = new elmlistuser;
    info(P) = X;
    next(P) = NULL;
    return P;
}

address_relasi AlokasiRelasi(address_user X){ // rachmat dwi putra

    address_relasi P = new elmlistrelasi;
    next(P) = NULL;
    user(P) = X;
    return P;
}

address_user CariUser(infotypeuser X,listuser L){ // rachmat dwi putra

    address_user P = first(L);
    while (P != NULL && info(P) != X){
        P = next(P);
    }
    if (info(P) == X){
        return P;
    }else{
        return NULL;
    }
}

address CariFoto(infotypefoto X, listfoto L){ // rachmat dwi putra

    address P = first(L);
    while (P != NULL && info(P) != X){
        P = next(P);
    }
    if (info(P) == X){
        return P;
    }else{
        return NULL;
    }
}

void InsertFoto(listfoto &L, address P){ // rachmat dwi putra

    next(P) = first(L);
    first(L) = P;
}

void InsertUser(listuser &L, address_user P){ // rachmat dwi putra

    next(P) = first(L);
    first(L) = P;
}

void InsertRelasi(listrelasi &L, address_relasi P){ // rachmat dwi putra

    if (P != NULL) {
    next(P) = first(L);
    first(L) = P;
    }
}

void DeleteFoto(listfoto &L,infotypefoto X){ // rachmat dwi putra

    address P = first(L);
    address Q;
    if (info(P) == X){
        first(L) = next(P);
        delete P;
    }else{
        while ((info(next(P)) != X) && (next(P) != NULL)){
            P = next(P);
        }
        if (next(P) != NULL){
            Q = next(P);
            next(P) = next(Q);
            delete Q;
        }
    }
}

void DeleteUser(listuser &L,infotypeuser X){ // rachmat dwi putra

    address_user P = first(L);
    address_user Q;
    if (info(P) == X){
        first(L) = next(P);
        delete P;
    }else{
        while ((info(next(P)) != X) && (next(P) != NULL)){
            P = next(P);
        }
        if (next(P) != NULL){
            Q = next(P);
            next(P) = next(Q);
            delete Q;
        }
    }
}

void PrintAllFoto(listfoto L){ // rachmat dwi putra

    address P = first(L);
    address_relasi R;
    while (P != NULL){
        cout << info(P) <<endl;
        R = first(relasi(P));
        while (R != NULL){
            cout << "  -" << info(user(R)) << endl;
            R = next(R);
        }
        P = next(P);
    }
}

int HitungTag (listrelasi L){ // nabil anwar fauzi
    address_relasi P = first(L);
    int jml = 0;
    while (P != NULL){
        jml++;
        P = next(P);
    }
    return jml;
}

void PrintFotoTagTerbanyak (listfoto L){ // nabil anwar fauzi
    address P = first(L);
    address Q = next(P);
    int a,b;
    a = HitungTag(relasi(P));
    while (Q != NULL){
        b = HitungTag(relasi(Q));
        if (b > a){
            P = Q;
            a = b;
        }
        Q = next(Q);
    }
    cout << info(P) << " Dengan Jumlah Tag: " << a << endl;
}

int FoundUser (listrelasi L, address_user X){ // nabil anwar fauzi
    address_relasi P = first(L);
    bool found = false;
    int jml = 0;
    while (P != NULL && found == false){
        if (user(P) == X){
            found = true;
            jml = 1;
        }
        P = next(P);
    }
    return jml;
}

void PrintUserTagTerbanyak (listuser L1, listfoto L2){ // nabil anwar fauzi
    address Q;
    address_user P = first(L1);
    int a,jmla,b,jmlb = 0;
    while (P != NULL){
        Q = first(L2);
        while (Q != NULL){
            a = FoundUser(relasi(Q),P);
            jmla = jmla + a;
            Q = next(Q);
        }
        P = next(P);
    }
    address_user R = next(P);
    while (R != NULL){
        Q = first(L2);
        while (Q != NULL){
            b = FoundUser(relasi(Q),R);
            jmlb = jmlb + b;
            Q = next(Q);
        }
        if (jmla < jmlb){
            P = R;
            jmla = jmlb;
            jmlb = 0;
        }else{
            jmlb = 0;
        }
        R = next(R);
    }
    cout << "User Dengan Tag Terbanyak: " << info(R) << endl;
}

void PrintAllUserDalamSatuFoto(listfoto L, infotypefoto X){ // nabil anwar fauzi
    address P = first(L);
    address_relasi R;
    while (P != NULL && info(P) != X){
        P = next(P);
    }
    if (info(P) == X){
        cout << "User Yang Di-Tag DiFoto " << info(P) << " : ";
        R = first(relasi(P));
        if (first(relasi(P)) == NULL){
            cout << "Tag Tidak Ada" << endl;
        }else{
            while (R != NULL){
                cout << info(user(R));
                R = next(R);
            }
        }
    }
}







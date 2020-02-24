#ifndef TIKETKERETA_H_INCLUDED
#define TIKETKERETA_H_INCLUDED

#include <iostream>
#include <stdlib.h>

#define null NULL

#define nextCustomer(C) C -> nextCustomer
#define prevCustomer(C) C -> prevCustomer
#define firstTiket(C) C -> firstTiket
#define nextKereta(K) K -> nextKereta
#define prevKereta(K) K -> prevKereta
#define usern(C) C -> usern
#define noIdentitas(C) C -> noIdentitas
#define name(C) C -> name
#define sisaTiket(K) K -> sisaTiket
#define hargaTiket(K) K -> hargaTiket
#define tujuan(K) K -> tujuan
#define Tiket(T) T -> Tiket
#define nextTiket(T) T -> nextTiket
#define firstCustomer(P) P.firstCustomer
#define firstKereta(V) V.firstKereta

using namespace std;

typedef struct elmCustomer *adrCustomer;
typedef struct elmKereta *adrKereta;
typedef struct elmTiket *adrTiket;

struct elmCustomer{
    string usern;
    string noIdentitas;
    string name;
    adrCustomer nextCustomer;
    adrCustomer prevCustomer;
    adrTiket firstTiket;

};

struct elmKereta{
    int sisaTiket;
    int hargaTiket;
    string tujuan;
    adrKereta nextKereta;
    adrKereta prevKereta;
};

struct elmTiket{
    adrKereta Tiket;
    adrTiket nextTiket;
};

struct Customer{
    adrCustomer firstCustomer;
};

struct Kereta{
    adrKereta firstKereta;
};

adrCustomer Login (Customer C, string user);
void Register (Customer &C);
adrKereta createDataKereta (string tujuan, int sisa, int harga);
void addDataKereta (Kereta &K, string tujuan, int sisa, int harga);
adrTiket buatTiket ();
adrKereta searchTujuan (Kereta K, string tujuan);
void beliTiket (Customer &C, Kereta &K, adrCustomer &Q, adrKereta &R);
adrCustomer searchCustomer (Customer C, string usern);
void updateDataC (Customer &C, adrCustomer &Q);
void liatTujuan (Kereta K);
void liatDataC (Customer C);
void deleteCustomer (Customer &C, adrCustomer &P);
void historyCustomer (Customer C);
void hapusHistory (Customer &C, adrCustomer P);

#endif

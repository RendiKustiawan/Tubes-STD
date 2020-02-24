#include "Tiket.h"

adrCustomer Login (Customer C, string user){
    if (firstCustomer(C) == null)
        return null;
    else{
        adrCustomer P = searchCustomer(C, user);
        return P;
    }
}

void Register (Customer &C){
    string usern, name, nomor;

    cout << "Username: "; cin >> usern;
    cout << "Name: "; cin.ignore(); getline(cin, name);
    cout << "Nomor identitas: "; cin >> nomor;

    adrCustomer P, Q;
    P = new elmCustomer;
    Q = searchCustomer(C, usern);

    nextCustomer(P) = null;
    prevCustomer(P) = null;
    firstTiket(P) = null;

    if (Q == null){
        usern(P) = usern;
        name(P) = name;
        noIdentitas(P) = nomor;
    }
    else{
        while (Q != null){
            cout << "\nUsername sudah dipakai. Silahkan memasukkan username lain.\n\n";
            cout << "Username: "; cin >> usern;
            Q = searchCustomer(C, usern);
        }
        cout << "Name: "; cin >> name;
        cout << "Nomor identitas: "; cin >> nomor;
        usern(P) = usern;
        name(P) = name;
        noIdentitas(P) = nomor;
    }

    if (firstCustomer(C) != null){
        nextCustomer(P) = firstCustomer(C);
        prevCustomer(firstCustomer(C)) = P;
    }
    firstCustomer(C) = P;
}

adrKereta createDataKereta (string tujuan, int sisa, int harga){
    adrKereta P = new elmKereta;
    tujuan(P) = tujuan;
    sisaTiket(P) = sisa;
    hargaTiket(P) = harga;
    nextKereta(P) = null;
    prevKereta(P) = null;
    return P;


}

void addDataKereta (Kereta &K, string tujuan, int sisa, int harga){
    adrKereta P = createDataKereta(tujuan, sisa, harga);

    if (firstKereta(K) != null){
        nextKereta(P) = firstKereta(K);
        prevKereta(firstKereta(K)) = P;
    }
    firstKereta(K) = P;

}

adrTiket buatTiket (){
    adrTiket P = new elmTiket;
    Tiket(P) = null;
    nextTiket(P) = null;
    return P;
}

adrKereta searchTujuan (Kereta K, string tujuan){
    adrKereta P = firstKereta(K);
    while (P != null && tujuan != tujuan(P))
        P = nextKereta(P);
    return P;
}

void beliTiket (Customer &C, Kereta &K, adrCustomer &Q, adrKereta &R){
    adrTiket P = buatTiket();

    if (firstTiket(Q) != null)
        nextTiket(P) = firstTiket(Q);
    firstTiket(Q) = P;
    Tiket(P) = R;
    sisaTiket(Tiket(P))--;
}

adrCustomer searchCustomer (Customer C, string noIdentitas){
    adrCustomer P = firstCustomer(C);

    while (P != null && noIdentitas!= noIdentitas(P))
        P = nextCustomer(P);
    return P;
}

void updateDataC (Customer &C, adrCustomer &Q){

    if (Q == null){
        cout << "\nData Tidak Ditemukan.\n\n";
    }
    else{
        string p, q, r;
        cout << "Username: "; cin >> p;
        cout << "Nama: "; cin >> q;
        cout << "No Identitas: "; cin >> r;

        usern(Q) = p;
        name(Q) = q;
        noIdentitas(Q) = r;
    }
}

void liatTujuan (Kereta K){
    adrKereta P = firstKereta(K);

    cout << "Tujuan\t|\tHarga tiket\t|\tSisa tiket\n\n";
    while (P != null){
        cout << tujuan(P) << "\t|\t" << hargaTiket(P) << "\t\t|\t" << sisaTiket(P);
        cout << "\n---------------------------------------------------------------\n";
        P = nextKereta(P);
    }
    cout << endl;
}

void liatDataC (Customer C){
      string user;

    cout << "Masukkan username: "; cin >> user;

    adrCustomer P = Login(C, user);

    if (P == null){
        cout << "\nData Customer Tidak Ditemukan.\n\n";
    }
    else{
        cout << "Nama: " << name(P) << endl;
        cout << "No Identitas: " << noIdentitas(P) << "\n\n";
    }
}

void deleteCustomer (Customer &C, adrCustomer &P){
    if (P == null)
        cout << "Data akun tidak ditemukan.\n";
    else{
        if (nextCustomer(firstCustomer(C)) == null){
            firstCustomer(C) = null;
        }
        else if (P == firstCustomer(C)){
            firstCustomer(C) = nextCustomer(P);
            prevCustomer(nextCustomer(P)) = null;
            nextCustomer(P) = null;
        }
        else if (nextCustomer(P) == null){
            nextCustomer(prevCustomer(P)) = null;
            prevCustomer(P) = null;
        }
        else{
            prevCustomer(nextCustomer(P)) = prevCustomer(P);
            nextCustomer(prevCustomer(P)) = nextCustomer(P);
            nextCustomer(P) = null;
            prevCustomer(P) = null;
        }
    }
}

void historyCustomer (Customer C){
    string user, jawaban;

    cout << "Masukkan username: "; cin >> user;

    adrCustomer P = Login(C, user);

    if (P == null)
        cout << "\nAkun tidak ditemukan.\n\n";
    else{
        if (firstTiket(P) == null)
            cout << "\nTidak ada history pembelian.\n\n";
        else{
            adrTiket T = firstTiket(P);

            cout << "\nTujuan\t|\tHarga tiket\n\n";
            while (T != null){
                cout << tujuan(Tiket(T)) << "\t|\t" << hargaTiket(Tiket(T)) << "\n---------------------------------\n";
                T = nextTiket(T);
            }
            cout << "\nIngin menghapus history (ya/tidak)? "; cin >> jawaban;
            if (jawaban == "ya"){
                hapusHistory(C, P);
                cout << "\nPenghapusan berhasil.\n\n";
            }
            else if (jawaban == "tidak")
                cout << "\nPenghapusan dibatalkan.\n\n";
        }
    }
}

void hapusHistory (Customer &C, adrCustomer P){
    adrTiket T = firstTiket(P);

    while (firstTiket(P) != null){
        T = firstTiket(P);
        firstTiket(P) = nextTiket(T);
        delete T;
    }
}

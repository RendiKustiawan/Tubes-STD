#include "Tiket.h"

int main(){
    Customer C;
    Kereta K;

    firstCustomer(C) = null;
    firstKereta(K) = null;

    addDataKereta(K, "Malang", 260000, 100);
    addDataKereta(K, "Subang", 200000, 100);
    addDataKereta(K, "Cirebon", 165000, 100);
    addDataKereta(K, "Jakarta", 110000, 100);
    addDataKereta(K, "Ciamis", 90000, 100);
    addDataKereta(K, "Cimahi", 80000, 100);

    adrCustomer P, A;
    adrKereta Q;

    int nmr;
    string user, tujuan, kepastian;

    do{
        cout << "1. Liat tujuan\t\t\t\t\t\t\t\t\t\t\t===============\n";
        cout << "2. Beli tiket\t\t\t\t\t\t\t\t\t\t\t=KERETA API RD=\n";
        cout << "3. Register\t\t\t\t\t\t\t\t\t\t\t===============\n";
        cout << "4. Data pelanggan (Liat data / Update data / Hapus data / History pembelian)\n";
        cout << "0. Keluar\n";
        cout << "Masukkan pilihan: "; cin >> nmr; system("cls");

        switch (nmr){
            case 1:{
                liatTujuan(K);
                system("pause");
                system("cls"); break;
            }
            case 2:{
                cout << "Masukkan username: "; cin >> user;

                P = Login(C, user);

                if (P == null)
                    cout << "\nAnda belum memiliki akun. Silahkan pilih menu 3 untuk membuat akun.\n\n";
                else{
                    cout << "Masukkan tujuan: "; cin >> tujuan;

                    Q = searchTujuan(K, tujuan);

                    if (Q == null)
                        cout << "\nTujuan belum tersedia di KERETA API RD atau Huruf pertama tidak kapital.\n\n";
                    else{
                        cout << endl << tujuan(Q) << " | " << hargaTiket(Q) << " | " << sisaTiket(Q);
                        cout << "\n\nAnda yakin membeli (ya/tidak)? ";
                        cin >> kepastian;
                        if (kepastian == "ya"){
                            beliTiket(C, K, P, Q);
                            cout << "\nPembelian berhasil.\n\n";
                        }
                        else
                            cout << "\nPembelian dibatalkan.\n\n";
                    }
                }
                system("pause");
                system("cls"); break;
            }
            case 3:{
                Register(C); cout << endl;
                system("pause");
                system("cls"); break;
            }
            case 4:{
                int a;
                cout << "1. Lihat data\n";
                cout << "2. Update data\n";
                cout << "3. Hapus data\n";
                cout << "4. History pembelian\nMasukkan pilihan: "; cin >> a;
                system("cls");
                if (a == 1){
                    liatDataC(C);
                    system("pause");
                    system("cls"); break;
                }
                else if (a == 2){
                    cout << "Masukkan username: "; cin >> user;
                    A = Login(C, user);
                    updateDataC(C, A);
                    system("pause");
                    system("cls"); break;
                }
                else if (a == 3){
                    cout << "Masukkan username: "; cin >> user;

                    adrCustomer Z = Login(C, user);

                    if (Z == null)
                        cout << "\nAkun tidak ditemukan.\n\n";
                    else{
                        cout << endl << usern(Z) << " | " << name(Z) << " | " << noIdentitas(Z);
                        cout << "\n\nAnda yakin akan menghapus akun ini (ya/tidak)? "; cin >> kepastian;
                        if (kepastian == "ya"){
                            deleteCustomer(C, Z);
                            cout << "\nAkun berhasil dihapus.\n\n";
                        }
                        else{
                            cout << "\nPenghapusan dibatalkan.\n\n";
                        }
                    }
                }
                else if (a == 4){
                historyCustomer(C);
                system("pause");
                system("cls"); break;
                }
                system("pause");
                system("cls"); break;
            }
            default:{
                cout << "Terimakasih sudah percaya kepada KERETA API RD.\n\n";
                system("pause"); system("cls"); break;
            }
        }
    } while (nmr != 0);


    return 0;
}

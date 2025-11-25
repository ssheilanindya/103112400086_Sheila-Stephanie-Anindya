#include "soal1.h"
#include <iostream>

using namespace std;

int main() {
    list L;
    createList(L);

    int pilihan;
    string nama;

    do {
        cout << "Menu: 1 insert, 2 delete, 3 view, 4 hitung genap, 0 exit\n";
        cin >> pilihan;

        if (pilihan == 1) {
            cout << "Masukkan nama: ";
            cin >> nama;
            insertAkhir(L, nama);
        }
        else if (pilihan == 2) {
            cout << "Masukkan nama untuk delete: ";
            cin >> nama;
            deleteNama(L, nama);
        }
        else if (pilihan == 3) {
            viewList(L);
        }
        else if (pilihan == 4) {
            cout << "Jumlah nama dengan huruf genap: " << hitungGenap(L) << endl;
        }

    } while (pilihan != 0);

    return 0;
}

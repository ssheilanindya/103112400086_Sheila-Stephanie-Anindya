#include "doublyList.h"

int main() {
    List L;
    CreateList(L);

    int n;

    cout << "masukkan jumlah kendaraan : ";
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        infotype x;

        cout << "\nmasukkan nomor polisi : ";
        cin >> x.nopol;

        cout << "masukkan warna kendaraan : ";
        cin >> x.warna;

        cout << "masukkan tahun kendaraan : ";
        cin >> x.thnBuat;

        if (searchByNopol(L, x.nopol) != Nil) {
            cout << "nomor polisi sudah terdaftar\n";
            i--;
            continue;
        }

        address P = alokasi(x);
        insertFirst(L, P);
    }

    printInfo(L);
    return 0;
}

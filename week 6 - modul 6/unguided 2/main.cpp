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
            cout << "nomor polisi sudah terdaftar!\n";
            i--;
            continue;
        }

        address P = alokasi(x);
        insertFirst(L, P);
    }

    printInfo(L);

    // cari elemen berdasarkan nopol
    infotype cari;
    cout << "\nmasukkan nomor polisi yang dicari : ";
    cin >> cari.nopol;

    address hasil = findElm(L, cari);
    if (hasil != Nil) {
        cout << "\nnomor polisi : " << hasil -> info.nopol << endl;
        cout << "warna        : " << hasil -> info.warna << endl;
        cout << "tahun        : " << hasil -> info.thnBuat << endl;
    } else {
        cout << "\ndata tidak ditemukan!" << endl;
    }

    return 0;
}

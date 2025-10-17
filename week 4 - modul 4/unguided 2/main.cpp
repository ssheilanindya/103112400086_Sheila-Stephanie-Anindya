// main.cpp

#include "singlylist.h"
#include <iostream>

using namespace std;

int main() {
    List L;
    address P1, P2, P3, P4, P5, P;

    CreateList(L);

    P1 = alokasi(2);
    insertFirst(L, P1);

    P2 = alokasi(0);
    insertFirst(L, P2);

    P3 = alokasi(8);
    insertFirst(L, P3);

    P4 = alokasi(12);
    insertFirst(L, P4);

    P5 = alokasi(9);
    insertFirst(L, P5);

    // hapus node 9
    deleteFirst(L, P);
    dealokasi(P);

    // hapus node 2
    deleteLast(L, P);
    dealokasi(P);

    //  hapus node 8
    address Prec = L.First; 
    deleteAfter(L, Prec, P);
    dealokasi(P);

    printInfo(L);
    cout << "jumlah node : " << nbList(L) << endl;

    // hapus semua node
    deleteList(L);
    cout << "jumlah node : " << nbList(L) << endl;

    return 0;
}

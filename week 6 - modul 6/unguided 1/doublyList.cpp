#include "doublyList.h"

void CreateList(List &L) {
    L.first = Nil;
    L.last = Nil;
}

address alokasi(infotype x) {
    address P = new ElmList;
    P -> info = x;
    P -> next = Nil;
    P -> prev = Nil;
    return P;
}

void dealokasi(address P) {
    delete P;
}

void insertFirst(List &L, address P) {
    if (L.first == Nil) {
        L.first = P;
        L.last = P;
    } else {
        P -> next = L.first;
        L.first -> prev = P;
        L.first = P;
    }
}

address searchByNopol(List L, string nopol) {
    address P = L.first;
    while (P != Nil) {
        if (P -> info.nopol == nopol)
            return P;
        P = P -> next;
    }
    return Nil;
}

void printInfo(List L) {
    cout << "\nDATA LIST 1" << endl;
    address P = L.first;
    while (P != Nil) {
        cout << "\nno polisi : " << P -> info.nopol << endl;
        cout << "warna     : " << P -> info.warna << endl;
        cout << "tahun     : " << P -> info.thnBuat << endl;
        P = P -> next;
    }
}

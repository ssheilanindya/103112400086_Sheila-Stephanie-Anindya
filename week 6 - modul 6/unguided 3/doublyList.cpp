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

address findElm(List L, infotype x) {
    address P = L.first;
    while (P != Nil) {
        if (P -> info.nopol == x.nopol) {
            return P; // ketemu
        }
        P = P -> next;
    }
    return Nil; // gak ketemu
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

void deleteFirst(List &L, address &P) {
    if (L.first == Nil) {
        P = Nil;
        cout << "list kosong" << endl;
    } else if (L.first == L.last) {
        P = L.first;
        L.first = Nil;
        L.last = Nil;
    } else {
        P = L.first;
        L.first = L.first -> next;
        L.first -> prev = Nil;
        P -> next = Nil;
    }
}

void deleteLast(List &L, address &P) {
    if (L.first == Nil) {
        P = Nil;
        cout << "list kosong" << endl;
    } else if (L.first == L.last) {
        P = L.last;
        L.first = Nil;
        L.last = Nil;
    } else {
        P = L.last;
        L.last = L.last -> prev;
        L.last -> next = Nil;
        P -> prev = Nil;
    }
}

void deleteAfter(address Prec, address &P) {
    if (Prec == Nil || Prec -> next == Nil) {
        P = Nil;
        cout << "tidak ada elemen setelahnya" << endl;
    } else {
        P = Prec -> next;
        Prec -> next = P -> next;
        if (P -> next != Nil) {
            P -> next -> prev = Prec;
        }
        P -> next = Nil;
        P -> prev = Nil;
    }
}

void deleteByNopol(List &L, string nopol) {
    address P = searchByNopol(L, nopol);

    if (P == Nil) {
        cout << "data dengan nomor polisi " << nopol << " tidak ditemukan" << endl;
        return;
    }

    // hapus berdasarkan urutan
    if (P == L.first) {
        deleteFirst(L, P);
    } else if (P == L.last) {
        deleteLast(L, P);
    } else {
        deleteAfter(P -> prev, P);
    }

    cout << "data dengan nomor polisi " << nopol << " berhasil dihapus" << endl;
    dealokasi(P);
}

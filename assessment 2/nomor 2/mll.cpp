#include "mll.h"

void createListParent(listParent &L) {
    L.first = nullptr;
    L.last = nullptr;
}

void createListChildl(listChild &L) {
    L.first = nullptr;
    L.last = nullptr;
}

nodeParent* alokasiNodeParent(string id, string nama) {
    nodeParent *P = new nodeParent;
    P -> IDgenre = id;
    P -> namaGenre = nama;
    P -> next = nullptr;
    P -> prev = nullptr;
    createListChild(P -> childs);
    return P;
}

nodeChild* alokasiNodeChild(string id, string judul, int durasi, int tahun, float rating) {
    nodeChild *P = new nodeChild;
    P -> IDfilm = id;
    P -> judulFilm = judul;
    P -> durasiFilm = durasi;
    P -> tahunTayang = tahun;
    P -> ratingFilm = rating;
    P -> next = nullptr;
    P -> prev = nullptr;
    return P;
}

void dealokasiNodeParent(nodeParent *&P) { 
    delete P; 
    P = nullptr; 
}
void dealokasiNodeChild(nodeChild *&P) { 
    delete P; 
    P = nullptr; 
}

void insertFirstParent(listParent &L, nodeParent *P) {
    if (L.first == nullptr) {
        L.first = L.last = P;
    } else {
        P -> next = L.first;
        L.first -> prev = P;
        L.first = P;
    }
}

void insertLastChild(listChild &L, nodeChild *P) {
    if (L.first == nullptr) {
        L.first = L.last = P;
    } else {
        P -> prev = L.last;
        L.last -> next = P;
        L.last = P;
    }
}

void hapusListChild(listChild &L) {
    nodeChild *P = L.first;
    while (P != nullptr) {
        nodeChild *temp = P;
        P = P -> next;
        dealokasiNodeChild(temp);
    }
    L.first = L.last = nullptr;
}

void deleteAfterParent(listParent &L, nodeParent *prec, nodeParent *&P) {
    if (prec == nullptr || prec -> next == nullptr) {
        P = nullptr;
        return;
    }
    P = prec -> next;
    hapusListChild(P -> childs);
    if (P == L.last) {
        L.last = prec;
        prec -> next = nullptr;
    } else {
        prec -> next = P -> next;
    }
    P -> next = P -> prev = nullptr;
}

void searchFilmByRatingRange(listParent L, float minRate, float maxRate) {
    nodeParent *P = L.first;
    int posP = 1;
    while (P != nullptr) {
        nodeChild *C = P -> childs.first;
        int posC = 1;
        while (C != nullptr) {
            if (C -> ratingFilm >= minRate && C -> ratingFilm <= maxRate) {
                cout << "data film ditemukan pada list child dari node parent " << P -> namaGenre << " pada posisi ke- " << posC << "!" << endl;
                cout << "--- data film (child) ---" << endl;
                cout << "judul film : " << C -> judulFilm << endl;
                cout << "posisi dalam list child : posisi ke- " << posC << endl;
                cout << "ID film : " << C -> IDfilm << endl;
                cout << "durasi film : " << C -> durasiFilm << " menit" << endl;
                cout << "tahun tayang : " << C -> tahunTayang << endl;
                cout << "rating film : " << C -> ratingFilm << endl;
                cout << "-------------------------" << endl;
                cout << "--- data genre (parent) ---" << endl;
                cout << "ID genre : " << P -> IDgenre << endl;
                cout << "posisi dalam list parent : posisi ke- " << posP << endl;
                cout << "nama genre : " << P -> namaGenre << endl;
                cout << "========================================" << endl;
            }
            C = C -> next;
            posC++;
        }
        P = P -> next;
        posP++;
    }
}

void printStrukturMLL(listParent L) {
    nodeParent *P = L.first;
    int countP = 1;
    while (P != nullptr) {
        cout << "=== parent " << countP << " ===" << endl;
        cout << "ID genre : " << P -> IDgenre << endl;
        cout << "nama genre : " << P -> namaGenre << endl;
        nodeChild *C = P -> childs.first;
        int countC = 1;
        while (C != nullptr) {
            cout << " - child " << countC << " :" << endl;
            cout << "   ID film : " << C->IDfilm << endl;
            cout << "   judul film : " << C -> judulFilm << endl;
            cout << "   durasi film : " << C -> durasiFilm << " menit" << endl;
            cout << "   tahun tayang : " << C -> tahunTayang << endl;
            cout << "   rating film : " << C -> ratingFilm << endl;
            C = C -> next;
            countC++;
        }
        cout << "--------------------------" << endl;
        P = P -> next;
        countP++;
    }
}
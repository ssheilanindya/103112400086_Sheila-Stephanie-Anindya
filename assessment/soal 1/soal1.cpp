#include "soal1.h"

void createList(list &L) {
    L.first = nullptr;
}

void insertAkhir(list &L, string nama) {
    node* baru = new node;
    baru -> nama = nama;
    baru -> next = nullptr;

    if (L.first == nullptr) {
        L.first = baru;
    } else {
        node* temp = L.first;
        while (temp -> next != nullptr) temp = temp -> next;
        temp -> next = baru;
    }
}

void deleteNama(list &L, string target) {
    if (L.first == nullptr) return;

    if (L.first->nama == target) {
        node* dealokasi = L.first;
        L.first = L.first->next;
        delete dealokasi;
        return;
    }

    node* temp = L.first;
    while (temp -> next != nullptr && temp -> next -> nama != target) {
        temp = temp -> next;
    }

    if (temp -> next != nullptr) {
        node* dealokasi = temp->next;
        temp->next = temp->next->next;
        delete dealokasi;
    }
}

void viewList(list L) {
    if (L.first == nullptr) {
        cout << "List kosong\n";
        return;
    }

    node* temp = L.first;
    while (temp != nullptr) {
        cout << temp->nama << " ";
        temp = temp->next;
    }
    cout << endl;
}

int hitungGenap(list L) {
    int count = 0;
    node* temp = L.first;

    while (temp != nullptr) {
        if (temp -> nama.length() % 2 == 0) count++;
        temp = temp -> next;
    }
    return count;
}

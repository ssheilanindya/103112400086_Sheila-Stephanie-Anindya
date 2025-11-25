#include "soal4.h"
#include <iostream>

using namespace std;

bool isEmpty(queueEkspedisi &Q) {
    return Q.head == -1 && Q.tail == -1;
}

bool isFull(queueEkspedisi &Q) {
    return Q.tail == MAX_QUEUE - 1;
}

void createQueue(queueEkspedisi &Q) {
    Q.head = Q.tail = -1;
}

void enqueue(queueEkspedisi &Q, paket newPaket) {
    if (isFull(Q)) {
        cout << "queue penuh\n";
        return;
    }

    if (isEmpty(Q)) {
        Q.head = Q.tail = 0;
    } else {
        Q.tail++;
    }

    Q.dataPaket[Q.tail] = newPaket;
}

void dequeue(queueEkspedisi &Q) {
    if (isEmpty(Q)) {
        cout << "queue kosong\n";
        return;
    }

    for (int i = Q.head; i < Q.tail; i++) {
        Q.dataPaket[i] = Q.dataPaket[i + 1];
    }

    Q.tail--;

    if (Q.tail < Q.head) {
        Q.head = Q.tail = -1;
    }
}

void viewQueue(queueEkspedisi &Q) {
    if (isEmpty(Q)) {
        cout << "queue kosong!\n";
        return;
    }

    for (int i = Q.head; i <= Q.tail; i++) {
        cout << "paket " << (i + 1) << ":\n";
        cout << "kode resi      : " << Q.dataPaket[i].kodeResi << endl;
        cout << "pama pengirim  : " << Q.dataPaket[i].namaPengirim << endl;
        cout << "berat barang   : " << Q.dataPaket[i].berat << endl;
        cout << "tujuan         : " << Q.dataPaket[i].tujuan << endl;
    }
}

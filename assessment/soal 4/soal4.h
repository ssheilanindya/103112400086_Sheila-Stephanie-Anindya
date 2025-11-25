#ifndef SOAL4_H
#define SOAL4_H

#include <string>
using namespace std;

#define MAX_QUEUE 5

struct paket {
    string kodeResi;
    string namaPengirim;
    int    berat;
    string tujuan;   
};

struct queueEkspedisi {
    paket dataPaket[MAX_QUEUE];
    int head;
    int tail;
};

bool isEmpty(queueEkspedisi &Q);
bool isFull(queueEkspedisi &Q);
void createQueue(queueEkspedisi &Q);
void enqueue(queueEkspedisi &Q, paket newPaket);
void dequeue(queueEkspedisi &Q);
void viewQueue(queueEkspedisi &Q);
void totalBiayaPengiriman(queueEkspedisi &Q);

#endif
// header ugard digunakan untuk mencegah header file yang sama di-include lebih dari satu kali
#ifndef LISTBUAH_H
#define LISTBUAH_H
#define Nil nullptr

#include <iostream>
using namespace std;

struct buah {
    string nama;
    int jumlah;
    float harga;
};

typedef buah dataBuah; // memberikan nama alias dataBuah pada struct buah

typedef struct node*address; // mendefinisikan address sebagai pointer ke struct node

struct node { // node untuk isi dari linked listnya, isi setiap node adalah dataBuah dan pointer ke node selanjutnya
    dataBuah isidata;
    address next;
};

struct linkedlist { // mendefinisikan linked list dengan pointer ke node pertama 
    address first;
};

// semua function & prosedur yang berhubungan dengan linked list
// materi modul 4

bool isEmpty(linkedlist List);
void createList(linkedlist &List);
address alokasi(string nama, int jumlah, float harga);
void dealokasi(address &node);
void printList(linkedlist List);
void insetAfter(linkedlist &List, address nodeBaru, address prev);
void insertLast(linkedlist &List, address nodeBaru);
void delFirst(linkedlist &List);
void delLast(linkedlist &List);
void delAfter(linkedlist &List, address nodeHapus, address nodePrev);
int nbList(linkedlist List);
void deleteList(linkedlist &List);

// Materi modul 5 (part 1 - update)
void updateFirst(linkedlist &List);
void updateLast(linkedlist &List);
void updateAfter(linkedlist &List, address prev);

#endif // LISTBUAH_H
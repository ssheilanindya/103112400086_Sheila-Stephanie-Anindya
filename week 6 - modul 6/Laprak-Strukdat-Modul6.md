# <h1 align="center">Laporan Praktikum Modul 6 - Doubly Linked List (Bagian Kedua) </h1>
<p align="center"> Sheila Stephanie Anindya - 103112400086 </p>

## Dasar Teori

### A. Linked List <br/>
Linked   List   adalah struktur   data   linier,   di   mana elemen  tidak  disimpan  di  lokasi  yang  berdekatan,  tetapi ditautkan  menggunakan  pointer.  Linked  List  membentuk rangkaian   node   yang   terhubung,   dimana   setiap   node menyimpan    data    dan    alamat    dari    node    berikutnya. (GeeksforGeeks,  Understanding  the  basics  of  Linked  List, 2023)[1]
Terdapat 2 linked list dalam pemrograman, yaitu Singly Linked List dan Doubly Linked List. Salah satu kelemahan single linked list adalah pointer (penunjuk) hanya dapat bergerak satu arah saja, maju/ mundur, atau kanan/kiri sehingga pencarian data pada single linked list hanya dapat bergerak dalam satu arah saja. Untuk mengatasi kelemahan tersebut, terdapat metode doubly linked list. Linked list ini dikenal dengan nama Linked list berpointer Ganda atau Double Linked List. [4]

### B. Doubly Linked List <br/>
Doubly Linked List (DLL) merupakan struktur data yang terdiri dari node-node yang terhubung secara berpasangan, di mana setiap node memiliki pointer ke node sebelumnya (prev) dan node berikutnya (next).[2] Berbeda dengan Single Linked List (SLL) yang hanya memiliki satu pointer yang menunjuk ke node berikutnya. Keunggulan DLL dibandingkan SLL terletak pada kemudahan dalam melakukan operasi penyisipan dan penghapusan data, karena DLL memungkinkan navigasi dua arahdalamdaftar.penggunaan algoritma DLL untuk operasi insertion dan deletion. Algoritma insertion pada DLL dapat dilakukan di awal list (depan), di akhir list (belakang), atau di tengah list. Algoritma deletion pada DLL juga dapat dilakukan di awal list, di akhir list, atauditengahlist. [2]
Doubly linked list juga menggunakan dua buah successor utama yang terdapat pada list, yaitu first (successor yang menunjuk elemen pertama) dan last (susesor yang menunjuk elemen terakhir list). Komponen-komponen dalam Doubly linked list: 
#### 1. First
pointer pada list yang menunjuk pada elemen pertama list. [3]
#### 2. Last
pointer pada list yang menunjuk pada elemen terakhir list.[3]
#### 3. Next
pointer pada elemen sebagai successor yang menunjuk pada elemen didepannya. [3]
#### 4. Prev
pointer pada elemen sebagai successor yang menunjuk pada elemen dibelakangnya. [3]

## Guided 

### 1. List Makanan

```C++
// listMakanan.h
#ifndef LISTMAKANAN_H
#define LISTMAKANAN_H
#define Nil NULL

#include<iostream>
using namespace std;

struct makanan{
    string nama;
    string jenis; 
    float harga;
    float rating; 
};

typedef makanan dataMakanan;

typedef struct node *address;

struct node{
    dataMakanan isidata;
    address next;
    address prev;
};

struct linkedlist{
    address first;
    address last;
};

bool isEmpty(linkedlist List);
void createList(linkedlist &List);
address alokasi(string nama, string jenis, float harga, float rating);
void dealokasi(address &node);

void insertFirst(linkedlist &List, address nodeBaru);
void insertLast(linkedlist &List, address nodeBaru);
void insertAfter(linkedlist &List, address nodeBaru, address Prev);
void insertBefore(linkedlist &List, address nodeBaru, address nodeNext);

void printList(linkedlist List);

void updateFirst(linkedlist List);
void updateLast(linkedlist List);
void updateAfter(linkedlist List, address prev);
void updateBefore(linkedlist List, address nodeNext);

#endif

// listMakanan.cpp
#include "listMakanan.h"
#include <iostream>
using namespace std;

bool isEmpty(linkedlist List) {
    if(List.first == Nil){
        return true; 
    } else {
        return false;
    }
}

void createList(linkedlist &List) {
    List.first = Nil;
    List.last = Nil;
}

address alokasi(string nama, string jenis, float harga, float rating) { 
    address nodeBaru = new node;
    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.jenis = jenis; 
    nodeBaru->isidata.harga = harga;
    nodeBaru->isidata.rating =  rating;
    nodeBaru->next = Nil;
    nodeBaru->prev = Nil;
    return nodeBaru;
}

void dealokasi(address &node) {
    node->next = Nil;
    node->prev = Nil;
    delete node;
}

void insertFirst(linkedlist &List, address nodeBaru){
    if (isEmpty(List)) {
        List.first = List.last = nodeBaru;
    } else {
        nodeBaru->next = List.first;
        List.first->prev = nodeBaru;
        List.first = nodeBaru;
    }
    cout << "Node " << nodeBaru->isidata.nama << " berhasil ditambahkan sebagai node pertama list" << endl;
}

void insertLast(linkedlist &List, address nodeBaru){
    if(isEmpty(List) == true){
        List.first = List.last = nodeBaru;
    } else {
        nodeBaru->prev = List.last;
        List.last->next = nodeBaru;
        List.last = nodeBaru;
    }
    cout << "Node " << nodeBaru->isidata.nama << " berhasil ditambahkan sebagai node terakhir list" << endl;
}

void insertAfter(linkedlist &List, address nodeBaru, address nodePrev){
    if(isEmpty(List) == true){
        List.first = List.last = nodeBaru;
    } else {
        if (nodePrev != Nil){
            if(nodePrev == List.last){
                insertLast(List, nodeBaru);
            } else {
                nodeBaru->next = nodePrev->next;
                nodeBaru->prev = nodePrev;
                (nodePrev->next)->prev = nodeBaru;
                nodePrev->next = nodeBaru;
                cout << "Node " << nodeBaru->isidata.nama << " berhasil ditambahkan setelah node " << nodePrev->isidata.nama << endl;
            }
        } else {
            cout << "node sebelumnya (nodePrev) tidak valid!" << endl;
        }
    }
}

void insertBefore(linkedlist &List, address nodeBaru, address nodeNext){
    if(isEmpty(List) == true){
        List.first = List.last = nodeBaru;
    } else {
        if (nodeNext != Nil){
            if(nodeNext == List.first){
                insertFirst(List, nodeBaru);
            } else {
                nodeBaru->next = nodeNext;
                nodeBaru->prev = nodeNext->prev;
                (nodeNext->prev)->next = nodeBaru;
                nodeNext->prev = nodeBaru;
                cout << "Node " << nodeBaru->isidata.nama << " berhasil ditambahkan sebelum node " << nodeNext->isidata.nama << endl;
            }
        } else {
            cout << "node setelahnya (nodeNext) tidak valid!" << endl;
        }
    }
}

void printList(linkedlist List) {
    if (isEmpty(List) == true) {
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu != Nil) { 
            cout << "Nama makanan : " << nodeBantu->isidata.nama << endl;
            cout << "Jenis        : " << nodeBantu->isidata.jenis << endl;
            cout << "Harga        : " << nodeBantu->isidata.harga << endl; 
            cout << "Rating       : " << nodeBantu->isidata.rating << endl;
            cout << "-------------------------------" << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}

void updateFirst(linkedlist List){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        cout << "Masukkan update data node pertama : " << endl;
        cout << "Nama makanan : ";
        getline(cin, List.first->isidata.nama);
        cout << "Jenis makanan : ";
        getline(cin, List.first->isidata.jenis);
        cout << "Harga : ";
        cin >> List.first->isidata.harga;
        cout << "Rating : ";
        cin >> List.first->isidata.rating;
        cin.ignore(); //menghapus karakter newline (/n) dari input buffer
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl; 
    }
}

void updateLast(linkedlist List){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        cout << "Masukkan update data node terakhir : " << endl;
        cout << "Nama makanan : ";
        getline(cin, List.last->isidata.nama);
        cout << "Jenis makanan : ";
        getline(cin, List.last->isidata.jenis);
        cout << "Harga : ";
        cin >> List.last->isidata.harga;
        cout << "Rating : ";
        cin >> List.last->isidata.rating;
        cin.ignore(); //menghapus karakter newline (/n) dari input buffer
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl; 
    }
}

void updateAfter(linkedlist List, address nodePrev){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        if(nodePrev != Nil && nodePrev->next != Nil){
            address nodeBantu = nodePrev->next;
            cout << "masukkan update data node setelah node " << nodePrev->isidata.nama << " : " << endl;
            cout << "Nama makanan : ";
            getline(cin, nodeBantu->isidata.nama);
            cout << "Jenis makanan : ";
            getline(cin, nodeBantu->isidata.jenis);
            cout << "Harga : ";
            cin >> nodeBantu->isidata.harga;
            cout << "Rating : ";
            cin >> nodeBantu->isidata.rating;
            cin.ignore(); //menghapus karakter newline (/n) dari input buffer
            cout << "Data Berhasil Diupdate!" << endl;
            cout << endl;
        } else {
            cout << "Node sebelumnya (nodePrev) tidak valid!" << endl;
        }
    }
}

void updateBefore(linkedlist List, address nodeNext){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        if (nodeNext != Nil && nodeNext->prev != Nil){
            address nodeBantu = nodeNext->prev;
            cout << "masukkan update data node sebelum node " << nodeNext->isidata.nama << " : " << endl;
            cout << "Nama makanan : ";
            getline(cin, nodeBantu->isidata.nama);
            cout << "Jenis makanan : ";
            getline(cin, nodeBantu->isidata.jenis);
            cout << "Harga : ";
            cin >> nodeBantu->isidata.harga;
            cout << "Rating : ";
            cin >> nodeBantu->isidata.rating;
            cin.ignore(); //menghapus karakter newline (/n) dari input buffer
            cout << "Data Berhasil Diupdate!" << endl;
            cout << endl;
        } else {
            cout << "Node selanjutnya (nodeNext) tidak valid!" << endl;
        }
    }
}

//main.cpp
#include "listMakanan.h"
#include <iostream>

using namespace std;

int main(){
    linkedlist List;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createList(List);

    dataMakanan dtMakanan;

    nodeA = alokasi("Nasi Rames", "Makanan Berat", 10000, 8.5);
    nodeB = alokasi("Ayam Geprek", "Makanan Berat", 13000, 9.0);
    nodeC = alokasi("Risol Mayo", "Makanan Ringan", 3500, 8.8);
    nodeD = alokasi("Mie Ayam", "Makanan Berat", 15000, 9.9);
    nodeE = alokasi("Donat", "Makanan Ringan", 2000, 7.7);

    insertFirst(List, nodeD);
    insertLast(List, nodeE);
    insertAfter(List, nodeA, nodeD);
    insertBefore(List, nodeC, nodeE);
    insertLast(List, nodeB);
    cout << endl;

    //D - A - C - E - B
    cout << "--- Isi List Setelah Insert ---" << endl;
    printList(List);
    cout << endl;

    updateFirst(List);
    updateLast(List);
    updateBefore(List, nodeC);
    updateAfter(List, nodeC);

    cout << "--- Isi List Setelah Update ---" << endl;
    printList(List);

    return 0;
}


```
kode c++ tersebut merupakan doubly linked list yang menyimpan data makanan yang terdiri dari nama, jenis, harga, dan rating. pada listMakanan.h berisi struktur data dan deklarasi fungsi, sedangkan listMakanan.cpp berisi implementasi fungsi untuk membuat list, menambah node di awal, akhir, sebelum, dan sesudah node tertentu, menampilkan isi list, serta mengubah data node tertentu. lalu pada main terdapat beberapa node makanan menggunakan fungsi alokasi, menambahkannya ke list dengan berbagai posisi, menampilkan isi list, lalu melakukan beberapa proses update sebelum menampilkan hasil akhirnya.

### 2. Doubly List

```C++
// doublyList.h
#ifndef DOUBLYLIST_H
#define DOUBLYLIST_H

#include <iostream>
#include <string>
#define Nil NULL

using namespace std;

// Tipe data info (kendaraan)
struct kendaraan { //struktur untuk menyimpan info kendaraan
    string nopol; 
    string warna;
    int thnBuat;
};
typedef kendaraan infotype;

// Tipe address dan elemen list
typedef struct ElmList *address;
struct ElmList {
    infotype info; // info kendaraan
    address next;
    address prev;
};

// Tipe list
struct List {
    address first; //pointer ke elemen pertama
    address last;  //pointer ke elemen terakhir
};

// Prototypes
void CreateList(List &L); //ngebuat list kosong
address alokasi(infotype x); //alokasi elemen baru/nambah elemen baru
void dealokasi(address &P); //dealokasi elemen/hapus elemen

// Insert Last
void insertLast(List &L, address P);

// Searching
address findElm(List L, string nopol);

// Delete
void deleteByNopol(List &L, string nopol);

// Tampilkan isi list
void printInfo(List L);

#endif 

// doublyList.cpp
#include "Doublylist.h"
using namespace std;

void CreateList(List &L) { //blm ada elemen
    L.first = Nil;
    L.last = Nil;
}

address alokasi(infotype x) { //fs alokasi elemen baru
    address P = new ElmList; //alokasi memori untuk elemen baru
    P->info = x; //mengisi bagian info dengan data x
    P->next = Nil; //ini jadi nill karena gak terhubung ke list manapun
    P->prev = Nil;
    return P;
}

void dealokasi(address &P) {
    delete P; //menghapus elemen yang ditunjuk oleh P dan mengembalikan memori ke sistem
}

void insertLast(List &L, address P) {
    if (L.first == Nil) { // List kosong
        L.first = P; // elemen pertama dan terakhir sama dengan P
        L.last = P;
    } else { // List ada isi
        P->prev = L.last; // prev P menunjuk ke elemen terakhir saat ini
        (L.last)->next = P; // next elemen terakhir saat ini menunjuk ke P
        L.last = P; // update last menjadi P
    }
}

// Searching
address findElm(List L, string nopol) {
    address P = L.first; // mulai dari elemen pertama
    while (P != Nil) {
        //Bandingkan nopol yang dicari dengan nopol di elemen saat ini
        if (P->info.nopol == nopol) {
            return P; // Ketemu
        }
        P = P->next; // Lanjut ke elemen berikutnya kalau g cocok
    }
    return Nil; // Tidak ketemu
}

// Delete
void deleteByNopol(List &L, string nopol) {
    // Cari elemen dengan nopol yang sesuai
    address P = findElm(L, nopol);
    if (P == Nil) { // Tidak ditemukan
        cout << "Nomor polisi " << nopol << " tidak ditemukan.\n";
    } else { // Ditemukan
        if (P == L.first && P == L.last) { // Kasus 1: Hanya 1 elemen di list
            L.first = Nil; L.last = Nil;
        } else if (P == L.first) { // Kasus 2: Hapus elemen pertama tapi bukan satu-satunya
            L.first = P->next; // update first ke elemen berikutnya
            (L.first)->prev = Nil; // update prev elemen pertama barumenjadi nil
        } else if (P == L.last) { // Kasus 3: Hapus elemen terakhir
            L.last = P->prev; // update last ke elemen sebelumnya
            (L.last)->next = Nil; P->prev = Nil; // update next elemen terakhir baru menjadi nil
        } else { // Kasus 4: Hapus elemen di tengah
            address Prec = P->prev; // elemen sebelum P
            address Succ = P->next; // elemen setelah P
            Prec->next = Succ; Succ->prev = Prec; // hubungkan Prec ke Succ
            P->next = Nil; P->prev = Nil; // putuskan  hubungan P dari list
        }
        dealokasi(P); // dealokasi elemen P
        cout << "Data dengan nomor polisi " << nopol << " berhasil dihapus.\n";
    }
}


void printInfo(List L) { //menampilkan isi list
    address P = L.first; //mulai dari elemen pertama
    if (P == Nil) {
        cout << "List Kosong.\n";
    } else {
        while (P != Nil) {
            cout << "no polisi: " << P->info.nopol << endl;
            cout << "warna    : " << P->info.warna << endl;
            cout << "tahun    : " << P->info.thnBuat << endl << endl;
            P = P->next;
        }
    }
}

// main.cpp
#include "Doublylist.h"

using namespace std;

int main() { // penggunaan fungsi-fungsi dalam Doublylist
    List L; // deklarasi list
    CreateList(L); // buat list kosong
    address P; // deklarasi pointer elemen list
    infotype data; // deklarasi variabel info kendaraan

    data = {"D001", "hitam", 90}; P = alokasi(data); insertLast(L, P);
    data = {"D003", "putih", 70}; P = alokasi(data); insertLast(L, P);
    data = {"D004", "kuning", 90}; P = alokasi(data); insertLast(L, P);

    cout << "DATA LIST AWAL" << endl;
    printInfo(L);


    string cariNopol = "D001";
    cout << "MENCARI NOPOL " << cariNopol << " -" << endl;
    address found = findElm(L, cariNopol); //Manggil fungsi pencarian di Doublylist.cpp
    if (found != Nil) { // Ketemu
        cout << "Ditemukan: " << found->info.nopol << ", Warna: " << found->info.warna << endl << endl;
    } else {
        cout << cariNopol << " tidak ditemukan." << endl << endl;
    }

    string hapusNopol = "D003";
    cout << "MENGHAPUS NOPOL " << hapusNopol << " -" << endl;
    deleteByNopol(L, hapusNopol); //Manggil fungsi delete di Doublylist.cpp
    cout << endl;

    cout << "DATA LIST SETELAH HAPUS" << endl;
    printInfo(L);

    // Contoh delete elemen pertama
    cout << "MENGHAPUS ELEMEN PERTAMA " << endl;
    deleteByNopol(L, L.first->info.nopol); //Menghapus elemen pertama
    cout << endl;
    printInfo(L);


    return 0;
}

```
kode c++ tersebut menggunakan doubly linked list untuk menyimpan data kendaraan seperti nomor polisi, warna, dan tahun pembuatan. fungsi insertLast untuk menambah data di akhir list, findElm untuk mencari kendaraan berdasarkan nomor polisi, dan deleteByNopol untuk menghapus data kendaraan tertentu. pada kode ini, program bisa menambah dan menampilkan data, sertaa mencari serta menghapus kendaraan secara spesifik.

## Unguided 

### 1. Buat implementasi ADT Doubly Linked list tentang data kendaraan

```C++
// doublyList.h
#ifndef DOUBLYLIST_H
#define DOUBLYLIST_H

#include <iostream>
#include <string>
#define Nil NULL

using namespace std;

struct kendaraan {
    string nopol;
    string warna;
    int thnBuat;
};

typedef kendaraan infotype;

struct ElmList;
typedef ElmList* address;

struct ElmList {
    infotype info;
    address next;
    address prev;
};

struct List {
    address first;
    address last;
};

void CreateList(List &L);
address alokasi(infotype x);
void dealokasi(address P);

void insertFirst(List &L, address P);
address searchByNopol(List L, string nopol);
void printInfo(List L);

#endif

// doublyList.cpp
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


// main.cpp
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

```
### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/ssheilanindya/103112400086_Sheila-Stephanie-Anindya/blob/main/output/output1-unguided1-modul6.png)


kode c++ tersebut merupakan doubly linked list yang menyimpan data kendaraan yang berisi nomor polisi, warna, dan tahun pembuatan. pada doublyList.h mendefinisikan struktur data dan deklarasi fungsi, sedangkan doublyList.cpp berisi implementasinya seperti membuat list baru, menambahkan data di awal list (insertFirst), mencari kendaraan berdasarkan nomor polisi (searchByNopol), dan menampilkan seluruh isi list (printInfo). di fungsi main, program meminta input beberapa data kendaraan, memastikan nomor polisi tidak duplikat dengan fungsi pencarian, lalu menyimpan setiap data ke list menggunakan alokasi dan insertFirst.

### 2. Carilah elemen dengan nomor polisi D001 dengan membuat fungsi baru.


```C++
// doublyList.h
#ifndef DOUBLYLIST_H
#define DOUBLYLIST_H

#include <iostream>
#include <string>
#define Nil NULL

using namespace std;

struct kendaraan {
    string nopol;
    string warna;
    int thnBuat;
};

typedef kendaraan infotype;

struct ElmList;
typedef ElmList* address;

struct ElmList {
    infotype info;
    address next;
    address prev;
};

struct List {
    address first;
    address last;
};

void CreateList(List &L);
address alokasi(infotype x);
void dealokasi(address P);

void insertFirst(List &L, address P);
address searchByNopol(List L, string nopol);
void printInfo(List L);
address findElm(List L, infotype x);

#endif

// doublyList.cpp
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


// main.cpp
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

```
### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 2_1](https://github.com/ssheilanindya/103112400086_Sheila-Stephanie-Anindya/blob/main/output/output1-unguided2-modul6.png)

##### Output 2
![Screenshot Output Unguided 2_2](https://github.com/ssheilanindya/103112400086_Sheila-Stephanie-Anindya/blob/main/output/output2-unguided2-modul6.png)

kode c++ tersebut merupakan modifikasi dari unguided 1 yaitu dengan menambahkan fungsi findElm yang digunakan untuk mencari data kendaraan berdasarkan nomor polisi yang dimasukkan oleh pengguna, serta menampilkan detail kendaraan jika data tersebut ditemukan dalam list.

### 3. Hapus elemen dengan nomor polisi D003 dengan procedure delete.

```C++
// doublyList.h
#ifndef DOUBLYLIST_H
#define DOUBLYLIST_H

#include <iostream>
#include <string>
#define Nil NULL

using namespace std;

struct kendaraan {
    string nopol;
    string warna;
    int thnBuat;
};

typedef kendaraan infotype;

struct ElmList;
typedef ElmList* address;

struct ElmList {
    infotype info;
    address next;
    address prev;
};

struct List {
    address first;
    address last;
};

void CreateList(List &L);
address alokasi(infotype x);
void dealokasi(address P);

void insertFirst(List &L, address P);
address searchByNopol(List L, string nopol);
void printInfo(List L);
address findElm(List L, infotype x);

void deleteFirst(List &L, address &P);
void deleteLast(List &L, address &P);
void deleteAfter(address Prec, address &P);
void deleteByNopol(List &L, string nopol);

#endif

// doublyList.cpp
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

// main.cpp
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

        address P = alokasi(x);
        insertFirst(L, P);
    }

    printInfo(L);

    // cari berdasarkan nopol
    string hapusNopol;
    cout << "\nmasukkan nomor polisi yang akan dihapus : ";
    cin >> hapusNopol;
    deleteByNopol(L, hapusNopol);

    printInfo(L);
    return 0;
}
```
### Output Unguided 3 :

##### Output 1
![Screenshot Output Unguided 3_1](https://github.com/ssheilanindya/103112400086_Sheila-Stephanie-Anindya/blob/main/output/output1-unguided3-modul6.png)

kode c++ tersebut merupakan modifikasi dari unguided 2 yaitu dengan menambahkan fungsi penghapusan data, seperti deleteFirst, deleteLast, deleteAfter, dan deleteByNopol, yang berfungsi untuk menghapus node kendaraan dari list berdasarkan posisinya atau nomor polisi yang dicari, sehingga program tidak hanya bisa menambah dan mencari data, tetapi juga dapat menghapus data tertentu dari doubly linked list.

## Kesimpulan
Doubly Linked List (DLL) merupakan pengembangan dari Singly Linked List (SLL) yang memiliki dua pointer, yaitu next untuk menunjuk elemen berikutnya dan prev untuk menunjuk elemen sebelumnya. Karena adanya dua arah ini, DLL memberikan fleksibilitas lebih dalam melakukan berbagai operasi seperti menambahkan data (insert), menghapus data (delete), dan mencari data (search), karena elemen dapat diakses dari kedua arah, yaitu depan dan belakang. dalam tugas ini, DLL diterapkan dalam berbagai konteks data seperti daftar makanan dan data kendaraan. penerapan ini mencakup pembuatan list, menambahkan data di posisi tertentu, memperbarui data, mencari elemen berdasarkan atribut misalnya nomor polisi, serta menghapus elemen tertentu.

## Referensi
[1] Ginting, S. H. N., Effendi, H., Kumar, S., Marsisno, W., Sitanggang, Y. R. U., Anwar, K., Santiari, N. P. L., Setyowibowo, S., Sigar, T. R., Atho'illah, I., Setyantoro, D., & Smrti, N. E. (n.d.). Pengantar Struktur Data. Sarwandi (Ed.), Miftahul Jannah (Penyunting), Rifki Ramadhan (Desain sampul). PT. Mifandi Mandiri Digital. ISBN 978-623-88663-0-4. <br>
[2] Wijoyo, A., Farhan, A., Prayudi, L. A., Fiqih, M., Santoso, R. D., Setiawan Putra, R. T., & Arifin, T. (n.d.). Penggunaan Algoritma Doubly Linked List Untuk Insertion dan Deletion. Program Studi S1 Teknik Informatika, Fakultas Ilmu Komputer, Universitas Pamulang, Kota Tangerang Selatan, Banten, Indonesia. Email: teguharifin172202@gmail.com <br>
[3]  Teknik Informatika Telkom University. (2025). Modul praktikum 6: Doubly linked list (Bagian Kedua). Telkom University. <br>
[4] Universitas Pelita Harapan – OCW. (n.d.). Handout – TIF104 Modul Praktikum Struktur Data. Diakses pada (https://www.ocw.upj.ac.id/files/Handout-TIF104-Modul-Praltikum-Struktur-Data.pdf)


# <h1 align="center">Laporan Praktikum Modul 4 - Singly Linked List (Bagian Pertama) </h1>
<p align="center"> Sheila Stephanie Anindya - 103112400086 </p>

## Dasar Teori

### A. Linked List <br/>
Linked list (biasa disebut list saja) adalah salah satu bentuk struktur data (representasi penyimpanan) berupa serangkaian elemen data yang saling berkait (berhubungan) dan bersifat fleksibel karena dapat tumbuh dan mengerut sesuai kebutuhan. Data yang disimpan dalam Linked list bisa berupa data tunggal atau data majemuk. Data tunggal merupakan data yang hanya terdiri dari satu data (variabel), misalnya: nama bertipe string. Sedangkan data majemuk merupakan sekumpulan data (record) yang di dalamnya terdiri dari berbagai tipe data, misalnya: Data Mahasiswa, terdiri dari Nama bertipe string, NIM bertipe long integer, dan Alamat bertipe string. [2]

### B. Single Linked List <br/>
Single Linked List merupakan model ADT yang hanya menggunakan satu arah pointer. Singly Linked list Menurut (Joko Musridho, 2024) (Ahmad, 2024)Single Linked list adalah Daftar terhubung yang setiap simpul pembentuknya mempunyai satu rantai(link) ke simpul lainnya. simpul yang saling terhubung satu sama lain dengan menggunakan pointer. Setiap simpul dalam singly Linked list memiliki dua bagian, yaitu data dan pointer yang menunjuk ke simpul berikutnya. Singly Linked list hanya memiliki satu arah, yaitu dari simpul awal (head) ke simpul akhir (tail). [1]
#### 1. Komponen Elemen
Komponen elemen dalam SLL terdapat elemen, data, dan successor. Elemen merupakan segmen-segmen data yang terdapat dalam suatu list. Sementara data merupakan informasi utama yang tersimpan dalam sebuah elemen. Successor merupakan bagian elemen yang berfungsi sebagai penghubung antar elemen. [2]
#### 2. Sifat dari SLL [2]
- Hanya memerlukan satu buah pointer.
- Node akhir menunjuk ke Nil kecuali untuk list circular.
- Hanya dapat melakukan pembacaan maju.
- Pencarian sequential dilakukan jika data tidak terurut.
- Lebih mudah ketika melakukan penyisipan atau penghapusan di tengah list. 
#### 3. Istilah dalam SLL [2]
1) first/head: pointer pada list yang menunjuk alamat elemen pertama list.
2) next: pointer pada elemen yang berfungsi sebagai successor (penunjuk) alamat elemen di depannya.
3) NULL/Nil: artinya tidak memiliki nilai, atau tidak mengacu ke mana pun, atau kosong.
4) Node/simpul/elemen: merupakan tempat penyimpanan data pada suatu memori tertentu. 

## Guided 

### 1. linked list

```C++
//Header guard digunakan untuk mencegah file header yang sama 
//di-include lebih dari sekali dalam satu program.

#ifndef LIST_H
#define LIST_H
#define Nil NULL

#include<iostream>
using namespace std;

//deklarasi isi data struct mahasiswa
struct mahasiswa{
    string nama; 
    string nim;
    int umur;
};

typedef mahasiswa dataMahasiswa; //Memberikan nama alias dataMahasiswa untuk struct mahasiswa.

typedef struct node *address; //Mendefinisikan alias address sebagai pointer ke struct node

struct node{ // node untuk isi dari linked listnya, isi setiap node adalah data & pointer next
    dataMahasiswa isidata;
    address next;
};

struct linkedlist{ //ini linked list nya
    address first;
};

//semua function & prosedur yang akan dipakai
bool isEmpty(linkedlist List);
void createList(linkedlist &List);
address alokasi(string nama, string nim, int umur);
void dealokasi(address &node);
void printList(linkedlist List);
void insertFirst(linkedlist &List, address nodeBaru);
void insertAfter(linkedlist &List, address nodeBaru, address Prev);
void insertLast(linkedlist &List, address nodeBaru);

#endif

#include "list.h"
#include <iostream>
using namespace std;

//I.S = Initial State / kondisi awal
//F.S = Final State / kondisi akhir

//fungsi untuk cek apakah list kosong atau tidak
bool isEmpty(linkedlist List) {
    if(List.first == Nil){
        return true; 
    } else {
        return false;
    }
}

//pembuatan linked list kosong
void createList(linkedlist &List) {
    /* I.S. sembarang
       F.S. terbentuk list kosong */
    List.first = Nil;
}

//pembuatan node baru dengan menerapkan manajemen memori
address alokasi(string nama, string nim, int umur) { 
    /* I.S. sembarang
       F.S. mengembalikan alamat node baru dengan isidata = sesuai parameter dan next = Nil */
    address nodeBaru = new node; 
    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.nim = nim; 
    nodeBaru->isidata.umur = umur;
    nodeBaru->next = Nil;
    return nodeBaru;
}

//penghapusan node dengan menerapkan manajemen memori
void dealokasi(address &node) {
    /* I.S. P (node nya) terdefinisi
       F.S. memori yang digunakan node dikembalikan ke sistem */
    node->next = Nil;
    delete node;
}

//prosedur-prosedur untuk insert / menambahkan node baru kedalam list
void insertFirst(linkedlist &List, address nodeBaru) {
    /* I.S. sembarang, P (node nya) sudah dialokasikan (didelete)
       F.S. menempatkan elemen list (node) pada awal list */
    nodeBaru->next = List.first; 
    List.first = nodeBaru;
}

void insertAfter(linkedlist &List, address nodeBaru, address Prev) {
    /* I.S. sembarang, nodeBaru dan Prev alamat salah satu elemen list (node)
       F.S. menempatkan elemen (node) sesudah elemen node Prev */
    if (Prev != Nil) {
        nodeBaru->next = Prev->next;
        Prev->next = nodeBaru;
    } else {
        cout << "Node sebelumnya tidak valid!" << endl;
    }
}

void insertLast(linkedlist &List, address nodeBaru) {
    /* I.S. sembarang, nodeBaru sudah dialokasikan
       F.S. menempatkan elemen nodeBaru pada akhir list */
    if (isEmpty(List) == true) {
        List.first = nodeBaru;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu->next != Nil) {
            nodeBantu = nodeBantu->next;
        }
        nodeBantu->next = nodeBaru;
    }
}

//prosedur untuk menampilkan isi list
void printList(linkedlist List) {
    /* I.S. list mungkin kosong
       F.S. jika list tidak kosong menampilkan semua info yang ada pada list */
    if (isEmpty(List) == true) {
        cout << "List kosong." << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu != Nil) { 
            cout << "Nama : " << nodeBantu->isidata.nama << ", NIM : " << nodeBantu->isidata.nim 
            << ", Usia : " << nodeBantu->isidata.umur << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}

#include "list.h"

#include<iostream>
using namespace std;

int main(){
    linkedlist List;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createList(List);

    dataMahasiswa mhs;

    nodeA = alokasi("Dhimas", "2311102151", 20);
    nodeB = alokasi("Arvin", "2211110014", 21);
    nodeC = alokasi("Rizal", "2311110029", 20);
    nodeD = alokasi("Satrio", "2211102173", 21);
    nodeE = alokasi("Joshua", "2311102133", 21);

    insertFirst(List, nodeA);
    insertLast(List, nodeB);
    insertAfter(List, nodeC, nodeA);
    insertAfter(List, nodeD, nodeC);
    insertLast(List, nodeE);

    cout << "--- ISI LIST SETELAH DILAKUKAN INSERT ---" << endl;
    printList(List);

    return 0;
}
```
kode c++ tersebut membuat program linked list untuk menyimpan data mahasiswa dan dapat menambah data mahasiswa, serta bisa menampilkan data dari awal, tengah, dan akhir list. program membuat struktur data mahasiswa, node, dan linkedlist untuk menyimpan isi list. lalu terdapat fungsi untuk membuat list kosong, menambah data di awal, tengah, akhir list, dan menampilkan seluruh isi list. pada fungsi main, beberapa data mahasiswa dibuat, lalu dimasukkan ke dalam list dan akhirnya ditampilkan ke output.

### 2. linked list

```C++
//Header guard digunakan untuk mencegah file header yang sama
//di-include lebih dari sekali dalam satu program.
#ifndef LIST_H
#define LIST_H
#define Nil NULL

#include <iostream>
using namespace std;

//deklarasi isi data struct mahasiswa
struct mahasiswa{
    string nama; 
    string nim;
    int umur;
};

typedef mahasiswa dataMahasiswa; //Memberikan nama alias dataMahasiswa untuk struct mahasiswa.

typedef struct node *address; //Mendefinisikan alias address sebagai pointer ke struct node

struct node{ // node untuk isi dari linked listnya, isi setiap node adalah data & pointer next
    dataMahasiswa isidata;
    address next;
};

struct linkedlist{ //ini linked list nya
    address first;
};

//semua function & prosedur yang akan dipakai
bool isEmpty(linkedlist List);
void createList(linkedlist &List);
address alokasi(string nama, string nim, int umur);
void dealokasi(address &node);
void printList(linkedlist List);
void insertFirst(linkedlist &List, address nodeBaru);
void insertAfter(linkedlist &List, address nodeBaru, address Prev);
void insertLast(linkedlist &List, address nodeBaru);

void delFirst(linkedlist &List);
void delLast(linkedlist &List);
void delAfter(linkedlist &List, address nodeHapus, address nodePrev);
int nbList(linkedlist List);
void deleteList(linkedlist &List);

#endif

#include "list.h"
#include <iostream>
using namespace std;

//I.S = Initial State / kondisi awal
//F.S = Final State / kondisi akhir

//fungsi untuk cek apakah list kosong atau tidak
bool isEmpty(linkedlist List) {
    if(List.first == Nil){
        return true; 
    } else {
        return false;
    }
}

//pembuatan linked list kosong
void createList(linkedlist &List) {

    List.first = Nil;
}

//pembuatan node baru
address alokasi(string nama, string nim, int umur) { 

    address nodeBaru = new node; 
    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.nim = nim; 
    nodeBaru->isidata.umur = umur;
    nodeBaru->next = Nil;
    return nodeBaru;
}

//penghapusan node
void dealokasi(address &node) {
    node->next = Nil;
    delete node;
}

//prosedur-prosedur untuk insert / menambahkan node baru kedalam list
void insertFirst(linkedlist &List, address nodeBaru) {

    nodeBaru->next = List.first; 
    List.first = nodeBaru;
}

void insertAfter(linkedlist &List, address nodeBaru, address Prev) {

    if (Prev != Nil) { //Previous (sebelumnya) tidak boleh NULL
        nodeBaru->next = Prev->next;
        Prev->next = nodeBaru;
    } else {
        cout << "Node sebelumnya tidak valid!" << endl;
    }
}

void insertLast(linkedlist &List, address nodeBaru) {

    if (isEmpty(List)) {
        List.first = nodeBaru;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu->next != Nil) {
            nodeBantu = nodeBantu->next;
        }
        nodeBantu->next = nodeBaru;
    }
}

//prosedur-prosedur untuk delete / menghapus node yang ada didalam list
void delFirst(linkedlist &List){

    address nodeHapus;
    if (isEmpty(List) == false) {
        nodeHapus = List.first;
        List.first = List.first->next;
        nodeHapus->next = Nil;
        dealokasi(nodeHapus);
    } else {
        cout << "List kosong!" << endl;
    }
}

void delLast(linkedlist &List){

    address nodeHapus, nodePrev;
    if(isEmpty(List) == false){
        nodeHapus = List.first;
        if(nodeHapus->next == Nil){
            List.first->next = Nil;
            dealokasi(nodeHapus);
        } else { 
            while(nodeHapus->next != Nil){
                nodePrev = nodeHapus; 
                nodeHapus = nodeHapus->next;
            }
            nodePrev->next = Nil; 
            dealokasi(nodeHapus);
        }
    } else {
        cout << "list kosong" << endl;
    }
}

void delAfter(linkedlist &List, address nodeHapus, address nodePrev){

    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else { //jika list tidak kosong
        if (nodePrev != Nil && nodePrev->next != Nil) { 
            nodeHapus = nodePrev->next;       
            nodePrev->next = nodeHapus->next;  
            nodeHapus->next = Nil;         
            dealokasi(nodeHapus);
        } else {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}

//prosedur untuk menampilkan isi list
void printList(linkedlist List) {

    if (isEmpty(List)) {
        cout << "List kosong." << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu != Nil) { 
            cout << "Nama : " << nodeBantu->isidata.nama << ", NIM : " << nodeBantu->isidata.nim << ", Usia : " << nodeBantu->isidata.umur << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}

//function untuk menampilkan jumlah node didalam list
int nbList(linkedlist List) {

    int count = 0;
    address nodeBantu = List.first;
    while (nodeBantu != Nil) {
        count++;
        nodeBantu = nodeBantu->next; 
    }
    return count;
}

//prosedur untuk menghapus list (menghapus semua node didalam list)
void deleteList(linkedlist &List){

    address nodeBantu, nodeHapus;
    nodeBantu = List.first;
    while(nodeBantu != Nil){
        nodeHapus = nodeBantu;
        nodeBantu = nodeBantu->next;
        dealokasi(nodeHapus); 
    }
    List.first = Nil; 
    cout << "List sudah terhapus!" << endl;
}

#include "list.h"

#include<iostream>
using namespace std;

int main(){
    linkedlist List;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createList(List);

    dataMahasiswa mhs;

    nodeA = alokasi("Dhimas", "2311102151", 20);
    nodeB = alokasi("Arvin", "2211110014", 21);
    nodeC = alokasi("Rizal", "2311110029", 20);
    nodeD = alokasi("Satrio", "2211102173", 21);
    nodeE = alokasi("Joshua", "2311102133", 21);

    insertFirst(List, nodeA);
    insertLast(List, nodeB);
    insertAfter(List, nodeC, nodeA);
    insertAfter(List, nodeD, nodeC);
    insertLast(List, nodeE);

    cout << "ISI LIST SETELAH DILAKUKAN INSERT" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    delFirst(List);
    delLast(List);
    delAfter(List, nodeD, nodeC);

    cout << "ISI LIST SETELAH DILAKUKAN DELETE" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    deleteList(List);
    cout << "ISI LIST SETELAH DILAKUKAN HAPUS LIST" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    return 0;
}
```
kode c++ ini menambahkan fungsi dari kode sebelumnya (guided 1) untuk menghapus node (delFirst, delLast, delAfter), menghitung jumlah node (nbList), dan menghapus seluruh list (deleteList).


## Unguided 

### 1. Buatlah ADT Singly Linked List 

```C++
// singlylist.h

#ifndef SINGLYLIST_H
#define SINGLYLIST_H
#define Nil NULL

#include <iostream>
using namespace std;

typedef int infotype;
typedef struct ElmtList *address;

struct ElmtList {
    infotype info;
    address next;
};

struct List {
    address First;
};

void CreateList(List &L);
address alokasi(infotype x);
void dealokasi(address &P);
void printInfo(List L);
void insertFirst(List &L, address P);

#endif

// singlylist.cpp

#include "singlylist.h"
#include <iostream>
using namespace std;

void CreateList(List &L) {
    L.First = Nil;
}

address alokasi(infotype x) {
    address P = new ElmtList;
    if (P != Nil) {
        P -> info = x;
        P -> next = Nil;
    }
    return P;
}

void dealokasi(address &P) {
    delete P;
    P = Nil;
}

void printInfo(List L) {
    address P = L.First;
    while (P != Nil) {
        cout << P -> info << " ";
        P = P -> next;
    }
    cout << endl;
}

void insertFirst(List &L, address P) {
    P -> next = L.First;
    L.First = P;
}

// main.cpp

#include "singlylist.h"
#include <chrono>
#include <iostream>
#include <iomanip>

using namespace std;
using namespace std::chrono;

int main() {
    auto start = high_resolution_clock::now();  // mulai timer

    List L;
    address P1, P2, P3, P4, P5;

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

    printInfo(L);

    auto stop = high_resolution_clock::now();   // stop timer
    duration<double> elapsed = stop - start;    // durasi detik

    cout << fixed << setprecision(3);
    cout << "Process returned 0 (0x0)   execution time : "
         << elapsed.count() << " s" << endl;

    cout << "Press any key to continue.";
    cin.get();  // nunggu inputan sebelum program selesai
    return 0;
}


```
### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/ssheilanindya/103112400086_Sheila-Stephanie-Anindya/blob/main/output/output1-unguided1-modul4.png)

kode c++ tersebut membuat singly linked list yang menyimpan integer, dengan fungsi untuk membuat list kosong (CreateList), membuat node baru (alokasi), menghapus node (dealokasi), menambahkan node di awal list (insertFirst), dan menampilkan semua elemen (printInfo). pada fungsi main, beberapa node dibuat sesuai perintah soal dan dimasukkan ke list, kemudian isi list ditampilkan. pada fungsi main terdapat kode yang menghitung dan menampilkan waktu eksekusi program, dibuat sesuai contoh output dengan bantuan AI.

### 2. Dari soal Latihan pertama, lakukan penghapusan node 9 menggunakan deleteFirst(), node 2 menggunakan deleteLast(), dan node 8 menggunakan deleteAfter(). Kemudian tampilkan jumlah node yang tersimpan menggunakan nbList() dan lakukan penghapusan seluruh node menggunakan deleteList().

```C++
// singlylist.h

#ifndef SINGLYLIST_H
#define SINGLYLIST_H
#define Nil NULL

#include <iostream>

using namespace std;

typedef int infotype;
typedef struct ElmtList *address;

struct ElmtList {
    infotype info;
    address next;
};

struct List {
    address First;
};

void CreateList(List &L);
address alokasi(infotype x);
void dealokasi(address &P);
void printInfo(List L);
void insertFirst(List &L, address P);

void deleteFirst(List &L, address &P);
void deleteLast(List &L, address &P);
void deleteAfter(List &L, address Prec, address &P);
int nbList(List L);
void deleteList(List &L);

#endif

// singlylist.cpp

#include "singlylist.h"
#include <iostream>

using namespace std;

void CreateList(List &L) {
    L.First = Nil;
}

address alokasi(infotype x) {
    address P = new ElmtList;
    if (P != Nil) {
        P->info = x;
        P->next = Nil;
    }
    return P;
}

void dealokasi(address &P) {
    delete P;
    P = Nil;
}

void printInfo(List L) {
    address P = L.First;
    while (P != Nil) {
        cout << P->info << " ";
        P = P->next;
    }
    cout << endl;
}

void insertFirst(List &L, address P) {
    P->next = L.First;
    L.First = P;
}

void deleteFirst(List &L, address &P) { // hapus node 9
    if (L.First != Nil) {
        P = L.First;
        L.First = P->next;
        P->next = Nil;
    }
}

void deleteLast(List &L, address &P) { // hapus node 2
    if (L.First != Nil) {
        address Q = L.First;
        if (Q->next == Nil) {
            P = Q;
            L.First = Nil;
        } else {
            while (Q->next->next != Nil) {
                Q = Q->next;
            }
            P = Q->next;
            Q->next = Nil;
        }
    }
}

void deleteAfter(List &L, address Prec, address &P) { // hapus node 8
    if (Prec != Nil && Prec->next != Nil) {
        P = Prec->next;
        Prec->next = P->next;
        P->next = Nil;
    }
}

int nbList(List L) { // nampilin jumlah node yang tersimpan
    int count = 0;
    address P = L.First;
    while (P != Nil) {
        count++;
        P = P->next;
    }
    return count;
}

void deleteList(List &L) { // hapus semua node
    address P;
    while (L.First != Nil) {
        deleteFirst(L, P);
        dealokasi(P);
    }
    cout << "\n- list berhasil terhapus -" << endl;
}

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

```
### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 2_1](https://github.com/ssheilanindya/103112400086_Sheila-Stephanie-Anindya/blob/main/output/output1-unguided2-modul4.png)

kode c++ tersebut merupakan modifikasi dari kode unguided 1 yaitu membuat singly linked list yang menyimpan integer, dengan fungsi untuk membuat list kosong, menambah node di awal (insertFirst), menghapus node dari awal (deleteFirst), akhir (deleteLast), setelah node tertentu (deleteAfter), menghitung jumlah node (nbList), menampilkan isi list (printInfo), dan menghapus seluruh list (deleteList). pada fungsi main, beberapa node dibuat, beberapa dihapus menggunakan fungsi delete, lalu isi list dan jumlah node ditampilkan sebelum akhirnya seluruh list dihapus.


## Kesimpulan
dari kode-kode di atas adalah bahwa program-program tersebut mengimplementasikan singly linked list untuk menyimpan data (baik integer maupun data mahasiswa), dengan kemampuan dasar seperti membuat list kosong, menambahkan node di awal, menampilkan isi list, serta operasi penghapusan node dari awal, akhir, atau setelah node tertentu. selain itu, program juga menyediakan fungsi untuk menghitung jumlah node dan menghapus seluruh list secara aman menggunakan manajemen memori (new dan delete). implementasi ini menunjukkan konsep dasar linked list, alokasi dan dealokasi, serta pointer untuk menambah, menghapus, dan menelusuri elemen list.

## Referensi
[1] Setiyawan, R. D., Hermawan, D., Abdillah, A. F., Mujayanah, A., & Vindua, R. (2023). Penggunaan struktur data stack dalam pemrograman C++ dengan pendekatan array dan linked list. Fakultas Ilmu Komputer, Universitas Pamulang. Diakses dari https://www.researchgate.net/publication/387858466_PENGGUNAAN_STRUKTUR_DATA_STACK_DALAM_PEMROGRAMAN_C_DENGAN_PENDEKATAN_ARRAY_DAN_LINKED_LIST
[2] Teknik Informatika Telkom University. (2025). Modul praktikum 4: Singly linked list (Bagian pertama). Telkom University.

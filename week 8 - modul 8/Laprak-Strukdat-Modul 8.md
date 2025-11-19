# <h1 align="center">Laporan Praktikum Modul 8 - QUEUE </h1>
<p align="center"> Sheila Stephanie Anindya - 103112400086 </p>

## Dasar Teori

### A. QUEUE<br/>
Queue (dibaca : kyu) merupakan struktur data yang dapat diumpamakan seperti sebuah antrean.
Misalkan antrean pada loket pembelian tiket Kereta Api. Orang yang akan mendapatkan pelayanan
yang pertama adalah orang pertamakali masuk dalam antrean tersebut dan yang terakhir masuk dia
akan mendapatkan layanan yang terakhir pula. Jadi prinsip dasar dalam Queue adalah FIFO (First in
Fisrt out), proses yang pertama masuk akan diakses terlebih dahulu. Dalam pengimplementasian
struktur Queue dalam C dapat menggunakan tipe data array dan linked list. [1]
Berbeda dengan struktur data stack yang menyimpan data secara bertumpuk dimana hanya terdapat satu ujung yang terbuka untuk melakukan operasi data, struktur data queue justru disusun secara horizontal dan terbuka di kedua ujungnya. Ujung pertama (head) digunakan untuk menghapus data sedangkan ujung lainnya (tail) digunakan untuk menyisipkan data.Persamaan antara stack dan queue adalah keduanya dapat diimplementasikan menggunakan struktur data linked list atau array. [2]
Contoh nyata dalam kehidupan sehari-hari yang dapat menggambarkan struktur data queue adalah barisan orang yang menunggu untuk membeli tiket di gedung bioskop.Orang yang baru datang akan bergabung dengan barisan dari ujung dan orang yang berdiri di depan akan menjadi yang pertama mendapatkan tiket dan meninggalkan barisan. Demikian pula dalam struktur data queue, data yang ditambahkan terlebih dahulu akan meninggalkan antrian terlebih dahulu. [2]

### B. Prinsip FIFO pada Queue<br/>
Caranya bekerja adalah seperti jejeran orang yang sedang menunggu antrean di supermarket di mana orang pertama yang datang adalah yang pertama dilayani (First In, First Out).[4] Pada struktur data ini, urutan pertama (data yang akan dikeluarkan) disebut Front atau Head. Sebaliknya, data pada urutan terakhir (data yang baru saja ditambahkan) disebut Back, Rear, atau Tail. Proses untuk menambahkan data pada antrean disebut dengan Enqueue, sedangkan proses untuk menghapus data dari antrean disebut dengan Dequeue. [1]

### C. Jenis-jenis Queue<br/>
#### 1. Simple Queue
Elemen-elemen data disusun dalam barisan linear dan penambahan serta penghapusan elemen hanya terjadi pada dua ujung barisan tersebut.
#### 2. Circular Queue
Seperti simple queue namun ujung-ujung barisan terhubung satu sama lain, menciptakan struktur antrean yang berputar.
#### 3. Priority Queue
Setiap elemen memiliki prioritas tertentu. Elemen dengan prioritas tertinggi akan diambil terlebih dahulu.
#### 4. Double-ended Queue (Dequeue)
Elemen dapat ditambahkan atau dihapus dari kedua ujung antrean.

## Guided 

### 1. QUEUE

```C++
#ifndef QUEUE_H
#define QUEUE_H
#define Nil NULL

#include <iostream>
using namespace std;

typedef struct node *address;

struct node{
    int dataAngka;
    address next;
};

struct queue{
    address head;
    address tail;
};

bool isEmpty(queue Q);
void createQueue(queue &Q);
address alokasi(int angka);
void dealokasi(queue &node);

void enQueue(queue &Q, address nodeBaru);
void deQueue(queue &Q);
void updateQueue(queue &Q, int posisi);
void viewQueue(queue Q);
void searchData(queue Q, int data);

#endif

// queue.cpp
#include "queue.h"
#include <iostream>

using namespace std;

bool isEmpty(queue Q){
    if(Q.head == Nil){
        return true;
    } else {
        return false;
    }
}

void createQueue(queue &Q){
    Q.head =  Q.tail = Nil;
}

address alokasi(int angka){
    address nodeBaru = new node;
    nodeBaru->dataAngka = angka;
    nodeBaru->next = Nil;
    return nodeBaru;
}

void dealokasi(address &node){
    node->next = Nil;
    delete node;
}

void enQueue(queue &Q, address nodeBaru){
    if(isEmpty(Q) == true){
        Q.head = Q.tail = nodeBaru;
    } else {
        Q.tail->next = nodeBaru;
        Q.tail = nodeBaru;
    }
    cout << "Node " << nodeBaru->dataAngka << " berhasil ditambahkan kedalam queue!" << endl;
}

void deQueue(queue &Q){
    address nodeHapus;
    if(isEmpty(Q) == true){
        cout << "Queue kosong!" << endl;
    } else {
        nodeHapus = Q.head;
        Q.head = Q.head->next;
        nodeHapus->next = Nil;
        if(Q.head == Nil){
            Q.tail = Nil;
        }
        dealokasi(nodeHapus);
        cout << "node " <<  nodeHapus->dataAngka << " berhasil dihapus dari queue!" << endl;
    }
}

void updateQueue(queue &Q, int posisi){
    if(isEmpty(Q) == true){
        cout << "Queue kosong!" << endl;
    } else {
        if(posisi == 0){
            cout << "Posisi tidak valid!" << endl;
        } else {
            address nodeBantu = Q.head;
            int count = 1;
            bool found = false;
            while(nodeBantu != Nil){
                if(count < posisi){
                    nodeBantu = nodeBantu->next;
                    count++;
                } else if(count == posisi){
                    cout << "Update node poisisi ke-" << posisi << endl;
                    cout << "Masukkan angka : ";
                    cin >> nodeBantu->dataAngka;
                    cout << "Data berhasil diupdate!" << endl;
                    cout << endl;
                    found = true;
                    break;
                }
            }
            if(found == false){
                cout << "Posisi " << posisi << " tidak valid!" << endl;
            }
        }
    }
}

void viewQueue(queue Q){
    if(isEmpty(Q) == true){
        cout << "Queue kosong!" << endl;
    } else {
        address nodeBantu = Q.head;
        while(nodeBantu != Nil){
            cout << nodeBantu->dataAngka << " ";
            nodeBantu = nodeBantu->next;
        }
    }
    cout << endl;
}

void searchData(queue Q, int data){
    if(isEmpty(Q) == true){
        cout << "Queue kosong!" << endl;
    } else {
        address nodeBantu = Q.head;
        int posisi = 1;
        bool found = false;
        cout << "Mencari data " << data << "..." << endl;
        while(nodeBantu != Nil){
            if(nodeBantu->dataAngka == data){
                cout << "Data " << data << " ditemukan pada posisi ke-" << posisi << endl;
                found = true;
                cout << endl;
                break;
            } else {
                posisi++;
                nodeBantu = nodeBantu->next;
            }
        }
        if(found == false){
            cout << "Data " << data << " tidak ditemukan didalam queue!" << endl;
            cout << endl;
        }
    }
}

// main.cpp
#include "queue.h"
#include <iostream>
using namespace std;

int main(){
    queue Q;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createQueue(Q);

    nodeA = alokasi(1);
    nodeB = alokasi(2);
    nodeC = alokasi(3); 
    nodeD = alokasi(4);
    nodeE = alokasi(5);

    enQueue(Q, nodeA);
    enQueue(Q, nodeB);
    enQueue(Q, nodeC);
    enQueue(Q, nodeD);
    enQueue(Q, nodeE);
    cout << endl;

    cout << "--- Queue setelah enQueue ---" << endl;
    viewQueue(Q);
    cout << endl;

    deQueue(Q);
    deQueue(Q);
    cout << endl;

    cout << "--- Queue setelah deQueue 2 kali ---" << endl;
    viewQueue(Q);
    cout << endl;

    updateQueue(Q, 2);
    updateQueue(Q, 1);
    updateQueue(Q, 4);
    cout << endl;

    cout << "--- Queue setelah update ---" << endl;
    viewQueue(Q);
    cout << endl;

    searchData(Q, 4);
    searchData(Q, 9);
    return 0;
}

```

kode c++ tersebut menggunakan struktur data queue. queue disimpan dengan pointer head dan tail, lalu setiap node menyimpan angka dan pointer ke node berikutnya. terdapat function membuat queue, mengecek apakah queue kosong, menambah elemen ke belakang (enqueue), menghapus elemen dari depan (dequeue), memperbarui nilai pada posisi tertentu, menampilkan isi queue, dan mencari data di dalam queue. pafa function main program membuat beberapa node, memasukkannya ke queue, menghapus dua elemen pertama, mengupdate beberapa posisi, menampilkan hasil akhirnya, dan mencari data tertentu dalam queue.

### 2. QUEUE

```C++
// queue.h
#ifndef QUEUE_H
#define QUEUE_H
#define Nil NULL

#define MAX_QUEUE 5

struct queue {
    int info[MAX_QUEUE];
    int head;
    int tail;
    int count;
};

void createQueue(queue &Q);
bool isEmpty(queue Q);
bool isFull(queue Q);

void enqueue(queue &Q, int x);
int dequeue(queue &Q);
void printInfo(queue Q);

#endif

// queue.cpp
#include "queue.h" 
#include <iostream>

using namespace std;

void createQueue(queue &Q) {
    Q.head = 0; 
    Q.tail = 0; 
    Q.count = 0;
}

bool isEmpty(queue Q) {
    return Q.count == 0; //Kembalikan true jika jumlah elemen adalah 0
}

bool isFull(queue Q) {
    return Q.count == MAX_QUEUE; // Kembalikan true jika jumlah elemen sama dengan maks
}

// Definisi prosedur untuk menambahkan elemen (enqueue)
void enqueue(queue &Q, int x) {
    if (!isFull(Q)) { 
        Q.info[Q.tail] = x; // Masukkan data (x) ke posisi ekor (tail)
        // Pindahkan ekor secara circular (memutar)
        Q.tail = (Q.tail + 1) % MAX_QUEUE; 
        Q.count++; //Tambah jumlah elemen
    } else { 
        cout << "Antrean Penuh!" << endl;
    }
}

//Definisi fungsi untuk menghapus elemen (dequeue)
int dequeue(queue &Q) {
    if (!isEmpty(Q)) { 
        int x = Q.info[Q.head]; // Ambil data di posisi  (head)
        Q.head = (Q.head + 1) % MAX_QUEUE;
        Q.count--; // Kurangi jumlah elemen
        return x;
    } else {
        cout << "Antrean Kosong!" << endl;
        return -1;
    }
}

// Definisi prosedur untuk menampilkan isi queue 
void printInfo(queue Q) {
    cout << "Isi Queue: [ ";
    if (!isEmpty(Q)) { 
        int i = Q.head; // Mulai dari head
        int n = 0; //Penghitung elemen yang sudah dicetak
        while (n < Q.count) { // Ulangi sebanyak jumlah elemen
            cout << Q.info[i] << " "; // Cetak info
            i = (i + 1) % MAX_QUEUE; // Geser i secara circular
            n++; // Tambah penghitung
        }
    }
    cout << "]" << endl;
}

// main.cpp
#include <iostream>
#include "queue.h"

using namespace std;

int main(){
    queue Q;

    createQueue(Q);
    printInfo(Q);

    cout << "\n Enqueue 3 elemen" << endl;
    enqueue(Q, 5);
    printInfo(Q);
    enqueue(Q, 2);
    printInfo(Q);
    enqueue(Q, 7);
    printInfo(Q);

    cout << "\n dequeue 1 elemen" << endl;
    cout << "elemen keluar: " << dequeue(Q) << endl;
    printInfo(Q);

    cout << "\n Enqueue 1 Elemen" << endl;
    enqueue(Q, 4);
    printInfo(Q);

    cout << "\n Dequeue 2 elemen" << endl;
    cout << "elemen keluar: " << dequeue(Q) << endl;
    cout << "elemen keluar: " << dequeue(Q) << endl;
    printInfo(Q);

    return 0;

}

```
kode c++ tersebut menggunakan struktur data queue berbasis array. queue disimpan dengan circular buffer yaitu elemen disimpan di dalam array yang berukuran tetap (MAX_QUEUE), lalu terdapat tiga variabel pada queue yaitu head, tail, dan count.head untuk posisi depan, tail untuk posisi belakang, dan count untuk jumlah elemen. terdapat function membuat queue, mengecek apakah queue kosong/penuh, memasukkan elemen (enqueue) dengan menggeser tail secara melingkar, menghapus elemen (dequeue) dari head, dan menampilkan isi queue. pafa function main program menguji dengan menambah beberapa elemen, menghapus beberapa elemen, lalu mencetak queue setelah setiap operasi.



## Unguided 

### 1. (isi dengan soal unguided 1)

```C++
// queue.h
#ifndef QUEUE_H
#define QUEUE_H

#define MaxEl 5
#define Nil -1

#include <iostream>

using namespace std;

typedef int infotype;

struct queue {
    infotype info[MaxEl];
    int head;
    int tail;
};

void createQueue(queue &Q);
bool isEmptyQueue(queue Q);
bool isFullQueue(queue Q);
void enqueue(queue &Q, infotype x);
infotype dequeue(queue &Q);
void printInfo(queue Q);

#endif

// queue.cpp
#include "queue.h"
#include <iostream>

using namespace std;

void createQueue(queue &Q) {
    Q.head = Nil;
    Q.tail = Nil;
}

bool isEmptyQueue(queue Q) {
    return (Q.head == Nil && Q.tail == Nil);
}

bool isFullQueue(queue Q) {
    return (Q.tail == MaxEl - 1);
}

void enqueue(queue &Q, infotype x) {
    if (isFullQueue(Q)) {
        cout << "Queue penuh" << endl;
    } else {
        if (isEmptyQueue(Q)) {
            Q.head = 0;
            Q.tail = 0;
        } else {
            Q.tail++;
        }
        Q.info[Q.tail] = x;
    }
}

infotype dequeue(queue &Q) {
    if (isEmptyQueue(Q)) {
        cout << "empty queue" << endl;
        return -1;
    }

    infotype x = Q.info[Q.head];

    if (Q.head == Q.tail) {
        Q.head = Nil;
        Q.tail = Nil;
    } else { // geser elemen ke kiri
        for (int i = Q.head; i < Q.tail; i++) {
            Q.info[i] = Q.info[i + 1];
        }
        Q.tail--; // soalnya elemen bergeser
    }

    return x;
}

void printInfo(queue Q) {
    cout << Q.head << " - " << Q.tail << " | ";

    if (isEmptyQueue(Q)) {
        cout << "empty queue" << endl;
    } else {
        for (int i = Q.head; i <= Q.tail; i++) {
            cout << Q.info[i];
            if (i < Q.tail) cout << " ";
        }
        cout << endl;
    }
    
}

// main.cpp
#include "queue.h"
#include <iostream>

using namespace std;

int main() {
    cout << "hello world!" << endl;

    queue Q;
    createQueue(Q);

    cout << "-------------------------" << endl;
    cout << " H - T | queue info" << endl;
    cout << "-------------------------" << endl;

    printInfo(Q);

    enqueue(Q, 5); printInfo(Q);
    enqueue(Q, 2); printInfo(Q);
    enqueue(Q, 7); printInfo(Q);

    dequeue(Q);    printInfo(Q);   // 2 7
    dequeue(Q);    printInfo(Q);   // 7
    enqueue(Q, 4); printInfo(Q);   // 7 4
    dequeue(Q);    printInfo(Q);   // 4

    dequeue(Q); printInfo(Q);

    return 0;
}

```
### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/ssheilanindya/103112400086_Sheila-Stephanie-Anindya/blob/main/output/output1-unguided1-modul8.png)

kode c++ tersebut menggunakan struktur data queue berbasis array. queue disimpan dengan circular buffer yaitu elemen disimpan di dalam array yang berukuran tetap dengan maksimal 5. queue dianggap kosong saat head dan tail bernilai Nil, dan dianggap penuh jika tail mencapai indeks maksimum. procedure enqueue menambah data ke posisi berikutnya, sedangkan dequeue mengambil elemen depan lalu menggeser seluruh elemen ke kiri agar urutan tetap benar. printInfo menampilkan kondisi queue serta indeks head dan tail. 

### 2. Buatlah implementasi ADT Queue pada file “queue.cpp” dengan menerapkan mekanisme queue Alternatif 2 (head bergerak, tail bergerak).

```C++
// queue.h
#ifndef QUEUE_H
#define QUEUE_H

#define MaxEl 5
#define Nil -1

#include <iostream>

using namespace std;

typedef int infotype;

struct queue {
    infotype info[MaxEl];
    int head;
    int tail;
};

void createQueue(queue &Q);
bool isEmptyQueue(queue Q);
bool isFullQueue(queue Q);
void enqueue(queue &Q, infotype x);
infotype dequeue(queue &Q);
void printInfo(queue Q);

#endif


// queue.cpp
#include "queue.h"

void createQueue(queue &Q) {
    Q.head = Nil;
    Q.tail = Nil;
}

bool isEmptyQueue(queue Q) {
    return (Q.head == Nil && Q.tail == Nil);
}

bool isFullQueue(queue Q) {
    return (Q.tail == MaxEl - 1);
}

void enqueue(queue &Q, infotype x) {
    if (isFullQueue(Q)) {
        cout << "queue penuh" << endl;
    } else {
        if (isEmptyQueue(Q)) {
            Q.head = 0;
            Q.tail = 0;
        } else {
            Q.tail++;
        }
        Q.info[Q.tail] = x;
    }
}

infotype dequeue(queue &Q) {
    if (isEmptyQueue(Q)) {
        cout << "queue kosong" << endl;
        return -1;
    }

    infotype x = Q.info[Q.head];

    if (Q.head == Q.tail) { 
        Q.head = Nil;
        Q.tail = Nil;
    } else {
        Q.head++;     // head bergerak
    }

    return x;
}

void printInfo(queue Q) {
    cout << Q.head << " - " << Q.tail << " | ";

    if (isEmptyQueue(Q)) {
        cout << "empty queue" << endl;
    } else {
        for (int i = Q.head; i <= Q.tail; i++) {
            cout << Q.info[i] << " ";
        }
        cout << endl;
    }
}


// main.cpp
#include "queue.h"
#include <iostream>

using namespace std;

int main() {
    cout << "hello world!" << endl;

    queue Q;
    createQueue(Q);

    cout << "-------------------------" << endl;
    cout << " H - T | queue info" << endl;
    cout << "-------------------------" << endl;

    printInfo(Q);

    enqueue(Q, 5); printInfo(Q);
    enqueue(Q, 2); printInfo(Q);
    enqueue(Q, 7); printInfo(Q);

    dequeue(Q);    printInfo(Q);   // 2 7
    dequeue(Q);    printInfo(Q);   // 7
    enqueue(Q, 4); printInfo(Q);   // 7 4
    dequeue(Q);    printInfo(Q);   // 4

    dequeue(Q); printInfo(Q);

    return 0;
}

```
### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 2_1](https://github.com/ssheilanindya/103112400086_Sheila-Stephanie-Anindya/blob/main/output/output1-unguided2-modul8.png)


kode c++ ini merupakan modifikasi dari unguided 1, di mana queue tetap menggunakan array berukuran tetap, tetapi kini operasinya dibuat lebih sederhana tanpa melakukan pergeseran seluruh elemen. queue dianggap kosong ketika head dan tail bernilai Nil, dan penuh ketika tail mencapai indeks maksimum. pada procedure enqueue, data baru dimasukkan ke posisi belakang, sedangkan dequeue hanya menggeser head maju satu langkah untuk mengambil elemen terdepan. jika elemen terakhir dihapus, queue otomatis kembali ke kondisi kosong. function printInfo digunakan untuk menampilkan nilai head, tail, serta isi queue saat ini. pada function main masih sama seperti unguided 1.

### 3. Buatlah implementasi ADT Queue pada file “queue.cpp” dengan menerapkan mekanisme queue Alternatif 3 (head dan tail berputar).

```C++
// queue.h
#ifndef QUEUE_H
#define QUEUE_H

#define MaxEl 5
#define Nil -1

#include <iostream>

using namespace std;

typedef int infotype;

struct queue {
    infotype info[MaxEl];
    int head;
    int tail;
};

void createQueue(queue &Q);
bool isEmptyQueue(queue Q);
bool isFullQueue(queue Q);
void enqueue(queue &Q, infotype x);
infotype dequeue(queue &Q);
void printInfo(queue Q);

#endif

// queue.cpp
#include "queue.h"

void createQueue(queue &Q) {
    Q.head = Nil;
    Q.tail = Nil;
}

bool isEmptyQueue(queue Q) {
    return (Q.head == Nil && Q.tail == Nil);
}

bool isFullQueue(queue Q) {
    return ((Q.tail + 1) % MaxEl == Q.head);
}

void enqueue(queue &Q, infotype x) {
    if (isFullQueue(Q)) {
        cout << "queue penuh" << endl;
    } else {
        if (isEmptyQueue(Q)) {
            Q.head = 0;
            Q.tail = 0;
        } else {
            Q.tail = (Q.tail + 1) % MaxEl;   // tail berputar
        }
        Q.info[Q.tail] = x;
    }
}

infotype dequeue(queue &Q) {
    if (isEmptyQueue(Q)) {
        cout << "queue kosong" << endl;
        return -1;
    }

    infotype x = Q.info[Q.head];

    if (Q.head == Q.tail) {
        Q.head = Nil;
        Q.tail = Nil;
    } else {
        Q.head = (Q.head + 1) % MaxEl;   // head berputar
    }

    return x;
}

void printInfo(queue Q) {
    cout << Q.head << " - " << Q.tail << " | ";

    if (isEmptyQueue(Q)) {
        cout << "empty queue" << endl;
        return;
    }

    int i = Q.head;
    while (true) {
        cout << Q.info[i] << " ";
        if (i == Q.tail) break;
        i = (i + 1) % MaxEl;
    }

    cout << endl;
}

// main.cpp
#include "queue.h"
#include <iostream>

using namespace std;

int main() {
    cout << "hello world!" << endl;

    queue Q;
    createQueue(Q);

    cout << "-------------------------" << endl;
    cout << " H - T | queue info" << endl;
    cout << "-------------------------" << endl;

    printInfo(Q);

    enqueue(Q, 5); printInfo(Q);
    enqueue(Q, 2); printInfo(Q);
    enqueue(Q, 7); printInfo(Q);

    dequeue(Q);    printInfo(Q);   // 2 7
    dequeue(Q);    printInfo(Q);   // 7
    enqueue(Q, 4); printInfo(Q);   // 7 4
    dequeue(Q);    printInfo(Q);   // 4

    dequeue(Q); printInfo(Q);

    return 0;
}

```
### Output Unguided 3 :

##### Output 1
![Screenshot Output Unguided 3_1](https://github.com/ssheilanindya/103112400086_Sheila-Stephanie-Anindya/blob/main/output/output1-unguided3-modul8.png)


kode c++ ini merupakan modifikasi dari unguided 1 dan 2, di mana queue tetap menggunakan array berukuran tetap, tetapi kini menerapkan konsep circular queue sehingga posisi head dan tail dapat berputar kembali ke indeks awal. pada kode ini, queue tidak lagi memindahkan atau menggeser elemen saat melakukan procedure dequeue. function enqueue memasukkan data dengan menggeser tail secara melingkar, sedangkan dequeue mengambil elemen dari head yang juga bergerak secara circular. queue dikatakan penuh ketika posisi berikutnya dari tail bertemu dengan head, dan kembali kosong jika elemen terakhir dihapus. function printInfo menampilkan posisi head–tail serta isi queue sesuai urutan antrian. pada function main program menampilkan perubahan queue setelah beberapa procedure enqueue dan dequeue untuk memperlihatkan cara kerja circular queue.

## Kesimpulan
Struktur data QUEUE bekerja dengan prinsip FIFO (First In, First Out) di mana elemen pertama yang masuk menjadi elemen pertama yang keluar. Implementasi queue dapat dilakukan dengan berbagai mekanisme, mulai dari queue sederhana yang masih melakukan pergeseran elemen, hingga versi yang lebih efisien seperti head bergerak dan circular queue yang membuat proses enqueue dan dequeue tidak lagi membutuhkan pemindahan elemen secara manual. Perbedaan mekanisme tersebut terlihat pada bagaimana head dan tail dikelola, namun semuanya tetap menghasilkan queue yang sama. 

## Referensi
[1] Modul 8 Praktikum Struktur Data - QUEUE. Universitas Telkom.
[2] Dicoding. (2023). Struktur Data Queue: Pengertian, Fungsi, dan Jenisnya. Diakses pada 18 November 2025 melalui (https://www.dicoding.com/blog/struktur-data-queue-pengertian-fungsi-dan-jenisnya/)
[3] Studocu. (n.d.). Struktur Data Queue. Diakses pada 18 November 2025 melalui (https://www.studocu.com/id/document/universitas-lambung-mangkurat/struktur-data/struktur-data-queue/44000650)
[4] Sianipar, Rismon Hasiholan. (2025). Pemrograman C++ Untuk Pemula. Jakarta: Penerbit Informatika. Diakses pada 18 November 2025 melalui (https://books.google.co.id/books?hl=en&lr=&id=tQR2DwAAQBAJ&oi=fnd&pg=PA1&dq=tipe+data+c%2B%2B&ots=rEn-jyJIHU&sig=7ZfteP1lCSbYBhucPaiU6xJNeBY&redir_esc=y#v=onepage&q=tipe%20data%20c%2B%2B&f=false)
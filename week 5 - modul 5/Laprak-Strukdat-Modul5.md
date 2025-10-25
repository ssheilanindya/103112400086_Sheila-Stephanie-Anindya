# <h1 align="center">Laporan Praktikum Modul 5 - Singly Linked List (Bagian Kedua) </h1>
<p align="center"> Sheila Stephanie Anindya - 103112400086 </p>

## Dasar Teori

### A. Linked List
Linked list (biasa disebut list saja) adalah salah satu bentuk struktur data (representasi penyimpanan) berupa serangkaian elemen data yang saling berkait (berhubungan) dan bersifat fleksibel karena dapat tumbuh dan mengerut sesuai kebutuhan. Data yang disimpan dalam Linked list bisa berupa data tunggal atau data majemuk. Data tunggal merupakan data yang hanya terdiri dari satu data (variabel), misalnya: nama bertipe string. Sedangkan data majemuk merupakan sekumpulan data (record) yang di dalamnya terdiri dari berbagai tipe data, misalnya: Data Mahasiswa, terdiri dari Nama bertipe string, NIM bertipe long integer, dan Alamat bertipe string. [1] <br/>

### B. Single Linked List
Single Linked List merupakan model ADT yang hanya menggunakan satu arah pointer. Singly Linked list Menurut (Joko Musridho, 2024) (Ahmad, 2024)Single Linked list adalah Daftar terhubung yang setiap simpul pembentuknya mempunyai satu rantai(link) ke simpul lainnya. simpul yang saling terhubung satu sama lain dengan menggunakan pointer. Setiap simpul dalam singly Linked list memiliki dua bagian, yaitu data dan pointer yang menunjuk ke simpul berikutnya. Singly Linked list hanya memiliki satu arah, yaitu dari simpul awal (head) ke simpul akhir (tail). [2] <br/>
...
#### 1. Searching
Searching merupakan operasi dasar list dengan melakukan aktivitas pencarian terhadap node tertentu. Proses ini berjalan dengan mengunjungi setiap node dan berhenti setelah node yang dicari ketemu. Dengan melakukan operasi searching, operasi-operasi seperti insert after, delete after, dan update akan lebih mudah. [3] <br/>
#### 2. Binary Search
Binary Search adalah algoritma pencarian yang bekerja pada data yang telah terurut. Algoritma ini menggunakan prinsip divide and conquer, yaitu membagi masalah besar menjadi masalah yang lebih kecil hingga ditemukan solusi. Saat melakukan pencarian, algoritma ini memeriksa elemen tengah dari daftar, lalu menentukan apakah target lebih kecil, lebih besar, atau sama dengan elemen tersebut. [4] <br/>
Kelebihan dari Binary Search :
1. Proses pencarian jauh lebih cepat jika menghadapi banyak data.
2. Pencarian lebih efisien.

Kekurangan dari Binary Search:
1. Data harus dalam kondisi urut.
2. Waktu pencarian tidak berbeda jauh dengan linera search jika data berjumlah sedikit.
#### 3. Linear Search
Linear Serach merupakan algoritma yang bekerja dengan mencocokan data secara berurutan satu per satu dari satu ujung kumpulan data ke ujung lainnya. Pencarian dengan linear search tidak akan berhenti hingga data yang diinginkan ditemukan. [5] <br/>
Kelebihan dari Linear Search : 
1. Data tidak perlu dalam kondisi urut.
2. Algoritma mudah dipelajari dan diimplementasikan.

Kekurangan dari Linear Search :
1. Tidak cocok untuk data dengan jumlah yang sangat banyak.
2. Waktu dalam pencarian tergolong lama.

## Guided 

### 1. List Buah

```C++
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

#include "listBuah.h"
#include <iostream>
using namespace std;

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
//pembuatan node baru dengan menerapkan manajemen memori
address alokasi(string nama, int jumlah, float harga) { 
    address nodeBaru = new node; 
    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.jumlah = jumlah; 
    nodeBaru->isidata.harga = harga;
    nodeBaru->next = Nil;
    return nodeBaru;
}

//penghapusan node dengan menerapkan manajemen memori
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
    if (Prev != Nil) {
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
        cout << "Node pertama berhasil terhapus!" << endl;
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
        cout << "Node terakhir berhasil terhapus!" << endl;
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
            cout << "Node setelah node " << nodePrev->isidata.nama << " berhasil terhapus!" << endl;
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
            cout << "Nama Buah : " << nodeBantu->isidata.nama << ", Jumlah : " << nodeBantu->isidata.jumlah << ", Harga : " << nodeBantu->isidata.harga << endl;
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
    cout << "List berhasil terhapus!" << endl;
}

/*----- MATERI PERTEMUAN 5 - SINGLY LINKED LIST (BAGIAN KEDUA) - PART 1 (UPDATE) -----*/
//prosedur-prosedur untuk melakukan update data node
void updateFirst(linkedlist List){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        cout << "Masukkan update data node pertama : " << endl;
        cout << "Nama buah : ";
        cin >> List.first->isidata.nama;
        cout << "Jumlah : ";
        cin >> List.first->isidata.jumlah;
        cout << "Harga : ";
        cin >> List.first->isidata.harga;
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl;
    }
}

void updateLast(linkedlist List){
    if (isEmpty(List) == true) {
        cout << "List Kosong!" << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu->next != Nil) {
            nodeBantu = nodeBantu->next;
        }
        cout << "masukkan update data node terakhir : " << endl;
        cout << "Nama buah : ";
        cin >> nodeBantu->isidata.nama;
        cout << "Jumlah : ";
        cin >> nodeBantu->isidata.jumlah;
        cout << "Harga : ";
        cin >> nodeBantu->isidata.harga;
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl;
    }
}

void updateAfter(linkedlist List, address nodePrev){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        if (nodePrev != Nil && nodePrev->next != Nil){
            address nodeBantu = nodePrev->next;
            cout << "masukkan update data node setelah node " << nodePrev->isidata.nama << " : " << endl;
            cout << "Nama buah : ";
            cin >> nodeBantu->isidata.nama;
            cout << "Jumlah : ";
            cin >> nodeBantu->isidata.jumlah;
            cout << "Harga : ";
            cin >> nodeBantu->isidata.harga;
            cout << "Data Berhasil Diupdate!" << endl;
            cout << endl;
        } else {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}

#include "listBuah.h"

#include <iostream>
using namespace std;

void insertFirst(linkedlist &L, address P);

int main(){
    linkedlist List;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createList(List);

    dataBuah dtBuah;

    nodeA = alokasi("jeruk", 100, 3000);
    nodeB = alokasi("apel", 75, 4000);
    nodeC = alokasi("pir", 87, 5000);        
    nodeD = alokasi("semangka", 43, 11500);
    nodeE = alokasi("durian", 15, 31450);

    insertFirst(List, nodeA);
    insertLast(List, nodeB);
    insertAfter(List, nodeC, nodeA);
    insertAfter(List, nodeD, nodeC);
    insertLast(List, nodeE);


    // A -  C - D - B - E

    cout << "--- ISI LIST SETELAH DILAKUKAN INSERT --- " << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    updateFirst(List);
    updateLast(List);
    updateAfter(List, nodeD);

    cout << "--- ISI LIST SETELAH DILAKUKAN UPDATE --- " << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    return 0;
   
}
```
kode c++ tersebut membuat program menggunakan struktur data singly linked list, di setiap node menyimpan satu data buah (nama, jumlah, dan harga) serta alamat ke node berikutnya.header (listBuah.h) mendefinisikan bentuk data, fungsi, dan prosedur yang digunakan untuk mengelola list tersebut, seperti membuat list kosong, menambah data di awal/akhir/tengah, menghapus data, menghitung jumlah data, dan memperbarui isi data. di function main beberapa buah dibuat dan disusun ke dalam list menggunakan berbagai fungsi tersebut, ditampilkan hasilnya, kemudian dilakukan proses update agar datanya bisa diubah langsung.

### 2. Binary

```C++
#include <iostream>
using namespace std;

//definisi node
struct Node{ //memiliki 2 bagian yaitu data dan pointer
    int data;
    Node* next; //pointer ke node berikutnya
};

//fungsi untuk melakukan pencarian secara binary
Node* binarySearch(Node* head, int key) { //Node* ini pointer (kembalian) // head ini pointer ke node pertama //key ini data yang dicari
    int size = 0; //var size disi 0
    for (Node* current = head; current;current = current->next)size++; //current adalah pointer yan digunakan untuk menyusuri linked linked list
    Node *start = head; //start adalah pointer yang menunjuk ke node pertama
    Node *end = nullptr; //end adalah pointer yang menunjuk ke node terakhir (null karena linked list tidak memiliki pointer ke node terakhir yang pasti)

    while(size > 0) { //selama masih ada elemen > 0
        int mid = size / 2; //bagi size jadi 2
        Node* midNode = start; //midNode adalah pointer yang menunjuk ke node tengah
        for (int i = 0 ; i< mid;i++)midNode = midNode->next; //pindah ke node tengah

        if(midNode->data == key)return midNode; //jika ditemukan data yang cocok, kembalikan node
        if(midNode->data < key) { //jika data midNode lebih kecil dari key, kita cari dibagian kanan
            start = midNode->next; //Mulai pencarian dari node setelah midNode
        }
        else { //jika data midNode lebih besar dari key, kita cari dibagian kiri
            end = midNode; //Akhiri pencarian di midNode
        }
        size -= mid; //kita mengurangi size dengan mid
    }
    return nullptr; //jika key tidak ditemukan
}

//prosedur untuk menambah node
void append(Node*& head, int value) { // Node* ini pointer (kembalian) //fs linear search
    Node* newNode = new Node{value, nullptr}; //new node adalag pointer yang meunjuk ke node baru yang dibuat. // value == null karena node baru berada oaling akhir
    if (!head)head = newNode; // jika head null, head diisi node baru
    else {
        Node* temp = head; //mulai dari head
        while (temp->next)temp = temp->next; //pindah ke node berikutnya sampai node terakhir
        temp->next = newNode; // node terakhir dihubungkan ke node baru
    }
}

int main() {
    Node* head = nullptr; // inisiasi head list masih kosong
    append(head, 10);
    append(head, 20); 
    append(head, 30);
    append(head, 40);
    append(head, 50); //menambah node

    //mencari data 40  menggunakan binarysearch
    Node* result = binarySearch(head, 40); //result ini pointer untuk mencari data 40
    cout << (result? "found": "not found") << endl; // condition ? value_if_true : value_if_false
    return 0;
}

```
kode c++ tersebut menggunakan struktur data linked list node yang masing-masing menyimpan satu angka (data) dan petunjuk ke teman berikutnya (next). function append menambahkan node di akhir list. function binarySearch menghitung berapa banyak node dalam barisan, lalu mencari mid setiap kali sampai menemukan angka yang dicari (atau sampai habis). function main berisi angka 10, 20, 30, 40, dan 50, lalu mencari angka 40 menggunakan fungsi tersebut. jika ditemukan, program menampilkan “found”, kalau tidak, “not found”.

### 3. Linear

```C++
#include <iostream>
using namespace std;

// definisi node
struct Node{ // memiliki 2 bagian (data dan pointer)
    int data;
    Node* next;
};

// fungsi pencarian linear
Node* linearSearch(Node* head, int key){
    Node* current = head;
    while(current != nullptr){ //selama masih ada node
        if(current -> data == key) return current; //jika data ketemu
        current = current -> next; //pindah node berikutnya
    }
    return nullptr; //jika data tidak ditemukan
}

//prosedur menambah node
void append(Node*& head, int value){ //parameter head adalah refrence ke pointer head
    Node* newNode = new Node{value, nullptr}; //membuat pointer baru
    if(!head) head = newNode; //jika head null, head diisi node baru
    else{
        Node* temp = head; //mulai dari head
        while(temp -> next) temp = temp -> next; //pindah ke node terakhir
        temp -> next = newNode; //sambungkan node terakhir ke node baru
    }
}

int main(){
    Node* head = nullptr; //inisialilasi head sebagai null
    append(head, 10); append(head, 20); append(head, 30); //menambah node
    Node* result = linearSearch(head, 20); //result mencari node dengan data 20
    cout << (result ? "Found" : "Not found") << endl; 
    //condition ? value_if_true : value_if_false;
    
    return 0;

}

```
kode c++ tersebut memiliki struktur Node memiliki 2 data untuk menyimpan nilai dan next untuk menunjuk ke node berikutnya. fucntion append() digunakan untuk menambahkan node baru di bagian akhir linked list. linearSearch() bertugas mencari nilai tertentu dengan cara memeriksa setiap node satu per satu dari awal hingga akhir. apabila data ditemukan, function mengembalikan alamat node yang berisi data tersebut. jika tidak ditemukan, fungsi mengembalikan nullptr. pada function main program membuat linked list berisi tiga data (10, 20, dan 30), lalu melakukan pencarian terhadap nilai 20 menggunakan linearSearch. hasil pencarian berupa output “found” apabila data ditemukan atau “not found” jika data tidak ada di dalam list.

## Unguided 

### 1. Implementasikan program C++ yang menggunakan algoritma Binary Search pada Linked List untuk mencari elemen tertentu.

```C++
#include <iostream>
using namespace std;

//definisi node
struct Node{ // memiliki 2 bagian yaitu data dan pointer
    int data;
    Node* next; // pointer ke node berikutnya
};

// function node baru di akhir linked list
void append(Node*& head, int value) {
    Node* newNode = new Node{value, nullptr};
    if (!head)
        head = newNode;
    else {
        Node* temp = head;
        while (temp -> next)
            temp = temp -> next;
        temp -> next = newNode;
    }
}

void printList(Node* head) {
    cout << "linked list yang dibuat : ";
    Node* temp = head;
    while (temp) {
        cout << temp -> data << " -> ";
        temp = temp -> next;
    }
    cout << "NULL" << endl;
}

Node* binarySearch(Node* head, int key) {
    cout << "\nmencari nilai : " << key << endl;
    cout << "\nproses pencarian :" << endl;

    // hitung ukuran linked list
    int size = 0;
    for (Node* curr = head; curr; curr = curr -> next)
        size++;

    Node* start = head;
    Node* end = nullptr;
    int iteration = 1; // untuk mencatat langkah-langkah

    while (size > 0) {
        int mid = size / 2;
        Node* midNode = start;

        // geser pointer ke posisi tengah
        for (int i = 0; i < mid; i++)
            midNode = midNode->next;

        cout << "iterasi " << iteration++ << ": mid = " << midNode -> data << " (indeks tengah) ";

        // langkah detail proses
        if (midNode -> data == key) {
            cout << "- ditemukan!" << endl;

            cout << "\nhasil : nilai " << key << " ditemukan pada linked list!" << endl;
            cout << "alamat node : " << midNode << endl;
            cout << "data node : " << midNode -> data << endl;

            // node berikutnya
            if (midNode -> next)
                cout << "node berikutnya : " << midNode -> next -> data << endl;
            else
                cout << "node berikutnya : NULL" << endl;

            return midNode;
        } 
        else if (midNode -> data < key) {
            cout << "-> cari di bagian kanan" << endl;
            start = midNode -> next;
            size -= mid + 1; // kurangi elemen kiri (mid juga)
        } 
        else {
            cout << "-> cari di bagian kiri" << endl;
            size = mid - 1; // sisa bagian kiri
        }
    }
    cout << "tidak ada elemen tersisa." << endl;
    cout << "\nhasil : nilai " << key << " tidak ditemukan dalam linked list!" << endl;
    return nullptr;
}

int main() {
    Node* head = nullptr;

    append(head, 10);
    append(head, 20);
    append(head, 30);
    append(head, 40);
    append(head, 50);
    append(head, 60);

    cout << "BINARY SEARCH PADA LINKED LIST" << endl;
    printList(head);

    binarySearch(head, 40); // ditemukan
    binarySearch(head, 25); // tidak ditemukan

    return 0;
}

```
### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/ssheilanindya/103112400086_Sheila-Stephanie-Anindya/blob/main/output/output1-unguided1-modul5.png)

kode c++ tersebut hasil modifikasi kode guided binary sebelumnya. terdapat struktur Node berisi data angka dan penunjuk ke node berikutnya. function append() dipakai untuk menambahkan node baru di bagian akhir linked list, lalu printList() menampilkan isi seluruh node dari awal hingga akhir dengan tanda ->. binarySearch() berfungsi mencari nilai tertentu dalam linked list dengan cara menghitung dulu jumlah node, lalu menentukan posisi tengah (mid) untuk dibandingkan dengan nilai yang dicari. jika nilai tengah belum cocok, program akan melanjutkan pencarian ke bagian kiri atau kanan, sambil menampilkan proses iterasinya satu per satu. nantinya fungsi akan memberi tahu apakah nilai yang dicari ditemukan atau tidak, beserta informasi node-nya. function main menjalankan semua fungsi itu untuk membuat linked list berisi angka 10 sampai 60, kemudian mencoba mencari angka 40 (ditemukan) dan 25 (tidak ditemukan).

### 2. Implementasikan program C++ yang menggunakan algoritma Linear Search pada Linked List untuk mencari elemen tertentu.

```C++
#include <iostream>
using namespace std;

//definisi node
struct Node{ // memiliki 2 bagian (data dan pointer)
    int data;
    Node* next; // pointer ke node berikutnya
};

// function node baru di akhir linked list
void append(Node*& head, int value) {
    Node* newNode = new Node{value, nullptr};
    if (!head)
        head = newNode;
    else {
        Node* temp = head;
        while (temp -> next)
            temp = temp -> next;
        temp -> next = newNode;
    }
}
void printList(Node* head) {
    cout << "linked list yang dibuat : ";
    Node* temp = head;
    while (temp) {
        cout << temp -> data << " -> ";
        temp = temp -> next;
    }
    cout << "NULL" << endl;
}

Node* linearSearch(Node* head, int key) {
    cout << "mencari nilai : " << key << endl;
    cout << "\nproses pencarian : " << endl;

    Node* current = head;
    int nomorNode = 1;
    bool found = false;

    while (current != nullptr) {
        cout << "memeriksa node " << nomorNode << ": " << current -> data;

        if (current -> data == key) {
            cout << " (sama) - ditemukan!" << endl;

            cout << "\nhasil : nilai " << key << " ditemukan pada linked list!" << endl;
            cout << "alamat node : " << current << endl;
            cout << "data node : " << current -> data << endl;

            // node berikutnya kalo ada
            if (current -> next)
                cout << "node berikutnya : " << current -> next -> data << endl;
            else
                cout << "node berikutnya : NULL" << endl;

            found = true;
            break;
        } else {
            cout << " (tidak sama) " << endl;
        }

        current = current -> next;
        nomorNode++;
    }

    if (!found) {
        cout << "tidak ada node yang tersisa" << endl;
        cout << "\nhasil : nilai " << key << " tidak ditemukan dalam linked list!" << endl;
    }

    return found ? current : nullptr;
}

int main() {
    Node* head = nullptr;

    append(head, 10);
    append(head, 20);
    append(head, 30);
    append(head, 40);
    append(head, 50);

    cout << " LINEAR SEARCH PADA LINKED LIST" << endl;
    printList(head);

    linearSearch(head, 30); // ditemukan
    linearSearch(head, 25); // tidak ditemukan

    return 0;
}

```
### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 2_1](https://github.com/ssheilanindya/103112400086_Sheila-Stephanie-Anindya/blob/main/output/output1-unguided2-modul5.png)

kode c++ tersebut hasil modifikasi kode guided linear sebelumnya. struktur Node memiliki 2 data untuk menyimpan nilai dan next untuk menunjuk ke node berikutnya. fucntion append() digunakan untuk menambahkan node baru di bagian akhir linked list, lalu printList() menampilkan seluruh isi node secara berurutan. linearSearch() bertugas mencari nilai tertentu (key) dengan cara memeriksa setiap node satu per satu dari awal hingga akhir. taat program menemukan data yang cocok, ia akan menampilkan hasilnya beserta alamat dan data node tersebut, termasuk node setelahnya jika ada. namun, jika sudah diperiksa semua dan tidak ada yang cocok, nanti program akan memberi tahu bahwa nilai tidak ditemukan.  function main menjalankan semua fungsi itu untuk membuat linked list berisi angka 10 sampai 50, kemudian program mencoba mencari angka 30 (ditemukan) dan 25 (tidak ditemukan).


## Kesimpulan
berdasarkan teori dasar, ada dua jenis algoritma pencarian yang digunakan, yaitu linear search dan binary search. pada linear search, pencarian dilakukan dengan memeriksa setiap elemen secara berurutan, dari awal hingga elemen yang dicari ditemukan atau sampai semua node diperiksa.
algoritmanya cukup mudah, tetapi membutuhkan waktu yang relatif lama ketika data yang dicari banyak karena prosesnya dilakukan secara berurutan. sementara binary search melakukan pencarian dengan membagi data menjadi dua bagian setiap kali iterasi dilakukan, sehingga prosesnya lebih cepat.
namun, binary search hanya bisa digunakan jika data sudah terurut.
dari kedua kode tersebut dapat disimpulkan bahwa pilihan metode pencarian tergantung pada jenis struktur data dan kebutuhan efisiensi waktu. ilnear search lebih mudah diterapkan, sedangkan binary search lebih efisien, tetapi memiliki syarat tertentu.

## Referensi
[1] Setiyawan, R. D., Hermawan, D., Abdillah, A. F., Mujayanah, A., & Vindua, R. (2023). Penggunaan struktur data stack dalam pemrograman C++ dengan pendekatan array dan linked list. Fakultas Ilmu Komputer, Universitas Pamulang. Diakses dari https://www.researchgate.net/publication/387858466_PENGGUNAAN_STRUKTUR_DATA_STACK_DALAM_PEMROGRAMAN_C_DENGAN_PENDEKATAN_ARRAY_DAN_LINKED_LIST <br> 
[2] Teknik Informatika Telkom University. (2025). Modul praktikum 4: Singly linked list (Bagian Pertama). Telkom University. <br>
[3] Teknik Informatika Telkom University. (2025). Modul praktikum 5: Singly linked list (Bagian Kedua). Telkom University. <br>
[4] Hidayat, A. (2023, Oktober 20). Pengertian Algoritma Binary Search, Fungsi, dan Cara Kerjanya. Universitas Mahakarya Asia (UNMAHA). Diakses dari https://blog.unmaha.ac.id/pengertian-algoritma-binary-search-fungsi-dan-cara-kerjanya/
[5] Pratama Putra, M. N. A. (2023, Juni 29). Algoritma Pemrograman: Linear Search & Binary Search. Medium. Diakses dari https://medium.com/@naufal.adrian904/algoritma-pemrograman-linear-search-binary-search-3cd4403bab88

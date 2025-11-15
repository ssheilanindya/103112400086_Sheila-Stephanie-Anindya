# <h1 align="center">Laporan Praktikum Modul 7 - STACK </h1>
<p align="center"> Sheila Stephanie Anindya - 103112400086 </p>

## Dasar Teori

### A. STACK <br/>
Stack merupakan salah satu bentuk struktur data dimana prinsip operasi yang digunakan seperti
tumpukan. Seperti halnya tumpukan, elemen yang bisa diambil terlebih dahulu adalah elemen yang
paling atas, atau elemen yang pertama kali masuk, prinsip ini biasa disebut LIFO (Last In First Out).[1] Stack terdiri dari beberapa komponen penting, yakni top, data, bottom, dan pointer. Komponen-komponen ini memungkinkan stack untuk bekerja sesuai dengan prinsip LIFO. [2]
#### 1. Top (Puncak)
Posisi atau indeks teratas dari stack. Top menunjukkan elemen terbaru yang dimasukkan ke dalam stack dan tempat di mana operasi-operasi stack dilakukan.
#### 2. Data
Kumpulan elemen-elemen yang disimpan dalam stack. Elemen-elemen ini dapat berupa berbagai jenis data, seperti angka, karakter, string, atau tipe data lainnya.
#### 3. Bottom (Dasar)
Elemen data yang berada di posisi paling bawah stack. Bottom tidak dapat diakses secara langsung karena hanya elemen di top yang dapat diakses.
#### 4. Pointer
Penunjuk yang menandakan posisi top stack. Pointer selalu mengarah ke elemen data di top stack.

## Guided 

### 1. 

```C++
// stack.h
#ifndef STACK_H
#define STACK_H
#define Nil nullptr

#include <iostream>
using namespace std;

typedef struct node *address;

struct node {
    int dataAngka;
    address next;
};

struct stack{
    address top;
};

bool isEmpty(stack listStack);
void createStack(stack &listStack);
address alokasi(int angka);
void dealokasi(address &node);
void push(stack &listStack, address nodeBaru);
void pop(stack &listStack);
void update(stack &listStack, int posisi);
void view(stack listStack);
void searchData(stack listStack, int data);

#endif

// stack.cpp
#include "stack.h"
#include <iostream>

using namespace std;

bool isEmpty(stack listStack){
    if(listStack.top == Nil){
        return true;
    } else {
        return false;
    }
}

void createStack(stack &listStack){
    listStack.top = Nil;
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

void push(stack &listStack, address nodeBaru){
    nodeBaru->next = listStack.top;
    listStack.top = nodeBaru;
    cout << "Node " << nodeBaru->dataAngka << " berhasil ditambahkan kedalam stack!" << endl;
}

void pop(stack &listStack){
    address nodeHapus;
    if(isEmpty(listStack) == true){
        cout << "Stack kosong!" << endl;
    } else {
        nodeHapus = listStack.top;
        int data = nodeHapus->dataAngka;
        listStack.top = listStack.top->next;
        nodeHapus->next = Nil;
        dealokasi(nodeHapus);
        cout << "node " <<  data << " berhasil dihapus dari stack!" << endl;
    }
}

void update(stack &listStack, int posisi){
    if(isEmpty(listStack) == true){
        cout << "Stack kosong!" << endl;
    } else {
        if(posisi <= 0){
            cout << "Posisi tidak valid!" << endl;
        } else {
            address nodeBantu = listStack.top;
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

void view(stack listStack){ //mencetak dari tumpukan paling atas ke tumpukan paling bawah
    if(isEmpty(listStack) == true){
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = listStack.top;
        while(nodeBantu != Nil){
            cout << nodeBantu->dataAngka << " ";
            nodeBantu = nodeBantu->next;
        }
    }
    cout << endl;
}

void searchData(stack listStack, int data){
    if(isEmpty(listStack) == true){
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = listStack.top;
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
            cout << "Data " << data << " tidak ditemukan didalam stack!" << endl;
            cout << endl;
        }
    }
}

// main.cpp
#include "stack.h"
#include <iostream>

using namespace std;

int main(){
    stack listStack;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createStack(listStack);

    nodeA = alokasi(1);
    nodeB = alokasi(2);
    nodeC = alokasi(3);
    nodeD = alokasi(4);
    nodeE = alokasi(5);

    push(listStack, nodeA);
    push(listStack, nodeB);
    push(listStack, nodeC);
    push(listStack, nodeD);
    push(listStack, nodeE);
    cout << endl;

    cout << "--- Stack setelah push ---" << endl;
    view(listStack);
    cout << endl;

    pop(listStack);
    pop(listStack);
    cout << endl;

    cout << "--- Stack setelah pop 2 kali ---" << endl;
    view(listStack);
    cout << endl;

    update(listStack, 2);
    update(listStack, 1);
    update(listStack, 4);
    cout << endl;

    cout << "--- Stack setelah update ---" << endl;
    view(listStack);
    cout << endl;

    searchData(listStack, 4);
    searchData(listStack, 9);

    return 0;
}
```
kode c++ tersebut membuat stack kosong, menambah elemen (push), menghapus elemen teratas (pop), menampilkan isi stack (view), memperbarui data pada posisi tertentu (update), dan mencari data di dalam stack (search). pada file stack.h mendefinisikan struktur node dan stack beserta fungsi-fungsinya, sedangkan pada file stack.cpp berisi implementasinya seperti alokasi node baru, pengecekan kosong, operasi push/pop, dan traversal stack. pada main.cpp, beberapa node dibuat dan dimasukkan ke stack, lalu dilakukan operasi pop, update, dan search supaya kelihatan cara kerja stack-nya secara keseluruhan.

### 2. 

```C++
// stack.h
#ifndef STACK_H
#define STACK_H

#include <iostream>
#define MaxEl 20
#define Nil-1

typedef int infotype;

struct Stack{
    infotype info[MaxEl]; //array untuk menyimpan elemen stack
    int top; //indeks top stack
};

void CreateStack(Stack &S);
bool isEmpty(Stack S);
bool isFull(Stack S);
void push(Stack &S, infotype X); //menambahkan elemen ke stack
infotype pop(Stack &S); //mengambil elemen teratas dari stack
void printInfo(Stack S); //menampilkan isi stack
void balikStack(Stack &S); //membalik urutan elemen stack
#endif

// stack.cpp
#include "stack.h"
using namespace std;
// Fungsi untuk membuat stack baru dengan menginisialisasi top = Nil
void CreateStack(Stack &S) {
    S.top = Nil;  // Inisialisasi top dengan nilai Nil mendakan stack kosong
}

// Fungsi untuk mengecek apakah stack kosong
bool isEmpty(Stack S) {
    return S.top == Nil;  // Mengembalikan true jika top bernilai Nil, false jika tidak
}

// Fungsi untuk mengecek apakah stack penuh
bool isFull(Stack S) {
    return S.top == MaxEl - 1;  // Mengembalikan true jika top mencapai batas maksimum (MaxEl-1)
}

// Fungsi untuk menambah elemen ke dalam stack (push)
void push(Stack &S, infotype x) {
    if (!isFull(S)) {  // Cek apakah stack belum penuh
        S.top++;  // Increment nilai top
        S.info[S.top] = x;  // Masukkan nilai x ke array info pada indeks top
    } else {
        cout << "Stack Penuh!" << endl;  // Tampilkan pesan jika stack penuh
    }
}

// Fungsi untuk mengambil elemen teratas dari stack (pop)
infotype pop(Stack &S) {
    infotype x = -999;  // Inisialisasi nilai default jika stack kosong
    if (!isEmpty(S)) {  // Cek apakah stack tidak kosong
        x = S.info[S.top];  // Ambil nilai teratas
        S.top--;  // Decrement nilai top
    } else {
        cout << "Stack Kosong!" << endl;  // Tampilkan pesan jika stack kosong
    }
    return x;  // Kembalikan nilai yang diambil
}

// Fungsi untuk menampilkan isi stack
void printInfo(Stack S) {
    if (isEmpty(S)) {  // Cek apakah stack kosong
        cout << "Stack Kosong" << endl;  // Tampilkan pesan jika kosong
    } else {
        cout << "[TOP] ";  // Tampilkan penanda posisi top
        for (int i = S.top; i >= 0; i--) {  // Loop dari top sampai dasar stack
            cout << S.info[i] << " ";  // Tampilkan setiap elemen
        }
        cout << endl;  // Pindah baris setelah selesai
    }
}

// Fungsi untuk membalik urutan elemen dalam stack
void balikStack(Stack &S) {
    if (!isEmpty(S)) {  // Cek apakah stack tidak kosong
        Stack temp1, temp2;  // Deklarasi dua stack temporary
        CreateStack(temp1); CreateStack(temp2);  // Inisialisasi kedua stack temporary

        while (!isEmpty(S)) { push(temp1, pop(S)); }  // Pindahkan semua elemen ke temp1 (urutan terbalik)

        while (!isEmpty(temp1)) { push(temp2, pop(temp1)); }  // Pindahkan ke temp2 (urutan terbalik lagi)

        while (!isEmpty(temp2)) { push(S, pop(temp2)); }  // Kembalikan ke stack asal (urutan sudah benar)
    }
}

// main.cpp
#include "stack.h"
#include <iostream>

using namespace std;

int main() {
    Stack S;
    CreateStack(S);

    push(S, 3);
    push(S, 4);
    push(S, 8);
    pop(S);
    push(S, 2);
    push(S, 3);
    pop(S);
    push(S, 9);

    cout << "Stack Awal:" << endl;
    printInfo(S);

    cout << "balik stack" << endl;
    balikStack(S);

    cout << "Stack Setelah dibalik:" << endl;
    printInfo(S);

    return 0;
}
```
kode c++ tersebut merupakan stack dengan kapasitas array maks 20 elemen, yang punya fitur dasar seperti ngecek apakah stack kosong atau penuh, menambah data dari atas (push), mengambil data teratas (pop), dan menampilkan isi stack dari posisi top ke bawah. lalu ada fitur balikStack, yang membalik urutan elemen dalam stack dengan bantuan dua stack sementara. pada function main, beberapa angka dimasukkan dan di-pop terlebih dulu supaya isi stack berubah, lalu program menampilkan isi stack sebelum dan sesudah proses pembalikan supaya kelihatan perubahan urutannya.

## Unguided 

### 1. ADT Stack

```C++
// stack.h
#ifndef STACK_H
#define STACK_H

#include <iostream>
using namespace std;

#define MaxEl 20
#define Nil -1

typedef int infotype;

struct stack {
    infotype info[MaxEl];
    int top;
};

void createStack(stack &S);
void push(stack &S, infotype x);
infotype pop(stack &S);
void printInfo(stack S);
void balikStack(stack &S);

#endif

// stack.cpp
#include "stack.h"

using namespace std;

void createStack(stack &S) {
    S.top = -1;
}

void push(stack &S, int x) {
    if (S.top < MaxEl - 1) {
        S.top++;
        S.info[S.top] = x;
    } else {
        cout << "stack penuh" << endl;
    }
}

int pop(stack &S) {
    if (S.top >= 0) {
        int x = S.info[S.top];
        S.top--;
        return x;
    } else {
        cout << "stack kosong" << endl;
        return -1;
    }
}

void printInfo(stack S) {
    cout << "[TOP] ";
    for (int i = S.top; i >= 0; i--) {
        cout << S.info[i] << " ";
    }
    cout << endl;
}

void balikStack(stack &S) {
    stack temp;
    createStack(temp);

    while (S.top >= 0) {
        push(temp, pop(S));
    }

    S = temp;
}

// main.cpp
#include "stack.h"
#include <iostream>

using namespace std;

int main() {
    cout << "hello world!" << endl;

    stack S;
    createStack(S);

    push(S, 3);
    push(S, 4);
    push(S, 8);
    pop(S);
    push(S, 2);
    push(S, 3);
    pop(S);
    push(S, 9);

    printInfo(S);

    cout << "balik stack" << endl;
    balikStack(S);
    printInfo(S);

    return 0;
}

```
### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/ssheilanindya/103112400086_Sheila-Stephanie-Anindya/blob/main/output/output1-unguided1-modul7.png)

kode c++ tersebut merupakan stack dengan urutan LIFO (Last In, First Out). terdapaat fungsi untuk stack jadi kosong, memasukkan data ke atas (push), mengambil data teratas (pop), dan menunjukkan isi stack dari elemen paling atas sampai paling bawah. lalu ada fungsi balikStack yang membalik urutan elemen dengan cara mindahin semua isi stack ke stack sementara, lalu hasilnya dikembalikan lagi ke stack utama. pada function main, program melakukan beberapa operasi push-pop biar isi stack berubah dulu, lalu ditampilin sebelum dan sesudah dibalik supaya kelihatan perbedaannya.

### 2. Tambahkan prosedur pushAscending( in/out S : Stack, in x : integer)

```C++
// stack.h 
#ifndef STACK_H
#define STACK_H

#include <iostream>
using namespace std;

#define MaxEl 20
#define Nil -1

typedef int infotype;

struct stack {
    infotype info[MaxEl];
    int top;
};

void createStack(stack &S);
void push(stack &S, infotype x);
infotype pop(stack &S);
void printInfo(stack S);
void balikStack(stack &S);
void pushAscending(stack &S, infotype x);

#endif

// stack.cpp
#include "stack.h"

void createStack(stack &S) {
    S.top = Nil;
}

bool isEmpty(stack S) {
    return S.top == Nil;
}

bool isFull(stack S) {
    return S.top == MaxEl - 1;
}

void push(stack &S, infotype x) {
    if (!isFull(S)) {
        S.top++;
        S.info[S.top] = x;
    } else {
        cout << "stack penuh" << endl;
    }
}

infotype pop(stack &S) {
    infotype x = -999;

    if (!isEmpty(S)) {
        infotype x = S.info[S.top];
        S.top--;

        return x;

    } else {
        cout << "stack kosong" << endl;
        
        return x;
    }
}

void printInfo(stack S) {
    cout << "[TOP] ";
    for (int i = S.top; i >= 0; i--) {
        cout << S.info[i] << " ";
    }
    cout << endl;
}

void balikStack(stack &S) {
    if (!isEmpty(S)) {  
        stack temp1, temp2;  

        createStack(temp1); 
        createStack(temp2);  

        while (!isEmpty(S)) { 
            push(temp1, pop(S)); 
        }  

        while (!isEmpty(temp1)) { 
            push(temp2, pop(temp1)); 
        }  

        while (!isEmpty(temp2)) { 
            push(S, pop(temp2)); 
        }  
    }
}

void pushAscending(stack &S, infotype x) {
    stack temp;
    createStack(temp);

    while (!isEmpty(S) && S.info[S.top] > x) {
        push(temp, pop(S));
    }

    push(S, x);

    while (!isEmpty(temp)) {
        push(S, pop(temp));
    }
}

// main.cpp
#include <iostream>
#include "stack.h"

using namespace std;

int main() {
    cout << "hello world!" << endl;

    stack S;
    createStack(S);

    pushAscending(S,3);
    pushAscending(S,4);
    pushAscending(S,8);
    pushAscending(S,2);
    pushAscending(S,3);
    pushAscending(S,9);

    printInfo(S);

    cout << "balik stack" << endl;
    balikStack(S);
    printInfo(S);

    return 0;
}

```
### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 2_1](https://github.com/ssheilanindya/103112400086_Sheila-Stephanie-Anindya/blob/main/output/output1-unguided2-modul7.png)

kode c++ tersebut modifikasi/penambahan dari guided 1, yaitu menambahkan pushAscending. prosedur tersebut menyisipkan elemen baru ke dalam stack sambil menjaga agar isinya tetap terurut menaik dengan memindahkan sementara elemen yang lebih besar ke stack bantu. pada function main, program membuat stack, menambahkan beberapa nilai menggunakan pushAscending, mencetak isi stack yang sudah terurut, kemudian membalik urutannya dengan balikStack dan menampilkannya kembali

### 3. Tambahkan prosedur getInputStream( in/out S : Stack ).

```C++
// stack.h
#ifndef STACK_H
#define STACK_H

#include <iostream>
using namespace std;

#define MaxEl 20
#define Nil -1

typedef int infotype;

struct stack {
    infotype info[MaxEl];
    int top;
};

void createStack(stack &S);
void push(stack &S, infotype x);
infotype pop(stack &S);
void printInfo(stack S);
void balikStack(stack &S);
void pushAscending(stack &S, infotype x);
void getInputStream(stack &S);


#endif

// stack.cpp
#include "stack.h"

void createStack(stack &S) {
    S.top = Nil;
}

bool isEmpty(stack S) {
    return S.top == Nil;
}

bool isFull(stack S) {
    return S.top == MaxEl - 1;
}

void push(stack &S, infotype x) {
    if (!isFull(S)) {
        S.top++;
        S.info[S.top] = x;
    } else {
        cout << "stack penuh" << endl;
    }
}

infotype pop(stack &S) {
    infotype x = -999;

    if (!isEmpty(S)) {
        infotype x = S.info[S.top];
        S.top--;

        return x;

    } else {
        cout << "stack kosong" << endl;
        
        return x;
    }
}

void printInfo(stack S) {
    cout << "[TOP] ";
    for (int i = S.top; i >= 0; i--) {
        cout << S.info[i] << " ";
    }
    cout << endl;
}

void balikStack(stack &S) {
    if (!isEmpty(S)) {  
        stack temp1, temp2;  

        createStack(temp1); 
        createStack(temp2);  

        while (!isEmpty(S)) { 
            push(temp1, pop(S)); 
        }  

        while (!isEmpty(temp1)) { 
            push(temp2, pop(temp1)); 
        }  

        while (!isEmpty(temp2)) { 
            push(S, pop(temp2)); 
        }  
    }
}

void pushAscending(stack &S, infotype x) {
    stack temp;
    createStack(temp);

    while (!isEmpty(S) && S.info[S.top] > x) {
        push(temp, pop(S));
    }

    push(S, x);

    while (!isEmpty(temp)) {
        push(S, pop(temp));
    }
}

void getInputStream(stack &S) {
    char c;

    cout << "masukkan input : ";
 
    c = cin.get();

    if (c == '\n') c = cin.get();

    while (c != '\n') {
        if (!isFull(S)) {
            push(S, c - '0');
        }
        c = cin.get();
    }
}

// main.cpp
#include <iostream>
#include "stack.h"

using namespace std;

int main() {
    cout << "hello world!" << endl;

    stack S;
    createStack(S);
    getInputStream(S);
    printInfo(S);

    cout << "balik stack" << endl;

    balikStack(S);
    printInfo(S);

    return 0;
}

```
### Output Unguided 3 :

##### Output 1
![Screenshot Output Unguided 3_1](https://github.com/ssheilanindya/103112400086_Sheila-Stephanie-Anindya/blob/main/output/output1-unguided3-modul7.png)

kode c++ tersebut modifikasi/penambahan dari guided 1 dan 2, yaitu menambahkan getInputStream yang membaca input karakter dari pengguna dan menyimpannya ke dalam stack sebagai digit angka. pada function main, program menyapa pengguna, membuat stack baru, membaca input stream untuk mengisi stack, menampilkannya, lalu membalik urutannya menggunakan balikStack dan mencetak hasil akhirnya.

## Kesimpulan
Stack bekerja dengan prinsip LIFO, yaitu data yang terakhir masuk akan menjadi data pertama yang keluar. Melalui implementasi berbagai operasi seperti push, pop, menampilkan isi stack, membalik urutan, hingga penambahan fitur seperti update, pencarian data, pushAscending, dan getInputStream, cara kerja stack dapat dipahami dengan lebih jelas. Penggunaan stack berbasis array dan linked list juga menunjukkan perbedaan dalam fleksibilitas dan pengelolaan datanya. Secara keseluruhan, konsep dan operasi stack dapat diterapkan dengan baik untuk mengatur data secara terstruktur dan efisien.

## Referensi
[1]  Teknik Informatika Telkom University. (2025). Modul praktikum 7: Stack. Telkom University.
<br>
[2] Sianipar, Rismon Hasiholan. (2025). Pemrograman C++ Untuk Pemula. Jakarta: Penerbit Informatika. Diakses pada 12 Oktober 2025 melalui https://books.google.co.id/books?hl=en&lr=&id=tQR2DwAAQBAJ&oi=fnd&pg=PA1&dq=tipe+data+c%2B%2B&ots=rEn-jyJIHU&sig=7ZfteP1lCSbYBhucPaiU6xJNeBY&redir_esc=y#v=onepage&q=tipe%20data%20c%2B%2B&f=false

# <h1 align="center">Laporan Praktikum Modul 10 - Tree (Bagian Pertama) </h1>
<p align="center"> Sheila Stephanie Anindya - 103112400086 </p>

## Dasar Teori

### A. Rekursif<br/>
Rekursif adalah suatu proses dari sebuah fungsi yang dapat memanggil dirinya sendiri secara berulang-ulang. Berbeda dengan fungsi atau prosedur yang mana keduanya hanya bisa dilakukan pemanggilan dari fungsi atau prosedur lain, sementara rekursif dapat memanggil fungsinya sendiri[1]. Prosedur dan fungsi merupakan sub program yang bermanfaat dalam pemrograman, terutama untuk program atau proyek yang besar. Sub Program Rekursif adalah sub program yang memanggil dirinya sendiri selama kondisi pemanggilan dipenuhi. Dari segi algoritma, bila kita
mempertimbangkan penggunaan memori, waktu eksekusi sub program, sub program rekursif sering
bersifat tidak efisien. Dengan demikian sub program rekursif umumnya memiliki efisiensi dalam penulisan perintah, tetapi kadang tidak efisien secara algoritmis[2]. Secara umum gunakan penyelesaian rekursif hanya jika:
#### 1. Penyelesaian sulit dilaksanakan secara iteratif.
#### 2. Efisiensi dengan cara rekursif sudah memadai.
#### 3. Efisiensi bukan masalah dibandingkan dengan kejelasan logika program.

### B. Tree<br/>
Tree merupakan kumpulan node yang saling   terhubung   satu   sama   lain   dalam   suatu   kesatuan   yangmembentuk   layakya   struktur   sebuah   pohon.   Struktur   pohon   adalah   suatu   caramerepresentasikan suatu struktur hirarki (one-to-many) secara grafis yang mirip sebuah pohon,walaupun  pohon   tersebut   hanya   tampak   sebagai   kumpulan   node-node   dari   atas   ke   bawah.suatu struktur  data  yang tidak  linier  yang  menggambarkan  hubungan  yang hirarkis (one-to-many) dan tidak linier antara elemen-elemennya[3]. Tree digambarkan sebagai suatu graph tak berarah terhubung dan tidak terhubung dan tidak mengandung sirkuit. Karateristik dari suatu tree T adalah :
1. T kosong berarti empty tree
2. Hanya terdapat satu node tanpa pendahulu, disebut akar (root)
3. Semua node lainnya hanya mempunyai satu node pendahulu.

Jenis-jenis tree :
#### 1. Binary Tree
Setiap node di Binary Tree hanya dapat mempunyai maksimum 2 children tanpa pengecualian. Level
dari suatu tree dapat menunjukan berapa kemungkinan jumlah maximum nodes yang terdapat pada
tree tersebut. Misalnya, level tree adalah r, maka node maksimum yang mungkin adalah 2r[2].
#### 2. Ordered Tree
Ordered tree merupakan pohon yang urutan anak-anaknya penting[2].

## Guided 

### 1. Rekursif Pangkat 2

```C++
#include <iostream>

using namespace std;    

int pangkat_2 (int x) { // x pangkatnya
    if (x == 0) { // basis (kondisi dasar)
        return 1;
    } else if (x > 0 ) { // rekurens
        return 2 * pangkat_2(x - 1);
    }
}

int main() {
    cout << "=== rekursif pangkat 2 ===" << endl;

    int x;
    cout << "masukkan nilai x: ";
    cin >> x;
    cout << endl;
    cout << "2 pangkat " << x << " adalah " << pangkat_2(x);

    return 0;
}

```
kode c++ tersebut membuat fungsi rekursif pangkat_2 yang menghitung nilai 2 pangkat x, di mana jika x bernilai 0 fungsi mengembalikan 1 sebagai kondisi dasar, dan jika x lebih besar dari 0 fungsi memanggil dirinya sendiri sambil mengalikan hasil sebelumnya dengan 2 hingga mencapai basis; kemudian di fungsi main, program meminta input x dari pengguna dan menampilkan hasil perhitungan 2 pangkat x menggunakan fungsi rekursif tersebut.

### 2. Binary Search Tree

```C++
// .h
#ifndef BST_H
#define BST_H

#include <iostream>
using namespace std;

typedef int infotype; //alias infotype untuk data integer
typedef struct node *address;

struct node {
    infotype info;
    address left;
    address right;
};

bool isEmpty(address root); 
void createTree(address &root);

address newNode(infotype x);
address insertNode(address root, infotype x);

// fungsi traversal
void preOrder(address root); // tengah - kiri - kanan atau rood - child kiiri - child kanan
void inOrder(address root); // kiri - tengah - kanan atau child kiri - root - child kanan
void postOrder(address root); // kiri - kanan - tengah atau child kiri - child kanan - root

// utilities
int countNodes(address root); // menghitung jumlah node pada level tree
int treeDepth(address root); // menghitung height/kedalaman level tree

#endif
// .cpp
#include "BST.h"
#include <iostream>

using namespace std;

//isEmpty & createTree
bool isEmpty(address root) { //function untuk mengecek apakah BST kosong atau tidak
    if(root == NULL){
        return true;
    } else {
        return false;
    }
}

void createTree(address &root) { //function untuk membuat BST nya (root di-set sebagai NULL)
    root = NULL;
}


//alokasi & insert
address newNode(infotype x) { //function untuk memasukkan data (infotype) kedalam node
    address temp = new node;
    temp->info = x;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

address insertNode(address root, infotype x) { //function untuk memasukkan node kedalam BST
    if (root == NULL) {
        return newNode(x);
    }

    if (x < root->info) {
        root->left = insertNode(root->left, x);
    } else if (x > root->info) {
        root->right = insertNode(root->right, x);
    }

    return root;
}


//Traversal
void preOrder(address root) { //function traversal tree secara pre-order (tengah - kiri - kanan atau root - child kiri - child kanan)
    if (root != NULL) {
        cout << root->info << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

void inOrder(address root) { //function traversal tree secara in-order (kiri - tengah - kanan atau child kiri - root - child kanan)
    if (root != NULL) {
        inOrder(root->left);
        cout << root->info << " ";
        inOrder(root->right);
    }
}

void postOrder(address root) { //function traversal tree secara post-order (kiri - kanan - tengah atau child kiri - child kanan - root)
    if (root != NULL) {
        postOrder(root->left);
        postOrder(root->right);
        cout << root->info << " ";
    }
}


//Utilities
int countNodes(address root) { //function untuk menghitung size atau ukuran atau jumlah node yang ada didalam tree
    if (isEmpty(root) == true) {
        return 0;
    } else {
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
}

int treeDepth(address root) { //function untuk menghitung height atau kedalaman atau level tree
    if (isEmpty(root) == true) {
        return -1; //tree kosong jika depth = -1
    } else {
        int leftDepth = treeDepth(root->left);
        int rightDepth = treeDepth(root->right);
    
        return (leftDepth > rightDepth ? leftDepth : rightDepth) + 1;
    }
}
// main.cpp
#include <iostream>
#include "BST.h"

using namespace std;

int main(){
    address root;
    createTree(root);

    cout << "Binary Search Tree Insert & Traversal" << endl;
    cout << endl;

    root = insertNode(root, 20); // Root awal
    insertNode(root, 10);
    insertNode(root, 35);
    insertNode(root, 5);
    insertNode(root, 18);
    insertNode(root, 40);

    cout << "Hasil InOrder Traversal : ";
    inOrder(root);
    cout << endl;

    cout << "Hasil PreOrder Traversal : ";
    preOrder(root);
    cout << endl;

    cout << "Hasil PostOrder Traversal : ";
    postOrder(root);
    cout << endl;

    cout << endl;
    cout << "Jumlah Node : " << countNodes(root) << endl;
    cout << "Kedalaman Tree : " << treeDepth(root) << endl;


    return 0;
}
```
kode c++ tersebut membuat sebuah binary search tree (bst) dengan struktur node yang menyimpan nilai dan pointer anak kiri serta kanan, lalu menyediakan fungsi dasar seperti membuat tree, mengecek apakah tree kosong, membuat node baru, dan memasukkan data sesuai aturan bst. selain itu terdapat tiga fungsi traversal yaitu preorder, inorder, dan postorder untuk menampilkan isi tree dalam urutan berbeda, serta fungsi utilitas untuk menghitung jumlah node dan kedalaman tree; pada fungsi main, program membuat tree kosong, menambahkan beberapa nilai ke dalam bst, menampilkan hasil traversal, kemudian menampilkan jumlah node serta kedalaman tree secara keseluruhan.

### 3. Binary Search Tree

```C++
// .h
#ifndef BST_H
#define BST_H

#include <iostream>
using namespace std;

typedef int infotype; //alias infotype untuk data integer
typedef struct node *address;

struct node {
    infotype info;
    address left;
    address right;
};

bool isEmpty(address root); 
void createTree(address &root);

address newNode(infotype x);
address insertNode(address root, infotype x);

// fungsi traversal
void preOrder(address root); // tengah - kiri - kanan atau rood - child kiiri - child kanan
void inOrder(address root); // kiri - tengah - kanan atau child kiri - root - child kanan
void postOrder(address root); // kiri - kanan - tengah atau child kiri - child kanan - root

// utilities
int countNodes(address root); // menghitung jumlah node pada level tree
int treeDepth(address root); // menghitung height/kedalaman level tree

void searchByData(address root, infotype x);

// mostleft & mostright
address mostLeft(address root); // function menampilkan node paling kiri
                                // node dgn nilai terkecil
address mostRight(address root); // function menampilkan node paling kanan
                                // node dgn nilai terbesar

bool deleteNode(address &root, infotype x); // hapus berdasar parameter infotype
void deleteTree(address &root); // menghapus seluruh node bst

#endif
// .cpp
#include "BST2.h"
#include <iostream>

using namespace std;

//FUNCTION & PROSEDUR SEBELUMNYA
//isEmpty & createTree
bool isEmpty(address root) { //function untuk mengecek apakah BST kosong atau tidak
    if(root == NULL){
        return true;
    } else {
        return false;
    }
}

void createTree(address &root) { //function untuk membuat BST nya (root di-set sebagai NULL)
    root = NULL;
}


//alokasi & insert
address newNode(infotype x) { //function untuk memasukkan data (infotype) kedalam node
    address temp = new node;
    temp->info = x;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

address insertNode(address root, infotype x) { //function untuk memasukkan node kedalam BST
    if (root == NULL) {
        return newNode(x);
    }

    if (x < root->info) {
        root->left = insertNode(root->left, x);
    } else if (x > root->info) {
        root->right = insertNode(root->right, x);
    }

    return root;
}


//Traversal
void preOrder(address root) { //function traversal tree secara pre-order (tengah - kiri - kanan atau root - child kiri - child kanan)
    if (root != NULL) {
        cout << root->info << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

void inOrder(address root) { //function traversal tree secara in-order (kiri - tengah - kanan atau child kiri - root - child kanan)
    if (root != NULL) {
        inOrder(root->left);
        cout << root->info << " ";
        inOrder(root->right);
    }
}

void postOrder(address root) { //function traversal tree secara post-order (kiri - kanan - tengah atau child kiri - child kanan - root)
    if (root != NULL) {
        postOrder(root->left);
        postOrder(root->right);
        cout << root->info << " ";
    }
}


//Utilities
int countNodes(address root) { //function untuk menghitung size atau ukuran atau jumlah node yang ada didalam tree
    if (isEmpty(root) == true) {
        return 0;
    } else {
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
}

int treeDepth(address root) { //function untuk menghitung height atau kedalaman atau level tree
    if (isEmpty(root) == true) {
        return -1; //tree kosong jika depth = -1
    } else {
        int leftDepth = treeDepth(root->left);
        int rightDepth = treeDepth(root->right);
    
        return (leftDepth > rightDepth ? leftDepth : rightDepth) + 1;
    }
}


//FUNCTION & PROSEDUR BARU
//searching
void searchByData(address root, infotype x) { //function untuk melakukan searching data tertentu
    if(isEmpty(root) == true){
        cout << "BST kosong!" << endl;
    } else {
        address nodeBantu = root;
        address parent = NULL;
        bool ketemu = false;
        while(nodeBantu != NULL){
            if(x < nodeBantu->info){
                parent = nodeBantu;
                nodeBantu = nodeBantu->left;
            } else if(x > nodeBantu->info){
                parent = nodeBantu;
                nodeBantu = nodeBantu->right;
            } else if(x == nodeBantu->info){
                ketemu = true;
                break;
            }
        }
        if(ketemu == false){
            cout << "Data tidak ditemukan" << endl;
        } else if(ketemu == true){
            cout << "Data ditemukan didalam BST!" << endl;
            cout << "Data Angka : " << nodeBantu->info << endl;

            //menampilkan parentnya & pengecekan sibling
            address sibling = NULL;
            if(parent != NULL){
                cout << "Parent : " << parent->info << endl;
                if(parent->left == nodeBantu){
                    sibling = parent->right;
                } else if(parent->right == nodeBantu){
                    sibling = parent->left;
                }
            } else {
                cout << "Parent : - (node root)"<< endl;
            }

            //menampilkan siblingnya
            if(sibling != NULL){
                cout << "Sibling : " << sibling->info << endl;
            } else {
                cout << "Sibling : - " << endl;
            }

            //menampilkan childnya
            if(nodeBantu->left != NULL){
                cout << "Child kiri : " << nodeBantu->left->info << endl;
            } else if(nodeBantu->left == NULL){
                cout << "Child kiri : -" << endl;
            }
            if(nodeBantu->right != NULL){
                cout << "Child kanan : " << nodeBantu->right->info << endl;
            } else if(nodeBantu->right == NULL){
                cout << "Child kanan : -" << endl;
            }
        }
    }
}


//mostleft & mostright
address mostLeft(address root) { //function untuk menampilkan mostleft atau node paling kiri (node dengan nilai terkecil) didalam BST
    while (root->left != NULL){
        root = root->left;
    }
    return root;
}

address mostRight(address root) { //function untuk menampilkan mostright atau node paling kanan (node dengan nilai terbesar) didalam BST
    while (root->right != NULL){
        root = root->right;
    }
    return root;
}


//delete
bool deleteNode(address &root, infotype x) { //function untuk menghapus node tertentu didalam BST (menghapus berdasarkan parameter infotype)
    if (root == NULL) {
        return false; //data tidak ditemukan di subtree ini
    } else {
        if (x < root->info) {
            return deleteNode(root->left, x);
        } else if (x > root->info) {
            return deleteNode(root->right, x);
        } else {
            //jika node yang mau dihapus ditemukan
            //Case 1 : node yang mau dihapus adalah leaf
            if (root->left == NULL && root->right == NULL) {
                address temp = root;
                root = NULL;
                delete temp;
            }
            //Case 2 : node yang mau dihapus hanya punya right child
            else if (root->left == NULL) {
                address temp = root;
                root = root->right;
                delete temp;
            }
            //Case 3 : node yang mau dihapus hanya punya left child
            else if (root->right == NULL) {
                address temp = root;
                root = root->left;
                delete temp;
            }
            // Case 4 : jika node yang mau dihapus punya dua child, maka ambil mostleft dari subtree kanan untuk menggantikan node yang mau dihapus
            else {
                //mostleft dari subtree kanan = node successor (node penerus)
                address successor = mostLeft(root->right);
                //salin data successor ke node saat ini
                root->info = successor->info;
                //hapus successor pada subtree kanan
                return deleteNode(root->right, successor->info);
            }
            return true; //berhasil dihapus
        }
    }
}

void deleteTree(address &root) { //prosedur untuk menghapus BST (menghapus seluruh node BST)
    if(root == NULL){
        return;
    } else {
        deleteTree(root->left);
        deleteTree(root->right);
        delete root;
        root = NULL;
    }
}
// main.cpp
#include <iostream>
#include "BST2.h"

using namespace std;

int main(){
    address root;
    createTree(root);

    cout << "=== Binary Search Tree ==" << endl;
    cout << endl;

    root = insertNode(root, 30); // Root awal
    insertNode(root, 15);
    insertNode(root, 35);
    insertNode(root, 11);
    insertNode(root, 17);
    insertNode(root, 20);
    insertNode(root, 38);
    insertNode(root, 16);
    insertNode(root, 22);
    insertNode(root, 33);
    insertNode(root, 18);

    cout << "Hasil InOrder Traversal : ";
    inOrder(root);
    cout << endl;

    cout << endl;
    cout << "Jumlah Node : " << countNodes(root) << endl;
    cout << "Kedalaman Tree : " << treeDepth(root) << endl;

    cout << endl;
    searchByData(root, 17);
    
    cout << endl;
    cout << "Node mostleft : " << mostLeft(root)->info << endl;
    cout << "Node mostright : " << mostRight(root)->info << endl;

    cout << endl;
    infotype angkaHapus;
    cout << "Masukkan angka yang ingin dihapus: ";
    cin >> angkaHapus;
    //misal angka yang dihapus adalah angka 17
    if(deleteNode(root, angkaHapus)){
        cout << "Data " << angkaHapus << " berhasil dihapus!" << endl;
    } else {
        cout << "Data " << angkaHapus << " tidak ditemukan!" << endl;
    }
    cout << endl;

    searchByData(root, 17);
    cout << endl;
    searchByData(root, 18);

    cout << endl;
    cout << "Hasil InOrder Traversal : ";
    inOrder(root);
    cout << endl;

    cout << endl;
    deleteTree(root);
    cout << "Seluruh tree berhasil dihapus!" << endl;

    cout << endl;
    if(isEmpty(root) == true){
        cout << "BST kosong!" << endl;
    } else {
        cout << "Hasil InOrder Traversal : ";
        inOrder(root);
    }

    return 0;
}
```
kode c++ tersebut merupakan binary search tree (bst) dengan fitur dasar seperti membuat tree, memasukkan node baru, melakukan traversal preorder–inorder–postorder, menghitung jumlah node dan kedalaman tree, serta dilengkapi fitur lanjutan yaitu pencarian data beserta informasi parent–sibling–child, menemukan node bernilai paling kecil dan terbesar melalui mostleft dan mostright, menghapus node dengan empat kemungkinan kasus (leaf, satu child kiri, satu child kanan, atau dua child dengan successor), hingga menghapus seluruh tree. pada main, program mengisi bst dengan beberapa nilai, menampilkan traversal dan informasi tree, melakukan pencarian, menampilkan nilai paling kecil dan terbesar, menerima input angka yang ingin dihapus, lalu menampilkan hasil akhir dan menghapus seluruh tree sebelum mengecek kembali apakah bst sudah kosong.

## Unguided 

### 1. Buatlah implementasi ADT Binary Search Tree pada file “bstree.cpp” dan cobalah hasil implementasi ADT pada file “main.cpp”

```C++
// .h
#ifndef BSTREE_H
#define BSTREE_H

typedef int infotype; 
typedef struct node *address;

struct node {
    infotype info;
    address left;
    address right;
};

address alokasi(infotype x);
void insertNode(address &root, infotype x);
address findNode(infotype x, address root);
void printInorder(address root);
void InOrder(address root);

#endif
// .cpp
#include "bstree.h"
#include <iostream>

using namespace std;

address alokasi(infotype x) {
    address P = new node;
    P -> info = x;
    P -> left = NULL;
    P -> right = NULL;
    return P;
}

void insertNode(address &root, infotype x) {
    if (root == NULL) {
        root = alokasi(x);
    } else if (x < root -> info) {
        insertNode(root -> left, x);
    } else if (x > root -> info) {
        insertNode(root -> right, x);
    } 
}

address findNode(infotype x, address root) {
    if (root == NULL) return NULL;
    if (x == root -> info) return root;
    else if (x < root -> info) return findNode(x, root -> left);
    else return findNode(x, root -> right);
}

void printInorder(address root) {
    if (root != NULL) {
        printInorder(root -> left);
        cout << root -> info << " - ";
        printInorder(root -> right);
    }
}

void InOrder(address root) {
    printInorder(root);
}
// main.cpp
#include "bstree.h"
#include <iostream>

using namespace std;

int main() {
    cout << "hello world!" << endl;

    address root = NULL;

    insertNode(root,1);
    insertNode(root,2);
    insertNode(root,6);
    insertNode(root,4);
    insertNode(root,5);
    insertNode(root,3);
    insertNode(root,6);
    insertNode(root,7);

    InOrder(root);
    return 0;
}
```
### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/ssheilanindya/103112400086_Sheila-Stephanie-Anindya/blob/main/output/output1-unguided1-modul10.png)

kode c++ tersebut membuat struktur binary search tree sederhana dengan fitur untuk mengalokasikan node baru, memasukkan data ke dalam tree sesuai aturan bst, mencari node berdasarkan nilai tertentu, dan menampilkan isi tree menggunakan traversal inorder. pada fungsi main, program membuat root kosong lalu memasukkan beberapa angka sehingga tree terbentuk secara otomatis dalam struktur kiri–kanan, kemudian memanggil fungsi inorder untuk mencetak data secara berurutan dari yang terkecil hingga terbesar. 

### 2. Buatlah fungsi untuk menghitung jumlah node dengan fungsi berikut.

```C++
// .h
#ifndef BSTREE_H
#define BSTREE_H

typedef int infotype;
typedef struct node *address;

struct node {
    infotype info;
    address left;
    address right;
};

address alokasi(infotype x);
void insertNode(address &root, infotype x);

void printInorder(address root);
void InOrder(address root);

int hitungJumlahNode(address root);
int hitungTotalInfo(address root);
int hitungKedalaman(address root);

#endif
// .cpp
#include "bstree.h"
#include <iostream>
 
using namespace std;

address alokasi(infotype x) {
    address P = new node;
    P->info = x;
    P->left = NULL;
    P->right = NULL;
    return P;
}

void insertNode(address &root, infotype x) {
    if (root == NULL) {
        root = alokasi(x);
    } else if (x < root->info) {
        insertNode(root->left, x);
    } else if (x > root->info) {
        insertNode(root->right, x);
    }
}

void printInorder(address root) {
    if (root != NULL) {
        printInorder(root->left);
        cout << root->info << " - ";
        printInorder(root->right);
    }
}

void InOrder(address root) {
    printInorder(root);
}

int hitungJumlahNode(address root) {
    if (root == NULL) return 0;
    return 1 + hitungJumlahNode(root->left) + hitungJumlahNode(root->right);
}

int hitungTotalInfo(address root) {
    if (root == NULL) return 0;
    return root->info + hitungTotalInfo(root->left) + hitungTotalInfo(root->right);
}

int hitungKedalaman(address root) {
    if (root == NULL) return 0;
    int leftDepth = hitungKedalaman(root->left);
    int rightDepth = hitungKedalaman(root->right);
    return 1 + max(leftDepth, rightDepth);
}
// main.cpp
#include <iostream>
#include "bstree.h"

using namespace std;

int main() {
    cout << "hello world!" << endl;

    address root = NULL;

    insertNode(root,1);
    insertNode(root,2);
    insertNode(root,6);
    insertNode(root,4);
    insertNode(root,5);
    insertNode(root,3);
    insertNode(root,6); 
    insertNode(root,7);

    InOrder(root);
    cout << endl;

    cout << "kedalaman : " << hitungKedalaman(root) << endl;
    cout << "jumlah node : " << hitungJumlahNode(root) << endl;
    cout << "total : " << hitungTotalInfo(root) << endl;

    return 0;
}
```
### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 2_1](https://github.com/ssheilanindya/103112400086_Sheila-Stephanie-Anindya/blob/main/output/output1-unguided2-modul10.png)

kode c++ tersebut merupakan modifikasi dari unguided 1 yaitu menambahkan hitungJumlahNode untuk menghitung total node di dalam tree, hitungTotalInfo untuk menjumlahkan seluruh nilai info dalam node tree, dan hitungKedalaman untuk mengetahui kedalaman atau tinggi tree. pada fungsi main, program mengisi bst dengan beberapa angka, mencetak isi tree secara inorder, lalu menampilkan hasil perhitungan kedalaman tree, jumlah node, dan total seluruh nilai node.

### 3. Print tree secara pre-order dan post-order.

```C++
// .h
#ifndef BSTREE_H
#define BSTREE_H

typedef int infotype;
typedef struct node *address;

struct node {
    infotype info;
    address left;
    address right;
};

// dasar
address alokasi(infotype x);
void insertNode(address &root, infotype x);
address findNode(infotype x, address root);

// traversal
void printInorder(address root);
void InOrder(address root);

void printPreOrder(address root);
void printPostOrder(address root);

// perhitungan
int hitungJumlahNode(address root);
int hitungTotalInfo(address root);
int hitungKedalaman(address root, int start);

#endif
// .cpp
#include <iostream>
#include "bstree.h"

using namespace std;

address alokasi(infotype x) {
    address P = new node;
    P -> info = x;
    P -> left = NULL;
    P -> right = NULL;
    return P;
}

void insertNode(address &root, infotype x) {
    if (root == NULL) {
        root = alokasi(x);
    } else if (x < root -> info) {
        insertNode(root -> left, x);
    } else if (x > root -> info) {
        insertNode(root -> right, x);
    } 
}

address findNode(infotype x, address root) {
    if (root == NULL) return NULL;
    if (x == root -> info) return root;
    else if (x < root -> info) return findNode(x, root -> left);
    else return findNode(x, root -> right);
}

void printInorder(address root) {
    if (root != NULL) {
        printInorder(root -> left);
        cout << root -> info << " - ";
        printInorder(root -> right);
    }
}

void InOrder(address root) {
    printInorder(root);
}

void printPreOrder(address root) {
    if (root != NULL) {
        cout << root -> info << " - ";
        printPreOrder(root -> left);
        printPreOrder(root -> right);
    }
}

void printPostOrder(address root) {
    if (root != NULL) {
        printPostOrder(root -> left);
        printPostOrder(root -> right);
        cout << root->info << " - ";
    }
}

int hitungJumlahNode(address root) {
    if (root == NULL) return 0;
    return 1 + hitungJumlahNode(root -> left) + hitungJumlahNode(root -> right);
}

int hitungTotalInfo(address root) {
    if (root == NULL) return 0;
    return root->info + hitungTotalInfo(root -> left) + hitungTotalInfo(root -> right);
}

int hitungKedalaman(address root, int start) {
    if (root == NULL) return start;

    int leftDepth = hitungKedalaman(root -> left, start + 1);
    int rightDepth = hitungKedalaman(root -> right, start + 1);

    return (leftDepth > rightDepth) ? leftDepth : rightDepth;
}
// main.cpp
#include "bstree.h"
#include <iostream>

using namespace std;

int main() {

    cout << "hello world!" << endl;

    address root = NULL;

    insertNode(root,1);
    insertNode(root,2);
    insertNode(root,6);
    insertNode(root,4);
    insertNode(root,5);
    insertNode(root,3);
    insertNode(root,6); 
    insertNode(root,7);

    cout << "InOrder   : ";
    InOrder(root);
    cout << endl;

    cout << "PreOrder  : ";
    printPreOrder(root);
    cout << endl;

    cout << "PostOrder : ";
    printPostOrder(root);
    cout << endl;

    cout << "kedalaman : " << hitungKedalaman(root,0) << endl;
    cout << "jumlah node : " << hitungJumlahNode(root) << endl;
    cout << "total : " << hitungTotalInfo(root) << endl;

    return 0;
}
```
### Output Unguided 3 :

##### Output 1
![Screenshot Output Unguided 3_1](https://github.com/ssheilanindya/103112400086_Sheila-Stephanie-Anindya/blob/main/output/output1-unguided3-modul10.png)

kode c++ tersebut merupakan modifikasi dari unguided 1 dan 2 yaitu menambahkan inorder, preorder, dan postorder untuk menampilkan isi tree dalam urutan yang berbeda, serta fungsi perhitungan seperti menghitung jumlah node, menjumlahkan semua nilai info, dan menghitung kedalaman tree menggunakan parameter awal sebagai level. pada fungsi main, program memasukkan beberapa nilai ke dalam bst, lalu menampilkan hasil traversal dan perhitungan kedalaman, jumlah node, serta total seluruh nilai info di dalam tree.

## Kesimpulan
Secara keseluruhan, modul 10 menjelaskan konsep dasar rekursif dan struktur data tree, khususnya Binary Search Tree (BST), serta implementasinya dalam bahasa C++. Rekursif digunakan ketika suatu masalah dapat dipecah menjadi versi lebih kecil dari masalah itu sendiri, seperti perhitungan pangkat yang memanggil fungsi secara berulang hingga mencapai kondisi dasar. Sementara itu, BST adalah struktur data hierarkis yang menyimpan data secara terurut sehingga proses pencarian, penyisipan, dan penghapusan dapat dilakukan secara efisien. Melalui berbagai implementasi, ditunjukkan cara membangun node, memasukkan data sesuai aturan BST, melakukan traversal (inorder, preorder, postorder), menghitung jumlah node dan kedalaman tree, melakukan pencarian lengkap beserta informasi parent–sibling–child, menemukan nilai minimum dan maksimum, serta menghapus node hingga seluruh tree

## Referensi
[1] Rifai, Akhmad Ridlo. (1227050013). Medium. Diakses pada 7 Desember 2025 melalui https://medium.com/@akhmdrdlo/oleh-akhmad-ridlo-rifai-1227050013-5d2b8144a359
[2] Fakultas Informatika. (2025). Modul Praktikum Struktur Data Modul 10: TREE (Bagian Pertama). Bandung: Telkom University.
[3] Universitas Muhammadiyah Prof. Dr. Hamka. "Struktur Data Tree in C". Studocu. Diakses pada 7 Desember 2025 melalui https://www.studocu.id/id/document/universitas-muhammadiyah-prof-dr-hamka/praktikum-struktur-data/struktur-data-tree-in-c/33295531
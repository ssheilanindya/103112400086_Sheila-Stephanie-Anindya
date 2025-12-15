# <h1 align="center">Laporan Praktikum Modul 13 - Multi Linked List </h1>
<p align="center"> Sheila Stephanie Anindya - 103112400086 </p>

## Dasar Teori

### A. Multi Linked List<br/>
Multi Linked List merupakan sekumpulan list yang berbeda yang memiliki suatu keterhubungan satu sama lain. Tiap elemen dalam multi link list dapat membentuk list sendiri.Biasanya ada yang bersifat sebagai list induk dan list anak[1]. Dalam Multi Linked List, setiap node dapat memiliki N jumlah pointer ke node lain. Multi Linked List umumnya digunakan untuk mengatur beberapa urutan dari satu set elemen[2].
#### 1. Sifat - sifat MLL
a. Semua node (simpul) diintegrasikan menggunakan tautan-tautan pointer (penunjuk).
b. Node yang terhubung saling terkoneksi dengan data terkait.
c. Node mengandung pointer dari satu struktur ke struktur lainnya.

### B. Insert <br/>
Insert merupakan operasi dasar pada struktur data yang berarti menambahkan elemen data baru ke dalam koleksi atau struktur yang sudah ada.
#### 1. Insert Anak
Operasi ini adalah penambahan node/elemen baru ke dalam sub-list yang dimiliki oleh node/elemen Induk yang sudah ada. Dalam penambahan node/elemen anak harus diketahui dulu node/elemen induknya.
#### 2. Insert Induk
Operasi ini adalah penambahan node baru pada tingkat daftar utama (induk). Node yang disisipkan ini akan menjadi node Induk yang baru, yang menjadi kepala bagi node-node Anak.

### B. Delete <br/>
Operasi delete adalah kebalikan dari insert, yaitu menghapus elemen data dari struktur. Dalam MLL, ini melibatkan pencarian node, pemutusan tautan (pointer) yang mengarah ke node tersebut, dan membebaskan memori node.
#### 1. Delete Anak
Sama dengan insert anak untuk delete anak maka harus diketahui dulu induknya
#### 2. Delete Induk
Untuk delete elemen induk maka saat di hapus maka seluruh anak dengan induk tersebut juga harus
dihapus



## Guided 

### 1. Multi Linked List

```C++
// mll.h
#ifndef MLL_H
#define MLL_H

#include <iostream>
using namespace std;

typedef struct nodeParent *NodeParent; //alias pointer ke struct nodeParent
typedef struct nodeChild *NodeChild;   //alias pointer ke struct nodeChild

struct  nodeChild{ //node child
    string idMakanan;
    string namaMakanan;
    NodeChild next;
    NodeChild prev;
};

struct listAnak{ //list child
    NodeChild first;    
    NodeChild last;
};

struct nodeParent{ //node parent
 string idKategoriMakanan;
 string namaKategoriMakanan;
 NodeParent next;
 NodeParent prev;
 listAnak L_Anak; //list child
};

struct listInduk{ //list parent
    NodeParent first;
    NodeParent last;
};

//create list 
void createListInduk(listInduk &LInduk);
void createListAnak(listAnak &Lanak);

//alokasi &d elokasi parent
NodeParent alokasiNodeParent(string idkategoriMakanan, string namaKategoriMakanan);
void dealokasiNodeParent(NodeParent &NodeInduk);

//alokasi & delokasi child
NodeChild alokasiNodeChild(string idmakanan, string namamakanan);
void dealokasiNodeChild(NodeChild &NodeAnak);

//operasi pada parent
void insertLastParent(listInduk &LInduk, NodeParent nodeBaruParent);
void hapusListAnak(listAnak &LAnak);
void deleteAfterParent(listInduk &LInduk, NodeParent nodePrev);

//operasi pada child
void insertLastChild(listAnak &LAnak, NodeChild nodeBaruChild);
void deleteAfterChild(listAnak &LAnak, NodeChild nodePrev); 
void findChildByID(listInduk &LInduk, string IDCari);

//operasi print
void printStrukturMLL(listInduk &LInduk);

#endif
// mll.cpp
#include "mll.h"
#include <iostream>

using namespace std;

//create list
void createListInduk(listInduk &LInduk){
    LInduk.first = LInduk.last = NULL;
}

void createListAnak(listAnak &LAnak){
    LAnak.first = LAnak.last = NULL;
}

//alokasi & dealokasi parent
NodeParent alokasiNodeParent(string idKategoriMakanan, string namaKategoriMakanan){
    NodeParent nodeBaruParent = new nodeParent;
    nodeBaruParent->idKategoriMakanan = idKategoriMakanan;
    nodeBaruParent->namaKategoriMakanan = namaKategoriMakanan;
    nodeBaruParent->next = NULL;
    nodeBaruParent->prev = NULL;
    createListAnak(nodeBaruParent->L_Anak);
    return nodeBaruParent;
}

void dealokasiNodeParent(NodeParent &nodeInduk){
    if(nodeInduk != NULL) {
        nodeInduk->next = nodeInduk->prev = NULL;
        delete nodeInduk;
        nodeInduk = NULL;
    }
}

//alokasi & delaokasi child
NodeChild alokasiNodeChild(string idMakanan, string namaMakanan){
    NodeChild nodeBaruChild = new nodeChild;
    nodeBaruChild->idMakanan = idMakanan;
    nodeBaruChild->namaMakanan = namaMakanan;
    nodeBaruChild->next = NULL;
    nodeBaruChild->prev = NULL;
    return nodeBaruChild;
}

void dealokasiNodeChild(NodeChild &nodeAnak){
    if(nodeAnak != NULL) {
        nodeAnak->next = nodeAnak->prev = NULL;
        delete nodeAnak;
        nodeAnak = NULL;
    }
}

//operasi pada parent
void insertLastParent(listInduk &LInduk, NodeParent nodeBaruParent){
    if(LInduk.first == NULL) {
        LInduk.first = LInduk.last = nodeBaruParent;
    } else {
        nodeBaruParent->prev = LInduk.last;
        LInduk.last->next = nodeBaruParent;
        LInduk.last = nodeBaruParent;
    }
    cout << "Node parent "<< nodeBaruParent->namaKategoriMakanan << " berhasil ditambahkan kedalam urutan terakhir di list Induk!" << endl;
}

void hapusListAnak(listAnak &LAnak){
    NodeChild nodeBantu = LAnak.first;
    while(nodeBantu != NULL) {
        NodeChild nodeHapus = nodeBantu;
        nodeBantu = nodeBantu->next;
        dealokasiNodeChild(nodeHapus);
    }
    LAnak.first = LAnak.last = NULL;
}

void deleteAfterParent(listInduk &LInduk, NodeParent nodePrev){
    if(LInduk.first == NULL){
        cout << "List induk kosong!" << endl;
    } else {
        if(nodePrev != NULL && nodePrev->next != NULL){
            NodeParent nodeHapus = nodePrev->next;
            nodePrev->next = nodeHapus->next;
            if (nodeHapus->next != NULL){
                (nodeHapus->next)->prev = nodePrev;
            } else {
                LInduk.last = nodePrev;
            }
            nodeHapus->next = NULL;
            if(nodeHapus->L_Anak.first != NULL){
                hapusListAnak(nodeHapus->L_Anak);
            }
            dealokasiNodeParent(nodeHapus);
            cout << "Node parent setelah node " << nodePrev->namaKategoriMakanan << " berhasil dihapus beserta anak-anaknya!" << endl;
        } else {
            cout << "Node prev tidak valid!" << endl;
        }
    }
}

//operasi pada child
void insertLastChild(listAnak &LAnak, NodeChild nodeBaruChild){
    if(LAnak.first == NULL) {
        LAnak.first = LAnak.last = nodeBaruChild;
    } else {
        nodeBaruChild->prev = LAnak.last;
        LAnak.last->next = nodeBaruChild;
        LAnak.last = nodeBaruChild;
    }
    cout << "Node child "<< nodeBaruChild->namaMakanan << " berhasil ditambahkan kedalam urutan terakhir di list Anak!" << endl;
}

void deleteAfterChild(listAnak &LAnak, NodeChild nodePrev){
    if(LAnak.first == NULL){
        cout << "List anak kosong!" << endl;
    } else {
        if(nodePrev != NULL && nodePrev->next != NULL){
            NodeChild nodeHapus = nodePrev->next;
            nodePrev->next = nodeHapus->next;
            if (nodeHapus->next != NULL){
                (nodeHapus->next)->prev = nodePrev;
            } else {
                LAnak.last = nodePrev;
            }
            nodeHapus->next = NULL;
            dealokasiNodeChild(nodeHapus);
            cout << "Node child setelah node " << nodePrev->namaMakanan << " berhasil dihapus!" << endl;
        } else {
            cout << "Node prev tidak valid!" << endl;
        }
    }
}
void findChildByID(listInduk &LInduk, string IDCari){
    if(LInduk.first == NULL){
        cout << "List induk kosong!" << endl;
    } else {
        NodeParent nodeBantuParent = LInduk.first;
        int indexParent = 1;
        int ketemu = false;
        while(nodeBantuParent != NULL){
            NodeChild nodeBantuChild = nodeBantuParent->L_Anak.first;
            int indexChild = 1;
            while(nodeBantuChild != NULL){
                if(nodeBantuChild->idMakanan == IDCari) {
                    cout << "Data ID child ditemukan pada list anak dari node parent " << nodeBantuParent->namaKategoriMakanan << " pada posisi ke-" << indexChild << "!" << endl;
                    cout << "--- Data Child ---" << endl;
                    cout << "ID Child (ID Makanan) : " << nodeBantuChild->idMakanan << endl;
                    cout << "Posisi dalam list anak : posisi ke-" << indexChild << endl;
                    cout << "Nama Makanan : " << nodeBantuChild->namaMakanan << endl;
                    cout << "---------------------------" << endl;
                    cout << "--- Data Parent ---" << endl;
                    cout << "ID Parent (ID Kategori Makanan): " << nodeBantuParent->idKategoriMakanan << endl;
                    cout << "Posisi dalam list induk : posisi ke-" << indexParent << endl;
                    cout << "Nama Kategori Makanan : " << nodeBantuParent->namaKategoriMakanan << endl;
                    ketemu = true;
                    break;
                } else {
                    nodeBantuChild = nodeBantuChild->next;
                    indexChild++;
                }
            }
            if(ketemu){
                break;
            } else {
                nodeBantuParent = nodeBantuParent->next;
                indexParent++;
            }
        }
        if(!ketemu){
            cout << "Data ID child tidak ditemukan didalam list anak!" << endl;
        }
    }
}

//operasi print
void printStrukturMLL(listInduk &LInduk){
    if(LInduk.first == NULL) {
        cout << "List induk kosong!" << endl;
    } else {
        NodeParent nodeBantuParent = LInduk.first;
        int indexParent = 1;
        while(nodeBantuParent != NULL) {
            cout << "=== Parent " << indexParent << " ===" << endl;
            cout << "ID Kategori Makanan : " << nodeBantuParent->idKategoriMakanan << endl;
            cout << "Nama Kategori Makanan : " << nodeBantuParent->namaKategoriMakanan << endl;

            //print list anak dari node parentnya
            NodeChild nodeBantuChild = nodeBantuParent->L_Anak.first;
            if(nodeBantuChild == NULL) {
                cout << "  (tidak ada child)" << endl;
            } else {
                int indexChild = 1;
                while(nodeBantuChild != NULL) {
                    cout << "  - Child " << indexChild << " :" << endl;
                    cout << "      ID Makanan : " << nodeBantuChild->idMakanan << endl;
                    cout << "      Nama Makanan : " << nodeBantuChild->namaMakanan << endl;
                    nodeBantuChild = nodeBantuChild->next;
                    indexChild++;
                }
            }
            cout << "---------------------------" << endl;
            nodeBantuParent = nodeBantuParent->next;
            indexParent++;
        }
    }
}
// main.cpp
#include "mll.h"

#include <iostream>

using namespace std;

int main(){
    //1.instalasi List
    listInduk LInduk;
    createListInduk(LInduk);

    //2.membuat Data Parent (kategori makanan)
    NodeParent k01 = alokasiNodeParent("K01", "Makanan Berat");
    insertLastParent(LInduk, k01);
    NodeParent k02 = alokasiNodeParent("K02", "Minuman");
    insertLastParent(LInduk, k02);
    NodeParent k03 = alokasiNodeParent("K03", "Dessert");
    insertLastParent(LInduk, k03);
    cout<<endl;

    //3.masukkan Data Child (menu makanan) ke kategori tertentu
    //-->isi kategori makanan berat (k01)
    NodeChild M01 = alokasiNodeChild("M01", "Nasi Goreng");
    insertLastChild(k01->L_Anak, M01);
    NodeChild M02 = alokasiNodeChild("M02", "Ayam Bakar Madu");
    insertLastChild(k01->L_Anak, M02);  
    //--> isi kategori minuman (k02)
    NodeChild D02 = alokasiNodeChild("D02", "Jus Alpukat");
    insertLastChild(k02->L_Anak, D02);
    NodeChild D03 = alokasiNodeChild("D03", "Jus Alpukat");
    insertLastChild(k02->L_Anak, D03);
    //--> isi kategori dessert (k03)
    NodeChild S01 = alokasiNodeChild("DS01", "Puding Coklat");
    insertLastChild(k03->L_Anak, S01);
    cout << endl;  

    //4.print mll setelah insert-insert
    printStrukturMLL(LInduk);
    cout << endl;

    //5.searching node child
    findChildByID(LInduk, "D01");
    cout << endl;
    //6.delete node child
    deleteAfterChild(k01->L_Anak, M01);//menghapus node child ayam bakar madu
    cout<< endl;
    //7.delete node parent
    deleteAfterParent(LInduk, k02); //menghapus node parent minuman
    cout << endl;
    //8.print mll setelah delete
    printStrukturMLL(LInduk);
    cout << endl;
    
    return 0;
}
```
kode c++ tersebut menggunakan multi linked list dengan double linked list pada node parent dan child untuk merepresentasikan hubungan kategori makanan (parent) dan menu makanan (child), di mana setiap parent memiliki list anaknya sendiri.

## Unguided 

### 1. list parent dan child nya

```C++
// mll.h
#ifndef MLL_H
#define MLL_H

#include <iostream>

using namespace std;

struct golonganHewan {
    string idGolongan;
    string namaGolongan;
};

struct dataHewan {
    string idHewan;
    string namaHewan;
    string habitat;
    bool ekor;        
    float bobot;      
};

typedef struct nodeParent *NodeParent;
typedef struct nodeChild *NodeChild;

struct nodeChild {
    dataHewan isidata;
    NodeChild next;
    NodeChild prev;
};

struct listChild {
    NodeChild first;
    NodeChild last;
};

struct nodeParent {
    golonganHewan isidata;
    NodeParent next;
    NodeParent prev;
    listChild L_Child;    
};

struct listParent {
    NodeParent first;
    NodeParent last;
};

bool isEmptyParent(listParent LParent);
bool isEmptyChild(listChild LChild);

void createListParent(listParent &LParent);
void createListChild(listChild &LChild);

NodeParent allocNodeParent(string idGol, string namaGol);
NodeChild  allocNodeChild(string idHwn, string namaHwn, string habitat, bool tail, float weight);
void deallocNodeParent(NodeParent &NParent);
void deallocNodeChild(NodeChild &NChild);

void insertFirstParent(listParent &LParent, NodeParent newNParent);
void insertLastParent(listParent &LParent, NodeParent newNParent);

void deleteFirstParent(listParent &LParent);
void deleteAfterParent(listParent &LParent, NodeParent NPrev);

void insertFirstChild(listChild &LChild, NodeChild newNChild);
void insertLastChild(listChild &LChild, NodeChild newNChild);

void deleteFirstChild(listChild &LChild);
void deleteAfterChild(listChild &LChild, NodeChild NPrev);
void deleteListChild(listChild &LChild);

void printMLLStructure(listParent LParent);

#endif

// mll.cpp
#include "MLL.h"

bool isEmptyParent(listParent LParent) {
    return (LParent.first == nullptr);
}

bool isEmptyChild(listChild LChild) {
    return (LChild.first == nullptr);
}

void createListParent(listParent &LParent) {
    LParent.first = nullptr;
    LParent.last = nullptr;
}

void createListChild(listChild &LChild) {
    LChild.first = nullptr;
    LChild.last = nullptr;
}

NodeParent allocNodeParent(string idGol, string namaGol) {
    NodeParent NP = new nodeParent;
    NP -> isidata.idGolongan = idGol;
    NP -> isidata.namaGolongan = namaGol;
    NP -> next = nullptr;
    NP -> prev = nullptr;

    createListChild(NP -> L_Child);
    return NP;
}

NodeChild allocNodeChild(string idHwn, string namaHwn, string habitat, bool tail, float weight) {
    NodeChild NC = new nodeChild;
    NC -> isidata.idHewan = idHwn;
    NC -> isidata.namaHewan = namaHwn;
    NC -> isidata.habitat = habitat;
    NC -> isidata.ekor = tail;
    NC -> isidata.bobot = weight;
    NC -> next = nullptr;
    NC -> prev = nullptr;
    return NC;
}

void deallocNodeParent(NodeParent &NParent) {
    delete NParent;
    NParent = nullptr;
}

void deallocNodeChild(NodeChild &NChild) {
    delete NChild;
    NChild = nullptr;
}

void insertFirstParent(listParent &LParent, NodeParent newNParent) {
    if (isEmptyParent(LParent)) {
        LParent.first = newNParent;
        LParent.last = newNParent;
    } else {
        newNParent -> next = LParent.first;
        LParent.first -> prev = newNParent;
        LParent.first = newNParent;
    }
}

void insertLastParent(listParent &LParent, NodeParent newNParent) {
    if (isEmptyParent(LParent)) {
        insertFirstParent(LParent, newNParent);
    } else {
        LParent.last -> next = newNParent;
        newNParent -> prev = LParent.last;
        LParent.last = newNParent;
    }
}

void deleteFirstParent(listParent &LParent) {
    if (!isEmptyParent(LParent)) {
        NodeParent del = LParent.first;

        deleteListChild(del -> L_Child);

        if (LParent.first == LParent.last) {
            LParent.first = nullptr;
            LParent.last = nullptr;
        } else {
            LParent.first = del -> next;
            LParent.first -> prev = nullptr;
        }
        deallocNodeParent(del);
    }
}

void deleteAfterParent(listParent &LParent, NodeParent NPrev) {
    if (NPrev != nullptr && NPrev -> next != nullptr) {
        NodeParent del = NPrev -> next;

        deleteListChild(del -> L_Child);

        NPrev -> next = del -> next;
        if (del -> next != nullptr) {
            del -> next -> prev = NPrev;
        } else {
            LParent.last = NPrev;
        }
        deallocNodeParent(del);
    }
}

void insertFirstChild(listChild &LChild, NodeChild newNChild) {
    if (isEmptyChild(LChild)) {
        LChild.first = newNChild;
        LChild.last = newNChild;
    } else {
        newNChild -> next = LChild.first;
        LChild.first -> prev = newNChild;
        LChild.first = newNChild;
    }
}

void insertLastChild(listChild &LChild, NodeChild newNChild) {
    if (isEmptyChild(LChild)) {
        insertFirstChild(LChild, newNChild);
    } else {
        LChild.last -> next = newNChild;
        newNChild -> prev = LChild.last;
        LChild.last = newNChild;
    }
}

void deleteFirstChild(listChild &LChild) {
    if (!isEmptyChild(LChild)) {
        NodeChild del = LChild.first;

        if (LChild.first == LChild.last) {
            LChild.first = nullptr;
            LChild.last = nullptr;
        } else {
            LChild.first = del -> next;
            LChild.first -> prev = nullptr;
        }

        deallocNodeChild(del);
    }
}

void deleteAfterChild(listChild &LChild, NodeChild NPrev) {
    if (NPrev != nullptr && NPrev -> next != nullptr) {
        NodeChild del = NPrev -> next;

        NPrev -> next = del -> next;
        if (del->next != nullptr) {
            del -> next -> prev = NPrev;
        } else {
            LChild.last = NPrev;
        }

        deallocNodeChild(del);
    }
}

void deleteListChild(listChild &LChild) {
    while (!isEmptyChild(LChild)) {
        deleteFirstChild(LChild);
    }
}

void printMLLStructure(listParent LParent) {
    NodeParent P = LParent.first;
    int noParent = 1;

    while (P != nullptr) {
        cout << "=== parent " << noParent << " ===\n";
        cout << "ID golongan : " << P -> isidata.idGolongan << endl;
        cout << "nama golongan : " << P -> isidata.namaGolongan << endl;

        NodeChild C = P -> L_Child.first;
        int noChild = 1;

        if (C == nullptr) {
            cout << "- (tidak ada child)\n";
        } else {
            while (C != nullptr) {
                cout << "- child " << noChild << " :\n";
                cout << "  ID hewan   : " << C -> isidata.idHewan << endl;
                cout << "  nama hewan : " << C -> isidata.namaHewan << endl;
                cout << "  habitat    : " << C -> isidata.habitat << endl;
                cout << "  ekor       : " << (C -> isidata.ekor ? "1" : "0") << endl;
                cout << "  bobot      : " << C -> isidata.bobot << endl;
                cout << endl;

                C = C -> next;
                noChild++;
            }
        }

        cout << "---------------------------\n";

        P = P -> next;
        noParent++;
    }
}

// main.cpp
#include "MLL.h"

#include <iostream>

using namespace std;

int main() {
    listParent L;
    createListParent(L);

    NodeParent p1 = allocNodeParent("G001", "aves");
    NodeParent p2 = allocNodeParent("G002", "mammalia");
    NodeParent p3 = allocNodeParent("G003", "pisces");
    NodeParent p4 = allocNodeParent("G004", "amfibi");
    NodeParent p5 = allocNodeParent("G005", "reptil");

    insertLastParent(L, p1);
    insertLastParent(L, p2);
    insertLastParent(L, p3);
    insertLastParent(L, p4);
    insertLastParent(L, p5);

    NodeChild ch1 = allocNodeChild("AV001", "cendrawasih", "hutan", true, 0.3f);
    NodeChild ch2 = allocNodeChild("AV002", "bebek", "air", true, 2.0f);

    insertLastChild(p1 -> L_Child, ch1);
    insertLastChild(p1 -> L_Child, ch2);

    NodeChild ch3 = allocNodeChild("M001", "harimau", "hutan", true, 200.0f);
    NodeChild ch4 = allocNodeChild("M003", "gorila", "hutan", false, 160.0f);
    NodeChild ch5 = allocNodeChild("M002", "kucing", "darat", true, 4.0f);

    insertLastChild(p2 -> L_Child, ch3);
    insertLastChild(p2 -> L_Child, ch4);
    insertLastChild(p2 -> L_Child, ch5);

    NodeChild ch6 = allocNodeChild("AM001", "kodok", "sawah", false, 0.2f);
    insertLastChild(p4 -> L_Child, ch6);

    printMLLStructure(L);

    while (!isEmptyParent(L)) {
        deleteFirstParent(L);
    }

    return 0;
}


```
### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/ssheilanindya/103112400086_Sheila-Stephanie-Anindya/blob/main/output/output1-unguided1-modul13.png)


##### Output 2
![Screenshot Output Unguided 1_2](https://github.com/ssheilanindya/103112400086_Sheila-Stephanie-Anindya/blob/main/output/output2-unguided1-modul13.png)

##### Output 2
![Screenshot Output Unguided 1_2](https://github.com/ssheilanindya/103112400086_Sheila-Stephanie-Anindya/blob/main/output/output3-unguided1-modul13.png)

kode C++ tesebut mengelola data hewan berdasarkan golongannya menggunakan MLL, di mana parent merepresentasikan golongan hewan (aves, mammalia, pisces, reptil) dan setiap parent memiliki child berupa data hewan yang termasuk ke dalam golongan tersebut. kode program tersebut penyimpanan, pengelompokan, penambahan, penghapusan, dan penampilan data hewan secara terstruktur. data yang ditampilkan adalah seluruh isi list parent beserta seluruh child-nya.

### 2. menambahkan prosedur searchHewanByEkor(input/output LParent : listParent, input tail : Boolean) yang digunakan untuk melakukan operasi SEARCHING hewan-hewan yang memiliki EKOR FALSE

```C++
// mll.h
#ifndef MLL_H
#define MLL_H

#include <iostream>

using namespace std;

struct golonganHewan {
    string idGolongan;
    string namaGolongan;
};

struct dataHewan {
    string idHewan;
    string namaHewan;
    string habitat;
    bool ekor;        
    float bobot;      
};

typedef struct nodeParent *NodeParent;
typedef struct nodeChild *NodeChild;

struct nodeChild {
    dataHewan isidata;
    NodeChild next;
    NodeChild prev;
};

struct listChild {
    NodeChild first;
    NodeChild last;
};

struct nodeParent {
    golonganHewan isidata;
    NodeParent next;
    NodeParent prev;
    listChild L_Child;    
};

struct listParent {
    NodeParent first;
    NodeParent last;
};

bool isEmptyParent(listParent LParent);
bool isEmptyChild(listChild LChild);

void createListParent(listParent &LParent);
void createListChild(listChild &LChild);

NodeParent allocNodeParent(string idGol, string namaGol);
NodeChild  allocNodeChild(string idHwn, string namaHwn, string habitat, bool tail, float weight);
void deallocNodeParent(NodeParent &NParent);
void deallocNodeChild(NodeChild &NChild);

void insertFirstParent(listParent &LParent, NodeParent newNParent);
void insertLastParent(listParent &LParent, NodeParent newNParent);

void deleteFirstParent(listParent &LParent);
void deleteAfterParent(listParent &LParent, NodeParent NPrev);

void insertFirstChild(listChild &LChild, NodeChild newNChild);
void insertLastChild(listChild &LChild, NodeChild newNChild);

void deleteFirstChild(listChild &LChild);
void deleteAfterChild(listChild &LChild, NodeChild NPrev);
void deleteListChild(listChild &LChild);
void searchHewanByEkor(listParent LParent, bool tail);
void printMLLStructure(listParent LParent);

#endif

// mll.cpp
#include "MLL.h"

bool isEmptyParent(listParent LParent) {
    return (LParent.first == nullptr);
}

bool isEmptyChild(listChild LChild) {
    return (LChild.first == nullptr);
}

void createListParent(listParent &LParent) {
    LParent.first = nullptr;
    LParent.last = nullptr;
}

void createListChild(listChild &LChild) {
    LChild.first = nullptr;
    LChild.last = nullptr;
}

NodeParent allocNodeParent(string idGol, string namaGol) {
    NodeParent NP = new nodeParent;
    NP -> isidata.idGolongan = idGol;
    NP -> isidata.namaGolongan = namaGol;
    NP -> next = nullptr;
    NP -> prev = nullptr;

    createListChild(NP -> L_Child);
    return NP;
}

NodeChild allocNodeChild(string idHwn, string namaHwn, string habitat, bool tail, float weight) {
    NodeChild NC = new nodeChild;
    NC -> isidata.idHewan = idHwn;
    NC -> isidata.namaHewan = namaHwn;
    NC -> isidata.habitat = habitat;
    NC -> isidata.ekor = tail;
    NC -> isidata.bobot = weight;
    NC -> next = nullptr;
    NC -> prev = nullptr;
    return NC;
}

void deallocNodeParent(NodeParent &NParent) {
    delete NParent;
    NParent = nullptr;
}

void deallocNodeChild(NodeChild &NChild) {
    delete NChild;
    NChild = nullptr;
}

void insertFirstParent(listParent &LParent, NodeParent newNParent) {
    if (isEmptyParent(LParent)) {
        LParent.first = newNParent;
        LParent.last = newNParent;
    } else {
        newNParent -> next = LParent.first;
        LParent.first -> prev = newNParent;
        LParent.first = newNParent;
    }
}

void insertLastParent(listParent &LParent, NodeParent newNParent) {
    if (isEmptyParent(LParent)) {
        insertFirstParent(LParent, newNParent);
    } else {
        LParent.last -> next = newNParent;
        newNParent -> prev = LParent.last;
        LParent.last = newNParent;
    }
}

void deleteFirstParent(listParent &LParent) {
    if (!isEmptyParent(LParent)) {
        NodeParent del = LParent.first;

        deleteListChild(del -> L_Child);

        if (LParent.first == LParent.last) {
            LParent.first = nullptr;
            LParent.last = nullptr;
        } else {
            LParent.first = del -> next;
            LParent.first -> prev = nullptr;
        }
        deallocNodeParent(del);
    }
}

void deleteAfterParent(listParent &LParent, NodeParent NPrev) {
    if (NPrev != nullptr && NPrev -> next != nullptr) {
        NodeParent del = NPrev -> next;

        deleteListChild(del -> L_Child);

        NPrev -> next = del -> next;
        if (del -> next != nullptr) {
            del -> next -> prev = NPrev;
        } else {
            LParent.last = NPrev;
        }
        deallocNodeParent(del);
    }
}

void insertFirstChild(listChild &LChild, NodeChild newNChild) {
    if (isEmptyChild(LChild)) {
        LChild.first = newNChild;
        LChild.last = newNChild;
    } else {
        newNChild -> next = LChild.first;
        LChild.first -> prev = newNChild;
        LChild.first = newNChild;
    }
}

void insertLastChild(listChild &LChild, NodeChild newNChild) {
    if (isEmptyChild(LChild)) {
        insertFirstChild(LChild, newNChild);
    } else {
        LChild.last -> next = newNChild;
        newNChild -> prev = LChild.last;
        LChild.last = newNChild;
    }
}

void deleteFirstChild(listChild &LChild) {
    if (!isEmptyChild(LChild)) {
        NodeChild del = LChild.first;

        if (LChild.first == LChild.last) {
            LChild.first = nullptr;
            LChild.last = nullptr;
        } else {
            LChild.first = del -> next;
            LChild.first -> prev = nullptr;
        }

        deallocNodeChild(del);
    }
}

void deleteAfterChild(listChild &LChild, NodeChild NPrev) {
    if (NPrev != nullptr && NPrev -> next != nullptr) {
        NodeChild del = NPrev -> next;

        NPrev -> next = del -> next;
        if (del->next != nullptr) {
            del -> next -> prev = NPrev;
        } else {
            LChild.last = NPrev;
        }

        deallocNodeChild(del);
    }
}

void deleteListChild(listChild &LChild) {
    while (!isEmptyChild(LChild)) {
        deleteFirstChild(LChild);
    }
}

void printMLLStructure(listParent LParent) {
    NodeParent P = LParent.first;
    int noParent = 1;

    while (P != nullptr) {
        cout << "=== parent " << noParent << " ===\n";
        cout << "ID golongan : " << P -> isidata.idGolongan << endl;
        cout << "nama golongan : " << P -> isidata.namaGolongan << endl;

        NodeChild C = P -> L_Child.first;
        int noChild = 1;

        if (C == nullptr) {
            cout << "- (tidak ada child)\n";
        } else {
            while (C != nullptr) {
                cout << "- child " << noChild << " :\n";
                cout << "  ID hewan   : " << C -> isidata.idHewan << endl;
                cout << "  nama hewan : " << C -> isidata.namaHewan << endl;
                cout << "  habitat    : " << C -> isidata.habitat << endl;
                cout << "  ekor       : " << (C -> isidata.ekor ? "1" : "0") << endl;
                cout << "  bobot      : " << C -> isidata.bobot << endl;
                cout << endl;

                C = C -> next;
                noChild++;
            }
        }

        cout << "---------------------------\n";

        P = P -> next;
        noParent++;
    }
}

void searchHewanByEkor(listParent LParent, bool tail) {
    NodeParent P = LParent.first;
    int posParent = 1;
    bool foundAny = false;

    while (P != nullptr) {

        NodeChild C = P -> L_Child.first;
        int posChild = 1;

        while (C != nullptr) {

            if (C -> isidata.ekor == tail) {
                foundAny = true;

                cout << "data ditemukan pada list anak dari node parent " << P -> isidata.namaGolongan << " pada posisi ke-" << posChild << "!" << endl;

                cout << "--- data child ---" << endl;
                cout << "ID child : " << C -> isidata.idHewan << endl;
                cout << "posisi dalam list anak : posisi ke-" << posChild << endl;
                cout << "nama hewan : " << C -> isidata.namaHewan << endl;
                cout << "habitat : " << C -> isidata.habitat << endl;
                cout << "ekor : " << (C -> isidata.ekor ? 1 : 0) << endl;
                cout << "bobot : " << C -> isidata.bobot << endl;
                cout << "---------------------" << endl;

                cout << "--- data parent ---" << endl;
                cout << "ID parent : " << P -> isidata.idGolongan << endl;
                cout << "posisi dalam list induk : posisi ke-" << posParent << endl;
                cout << "nama golongan : " << P -> isidata.namaGolongan << endl;
                cout << "---------------------" << endl;
            }

            C = C -> next;
            posChild++;
        }

        P = P -> next;
        posParent++;
    }

    if (!foundAny) {
        cout << "tidak ada data child dengan ekor = " << (tail ? 1 : 0) << endl;
    }
}

// main.cpp
#include "MLL.h"

#include <iostream>

using namespace std;

int main() {
    listParent L;
    createListParent(L);

    NodeParent p1 = allocNodeParent("G001", "aves");
    NodeParent p2 = allocNodeParent("G002", "mammalia");
    NodeParent p3 = allocNodeParent("G003", "pisces");
    NodeParent p4 = allocNodeParent("G004", "amfibi");
    NodeParent p5 = allocNodeParent("G005", "reptil");

    insertLastParent(L, p1);
    insertLastParent(L, p2);
    insertLastParent(L, p3);
    insertLastParent(L, p4);
    insertLastParent(L, p5);

    NodeChild ch1 = allocNodeChild("AV001", "cendrawasih", "hutan", true, 0.3f);
    NodeChild ch2 = allocNodeChild("AV002", "bebek", "air", true, 2.0f);

    insertLastChild(p1 -> L_Child, ch1);
    insertLastChild(p1 -> L_Child, ch2);

    NodeChild ch3 = allocNodeChild("M001", "harimau", "hutan", true, 200.0f);
    NodeChild ch4 = allocNodeChild("M003", "gorila", "hutan", false, 160.0f);
    NodeChild ch5 = allocNodeChild("M002", "kucing", "darat", true, 4.0f);

    insertLastChild(p2 -> L_Child, ch3);
    insertLastChild(p2 -> L_Child, ch4);
    insertLastChild(p2 -> L_Child, ch5);

    NodeChild ch6 = allocNodeChild("AM001", "kodok", "sawah", false, 0.2f);
    insertLastChild(p4 -> L_Child, ch6);

    searchHewanByEkor(L, false);

    while (!isEmptyParent(L)) {
        deleteFirstParent(L);
    }

    return 0;
}

```
### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 2_1](https://github.com/ssheilanindya/103112400086_Sheila-Stephanie-Anindya/blob/main/output/output1-unguided2-modul13.png)

kode c++ tersebut modifikasi dari unguided 1, yaitu menambahkan prosedur searchHewanByEkor yang digunakan untuk mencari dan menampilkan semua data hewan (child) di dalam struktur MLL yang memiliki nilai ekor sesuai input (pada soal: FALSE, artinya hewan tidak berekor). cara kerjanya adalah dengan menelusuri seluruh node parent (golongan hewan) satu per satu, lalu mengecek setiap node child (data hewan) di dalam list anaknya. jika nilai C -> isidata.ekor sama dengan parameter tail, maka data hewan tersebut ditampilkan lengkap beserta informasi parent-nya (ID golongan, nama golongan, posisi parent dan child). jika setelah seluruh data dicek tidak ada hewan yang memenuhi kondisi, program akan menampilkan pesan bahwa tidak ditemukan hewan dengan ekor bernilai 0/false.

### 3. menambahkan operasi DELETE dengan menghapus node G004 yang ada pada list parent (list child dari node tersebut juga terhapus)

```C++
// mll.h
#ifndef MLL_H
#define MLL_H

#include <iostream>

using namespace std;

struct golonganHewan {
    string idGolongan;
    string namaGolongan;
};

struct dataHewan {
    string idHewan;
    string namaHewan;
    string habitat;
    bool ekor;        
    float bobot;      
};

typedef struct nodeParent *NodeParent;
typedef struct nodeChild *NodeChild;

struct nodeChild {
    dataHewan isidata;
    NodeChild next;
    NodeChild prev;
};

struct listChild {
    NodeChild first;
    NodeChild last;
};

struct nodeParent {
    golonganHewan isidata;
    NodeParent next;
    NodeParent prev;
    listChild L_Child;    
};

struct listParent {
    NodeParent first;
    NodeParent last;
};

bool isEmptyParent(listParent LParent);
bool isEmptyChild(listChild LChild);

void createListParent(listParent &LParent);
void createListChild(listChild &LChild);

NodeParent allocNodeParent(string idGol, string namaGol);
NodeChild  allocNodeChild(string idHwn, string namaHwn, string habitat, bool tail, float weight);
void deallocNodeParent(NodeParent &NParent);
void deallocNodeChild(NodeChild &NChild);

void insertFirstParent(listParent &LParent, NodeParent newNParent);
void insertLastParent(listParent &LParent, NodeParent newNParent);

void deleteFirstParent(listParent &LParent);
void deleteAfterParent(listParent &LParent, NodeParent NPrev);

void insertFirstChild(listChild &LChild, NodeChild newNChild);
void insertLastChild(listChild &LChild, NodeChild newNChild);

void deleteFirstChild(listChild &LChild);
void deleteAfterChild(listChild &LChild, NodeChild NPrev);
void deleteListChild(listChild &LChild);
void deleteParentByID(listParent &LParent, string idGol);
void searchHewanByEkor(listParent LParent, bool tail);
void printMLLStructure(listParent LParent);

#endif

// mll.cpp
#include "MLL.h"

bool isEmptyParent(listParent LParent) {
    return (LParent.first == nullptr);
}

bool isEmptyChild(listChild LChild) {
    return (LChild.first == nullptr);
}

void createListParent(listParent &LParent) {
    LParent.first = nullptr;
    LParent.last = nullptr;
}

void createListChild(listChild &LChild) {
    LChild.first = nullptr;
    LChild.last = nullptr;
}

NodeParent allocNodeParent(string idGol, string namaGol) {
    NodeParent NP = new nodeParent;
    NP -> isidata.idGolongan = idGol;
    NP -> isidata.namaGolongan = namaGol;
    NP -> next = nullptr;
    NP -> prev = nullptr;

    createListChild(NP -> L_Child);
    return NP;
}

NodeChild allocNodeChild(string idHwn, string namaHwn, string habitat, bool tail, float weight) {
    NodeChild NC = new nodeChild;
    NC -> isidata.idHewan = idHwn;
    NC -> isidata.namaHewan = namaHwn;
    NC -> isidata.habitat = habitat;
    NC -> isidata.ekor = tail;
    NC -> isidata.bobot = weight;
    NC -> next = nullptr;
    NC -> prev = nullptr;
    return NC;
}

void deallocNodeParent(NodeParent &NParent) {
    delete NParent;
    NParent = nullptr;
}

void deallocNodeChild(NodeChild &NChild) {
    delete NChild;
    NChild = nullptr;
}

void insertFirstParent(listParent &LParent, NodeParent newNParent) {
    if (isEmptyParent(LParent)) {
        LParent.first = newNParent;
        LParent.last = newNParent;
    } else {
        newNParent -> next = LParent.first;
        LParent.first -> prev = newNParent;
        LParent.first = newNParent;
    }
}

void insertLastParent(listParent &LParent, NodeParent newNParent) {
    if (isEmptyParent(LParent)) {
        insertFirstParent(LParent, newNParent);
    } else {
        LParent.last -> next = newNParent;
        newNParent -> prev = LParent.last;
        LParent.last = newNParent;
    }
}

void deleteFirstParent(listParent &LParent) {
    if (!isEmptyParent(LParent)) {
        NodeParent del = LParent.first;

        deleteListChild(del -> L_Child);

        if (LParent.first == LParent.last) {
            LParent.first = nullptr;
            LParent.last = nullptr;
        } else {
            LParent.first = del -> next;
            LParent.first -> prev = nullptr;
        }
        deallocNodeParent(del);
    }
}

void deleteAfterParent(listParent &LParent, NodeParent NPrev) {
    if (NPrev != nullptr && NPrev -> next != nullptr) {
        NodeParent del = NPrev -> next;

        deleteListChild(del -> L_Child);

        NPrev -> next = del -> next;
        if (del -> next != nullptr) {
            del -> next -> prev = NPrev;
        } else {
            LParent.last = NPrev;
        }
        deallocNodeParent(del);
    }
}

void insertFirstChild(listChild &LChild, NodeChild newNChild) {
    if (isEmptyChild(LChild)) {
        LChild.first = newNChild;
        LChild.last = newNChild;
    } else {
        newNChild -> next = LChild.first;
        LChild.first -> prev = newNChild;
        LChild.first = newNChild;
    }
}

void insertLastChild(listChild &LChild, NodeChild newNChild) {
    if (isEmptyChild(LChild)) {
        insertFirstChild(LChild, newNChild);
    } else {
        LChild.last -> next = newNChild;
        newNChild -> prev = LChild.last;
        LChild.last = newNChild;
    }
}

void deleteFirstChild(listChild &LChild) {
    if (!isEmptyChild(LChild)) {
        NodeChild del = LChild.first;

        if (LChild.first == LChild.last) {
            LChild.first = nullptr;
            LChild.last = nullptr;
        } else {
            LChild.first = del -> next;
            LChild.first -> prev = nullptr;
        }

        deallocNodeChild(del);
    }
}

void deleteAfterChild(listChild &LChild, NodeChild NPrev) {
    if (NPrev != nullptr && NPrev -> next != nullptr) {
        NodeChild del = NPrev -> next;

        NPrev -> next = del -> next;
        if (del->next != nullptr) {
            del -> next -> prev = NPrev;
        } else {
            LChild.last = NPrev;
        }

        deallocNodeChild(del);
    }
}

void deleteListChild(listChild &LChild) {
    while (!isEmptyChild(LChild)) {
        deleteFirstChild(LChild);
    }
}

void printMLLStructure(listParent LParent) {
    NodeParent P = LParent.first;
    int noParent = 1;

    while (P != nullptr) {
        cout << "=== parent " << noParent << " ===\n";
        cout << "ID golongan : " << P -> isidata.idGolongan << endl;
        cout << "nama golongan : " << P -> isidata.namaGolongan << endl;

        NodeChild C = P -> L_Child.first;
        int noChild = 1;

        if (C == nullptr) {
            cout << "- (tidak ada child)\n";
        } else {
            while (C != nullptr) {
                cout << "- child " << noChild << " :\n";
                cout << "  ID hewan   : " << C -> isidata.idHewan << endl;
                cout << "  nama hewan : " << C -> isidata.namaHewan << endl;
                cout << "  habitat    : " << C -> isidata.habitat << endl;
                cout << "  ekor       : " << (C -> isidata.ekor ? "1" : "0") << endl;
                cout << "  bobot      : " << C -> isidata.bobot << endl;
                cout << endl;

                C = C -> next;
                noChild++;
            }
        }

        cout << "---------------------------\n";

        P = P -> next;
        noParent++;
    }
}

void searchHewanByEkor(listParent LParent, bool tail) {
    NodeParent P = LParent.first;
    int posParent = 1;
    bool foundAny = false;

    while (P != nullptr) {

        NodeChild C = P -> L_Child.first;
        int posChild = 1;

        while (C != nullptr) {

            if (C -> isidata.ekor == tail) {
                foundAny = true;

                cout << "data ditemukan pada list anak dari node parent " << P -> isidata.namaGolongan << " pada posisi ke-" << posChild << "!" << endl;

                cout << "--- data child ---" << endl;
                cout << "ID child : " << C -> isidata.idHewan << endl;
                cout << "posisi dalam list anak : posisi ke-" << posChild << endl;
                cout << "nama hewan : " << C -> isidata.namaHewan << endl;
                cout << "habitat : " << C -> isidata.habitat << endl;
                cout << "ekor : " << (C -> isidata.ekor ? 1 : 0) << endl;
                cout << "bobot : " << C -> isidata.bobot << endl;
                cout << "---------------------" << endl;

                cout << "--- data parent ---" << endl;
                cout << "ID parent : " << P -> isidata.idGolongan << endl;
                cout << "posisi dalam list induk : posisi ke-" << posParent << endl;
                cout << "nama golongan : " << P -> isidata.namaGolongan << endl;
                cout << "---------------------" << endl;
            }

            C = C -> next;
            posChild++;
        }

        P = P -> next;
        posParent++;
    }

    if (!foundAny) {
        cout << "tidak ada data child dengan ekor = " << (tail ? 1 : 0) << endl;
    }
}

void deleteParentByID(listParent &LParent, string idGol) {
    NodeParent P = LParent.first;

    while (P != nullptr) {

        if (P -> isidata.idGolongan == idGol) {

            if (P == LParent.first) {
                deleteFirstParent(LParent);
            } else {
                deleteAfterParent(LParent, P -> prev);
            }
            return; // selesai karena node sudah dihapus
        }

        P = P->next;
    }

    cout << "parent dengan ID " << idGol << " tidak ditemukan.\n";
}


// main.cpp
#include "MLL.h"

#include <iostream>

using namespace std;

int main() {
    listParent L;
    createListParent(L);

    NodeParent p1 = allocNodeParent("G001", "aves");
    NodeParent p2 = allocNodeParent("G002", "mammalia");
    NodeParent p3 = allocNodeParent("G003", "pisces");
    NodeParent p4 = allocNodeParent("G004", "amfibi");
    NodeParent p5 = allocNodeParent("G005", "reptil");

    insertLastParent(L, p1);
    insertLastParent(L, p2);
    insertLastParent(L, p3);
    insertLastParent(L, p4);
    insertLastParent(L, p5);

    NodeChild ch1 = allocNodeChild("AV001", "cendrawasih", "hutan", true, 0.3f);
    NodeChild ch2 = allocNodeChild("AV002", "bebek", "air", true, 2.0f);

    insertLastChild(p1 -> L_Child, ch1);
    insertLastChild(p1 -> L_Child, ch2);

    NodeChild ch3 = allocNodeChild("M001", "harimau", "hutan", true, 200.0f);
    NodeChild ch4 = allocNodeChild("M003", "gorila", "hutan", false, 160.0f);
    NodeChild ch5 = allocNodeChild("M002", "kucing", "darat", true, 4.0f);

    insertLastChild(p2 -> L_Child, ch3);
    insertLastChild(p2 -> L_Child, ch4);
    insertLastChild(p2 -> L_Child, ch5);

    NodeChild ch6 = allocNodeChild("AM001", "kodok", "sawah", false, 0.2f);
    insertLastChild(p4 -> L_Child, ch6);

    deleteParentByID(L, "G004");
    printMLLStructure(L);

    while (!isEmptyParent(L)) {
        deleteFirstParent(L);
    }

    return 0;
}

```
### Output Unguided 3 :

##### Output 1
![Screenshot Output Unguided 3_1](https://github.com/ssheilanindya/103112400086_Sheila-Stephanie-Anindya/blob/main/output/output1-unguided3-modul13.png)

##### Output 2
![Screenshot Output Unguided 3_2](https://github.com/ssheilanindya/103112400086_Sheila-Stephanie-Anindya/blob/main/output/output2-unguided3-modul13.png)

kode c++ tersebut merupakan modifikasi dari unguided 1 dan 2 dengan menambahkan operasi DELETE parent G004 dengan prosedur deleteParentByID yang mencari node parent berdasarkan idGolongan, lalu menghapus node tersebut beserta seluruh list child-nya. 

## Kesimpulan
Multi Linked List (MLL) merupakan struktur data yang merepresentasikan hubungan hierarkis antara data induk dan data anak, di mana setiap node saling terhubung melalui pointer sehingga membentuk beberapa list yang saling berkaitan. Melalui operasi insert, data dapat ditambahkan baik pada level induk maupun anak secara terstruktur, sedangkan operasi delete memungkinkan penghapusan data dengan tetap menjaga konsistensi hubungan antarnode, khususnya saat menghapus node induk yang harus diikuti dengan penghapusan seluruh node anaknya.

## Referensi
[1] Fakultas Informatika. (2025). Modul Praktikum Struktur Data Modul 13: Multi Linked List. Bandung: Telkom University.
[2] GeeksforGeeks. "Introduction to Multi-Linked List." GeeksforGeeks. T.t. Web. 12 Desember 2025. [https://www.geeksforgeeks.org/dsa/introduction-to-multi-linked-list/](https://www.geeksforgeeks.org/dsa/introduction-to-multi-linked-list/).

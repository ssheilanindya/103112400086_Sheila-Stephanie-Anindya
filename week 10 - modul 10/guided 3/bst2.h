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
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

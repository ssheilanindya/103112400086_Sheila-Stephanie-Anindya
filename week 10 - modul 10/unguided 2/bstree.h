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

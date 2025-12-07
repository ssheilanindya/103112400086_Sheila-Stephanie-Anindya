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

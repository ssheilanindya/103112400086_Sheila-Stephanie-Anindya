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

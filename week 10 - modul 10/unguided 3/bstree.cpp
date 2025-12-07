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

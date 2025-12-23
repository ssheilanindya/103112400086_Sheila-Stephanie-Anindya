#include "bst.h"

void createTree(bst &T) {
    T.root = NULL;
}

bool isEmpty(bst T) {
    return T.root == NULL;
}

node* newNode(string nama, float berat, string tier) {
    node *P = new node;
    P -> namaMember = nama;
    P -> beratBadan = berat;
    P -> tierMember = tier;
    P -> left = NULL;
    P -> right = NULL;
    return P;
}

void insertNode(bst &T, node *P) {
    if (isEmpty(T)) {
        T.root = P;
    } else {
        node *curr = T.root;
        while (true) {
            if (P -> beratBadan < curr -> beratBadan) {
                if (curr -> left == NULL) {
                    curr -> left = P;
                    break;
                }
                curr = curr -> left;
            } else {
                if (curr -> right == NULL) {
                    curr -> right = P;
                    break;
                }
                curr = curr -> right;
            }
        }
    }
}

void inOrder(node *root) {
    if (root != NULL) {
        inOrder(root -> left);
        cout << root -> beratBadan << " - ";
        inOrder(root -> right);
    }
}

node* mostLeft(bst T) {
    node *curr = T.root;
    while (curr -> left != NULL) {
        curr = curr -> left;
    }
    return curr;
}

node* mostRight(bst T) {
    node *curr = T.root;
    while (curr -> right != NULL) {
        curr = curr -> right;
    }
    return curr;
}

node* searchByBeratBadan(bst T, float berat, node *&parent) {
    node *curr = T.root;
    parent = NULL;

    while (curr != NULL) {
        if (curr -> beratBadan == berat) {
            return curr;
        } else if (berat < curr -> beratBadan) {
            parent = curr;
            curr = curr -> left;
        } else {
            parent = curr;
            curr = curr -> right;
        }
    }
    return NULL;
}

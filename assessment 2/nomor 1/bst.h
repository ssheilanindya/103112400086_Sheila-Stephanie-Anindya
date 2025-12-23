#ifndef BST_H
#define BST_H

#include <iostream>
#include <string>

using namespace std;

struct node {
    string namaMember;
    float beratBadan;
    string tierMember;
    node *left;
    node *right;
};

struct bst {
    node *root;
};

bool isEmpty(bst T);
void createTree(bst &T);
node* newNode(string nama, float berat, string tier);
void insertNode(bst &T, node *P);
node* searchByBeratBadan(bst T, float berat, node *&parent);
node* mostLeft(bst T);
node* mostRight(bst T);
void inOrder(node *root);

#endif

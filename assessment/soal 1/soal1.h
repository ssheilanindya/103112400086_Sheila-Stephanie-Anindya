#ifndef SOAL1_H
#define SOAL1_H

#include <iostream>
using namespace std;

struct node {
    string nama;
    node* next;
};

struct list {
    node* first;
};

void createList(list &L);
void insertAkhir(list &L, string nama);
void deleteNama(list &L, string target);
void viewList(list L);
int hitungGenap(list L);

#endif

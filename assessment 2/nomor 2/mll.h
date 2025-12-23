#ifndef MLL_H
#define MLL_H

#include <iostream>
#include <string>
using namespace std;

struct nodeChild {
    string IDfilm;
    string judulFilm;
    int durasiFilm;
    int tahunTayang;
    float ratingFilm;
    nodeChild *next;
    nodeChild *prev;
};

struct listChild {
    nodeChild *first;
    nodeChild *last;
};

struct nodeParent {
    string IDgenre;
    string namaGenre;
    listChild childs;
    nodeParent *next;
    nodeParent *prev;
};

struct listParent {
    nodeParent *first;
    nodeParent *last;
};

void createListParent(listParent &L);
void createListChild(listChild &L);

nodeParent* alokasiNodeParent(string id, string nama);
nodeChild* alokasiNodeChild(string id, string judul, int durasi, int tahun, float rating);

void dealokasiNodeParent(nodeParent *&P);
void dealokasiNodeChild(nodeChild *&P);

void insertFirstParent(listParent &L, nodeParent *P);
void insertLastChild(listChild &L, nodeChild *P);

void deleteAfterParent(listParent &L, nodeParent *prec, nodeParent *&P);
void hapusListChild(listChild &L);
void searchFilmByRatingRange(listParent L, float minRate, float maxRate);
void printStrukturMLL(listParent L);

#endif
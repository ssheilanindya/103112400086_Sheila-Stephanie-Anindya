#ifndef SOAL3_H
#define SOAL3_H

#include <iostream>
using namespace std;

struct mahasiswa {
    string nama;
    string NIM;
    float nilaiTugas;
    float nilaiUTS;
    float nilaiUAS;
};

const int MAX = 6;

struct stackMahasiswa {
    mahasiswa data[MAX];
    int top;
};

typedef stackMahasiswa stackMHS;

bool isEmpty(stackMHS stack);
bool isFull(stackMHS stack);
void createStack(stackMHS &stack);
void push(stackMHS &stack);
void pop(stackMHS &stack);
void update(stackMHS &stack, int posisi);
void view(stackMHS stack);
void searchNilaiAkhir(stackMHS stack, float nilaiAkhirMin, float nilaiAkhirMax);
void maxNilaiAkhir(stackMHS stack);

#endif

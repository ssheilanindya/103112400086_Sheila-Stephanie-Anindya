#ifndef MAHASISWA_H
#define MAHASISWA_H

#include <string>
using namespace std;

//definisi tipe (struct)
struct mahasiswa {
    string nama;
    string nim;
    float uts;
    float uas;
    float tugas;
    float nilaiAkhir;
};

// deklarasi fungsi
float hitungNilaiAkhir(float uts, float uas, float tugas);
void inputMhs(mahasiswa& m);
void tampilkanMhs(const mahasiswa& m);

#endif

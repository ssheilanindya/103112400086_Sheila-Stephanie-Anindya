#include <iostream>
#include "mahasiswa.h"

using namespace std;

// realisasi dari fungsi hitungNilaiAkhir
float hitungNilaiAkhir(float uts, float uas, float tugas) {
    return (0.3 * uts) + (0.4 * uas) + (0.3 * tugas);
}

// realisasi dari fungsi inputMhs
void inputMhs(mahasiswa& m) {
    cout << "input nama: ";
    cin >> m.nama;
    cout << "input NIM: ";
    cin >> m.nim;
    cout << "input nilai UTS: ";
    cin >> m.uts;
    cout << "input nilai UAS: ";
    cin >> m.uas;
    cout << "input nilai tugas: ";
    cin >> m.tugas;

    m.nilaiAkhir = hitungNilaiAkhir(m.uts, m.uas, m.tugas);
}

// realisasi dari fungsi tampilkanMhs
void tampilkanMhs(const mahasiswa& m) {
    cout << "nama: " << m.nama << endl;
    cout << "NIM: " << m.nim << endl;
    cout << "nilai UTS: " << m.uts << endl;
    cout << "nilai UAS: " << m.uas << endl;
    cout << "nilai tugas: " << m.tugas << endl;
    cout << "nilai akhir: " << m.nilaiAkhir << endl;
}

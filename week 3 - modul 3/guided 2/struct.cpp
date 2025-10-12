#include<iostream>
using namespace std;

struct mahasiswa {
    string nama;
    float nilai1, nilai2;
};

void inputMhs(mahasiswa &m) {
    cout << "masukkan nama mahasiswa: "; 
    cin >> m.nama;
    cout << "masukkan Nilai 1: "; 
    cin >> m.nilai1;
    cout << "masukkan Nilai 2: "; 
    cin >> m.nilai2;
}

float rata2(mahasiswa m) {
    return (float)(m.nilai1 + m.nilai2) / 2;
}

int main() {
    mahasiswa mhs;

    inputMhs(mhs);

    cout << "rata-rata nilai adalah: " << rata2 (mhs) << endl;
    system("pause");

    return 0;
}
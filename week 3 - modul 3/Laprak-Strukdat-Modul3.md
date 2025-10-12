# <h1 align="center">Laporan Praktikum Modul 3 - Abstract Data Type (ADT) </h1>
<p align="center"> Sheila Stephanie Anindya - 103112400086 </p>

## Dasar Teori

### A. Data Type <br/>
Tujuan sebuah program C++ ditujukan untuk memanipulasi data. Sebuah program yang didesain untuk menghitung gaji karyawan akan menjumlahkan, mengurangi, mengalikan, dan membagi angka-angka, dan beberapa angka dipakai untuk merepresentasikan jam kerja dan gaji. Sama halnya, sebuah program yang didesain untuk mengalfabetisasi sebuah kelas dipakai untuk memanipulasi nama-nama. Anda tentu tidak akan mengalikan atau mengurangi nama-nama. Oleh karena itu, C++ mengelompokkan data menjadi beberapa tipe data, dan hanya operasi-operasi tertentu yang dapat diterapkan pada tipe data tertentu. Meskipun hal ini cukup membingungkan bagi programmer pemula, C++ telah mengawal programmer pemula dengan menyediakan mekanisme pemeriksaan built-in untuk mengantisipasi kesalahan tipe data. [3]


### B. Abstract Data Type <br/>
Abstract Data Type atau ADT merupakan koleksi data dan operasi yang dapat digunakan untuk memanipulasi data tersebut. [2]
#### 1. Fungsi ADT
ADT dapat memisahkan struktur penyimpanan (lokasi memori) dari perilakunya, serta mendukung penyembunyian informasi atau pengkapsulan. Dengan demikian, perubahan pada implementasi ADT tidak akan mengubah teks program lain selama antarmukanya tetap sama. Selain itu, penggunaan dan pembuatan ADT dapat dilakukan secara terpisah, asalkan terdapat kesepakatan mengenai antarmuka penggunaannya. ADT juga memungkinkan pembuatan modul-modul yang menyerupai konsep-konsep yang ditemukan pada domain persoalan, sehingga mempermudah pemodelan dan pengorganisasian program.[1]
#### 2. Definisi ADT Bertingkat
Definisi tipe dari sebuah ADT dapat mengandung sebuah definisi ADT lain. Misalnya:
1. ADT WAKTU yang terdiri dari dua buah ADT JAM dan ADT DATE[1]
2. Garis terdiri dari dua buah ADT POINT[1]
3. SEGI4 yang terdiri dari pasangan dua buah POINT (Top,Left) dan (Bottom,Right)[1]
#### 3. Implementasi ADT
Abstract Data Type (ADT) umumnya diimplementasikan menggunakan dua modul utama dan satu program interface utama (Driver). Modul pertama adalah Definisi/Spesifikasi (seringkali berupa header file .h), yang mendefinisikan type data sesuai kaidah bahasa (misalnya, menggunakan struct dalam C++) dan menentukan spesifikasi semua primitif (fungsi/prosedur). Spesifikasi ini meliputi: untuk Fungsi, ditentukan nama, domain (input), range (output), dan pre-kondisi; sedangkan untuk Prosedur, dijelaskan Initial state, Final state, serta proses yang dilakukan. Modul kedua adalah Body/Realisasi dari primitif (biasanya source file .c atau .cpp), yang berisi kode program aktual untuk mengimplementasikan primitif-primitif tersebut, di mana realisasinya harus diusahakan memanfaatkan primitif selector dan konstruktor.[1]

## Guided 

### 1. Rata - rata nilai mahasiswa

```C++
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
```
kode c++ tersebut menggunakan struct untuk merepresentasikan data mahasiswa dengan variabel nama, nilai1, dan nilai2.

## Unguided 

### 1. Buat program yang dapat menyimpan data mahasiswa (max. 10) ke sebuah array dengan field nama, nim, uts, uas, tugas, dan nilai akhir. Nilai akhir diperoleh dari fungsi dengan rumus 0.3∗uts+0.4∗uas+0.3∗tugas.

```C++
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

#include <iostream>
#include "mahasiswa.h"

using namespace std;

float hitungNilaiAkhir(float uts, float uas, float tugas) {
    return (0.3 * uts) + (0.4 * uas) + (0.3 * tugas);
}

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

void tampilkanMhs(const mahasiswa& m) {
    cout << "nama: " << m.nama << endl;
    cout << "NIM: " << m.nim << endl;
    cout << "nilai UTS: " << m.uts << endl;
    cout << "nilai UAS: " << m.uas << endl;
    cout << "nilai tugas: " << m.tugas << endl;
    cout << "nilai akhir: " << m.nilaiAkhir << endl;
}

#include <iostream>
#include "mahasiswa.h"

#include <cstdlib> //merupakan sistem pause biar kalo running ga langsung ke close

using namespace std;

int main() {
    mahasiswa mhs;

    inputMhs(mhs);         
    tampilkanMhs(mhs);     

    system("pause");
    return 0;
}


```
### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/ssheilanindya/103112400086_Sheila-Stephanie-Anindya/blob/main/output/output1-unguided1-modul3.png)


##### Output 2
![Screenshot Output Unguided 1_2](https://github.com/ssheilanindya/103112400086_Sheila-Stephanie-Anindya/blob/main/output/output2-unguided1-modul3.png)

kode c++ tersebut menghitung nilai akhir dengan dibagi 3 file terpisah. pada mahasiswa.h, didefinisikan struct mahasiswa yang berisi data nama, NIM, nilai UTS, UAS, tugas, dan nilai akhir, serta deklarasi tiga fungsi: hitungNilaiAkhir, inputMhs, dan tampilkanMhs. pada mahasiswa.cpp berisi implementasi dari fungsi-fungsi di mahasiswa.h,hitungNilaiAkhir menghitung nilai akhir dari bobot 30% UTS, 40% UAS, dan 30% tugas.

### 2. ADT Pelajaran

```C++
#ifndef PELAJARAN_H
#define PELAJARAN_H

#include <string>
using namespace std;

//definisi tipe (struct)
struct pelajaran {
    string namaMapel;
    string kodeMapel;
};

// deklarasi fungsi
pelajaran create_pelajaran(string namapel, string kodepel);
void tampil_pelajaran(pelajaran pel);

#endif

#include "pelajaran.h"
#include <iostream>

using namespace std;

pelajaran create_pelajaran(string namapel, string kodepel) {
    pelajaran p;
    p.namaMapel = namapel;
    p.kodeMapel = kodepel;
    return p;
}

void tampil_pelajaran(pelajaran pel) {
    cout << "nama pelajaran : " << pel.namaMapel << endl;
    cout << "nilai : " << pel.kodeMapel << endl;
}

#include "pelajaran.h"
#include <iostream>
#include <cstdlib> //merupakan sistem pause biar kalo running ga langsung ke close

using namespace std;

int main() {
    string namapel = "Struktur Data";
    string kodepel = "STD";

    pelajaran pel = create_pelajaran (namapel, kodepel);

    tampil_pelajaran(pel);

    return 0;
}
```
### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 2_1](https://github.com/ssheilanindya/103112400086_Sheila-Stephanie-Anindya/blob/main/output/output1-unguided2-modul3.png)


kode c++ tersebut menampilkan nama pelajaran dan nilai sesuai seperti ketentuan di soal. pada file pelajaran.h, struct pelajaran didefinisikan dengan namaMapel dan kodeMapel, serta dideklarasikan dua fungsi yaitu create_pelajaran() untuk membuat data pelajaran baru dan tampil_pelajaran() untuk menampilkannya. lalu pada fungsi main(), program membuat dua variabel string (namapel dan kodepel), memanggil fungsi create_pelajaran untuk membuat data pelajaran baru, dan menampilkannya lewat tampil_pelajaran.

### 3. 2D Array

```C++
#ifndef UNGUIDED3_H
#define UNGUIDED3_H

struct array2D {
    int data[3][3];
};

void tampil(array2D A);

#endif

#include <iostream>
#include "unguided3.h"

using namespace std;

void tampil(array2D A){
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            cout << A.data[i][j] << " ";
        }
        cout << endl;
    }
}

#include <iostream>
#include "unguided3.h"

using namespace std;

int main(){
    array2D A = {{{6,1,2},{4,8,3},{7,4,10}}};
    array2D B = {{{1,2,9},{7,3,6},{9,7,5}}};

    string x = "fly", y = "for";
    string *p1 = &x;
    string *p2 = &y;

    cout << "array A : \n";
    tampil(A);
    cout << "array B : \n";
    tampil(B);

    int baris = 1, kolom = 2;
    int temp = A.data[baris][kolom];
    A.data[baris][kolom] = B.data[baris][kolom];
    B.data[baris][kolom] = temp;

    cout << "\nsetelah tukar elemen ["<<baris<<"]["<<kolom<<"] : \n";
    cout << "array A : \n";
    tampil(A);
    cout << "array B : \n";
    tampil(B);

    cout << "\nsebelum tukar pointer : x = " << x << " y = " << y << endl;
    string t = *p1;
    *p1 = *p2;
    *p2 = t;
    cout << "sesudah tukar pointer : x = " << x << " y = " << y << endl;

    return 0;
}

```
### Output Unguided 3 :

##### Output 1
![Screenshot Output Unguided 3_1](https://github.com/ssheilanindya/103112400086_Sheila-Stephanie-Anindya/blob/main/output/output1-unguided3-modul3.png)

kode c++ tersebut menampilkan isi dua array 3x3 sebelum dan sesudah pertukaran elemen, serta nilai string x dan y sebelum dan sesudah pertukaran melalui pointer sesuai dengan ketentuan soal. nilai string ditukar secara tidak langsung melalui pointer (dengan mengambil isi dari alamat yang ditunjuk *p1 dan *p2), sehingga isi variabel x dan y saling bertukar tanpa menukar alamat memorinya.

## Kesimpulan
dari praktikum modul 3 ini, dapat disimpulkan bahwa Abstract Data Type (ADT) adalah konsep penting dalam pemrograman C++ yang memisahkan struktur data dan cara kerjanya. hal ini membuat program lebih mudah diperbaiki dan dikembangkan. implementasi ADT menggunakan struct dan fungsi/prosedur memudahkan penyimpanan, pengolahan, dan akses data secara teratur, seperti pada program tentang mahasiswa, pelajaran, dan array 2D. pemahaman tentang tipe data dasar dan pointer juga sangat penting dalam mengelola dan menukar data secara efisien.

## Referensi
[1] Modul 3 Praktikum Abstract Data Type (ADT). ADT – Abstract Data Type. Universitas Telkom.
[2] Muliono, Rizki. (2017). Abstract Data Type (ADT). Medan: Universitas Medan Area. Diakses pada 12 Oktober 2025 melalui https://rizkimuliono.blog.uma.ac.id/wp-content/uploads/sites/365/2017/05/ADT-Abstract-Data-Type.pdf
[3] Sianipar, Rismon Hasiholan. (2025). Pemrograman C++ Untuk Pemula. Jakarta: Penerbit Informatika. Diakses pada 12 Oktober 2025 melalui https://books.google.co.id/books?hl=en&lr=&id=tQR2DwAAQBAJ&oi=fnd&pg=PA1&dq=tipe+data+c%2B%2B&ots=rEn-jyJIHU&sig=7ZfteP1lCSbYBhucPaiU6xJNeBY&redir_esc=y#v=onepage&q=tipe%20data%20c%2B%2B&f=false


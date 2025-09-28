# <h1 align="center">Laporan Praktikum Modul 1 - Codeblocks IDE & Pengenalan Bahasa C++ (Bagian Pertama)</h1>
<p align="center">Sheila Stephanie Anindya - 103112400086 </p>

## Dasar Teori

### A. Bahasa C++ <br/>
...
#### 1. Bahasa pemrograman, atau sering diistilahkan dengan bahasa komputer, merupakan teknik komando atau instruksi standar untuk memerintah komputer. Bahasa pemrograman dapat dimanfaatkan untuk membagun sebuah sistem aplikasi sesuai dengan kebutuhan yang dapat dimanfaatkan dalam berbagai bidang baik dalam bidang pendidikan, ekonomi, bisnis bahkan dalam bidang sosial budaya. Salah satu di antaranya adalah bahasa pemrograman C++. [1]
#### 2. Bahasa C++ diciptakan oleh Bjarne Stroustrup di AT&T Bell Laboratories awal tahun 1980-an berdasarkan C ANSI (American National Standard Institute). Pertama kali, prototype C++ muncul sebagai C yang dipercanggih dengan fasilitas kelas. Bahasa tersebut disebut C dengan kelas (C with class). Selama tahun 1983-1984, C dengan kelas disempurnakan dengan menambahkan fasilitas pembenabelihan operator dan fungsi yang kemudian melahirkan apa yang disebut C++. Simbol ++ merupakan operator C untuk operasi penaikan, muncul untuk menunjukkan bahwa bahasa baru ini merupakan versi yang lebih canggih dari C.
#### 3. C++ merupakan bahasa pemrograman yang mendukung pemrograman prosedural sekaligus pemrograman berorientasi objek (object oriented programming). Dengan adanya konsep objek, program yang dibuat menjadi lebih modular, mudah dikembangkan, serta lebih mudah dipahami.

### B. Struktur Data <br/>
...
#### 1. Struktur data adalah cara menyimpan  atau  merepresentasikan data di dalam komputer agar bisa dipakai secara efisien, sedangkan data adalah representasi dari fakta dunia nyata. [3] 
#### 2. Linked List adalah salah satu struktur data penting dalam pemrograman yang digunakan untuk menyimpan dan mengelola data secara dinamis. Struktur data ini memungkinkan kita untuk dengan mudah membuat tempat baru untuk menyimpan data kapan saja dibutuhkan. Linked list atau yang disebut juga senarai berantai adalah Salah satu bentuk struktur data yang berisi kumpulan data yang tersusun secara sekuensial, saling bersambungan, dinamis, dan terbatas[2]. Linked list terdiri dari sejumlah node atau simpul yang dihubungkan secara linier dengan bantuan pointer.
#### 3. Dalam Linked List, data disimpan dalam bentuk simpul atau node yang saling terhubung satu sama lain dengan menggunakan referensi atau alamat dari simpul selanjutnya dalam urutan. Setiap simpul berisi dua hal penting: data yang ingin kita simpan dan alamat referensi ke simpul berikutnya dalam urutan. Dengan begitu, setiap simpul dapat menyimpan data dan mengetahui alamat simpul selanjutnya.

## Guided 

### 1. Input - Output

```C++
#include <iostream>
using namespace std;

int main(){
    int angka;
    cout << "masukkan angka : "; // c out selalu kurang dari
    cin >> angka; // c in untuk memasukkan value, selalu lebih dari
    cout << "angka yang dimasukkan " << angka << endl;
    return 0;
}
```
kode c++ ini meminta input sebuah angka, lalu outputnya berupa angka yang sudah kita input.

### 2. Operasi Aritmatika

```C++
#include <iostream>
using namespace std;

int main(){
    int angka1, angka2;
    cout << "masukkan angka 1 : ";
    cin >> angka1;
    cout << "masukkan angka 2 : ";
    cin >> angka2;

    cout << "penjumlahan : " << angka1 + angka2 << endl;
    cout << "pengurangan : " << angka1 - angka2 << endl;
    cout << "perkalian : " << angka1 * angka2 << endl;
    cout << "pembagian : " << angka1 / angka2 << endl;
    cout << "sisa bagi_mod : " << angka1 % angka2 << endl;
}

```
kode c++ ini meminta untuk menginput 2 angka, lalu program akan mengeksekusi operasi aritmatika dengan penjumlahan, pengurangan, perkalian, pembagian, dan sisa bagi angka.

### 3. Percabangan

```C++
#include <iostream>
using namespace std;

int main(){
     int angka1, angka2;
    cout << "masukkan angka 1 : ";
    cin >> angka1;
    cout << "masukkan angka 2 : ";
    cin >> angka2;

    if (angka1 < angka2) {
        cout << angka1 << " kurang dari " << angka2 << endl;
    } else {
        cout << angka1 << " lebih dari " << angka2 << endl;
    }

    if (angka1 == angka2){
        cout << angka1 << "sama dengan " << angka2 << endl;
    } else if (angka1 != angka2) {
        cout << " angka berbeda " << endl;
    }

    int pilihan;
    cout << "MENU" << endl;
    cout << "1. penjumlahan" << endl;
    cout << "2. pengurangan" << endl;
    cout << "masukkan pilihan : ";
    cin >> pilihan;

    switch (pilihan){
    case 1:
       cout << "penjumlahan : " << angka1 + angka2 << endl;
        break;

    case 2:
       cout << "pengurangan : " << angka1 - angka2 << endl;
       cout << endl;
        break;
    
    default:
    cout << "pilihan salah" << endl;
    }

return 0;
}
```
kode c++ ini meminta kita menginput dua angka, lalu program akan mengeluarkan output bahwa angka tersebut lebih kecil/lebih besar yang mana, serta apakah angka tersebut berbeda atau tidak. lalu diberi pilihan operasi aritmatika yaitu penjumlahan dan pengurangan, jika memilih penjumlahan, program akan menjumlahkan kedua angka yang sudah diinput.

```

### 4. Perulangan

```C++
#include <iostream>
using namespace std;

int main(){
     int angka1;
    cout << "masukkan angka 1 : ";
    cin >> angka1;
    

    for(int i = 0; i < angka1; i++){ //increment
        cout << i << " - "; //nampilinnya dari 0123 dst selama kurang dari angka i
    }
    cout << endl;

    int j = 10;
    while (j > angka1){
        cout << j << " - "; 
        j--; //decrement
    }

    cout << endl;
    int k = 10;
    do{
        cout << k << " - ";
    } while (k < angka1);

    return 0;
    {
       
    }
    
}
```
kode c++ ini meminta kita menginput satu angka, lalu menggunakan perulangan for untuk menampilkan angka dari 0 sampai 1 angka sebelum angka inputan. lalu menggunakan perulangan while dari angka 10 dan menurun satu persatu sampai nilainya lebih kecil dari angka yang sudah diinput. 

```

### 5. Struct

```C++
#include <iostream>
using namespace std;

int main(){
    const int MAX = 3;
    struct rapot{
        string nama;
        float nilai;
    };
    rapot siswa[MAX];

    for(int i = 0; i < MAX; i++){
        cout << "masukkan nama siswa : ";
        cin >> siswa[i].nama;
        cout << "masukkan nilai siswa : ";
        cin >> siswa[i].nilai;
        cout << endl;
    }

    int j = 0;
    while(j < MAX){
        cout << "Nama Siswa : " << siswa[j].nama << ", Nilai : " << siswa[j].nilai << endl;
    j++;
    }
    return 0;
}
```
kode c++ ini menyimpan rapot di struct untuk menyimpan data nama dan nilai siswa, lalu menggunakan array siswa dengan MAX = 3. Output program berupa nama siswa dan nilai siswa yang sudah diinput (maksimal 3).

## Unguided 

### 1. Unguided 1

Buatlah program yang menerima input-an dua buah bilangan betipe float, kemudian memberikan output-an hasil penjumlahan, pengurangan, perkalian, dan pembagian dari dua bilangan tersebut.

```C++
// 103112400086
// Sheila Stephanie Anindya

#include <iostream>
using namespace std;

int main() {
    float angka1, angka2;

    cout << "masukkan angka 1 : ";
    cin >> angka1;
    cout << "masukkan angka 2 : ";
    cin >> angka2;

    cout << "penjumlahan : " << angka1 + angka2 << endl;
    cout << "pengurangan : " << angka1 - angka2 << endl;
    cout << "perkalian : " << angka1 * angka2 << endl;
    cout << "pembagian : " << angka1 / angka2 << endl;

    return 0;
}
```
### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/ssheilanindya/103112400086_Sheila-Stephanie-Anindya/blob/main/output/output1-unguided1-modul1.png)

##### Output 2
![Screenshot Output Unguided 1_2](https://github.com/ssheilanindya/103112400086_Sheila-Stephanie-Anindya/blob/main/output/output2-unguided1-modul1.png)

kode c++ ini meminta untuk menginput 2 angka, lalu program akan mengeksekusi operasi aritmatika dengan penjumlahan, pengurangan, perkalian, pembagian angka.

### 2. Unguided 2

Buatlah sebuah program yang menerima masukan angka dan mengeluarkan output nilai angka tersebut dalam bentuk tulisan. Angka yang akan di-input-kan user adalah bilangan bulat positif mulai dari 0 s.d 100.

```C++
// 103112400086
// Sheila Stephanie Anindya

#include <iostream>
using namespace std;

int main(){
    string satuan[] = {"nol", "satu", "dua", "tiga", "empat", "lima", "enam", "tujuh", "delapan", "sembilan"};
    int n;

    cout << "masukkan angka (1-100) : ";
    cin >> n;

    cout << n << " : ";

    if (n < 10) {
        cout << satuan[n];
    } else if (n == 10) {
        cout << "sepuluh";
    } else if (n == 11) {
        cout << "sebelas";
    } else if (n == 100) {
        cout << "seratus";
    } else if (n < 20) {
        cout << satuan [n % 10] << " belas";
    } else {
        cout << satuan [n / 10] << " puluh";
        if (n % 10)
        {
            cout << " " << satuan [n % 10];
        }
        cout << endl;
    }   
}
```
### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 2_1](https://github.com/ssheilanindya/103112400086_Sheila-Stephanie-Anindya/blob/main/output/output1-unguided2-modul1.png)

##### Output 2
![Screenshot Output Unguided 2_2](https://github.com/ssheilanindya/103112400086_Sheila-Stephanie-Anindya/blob/main/output/output2-unguided2-modul1.png)

kode c++ tersebut mengonversi angka menjadi bentuk tulisan untuk rentang 1-100. program menyimpan satuan di array yang berisi kata dari angka 0-9. jika angka kurang dari 10, program akan mengambil kata dari array satuan. untuk angka 10, 11, dan 100 menggunakan 'if' sehingga memunculkan kata "sepuluh", "sebelas", dan "seratus". untuk angka 12–19, program menuliskan kata satuan kemudian menambahkan kata “belas”. sedangkan angka 20–99 dituliskan dengan format <puluhan> puluh <satuan>

### 3. Unguided 3

Buatlah program yang dapat memberikan input dan output berupa pola angka berbentuk simetris dengan tanda bintang ditengah.

```C++
// 103112400086
// Sheila Stephanie Anindya

#include <iostream>
using namespace std;

int main(){
    int angka;

    cout << "masukkan angka : ";
    cin >> angka;

    for (int i = angka; i >= 0; i--) {
        for (int j = angka; j > i; j--) {
            cout << "  ";
        }

        for (int k = i; k >= 1; k--) {
            cout << k << " ";
        }
        cout << "* "; // bintang

        for (int k = 1; k <= i; k++) {
            cout << k << " ";
        }
        cout << endl;
    }
    return 0;
}
```
### Output Unguided 3 :

##### Output 1
![Screenshot Output Unguided 3_1](https://github.com/ssheilanindya/103112400086_Sheila-Stephanie-Anindya/blob/main/output/output1-unguided3-modul1.png)

##### Output 2
![Screenshot Output Unguided 3_2](https://github.com/ssheilanindya/103112400086_Sheila-Stephanie-Anindya/blob/main/output/output2-unguided3-modul1.png)

kode c++ ini mencetak pola angka berbentuk simetris dengan tanda bintang ditengah. program menggunakan perulangan for untuk mengatur baris dari angka yang diinput sampai 0. di setiap baris, program mencetak spasi agar pola rata ke kanan, kemudian menampilkan deretan angka menurun dari i ke 1 di sebelah kiri. lalu program mencetak simbol * sebagai pemisah tengah, lalu menampilkan kembali angka naik dari 1 sampai i di sisi kanan.

## Kesimpulan
Bahasa pemrograman merupakan sarana utama untuk memberikan instruksi kepada komputer dalam membangun berbagai sistem aplikasi di beragam bidang. Salah satunya adalah bahasa C++, yang dikembangkan oleh Bjarne Stroustrup pada awal 1980-an sebagai pengembangan dari bahasa C. C++ memiliki keunggulan karena mendukung pemrograman prosedural maupun berorientasi objek, sehingga program yang dihasilkan lebih modular, fleksibel, dan mudah dikembangkan.
Sementara struktur data berperan penting dalam mengelola dan menyimpan data agar dapat digunakan secara efisien. Salah satu bentuk struktur data yang banyak digunakan adalah Linked List, yaitu senarai berantai yang terdiri dari simpul-simpul (node) yang terhubung secara linier menggunakan pointer. Setiap simpul menyimpan data serta referensi ke simpul berikutnya, sehingga memungkinkan pengelolaan data secara dinamis sesuai kebutuhan.

## Referensi
[1] Dewi, Luh Joni Erawati. (2010). “Media Pembelajaran Bahasa Pemrograman C++”. Jurnal Pengembangan Teknologi dan Kreativitas (JPTK), Vol. 7 No. 1, hal. 63–72. Medan: Universitas Pendidikan Ganesha. Diakses pada 28 September 2025 melalui https://share.google/m41jD9xhaVaQUKUrZ. 
[2] Triase. (2020). Diktat Edisi Revisi : STRUKTUR DATA. Medan: UNIVERSTAS ISLAM NEGERI SUMATERA UTARA MEDAN. 
<br>[2] Indahyati, Uce., Rahmawati Yunianita. (2020). "BUKU AJAR ALGORITMA DAN PEMROGRAMAN DALAM BAHASA C++". Sidoarjo: Umsida Press. Diakses pada 28 September 2025 melalui https://doi.org/10.21070/2020/978-623-6833-67-4.
[3] Hasdyna, Novia & Dinata, Rozzi Kesuma. (2021). Pembelajaran Struktur Data dalam Pemrograman C++. Lhokseumawe: Sefa Bumi Persada. Diakses pada 28 September 2025 melalui https://repository.unimal.ac.id/6709/1/PEMBELAJARAN%20STRUKTUR%20DATA%20DALAM%20PEMROGRAMAN%20C++.pdf.

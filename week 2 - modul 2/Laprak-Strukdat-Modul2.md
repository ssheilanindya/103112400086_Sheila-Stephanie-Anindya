# <h1 align="center">Laporan Praktikum Modul 2 - Pengenalan Bahasa C++ (Bagian Kedua)</h1>
<p align="center">Sheila Stephanie Anindya - 103112400086 </p>

## Dasar Teori
isi dengan penjelasan dasar teori disertai referensi jurnal (gunakan kurung siku [] untuk pernyataan yang mengambil refernsi dari jurnal).
contoh :
Linked list atau yang disebut juga senarai berantai adalah Salah satu bentuk struktur data yang berisi kumpulan data yang tersusun secara sekuensial, saling bersambungan, dinamis, dan terbatas[1]. Linked list terdiri dari sejumlah node atau simpul yang dihubungkan secara linier dengan bantuan pointer.

### A. Struktur Data <br/>
Struktur data adalah cara menyimpan atau tahap -tahap merepresentasikan data di dalam komputer. Struktur data menunjukkan skema organisasi, yang diterapkan pada data sehingga data dapat diinterpretasikan seperti struktur dan array, sehingga operasi-operasi spesifik dapat dilaksanakan pada data.[1]
Struktur data dan algoritma berhubungan sangat erat pada sebuah program. Algoritma merupakan tahapan terencana yang menyatakan dengan jelas pemecahan suatu permasalahan dalam rentang waktu tertentu. Setiap bahasa pemrograman mempunyai struktur pengkodingan untuk itu implementasi pembelajaran mempergunakan Bahasa C++. Pemahaman pengetahuan tentang teori dasar struktur data serta pembuatan algoritma. Secara garis besar buku ini membahas Konsep Struktur Data, Bahasa C++, Array dan Pointer, Pengurutan Data, Function, Linked List, Stack dan Queue, Tree disertai contoh pengkodingan bahasa C++.[1]
#### 1. Array di C++ dapat didefinisikan sebagai kumpulan beberapa variabel struktur di mana setiap variabel berisi informasi tentang entitas yang berbeda. Digunakan untuk menyimpan informasi tentang banyak entitas dari tipe data yang berbeda. Array of struct juga dikenal sebagai kumpulan dari struktur.[2] Elemen dalam array dapat dikenali sebagai elemen pertama, kedua, dan seterusnya hingga elemen ke-n. Array memiliki tipe data yang sama untuk semua elemennya, sehingga disebut homogen. Ciri khas array adalah penggunaan memori yang disiapkan secara statis, tipe data yang sama untuk semua elemen, dan kemampuan mengakses elemen secara langsung. Bentuk dasar dari array adalah tipe_data nama_array[jumlah_elemen], seperti int arr[5]; atau double d[10];. Array dapat dibagi menjadi beberapa jenis, yaitu array satu dimensi, dua dimensi, dan multidimensi. Untuk mengisi array, kita dapat memasukkan nilai-nilai elemen di dalam tanda kurung.
#### 2. Pointer adalah elemen penting dalam C++ yang membuka berbagai kemungkinan pengelolaan memori dan pengembangan program yang efisien. Misalnya kita ingin membuat beberapa penunjuk ke blok penyimpan yang berisi integer. Deklarasi pada C adalah: int *IntegerPointer;. Tanda asterisk (*) yang berada sebelum nama variabel IntegerPointer menandakan “pointer pada suatu int”. Jadi deklarasi tersebut berarti definisikan sebuah tipe yang terdiri dari pointer bertipe integer yang bernama IntegerPointer. Apabila di depannya ditambahkan typedef seperti typedef int *IntegerPointer;, maka IntegerPointer merupakan suatu tipe pointer berbentuk integer. Jika mendeklarasikan dua variabel A dan B sebagai penunjuk ke bilangan integer dengan IntegerPointer A, B;, maka kompiler C akan berisi nilai dari variabel A dan B yang menunjuk ke integer. Untuk membuat beberapa penunjuk ke beberapa penyimpan integer yang kosong dan untuk membuat A dan B menunjuk tempat tersebut, digunakan prosedur dinamis untuk alokasi penyimpan yang disebut malloc.[1]
#### 3. Function adalah bagian dari kode yang melakukan beberapa tugas. Function bisa memasukkan parameter input yang memungkinkan orang lain mengirimkan argumen ke dalam function tersebut. Function juga bisa mengembalikan nilai sebagai hasilnya. Function berguna untuk mengumpulkan tugas-tugas umum dalam satu bagian yang bisa digunakan berkali-kali, dan sebaiknya diberi nama yang jelas menjelaskan apa yang dilakukan oleh function itu. Pada function diperlukannya spesifikasi tipe data yang digunakan, kemudian diikuti dengan nama fungsi, parameter fungsi, isi  fungsi, dan terakhir adalah nilai yang dikembalikan oleh fungsi. Perlu diperhatikan bahwa nilai yang dikembalikan harus memiliki tipe data yang sama dengan tipe data fungsi itu sendiri.[3]
#### 4. Procedure adalah suatu program yang terpisah dalam blok sendiri dan berfungsi sebagai subprogram atau bagian dari program. Procedure biasanya merupakan suatu aktivitas, seperti mencari bilangan prima dari sekumpulan bilangan atau mencari bilangan genap dari sekumpulan bilangan. Procedure bisa mengembalikan atau tidak mengembalikan nilai/hasil, sedangkan function wajib mengembalikan nilai keluaran. Procedure membutuhkan suatu variabel khusus untuk menampung hasil/nilai ketika terjadi proses perhitungan, sedangkan function tidak membutuhkan karena berlaku ketentuan bahwa nama fungsi sama dengan nama atau variabel proses. Pada procedure, pencetakan hasil/nilai berada dalam blok subrutin itu sendiri yang kemudian dipanggil dengan nama procedurenya di dalam program utama, sedangkan pada function proses pencetakan hasil/nilai dilakukan di program utama ketika pemanggilan function-nya.[4]


## Guided 

### 1. Array Pointer

```C++
// arr N pointer

#include<iostream>
using namespace std;

int main(){
    int arr[] = {10, 20, 30, 40, 50};
    int *ptr = arr; // pointer yang menunjuk ke elemen pertama array 

    // mengakses elemen array menggunakan pointer
    for (int i = 0; i < 5; i++){
        cout << "elemen array ke-" << i + 1 << " menggunakan pointer : " << *(ptr + 1) << endl;
    }
    
    // mengakses elemen array menggunakan indeks
    for (int i = 0; i < 5; i++){
        cout << "elemen array ke-" << i + 1 << " menggunakan indeks : " << arr[i] << endl;
    }

    return 0;
    
}

```
code C++ di atas membuat sebuah array arr yang berisi lima angka dan sebuah pointer ptr yang menunjuk ke elemen pertama array tersebut. lalu program mencoba menampilkan elemen-elemen array dengan dua cara, yang pertama menggunakan pointer dengan ekspresi *(ptr + 1), dan kedua menggunakan indeks langsung arr[i].

## Unguided 

### 1. Buatlah program yang dapat melakukan operasi penjumlahan, pengurangan, dan perkalian matriks 3x3 tersebut. Buat prosedur untuk masing-masing operasi yang dilakukan; jumlahMatriks() untuk operasi penjumlahan, kurangMatriks() untuk pengurangan, dan kaliMatriks() untuk perkalian.

```C++
// aritmetika matriks ordo 3 x 3
#include <iostream>
using namespace std;

void tampilkanHasil(int arr[3][3]){
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            cout << arr[i][j] << "\t";
        }
        cout << endl;
    }
}

void jumlahMatriks(int arrA[3][3], int arrB[3][3]){
    int arrC[3][3];
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            arrC[i][j] = arrA[i][j] + arrB[i][j];
        }
    }

    cout << "hasil penjumlahan : " << endl;
    tampilkanHasil(arrC);
}

void kurangMatriks(int arrA[3][3], int arrB[3][3]){
    int arrC[3][3];
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            arrC[i][j] = arrA[i][j] - arrB[i][j];
        }
    }
    cout << "hasil pengurangan : " << endl;
    tampilkanHasil(arrC);
}

void kaliMatriks(int arrA[3][3], int arrB[3][3]){
    int arrC[3][3] = {0};
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            for (int k = 0; k < 3; k++){
                arrC[i][j] += arrA[i][k] * arrB[k][j];
            }
        }
    }
    cout << "hasil perkalian : " << endl;
    tampilkanHasil(arrC);
}

int main(){
    int arrA[3][3] = {
        {7, 12, 22},
        {31, 6, 41},
        {15, 19, 36}
    };

    int arrB[3][3] = {
        {11, 34, 7},
        {3, 25, 41},
        {5, 18, 33}
    };

    int pilihan;
    do {
        cout << "\n--- menu program matriks ---\n";
        cout << "1. penjumlahan matriks\n";
        cout << "2. pengurangan matriks\n";
        cout << "3. perkalian matriks\n";
        cout << "4. keluar\n";
        cout << "pilih menu: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                jumlahMatriks(arrA, arrB);
                break;
            case 2:
                kurangMatriks(arrA, arrB);
                break;
            case 3:
                kaliMatriks(arrA, arrB);
                break;
            case 4:
                cout << " " << endl;
                break;
            default:
                cout << "pilihan salah" << endl;
        }
    } while (pilihan != 4);

    return 0;
}

```
### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/ssheilanindya/103112400086_Sheila-Stephanie-Anindya/blob/main/output/output1-unguided1-modul2.png)

##### Output 2
![Screenshot Output Unguided 1_2]!(https://github.com/ssheilanindya/103112400086_Sheila-Stephanie-Anindya/blob/main/output/output2-unguided1-modul2.png)

kode C++ ini membuat operasi aritmetika pada matriks ber-ordo 3×3, yaitu penjumlahan, pengurangan, dan perkalian. program menyimpan dua matriks yang bernama arrA dan arrB, kemudian memberikan menu interaktif kepada pengguna untuk memilih jenis operasi yang ingin dilakukan. fungsi tampilkanHasil digunakan untuk menampilkan matriks ke layar, sedangkan fungsi jumlahMatriks, kurangMatriks, dan kaliMatriks masing-masing melakukan operasi penjumlahan, pengurangan, dan perkalian dengan membuat matriks hasil baru bernama arrC, lalu menampilkan hasilnya menggunakan fungsi tampilkanHasil. untuk operasi perkalian matriks, program menggunakan tiga buah loop bersarang untuk menghitung hasil perkalian elemen sesuai dengan aturan perkalian matriks. program akan terus meminta input dari pengguna sampai pengguna memilih menu keluar yaitu opsi nomor 4.

### 2. Buatlah program menghitung luas dan keliling persegi panjang dengan proses perhitungan dan perubahan nilainya menggunakan pointer

```C++
#include <iostream>
using namespace std;

int main() {
    int panjang = 10, 
    lebar = 5, 
    luas = 0;

    int *ptrPanjang = &panjang;
    int *ptrLebar = &lebar;

    cout << "--- nilai awal ---" << endl;
    cout << "panjang : " << *ptrPanjang << endl;
    cout << "lebar : " << *ptrLebar << endl;

    luas = (*ptrPanjang) * (*ptrLebar);
    int keliling = 2 * ((*ptrPanjang) + (*ptrLebar));

    cout << "\n--- hasil perhitungan ---" << endl;
    cout << "luas persegi panjang : " << luas << endl;
    cout << "keliling persegi panjang : " << keliling << endl;

    *ptrPanjang = 12;
    *ptrLebar = 6;

    luas = (*ptrPanjang) * (*ptrLebar);
    keliling = 2 * ((*ptrPanjang) + (*ptrLebar));

    cout << "\n--- nilai setelah diubah melalui pointer ---" << endl;
    cout << "panjang baru : " << *ptrPanjang << endl;
    cout << "Lebar baru : " << *ptrLebar << endl;
    cout << "luas baru : " << luas << endl;
    cout << "keliling baru : " << keliling << endl;

    return 0;
}

```
### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 2_1](https://github.com/ssheilanindya/103112400086_Sheila-Stephanie-Anindya/blob/main/output/output1-unguided2-modul2.png)


kode C++ ini mengambil dan merubah nilai variabel. program membuat dua variabel, yaitu panjang dan lebar, yang digunakan untuk menghitung luas dan keliling persegi panjang. lalu, program juga membuat dua pointer, yaitu ptrPanjang dan ptrLebar, yang menunjuk ke alamat variabel panjang dan lebar tersebut. di awal, program menampilkan nilai awal dari panjang dan lebar melalui pointer. lalu, program menghitung luas dan keliling persegi panjang menggunakan nilai tersebut. lalu, program mengubah nilai panjang dan lebar secara langsung melalui pointer, lalu menghitung dan menampilkan lagi nilai luas serta keliling setelah perubahan.


## Kesimpulan
Dari praktikum modul 2 ini, dapat disimpulkan bahwa memahami array, pointer, function, dan procedure sangat penting dalam pemrograman C++. Array memungkinkan penyimpanan banyak data yang tipe-nya sama dalam satu variabel. Pointer memungkinkan akses dan perubahan nilai variabel secara langsung melalui alamat memori, sehingga membuat program lebih fleksibel dan efisien. Function dan procedure membantu dalam mengatur kode dengan baik, memisahkan tugas-tugas tertentu sehingga bisa digunakan kembali. Dalam praktikum ini, konsep tersebut diterapkan melalui operasi matriks 3×3 dan perhitungan luas serta keliling persegi panjang menggunakan pointer, sehingga dapat dimengerti hubungan antara teori struktur data dan pemrograman nyata dalam C++.

## Referensi
[1] Sindar, Anita. (2019). STRUKTUR DATA DAN ALGORITMA DENGAN C. Diakses pada 3 Oktober 2025 melalui https://www.researchgate.net/profile/Anita-Sindar/publication/337657500_STRUKTUR_DATA_DAN_ALGORITMA_DENGAN_C/links/5de3c560299bf10bc33628a2/STRUKTUR-DATA-DAN-ALGORITMA-DENGAN-C.pdf
[2] Apriyanto, D. (2021). Dasar-Dasar Pemrograman. Yogyakarta: Deepublish. Diakses pada 3 Oktober 2025 melalui https://www.google.co.id/books/edition/Dasar_Dasar_Pemrograman/itUvEAAAQBAJ?hl=en&gbpv=0
[3] Putra, M. T. D., Munawir, M., & Yuniarti, A. R. (2023, September 14). Belajar pemrograman lanjut dengan C++. Diakses pada 3 Oktober 2025 melalui https://repository.penerbitwidina.com/publications/564507/belajar-pemrograman-lanjut-dengan-c#id-section-title
[4] Indahyanti, U., & Rahmawati, Y. (2021). Buku ajar algoritma dan pemrograman dalam bahasa C++. Umsida Press. https://doi.org/10.21070/2020/978-623-6833-67-4 
<br>...

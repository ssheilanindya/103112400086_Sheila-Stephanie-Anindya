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

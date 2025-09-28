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
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
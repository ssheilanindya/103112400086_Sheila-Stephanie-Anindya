// Call by Reference

#include <iostream>
using namespace std;

void ubahNilai(int & ref){
    ref = 20; //mengubah nilai melalui referensi
}

int main(){
    int x = 10;
    cout << "nilai sebelum diubah : " << x << endl;

    ubahNilai(x); //mengirimkan referensi ke x
    cout << "nilai setelah diubah : " << x << endl;

    return 0;
}
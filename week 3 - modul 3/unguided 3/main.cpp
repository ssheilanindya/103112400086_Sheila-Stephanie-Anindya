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

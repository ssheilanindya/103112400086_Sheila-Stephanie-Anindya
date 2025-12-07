#include <iostream>

using namespace std;    

int pangkat_2 (int x) { // x pangkatnya
    if (x == 0) { // basis (kondisi dasar)
        return 1;
    } else if (x > 0 ) { // rekurens
        return 2 * pangkat_2(x - 1);
    }
}

int main() {
    cout << "=== rekursif pangkat 2 ===" << endl;

    int x;
    cout << "masukkan nilai x: ";
    cin >> x;
    cout << endl;
    cout << "2 pangkat " << x << " adalah " << pangkat_2(x);

    return 0;
}

// misal x = 3
// run 1 = pangkat_2(3)
// 2 * pangkat(2);
// 2 * (2 * pangkat_2(1));
// 2 * (2 * (2 * pangkat_2(0)));
// = 2 * 2 * 2 * 1 = 8
// jadi 2 pangkat 3 = 8
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

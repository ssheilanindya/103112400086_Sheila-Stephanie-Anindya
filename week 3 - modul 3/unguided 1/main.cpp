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
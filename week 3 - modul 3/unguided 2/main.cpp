#include "pelajaran.h"
#include <iostream>
#include <cstdlib> //merupakan sistem pause biar kalo running ga langsung ke close

using namespace std;

int main() {
    string namapel = "Struktur Data";
    string kodepel = "STD";

    pelajaran pel = create_pelajaran (namapel, kodepel);

    tampil_pelajaran(pel);

    return 0;
}
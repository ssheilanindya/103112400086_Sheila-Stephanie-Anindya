// main.cpp

#include "singlylist.h"
#include <chrono>
#include <iostream>
#include <iomanip>

using namespace std;
using namespace std::chrono;

int main() {
    auto start = high_resolution_clock::now();  // mulai timer

    List L;
    address P1, P2, P3, P4, P5;

    CreateList(L);

    P1 = alokasi(2);
    insertFirst(L, P1);

    P2 = alokasi(0);
    insertFirst(L, P2);

    P3 = alokasi(8);
    insertFirst(L, P3);

    P4 = alokasi(12);
    insertFirst(L, P4);

    P5 = alokasi(9);
    insertFirst(L, P5);

    printInfo(L);

    auto stop = high_resolution_clock::now();   // stop timer
    duration<double> elapsed = stop - start;    // durasi detik

    cout << fixed << setprecision(3);
    cout << "Process returned 0 (0x0)   execution time : "
         << elapsed.count() << " s" << endl;

    cout << "Press any key to continue.";
    cin.get();  // nunggu inputan sebelum program selesai
    return 0;
}

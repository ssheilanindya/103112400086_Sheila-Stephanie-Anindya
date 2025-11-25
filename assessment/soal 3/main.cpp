#include "soal3.h"
#include <iostream>

using namespace std;

int main() {
    stackMHS stack;
    createStack(stack);
    
    for (int i = 0; i < 5; i++) {
        cout << i + 1 << endl;
        push(stack);
    }

    view(stack);
    pop(stack);
    view(stack);
    update(stack, 2);
    view(stack);
    searchNilaiAkhir(stack, 85.5f, 95.5f);
    maxNilaiAkhir(stack);

    return 0;
}

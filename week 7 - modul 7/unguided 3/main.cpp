#include <iostream>
#include "stack.h"

using namespace std;

int main() {
    cout << "hello world!" << endl;

    stack S;
    createStack(S);
    getInputStream(S);
    printInfo(S);

    cout << "balik stack" << endl;

    balikStack(S);
    printInfo(S);

    return 0;
}

#include "queue.h"
#include <iostream>

using namespace std;

int main() {
    cout << "hello world!" << endl;

    queue Q;
    createQueue(Q);

    cout << "-------------------------" << endl;
    cout << " H - T | queue info" << endl;
    cout << "-------------------------" << endl;

    printInfo(Q);

    enqueue(Q, 5); printInfo(Q);
    enqueue(Q, 2); printInfo(Q);
    enqueue(Q, 7); printInfo(Q);

    dequeue(Q);    printInfo(Q);   // 2 7
    dequeue(Q);    printInfo(Q);   // 7
    enqueue(Q, 4); printInfo(Q);   // 7 4
    dequeue(Q);    printInfo(Q);   // 4

    dequeue(Q); printInfo(Q);

    return 0;
}

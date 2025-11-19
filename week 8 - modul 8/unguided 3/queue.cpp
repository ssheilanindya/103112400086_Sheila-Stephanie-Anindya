#include "queue.h"

void createQueue(queue &Q) {
    Q.head = Nil;
    Q.tail = Nil;
}

bool isEmptyQueue(queue Q) {
    return (Q.head == Nil && Q.tail == Nil);
}

bool isFullQueue(queue Q) {
    return ((Q.tail + 1) % MaxEl == Q.head);
}

void enqueue(queue &Q, infotype x) {
    if (isFullQueue(Q)) {
        cout << "queue penuh" << endl;
    } else {
        if (isEmptyQueue(Q)) {
            Q.head = 0;
            Q.tail = 0;
        } else {
            Q.tail = (Q.tail + 1) % MaxEl;   // tail berputar
        }
        Q.info[Q.tail] = x;
    }
}

infotype dequeue(queue &Q) {
    if (isEmptyQueue(Q)) {
        cout << "queue kosong" << endl;
        return -1;
    }

    infotype x = Q.info[Q.head];

    if (Q.head == Q.tail) {
        Q.head = Nil;
        Q.tail = Nil;
    } else {
        Q.head = (Q.head + 1) % MaxEl;   // head berputar
    }

    return x;
}

void printInfo(queue Q) {
    cout << Q.head << " - " << Q.tail << " | ";

    if (isEmptyQueue(Q)) {
        cout << "empty queue" << endl;
        return;
    }

    int i = Q.head;
    while (true) {
        cout << Q.info[i] << " ";
        if (i == Q.tail) break;
        i = (i + 1) % MaxEl;
    }

    cout << endl;
}

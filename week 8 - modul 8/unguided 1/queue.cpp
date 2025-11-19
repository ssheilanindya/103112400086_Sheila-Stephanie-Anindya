#include "queue.h"
#include <iostream>

using namespace std;

void createQueue(queue &Q) {
    Q.head = Nil;
    Q.tail = Nil;
}

bool isEmptyQueue(queue Q) {
    return (Q.head == Nil && Q.tail == Nil);
}

bool isFullQueue(queue Q) {
    return (Q.tail == MaxEl - 1);
}

void enqueue(queue &Q, infotype x) {
    if (isFullQueue(Q)) {
        cout << "Queue penuh" << endl;
    } else {
        if (isEmptyQueue(Q)) {
            Q.head = 0;
            Q.tail = 0;
        } else {
            Q.tail++;
        }
        Q.info[Q.tail] = x;
    }
}

infotype dequeue(queue &Q) {
    if (isEmptyQueue(Q)) {
        cout << "empty queue" << endl;
        return -1;
    }

    infotype x = Q.info[Q.head];

    if (Q.head == Q.tail) {
        Q.head = Nil;
        Q.tail = Nil;
    } else { // geser elemen ke kiri
        for (int i = Q.head; i < Q.tail; i++) {
            Q.info[i] = Q.info[i + 1];
        }
        Q.tail--; // soalnya elemen bergeser
    }

    return x;
}

void printInfo(queue Q) {
    cout << Q.head << " - " << Q.tail << " | ";

    if (isEmptyQueue(Q)) {
        cout << "empty queue" << endl;
    } else {
        for (int i = Q.head; i <= Q.tail; i++) {
            cout << Q.info[i];
            if (i < Q.tail) cout << " ";
        }
        cout << endl;
    }
    
}
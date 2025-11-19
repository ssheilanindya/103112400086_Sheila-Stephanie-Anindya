#ifndef QUEUE_H
#define QUEUE_H

#define MaxEl 5
#define Nil -1

#include <iostream>

using namespace std;

typedef int infotype;

struct queue {
    infotype info[MaxEl];
    int head;
    int tail;
};

void createQueue(queue &Q);
bool isEmptyQueue(queue Q);
bool isFullQueue(queue Q);
void enqueue(queue &Q, infotype x);
infotype dequeue(queue &Q);
void printInfo(queue Q);

#endif

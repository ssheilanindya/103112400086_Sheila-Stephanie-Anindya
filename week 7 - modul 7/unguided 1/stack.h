#ifndef STACK_H
#define STACK_H

#include <iostream>
using namespace std;

#define MaxEl 20
#define Nil -1

typedef int infotype;

struct stack {
    infotype info[MaxEl];
    int top;
};

void createStack(stack &S);
void push(stack &S, infotype x);
infotype pop(stack &S);
void printInfo(stack S);
void balikStack(stack &S);

#endif

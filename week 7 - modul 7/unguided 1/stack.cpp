#include "stack.h"

using namespace std;

void createStack(stack &S) {
    S.top = -1;
}

void push(stack &S, int x) {
    if (S.top < MaxEl - 1) {
        S.top++;
        S.info[S.top] = x;
    } else {
        cout << "stack penuh" << endl;
    }
}

int pop(stack &S) {
    if (S.top >= 0) {
        int x = S.info[S.top];
        S.top--;
        return x;
    } else {
        cout << "stack kosong" << endl;
        return -1;
    }
}

void printInfo(stack S) {
    cout << "[TOP] ";
    for (int i = S.top; i >= 0; i--) {
        cout << S.info[i] << " ";
    }
    cout << endl;
}

void balikStack(stack &S) {
    stack temp;
    createStack(temp);

    while (S.top >= 0) {
        push(temp, pop(S));
    }

    S = temp;
}

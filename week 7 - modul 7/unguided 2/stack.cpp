#include "stack.h"

void createStack(stack &S) {
    S.top = Nil;
}

bool isEmpty(stack S) {
    return S.top == Nil;
}

bool isFull(stack S) {
    return S.top == MaxEl - 1;
}

void push(stack &S, infotype x) {
    if (!isFull(S)) {
        S.top++;
        S.info[S.top] = x;
    } else {
        cout << "stack penuh" << endl;
    }
}

infotype pop(stack &S) {
    infotype x = -999;

    if (!isEmpty(S)) {
        infotype x = S.info[S.top];
        S.top--;

        return x;

    } else {
        cout << "stack kosong" << endl;
        
        return x;
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
    if (!isEmpty(S)) {  
        stack temp1, temp2;  

        createStack(temp1); 
        createStack(temp2);  

        while (!isEmpty(S)) { 
            push(temp1, pop(S)); 
        }  

        while (!isEmpty(temp1)) { 
            push(temp2, pop(temp1)); 
        }  

        while (!isEmpty(temp2)) { 
            push(S, pop(temp2)); 
        }  
    }
}

void pushAscending(stack &S, infotype x) {
    stack temp;
    createStack(temp);

    while (!isEmpty(S) && S.info[S.top] > x) {
        push(temp, pop(S));
    }

    push(S, x);

    while (!isEmpty(temp)) {
        push(S, pop(temp));
    }
}

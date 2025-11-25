#include <iostream>
using namespace std;

struct node {
    int data;
    node* next;
    node* prev;
};

node* head = NULL;
node* tail = NULL;

void insertAkhir(int x) {
    node* baru = new node();
    baru -> data = x;
    baru -> next = NULL;
    baru -> prev = tail;

    if (head == NULL) {
        head = tail = baru;
    } else {
        tail -> next = baru;
        tail = baru;
    }
}

void deleteAkhir() {
    if (tail == NULL) {
        cout << "list kosong.\n";
        return;
    }

    node* hapus = tail;

    if (head == tail) { 
        head = tail = NULL;
    } else {
        tail = tail->prev;
        tail -> next = NULL;
    }

    delete hapus;
}

void viewForward() {
    node* p = head;
    if (!p) {
        cout << "list kosong\n";
        return;
    }
    while (p != NULL) {
        cout << p -> data << " ";
        p = p -> next;
    }
    cout << endl;
}

void reverseList() {
    node* curr = head;
    node* temp = NULL;

    while (curr != NULL) {
        temp = curr -> prev;
        curr -> prev = curr -> next;
        curr -> next = temp;
        curr = curr -> prev;  
    }

    if (temp != NULL) {
        head = temp -> prev;
    }

    tail = head;
    if (tail != NULL) {
        while (tail -> next != NULL)
            tail = tail -> next;
    }
}

int main() {
    int pilihan, x;

    do {
        cout << "menu : 1 insert (end), 2 delete (last), 3 view (depan), "
             << "4 reverse & view (depan), 0 exit\n";
        cin >> pilihan;

        if (pilihan == 1) {
            cout << "masukkan nilai : ";
            cin >> x;

            insertAkhir(x);

        } else if (pilihan == 2) {
            deleteAkhir();

        } else if (pilihan == 3) {
            viewForward();
            
        } else if (pilihan == 4) {
            reverseList();

            cout << "list setelah di-reverse: ";
            viewForward();

        }

    } while (pilihan != 0);

    return 0;
}

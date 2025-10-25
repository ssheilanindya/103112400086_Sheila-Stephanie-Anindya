#include <iostream>
using namespace std;

//definisi node
struct Node{ // memiliki 2 bagian (data dan pointer)
    int data;
    Node* next; // pointer ke node berikutnya
};

// function node baru di akhir linked list
void append(Node*& head, int value) {
    Node* newNode = new Node{value, nullptr};
    if (!head)
        head = newNode;
    else {
        Node* temp = head;
        while (temp -> next)
            temp = temp -> next;
        temp -> next = newNode;
    }
}
void printList(Node* head) {
    cout << "linked list yang dibuat : ";
    Node* temp = head;
    while (temp) {
        cout << temp -> data << " -> ";
        temp = temp -> next;
    }
    cout << "NULL" << endl;
}

Node* linearSearch(Node* head, int key) {
    cout << "mencari nilai : " << key << endl;
    cout << "\nproses pencarian : " << endl;

    Node* current = head;
    int nomorNode = 1;
    bool found = false;

    while (current != nullptr) {
        cout << "memeriksa node " << nomorNode << ": " << current -> data;

        if (current -> data == key) {
            cout << " (sama) - ditemukan!" << endl;

            cout << "\nhasil : nilai " << key << " ditemukan pada linked list!" << endl;
            cout << "alamat node : " << current << endl;
            cout << "data node : " << current -> data << endl;

            // node berikutnya kalo ada
            if (current -> next)
                cout << "node berikutnya : " << current -> next -> data << endl;
            else
                cout << "node berikutnya : NULL" << endl;

            found = true;
            break;
        } else {
            cout << " (tidak sama) " << endl;
        }

        current = current -> next;
        nomorNode++;
    }

    if (!found) {
        cout << "tidak ada node yang tersisa" << endl;
        cout << "\nhasil : nilai " << key << " tidak ditemukan dalam linked list!" << endl;
    }

    return found ? current : nullptr;
}

int main() {
    Node* head = nullptr;

    append(head, 10);
    append(head, 20);
    append(head, 30);
    append(head, 40);
    append(head, 50);

    cout << " LINEAR SEARCH PADA LINKED LIST" << endl;
    printList(head);

    linearSearch(head, 30); // ditemukan
    linearSearch(head, 25); // tidak ditemukan

    return 0;
}

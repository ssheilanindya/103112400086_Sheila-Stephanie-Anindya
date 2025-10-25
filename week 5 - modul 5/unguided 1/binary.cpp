#include <iostream>
using namespace std;

//definisi node
struct Node{ // memiliki 2 bagian yaitu data dan pointer
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

Node* binarySearch(Node* head, int key) {
    cout << "\nmencari nilai : " << key << endl;
    cout << "\nproses pencarian :" << endl;

    // hitung ukuran linked list
    int size = 0;
    for (Node* curr = head; curr; curr = curr -> next)
        size++;

    Node* start = head;
    Node* end = nullptr;
    int iteration = 1; // untuk mencatat langkah-langkah

    while (size > 0) {
        int mid = size / 2;
        Node* midNode = start;

        // geser pointer ke posisi tengah
        for (int i = 0; i < mid; i++)
            midNode = midNode->next;

        cout << "iterasi " << iteration++ << ": mid = " << midNode -> data << " (indeks tengah) ";

        // langkah detail proses
        if (midNode -> data == key) {
            cout << "- ditemukan!" << endl;

            cout << "\nhasil : nilai " << key << " ditemukan pada linked list!" << endl;
            cout << "alamat node : " << midNode << endl;
            cout << "data node : " << midNode -> data << endl;

            // node berikutnya
            if (midNode -> next)
                cout << "node berikutnya : " << midNode -> next -> data << endl;
            else
                cout << "node berikutnya : NULL" << endl;

            return midNode;
        } 
        else if (midNode -> data < key) {
            cout << "-> cari di bagian kanan" << endl;
            start = midNode -> next;
            size -= mid + 1; // kurangi elemen kiri (mid juga)
        } 
        else {
            cout << "-> cari di bagian kiri" << endl;
            size = mid - 1; // sisa bagian kiri
        }
    }
    cout << "tidak ada elemen tersisa." << endl;
    cout << "\nhasil : nilai " << key << " tidak ditemukan dalam linked list!" << endl;
    return nullptr;
}

int main() {
    Node* head = nullptr;

    append(head, 10);
    append(head, 20);
    append(head, 30);
    append(head, 40);
    append(head, 50);
    append(head, 60);

    cout << "BINARY SEARCH PADA LINKED LIST" << endl;
    printList(head);

    binarySearch(head, 40); // ditemukan
    binarySearch(head, 25); // tidak ditemukan

    return 0;
}

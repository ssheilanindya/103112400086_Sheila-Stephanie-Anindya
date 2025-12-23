#include <iostream>
#include <string>

using namespace std;

struct node;

struct edge {
    node* tujuan;
    edge* nextEdge;
};

struct node {
    string nama;
    bool dikunjungi;
    bool terkunci;
    edge* firstEdge;
    node* nextNode;
};

struct graph {
    node* head;
};

void tambahNode(graph& g, string nama) {
    node* newNode = new node{nama, false, false, nullptr, nullptr};

    if (!g.head) {
        g.head = newNode;
    } else {
        node* temp = g.head;
        while (temp -> nextNode) {
            temp = temp -> nextNode;
        }
        temp->nextNode = newNode;
    }
}

node* cariNode(graph& g, string nama) {
    node* temp = g.head;

    while (temp) {
        if (temp -> nama == nama) {
            return temp;
        }
        temp = temp -> nextNode;
    }
    return nullptr;
}

void tambahEdge(graph& g, string src, string dst) {
    node* s = cariNode(g, src);
    node* d = cariNode(g, dst);

    if (s && d) {
        s -> firstEdge = new edge{d, s -> firstEdge};
        d -> firstEdge = new edge{s, d -> firstEdge};
    }
}

void dfs(node* current, int& count) {
    current -> dikunjungi = true;
    count++;

    edge* e = current -> firstEdge;
    while (e) {
        if (!e -> tujuan -> dikunjungi && !e -> tujuan -> terkunci) {
            dfs(e -> tujuan, count);
        }
        e = e -> nextEdge;
    }
}

int main() {
    graph g = {nullptr};

    cout << "membangun jaringan distribusi vaksin" << endl;
    cout << endl;

    tambahNode(g, "A");
    tambahNode(g, "B");
    tambahNode(g, "C");
    tambahNode(g, "D");
    tambahNode(g, "E");

    tambahEdge(g, "A", "B");
    tambahEdge(g, "B", "E");
    tambahEdge(g, "B", "C");
    tambahEdge(g, "C", "D");

    node* curr = g.head;
    while (curr) {
        cout << "node " << curr -> nama << " terhubung ke: ";

        edge* e = curr -> firstEdge;
        while (e) {
            cout << e -> tujuan -> nama << " ";
            e = e -> nextEdge;
        }
        cout << endl;
        curr = curr -> nextNode;
    }

    cout << endl;
    cout << "analisis kota kritis (single point of failure)" << endl;
    cout << endl;

    int totalNodes = 0;
    for (node* t = g.head; t; t = t -> nextNode) {
        totalNodes++;
    }

    node* testNode = g.head;
    while (testNode) {

        for (node* r = g.head; r; r = r -> nextNode) {
            r -> dikunjungi = false;
        }
        testNode -> terkunci = true;

        node* start;
        if (testNode == g.head) {
            start = g.head -> nextNode;
        } else {
            start = g.head;
        }
        int reached = 0;

        if (start) {
            dfs(start, reached);
        }
        if (reached < (totalNodes - 1)) {
            cout << "[PERINGATAN] kota " << testNode -> nama << " adalah KOTA KRITIS!" << endl;
            cout << endl;
            cout << "-> jika " << testNode -> nama << " lockdown, distribusi terputus." << endl;
        } else {
            cout << "kota " << testNode -> nama << " aman (redundansi oke)." << endl;
        }
        testNode -> terkunci = false;
        testNode = testNode -> nextNode;
    }
    return 0;
}

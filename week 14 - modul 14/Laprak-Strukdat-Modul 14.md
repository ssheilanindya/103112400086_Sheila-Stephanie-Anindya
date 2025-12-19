# <h1 align="center">Laporan Praktikum Modul 14 - GRAPH </h1>
<p align="center"> Sheila Stephanie Anindya - 103112400086 </p>

## Dasar Teori

### A. GRAPH <br/>
Graph merupakan himpunan tidak kosong dari node (vertec) dan garis penghubung (edge). [1]
Jenis - jenis graph : 
#### 1. Graph Berarah (Directed Graph)
Graph berarah merupakan graph dimana tiap node memiliki edge yang memiliki arah, kemana node tersebut dihubungkan.
#### 2. Graph Tidak Berarah (Undirected Graph)
Graph tidak berarah merupakan graph dimana tiap node memiliki edge yang dihubungkan ke node lain tanpa arah.

Dalam implementasi struktur data, graph umumnya direpresentasikan menggunakan adjacency matrix atau adjacency list. Representasi adjacency list lebih efisien untuk graph yang jarang memiliki sisi karena hanya menyimpan hubungan yang benar-benar ada. Pendekatan ini juga sering dikombinasikan dengan konsep linked list, di mana setiap simpul memiliki daftar simpul lain yang terhubung dengannya. Representasi ini memudahkan proses penelusuran graph dan pengelolaan memori, terutama pada graph dengan jumlah simpul yang cukup besar.[2]

Penelusuran graph merupakan operasi penting untuk mengunjungi seluruh simpul dalam graph secara sistematis. Dua algoritma penelusuran yang paling umum digunakan adalah Depth First Search (DFS) dan Breadth First Search (BFS). DFS bekerja dengan cara menelusuri graph sedalam mungkin dari satu simpul ke simpul lainnya sebelum kembali dan berpindah ke jalur lain. Algoritma ini biasanya diimplementasikan secara rekursif dan banyak digunakan untuk mendeteksi jalur, siklus, serta komponen terhubung dalam graph. Sebaliknya, BFS menelusuri graph secara melebar dengan mengunjungi semua simpul yang bertetangga langsung terlebih dahulu sebelum berpindah ke tingkat berikutnya. BFS sering digunakan untuk mencari jarak terpendek pada graph tidak berbobot dan analisis level simpul.

Penggunaan atribut penanda seperti visited pada setiap simpul sangat penting dalam algoritma DFS dan BFS untuk mencegah simpul dikunjungi lebih dari satu kali. Tanpa mekanisme ini, penelusuran graph dapat mengalami perulangan tak berhingga, terutama pada graph yang memiliki siklus. Oleh karena itu, kombinasi antara struktur data graph, representasi adjacency list, dan algoritma penelusuran DFS serta BFS menjadi dasar penting dalam pengembangan berbagai aplikasi komputasi modern, khususnya yang berkaitan dengan pencarian, analisis jaringan, dan pemrosesan data terstruktur.[3]

## Guided 

### 1. GRAPH

```C++
// graph.h
#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>

using namespace std;

typedef char infoGraph;
typedef struct elmNode *adrNode;
typedef struct elmEdge *adrEdge;

struct elmNode {
    infoGraph info;
    bool visited;
    adrEdge firstEdge;
    adrNode next;
};

struct elmEdge {
    adrNode node;
    adrEdge next;
};

struct graph {
    adrNode first;
};

void createGraph(graph &G);
adrNode allocateNode(infoGraph x);
void insertNode(graph &G, infoGraph x);
void connectNode(graph &G, infoGraph start, infoGraph end);
void printGraph(graph G);

#endif
// graph edge
#include "graph.h"

adrNode findNode (graph G, infoGraph x) {
    adrNode p = G.first;
    while (p != NULL) {
        if (p -> info == x) {
            return p;
        }
        p = p -> next;
    }
    return NULL;
}

void connectNode (graph &G, infoGraph start, infoGraph end) {
    adrNode pStart = findNode(G, start);
    adrNode pEnd = findNode(G, end);

    if (pStart != NULL && pEnd != NULL) {
        adrEdge newEdge = new elmEdge;
        newEdge -> node = pEnd;
        newEdge -> next = pStart -> firstEdge;
        pStart -> firstEdge = newEdge;
    }
}
// graph init
#include "graph.h"

void createGraph (graph &G) {
    G.first = NULL;
}

adrNode allocateNode (infoGraph x) {
    adrNode P = new elmNode;
    P -> info = x;
    P -> visited = false;
    P -> firstEdge = NULL;
    P -> next = NULL;
    return P;
}

void insertNode (graph &G, infoGraph x) {
    adrNode P = allocateNode(x);
    if (G.first == NULL) {
        G.first = P;
    } else {
        adrNode Q = G.first;
        while (Q -> next != NULL) {
            Q = Q -> next;
        }
        Q -> next = P;
    }
}
// graph print 
#include "graph.h"

void printGraph (graph G) {
    adrNode p = G.first;
    while (p != NULL) {
        cout << "node" << p -> info << " terhubung ke : ";
        adrEdge e = p -> firstEdge;
        while (e != NULL) {
            cout << e -> node -> info << " ";
            e = e -> next;
        }
        cout << endl;
        p = p -> next;
    }
}
// main.cpp
#include "graph.h"
#include <iostream>    

using namespace std;

int main() {
    graph G;
    createGraph(G);

    insertNode(G, 'A');
    insertNode(G, 'B');
    insertNode(G, 'C');
    insertNode(G, 'D');

    connectNode(G, 'A', 'B');
    connectNode(G, 'A', 'C');
    connectNode(G, 'B', 'D');
    connectNode(G, 'C', 'D');

    cout << "isi graph : " << endl;
    printGraph(G);

    return 0;
}
```
kode c++ ini merupakan struktur data graph berarah menggunakan adjacency list dengan pointer. setiap graph direpresentasikan oleh elmnode yang menyimpan info node (char), status visited, pointer ke edge pertama, dan pointer ke graph berikutnya, sedangkan hubungan antar graph disimpan dalam elmEdge yang menunjuk ke graph tujuan. fungsi createGraph digunakan untuk inisialisasi graph kosong, allocateNode dan insertnode untuk membuat dan menambahkan graph baru, connectNode untuk menghubungkan graph awal ke graph tujuan dengan edge, dan printGraph untuk menampilkan isi graph beserta graph mana saja yang terhubung. pada main, graph diisi dengan graph A-D lalu dihubungkan sesuai aturan, sehingga hasil akhirnya menampilkan relasi antar graph yang sudah dibuat.

## Unguided 

### 1. Buatlah implementasi ADT Graph pada file “graph.cpp” dan cobalah hasil implementasi ADT pada file “main.cpp”.

```C++

// graph.h
#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>

using namespace std;

typedef char infoGraph;
typedef struct elmNode *adrNode;
typedef struct elmEdge *adrEdge;

struct elmNode {
    infoGraph info;
    int visited;
    adrEdge firstEdge;
    adrNode next;
};

struct elmEdge {
    adrNode node;
    adrEdge next;
};

struct graph {
    adrNode first;
};

void createGraph(graph &G);
adrNode insertNode(graph &G, infoGraph X);
void connectNode(adrNode N1, adrNode N2);
void printGraph(graph G);

#endif
// graph.cpp
#include "graph.h"

void createGraph(graph &G) {
    G.first = NULL;
}

adrNode insertNode(graph &G, infoGraph x) {
    adrNode P = new elmNode;
    P -> info = x;
    P -> visited = 0;
    P -> firstEdge = NULL;
    P -> next = NULL;

    if (G.first == NULL) {
        G.first = P;
    } else {
        adrNode Q = G.first;
        while (Q -> next != NULL) {
            Q = Q -> next;
        }
        Q -> next = P;
    }
    return P;
}

void connectNode(adrNode N1, adrNode N2) {
    adrEdge E1 = new elmEdge;
    E1 -> node = N2;
    E1 -> next = N1 -> firstEdge;
    N1 -> firstEdge = E1;

    adrEdge E2 = new elmEdge;
    E2 -> node = N1;
    E2 -> next = N2 -> firstEdge;
    N2 -> firstEdge = E2;
}


void printGraph(graph G) {
    adrNode P = G.first;
    while (P != NULL) {
        cout << "node " << P -> info << " terhubung dengan: ";
        adrEdge E = P -> firstEdge;
        while (E != NULL) {
            cout << E -> node -> info << " ";
            E = E -> next;
        }
        cout << endl;
        P = P -> next;
    }
}

// main.cpp
#include "graph.h"

int main() {
    graph G;
    createGraph(G);

    insertNode(G, 'A');
    insertNode(G, 'B');
    insertNode(G, 'C');
    insertNode(G, 'D');
    insertNode(G, 'E');
    insertNode(G, 'F');
    insertNode(G, 'G');
    insertNode(G, 'H');

    adrNode A = insertNode(G, 'A');
    adrNode B = insertNode(G, 'B');
    adrNode C = insertNode(G, 'C');
    adrNode D = insertNode(G, 'D');
    adrNode E = insertNode(G, 'E');
    adrNode F = insertNode(G, 'F');
    adrNode Gg = insertNode(G, 'G');
    adrNode H = insertNode(G, 'H');

    connectNode(A, B);
    connectNode(A, C);
    connectNode(B, D);
    connectNode(B, E);
    connectNode(C, F);
    connectNode(C, Gg);
    connectNode(D, H);
    connectNode(E, H);
    connectNode(F, H);
    connectNode(Gg, H);

    cout << "=== graph === " << endl;
    printGraph(G);

    return 0;
}


```
### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/ssheilanindya/103112400086_Sheila-Stephanie-Anindya/blob/main/output/output1-unguided1-modul14.png)

kode c++ tersebut hasil implementasi graph tidak berarah menggunakan list dengan pointer. node elmNode menyimpan informasi, status visited, pointer ke edge pertama, dan pointer ke node berikutnya, sedangkan hubungan antar graph disimpan di elmEdge. createGraph digunakan untuk menginisialisasi graph kosong, insertNode untuk menambahkan garph baru ke dalam graph, dan connectNode untuk menghubungkan dua graph secara dua arah. printGraph menampilkan setiap graph beserta daftar graph yang terhubung.

### 2. Buatlah prosedur untuk menampilkanhasil penelusuran DFS.

```C++
// graph.h
#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>

using namespace std;

typedef char infoGraph;
typedef struct elmNode *adrNode;
typedef struct elmEdge *adrEdge;

struct elmNode {
    infoGraph info;
    int visited;
    adrEdge firstEdge;
    adrNode next;
};

struct elmEdge {
    adrNode node;
    adrEdge next;
};

struct graph {
    adrNode first;
};

void createGraph(graph &G);
adrNode insertNode(graph &G, infoGraph X);
void connectNode(adrNode N1, adrNode N2);
void printDFS(graph G, adrNode N);
void printGraph(graph G);

#endif
// graph.cpp
#include "graph.h"

void createGraph(graph &G) {
    G.first = NULL;
}

adrNode insertNode(graph &G, infoGraph x) {
    adrNode P = new elmNode;
    P -> info = x;
    P -> visited = 0;
    P -> firstEdge = NULL;
    P -> next = NULL;

    if (G.first == NULL) {
        G.first = P;
    } else {
        adrNode Q = G.first;
        while (Q -> next != NULL) {
            Q = Q -> next;
        }
        Q -> next = P;
    }
    return P;
}

void connectNode(adrNode N1, adrNode N2) {
    adrEdge E1 = new elmEdge;
    E1 -> node = N2;
    E1 -> next = N1 -> firstEdge;
    N1 -> firstEdge = E1;

    adrEdge E2 = new elmEdge;
    E2 -> node = N1;
    E2 -> next = N2 -> firstEdge;
    N2 -> firstEdge = E2;
}

void printGraph(graph G) {
    adrNode P = G.first;
    while (P != NULL) {
        cout << "node " << P -> info << " terhubung dengan: ";
        adrEdge E = P -> firstEdge;
        while (E != NULL) {
            cout << E -> node -> info << " ";
            E = E -> next;
        }
        cout << endl;
        P = P -> next;
    }
}

void printDFS(graph G, adrNode N) {
    if (N == NULL || N -> visited == 1) {
        return;
    }

    N -> visited = 1;
    cout << N -> info << " ";

    adrEdge E = N -> firstEdge;
    while (E != NULL) {
        if (E -> node -> visited == 0) {
            printDFS(G, E -> node);
        }
        E = E -> next;
    }
}
// main.cpp
#include "graph.h"

int main() {
    graph G;
    createGraph(G);

    adrNode A = insertNode(G, 'A');
    adrNode B = insertNode(G, 'B');
    adrNode C = insertNode(G, 'C');
    adrNode D = insertNode(G, 'D');
    adrNode E = insertNode(G, 'E');
    adrNode F = insertNode(G, 'F');
    adrNode Gg = insertNode(G, 'G');
    adrNode H = insertNode(G, 'H');

    connectNode(A, B);
    connectNode(A, C);
    connectNode(B, D);
    connectNode(B, E);
    connectNode(C, F);
    connectNode(C, Gg);
    connectNode(D, H);
    connectNode(E, H);
    connectNode(F, H);
    connectNode(Gg, H);

    cout << "=== graph ===" << endl;
    printGraph(G);

    cout << endl << "=== DFS traversal ===" << endl;
    printDFS(G, A);
    cout << endl;

    return 0;
}

```
### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 2_1](https://github.com/ssheilanindya/103112400086_Sheila-Stephanie-Anindya/blob/main/output/output1-unguided2-modul14.png)

kode c++ tersebut merupakan modifikasi dari unguided 1 dengan menambahkan procedure DFS. DFS merupakan Depth First Search menelusuri graph dengan cara mengunjungi satu graph terlebih dahulu lalu masuk sedalam mungkin ke graph tetangganya secara rekursif sebelum kembali ke graph sebelumnya, dengan bantuan atribut visited agar graph tidak dikunjungi lebih dari satu kali. pada functuion connectNode, setiap edge ditambahkan ke awal list, sehingga tetangga yang terakhir dihubungkan akan dikunjungi lebih dulu. DFS dimulai dari node A, lalu masuk ke C, dilanjutkan ke G, kemudian ke H. dari H, DFS melanjutkan ke tetangga yang belum dikunjungi yaitu F, lalu setelah semua cabang dari C selesai, DFS melakukan backtracking ke A dan menelusuri cabang lain melalui B, kemudian ke E, dan terakhir ke D.

### 3. Buatlah prosedur untuk menampilkanhasil penelusuran DFS.

```C++
// graph.h
#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>

using namespace std;

typedef char infoGraph;
typedef struct elmNode *adrNode;
typedef struct elmEdge *adrEdge;

struct elmNode {
    infoGraph info;
    int visited;
    adrEdge firstEdge;
    adrNode next;
};

struct elmEdge {
    adrNode node;
    adrEdge next;
};

struct graph {
    adrNode first;
};

void createGraph(graph &G);
adrNode insertNode(graph &G, infoGraph X);
void connectNode(adrNode N1, adrNode N2);
void printDFS(graph G, adrNode N);
void printBFS(graph G, adrNode N);
void printGraph(graph G);

#endif
// graph.cpp
#include "graph.h"

void createGraph(graph &G) {
    G.first = NULL;
}

adrNode insertNode(graph &G, infoGraph x) {
    adrNode P = new elmNode;
    P -> info = x;
    P -> visited = 0;
    P -> firstEdge = NULL;
    P -> next = NULL;

    if (G.first == NULL) {
        G.first = P;
    } else {
        adrNode Q = G.first;
        while (Q -> next != NULL) {
            Q = Q -> next;
        }
        Q -> next = P;
    }
    return P;
}

void connectNode(adrNode N1, adrNode N2) {
    adrEdge E1 = new elmEdge;
    E1 -> node = N2;
    E1 -> next = N1 -> firstEdge;
    N1 -> firstEdge = E1;

    adrEdge E2 = new elmEdge;
    E2 -> node = N1;
    E2 -> next = N2 -> firstEdge;
    N2 -> firstEdge = E2;
}

void printGraph(graph G) {
    adrNode P = G.first;
    while (P != NULL) {
        cout << "node " << P -> info << " terhubung dengan: ";
        adrEdge E = P -> firstEdge;
        while (E != NULL) {
            cout << E -> node -> info << " ";
            E = E -> next;
        }
        cout << endl;
        P = P -> next;
    }
}

void printBFS(graph G, adrNode N) {
    if (N == NULL) {
        return;
    }

    adrNode Q[100];
    int front = 0, rear = 0;

    N -> visited = 1;
    Q[rear++] = N;

    while (front < rear) {
        adrNode P = Q[front++];

        cout << P -> info << " ";

        adrEdge E = P -> firstEdge;
        while (E != NULL) {
            if (E -> node -> visited == 0) {
                E -> node -> visited = 1;
                Q[rear++] = E -> node;
            }
            E = E -> next;
        }
    }
}

// main.cpp
#include "graph.h"

int main() {
    graph G;
    createGraph(G);

    adrNode A = insertNode(G, 'A');
    adrNode B = insertNode(G, 'B');
    adrNode C = insertNode(G, 'C');
    adrNode D = insertNode(G, 'D');
    adrNode E = insertNode(G, 'E');
    adrNode F = insertNode(G, 'F');
    adrNode Gg = insertNode(G, 'G');
    adrNode H = insertNode(G, 'H');

    connectNode(A, B);
    connectNode(A, C);
    connectNode(B, D);
    connectNode(B, E);
    connectNode(C, F);
    connectNode(C, Gg);
    connectNode(D, H);
    connectNode(E, H);
    connectNode(F, H);
    connectNode(Gg, H);

    cout << "=== graph ===" << endl;
    printGraph(G);

    cout << endl << "=== BFS traversal ===" << endl;
    printBFS(G, A);
    cout << endl;

    return 0;
}

```
### Output Unguided 3 :

##### Output 1
![Screenshot Output Unguided 3_1](https://github.com/ssheilanindya/103112400086_Sheila-Stephanie-Anindya/blob/main/output/output1-unguided3-modul14.png)

kode c++ tersebut merupakan modifikasi dari unguided 1 dengan menambahkan procedure BFS. BFS merupakan Breadth First Search algoritma pencarian secara menyeluruh dengan cara mengunjungi setiap simpul secara preorder. pada output BFS menjadi A C B G F E D H karena pada implementasi graph ini edge selalu ditambahkan di firstEdge, urutan tetangga yang diproses oleh BFS mengikuti urutan terakhir kali di‐connect, bukan urutan alfabet atau urutan penulisan di main. saat BFS dimulai dari node A, tetangga A yang berada di awal list adalah C lalu B, sehingga C diproses lebih dulu. lalu BFS menelusuri level berikutnya berdasarkan urutan node yang masuk ke queue (FIFO), yaitu dari C ke G dan F, lalu dari B ke E dan D, dan terakhir ke H.

## Kesimpulan
graph merupakan struktur data non-linear yang digunakan untuk merepresentasikan hubungan antar data dalam bentuk simpul dan sisi. bfs dan dfs adalah dua algoritma penelusuran pada graph, di mana bfs menelusuri simpul secara melebar per level menggunakan queue, sedangkan dfs menelusuri simpul secara mendalam menggunakan rekursi atau stack. pemahaman terhadap graph, bfs, dan dfs sangat penting karena menentukan cara penelusuran data dan membantu dalam menyelesaikan berbagai permasalahan yang melibatkan hubungan antar simpul secara efektif. implementasi kode menunjukkan peran penting setiap komponen, mulai dari pembentukan simpul, penghubung antar simpul, hingga penggunaan penanda visited untuk menghindari pengulangan saat penelusuran. secara teori, konsep graph, BFS, dan DFS menjadi dasar yang kuat untuk memahami proses penelusuran data pada struktur non-linear, di mana DFS menelusuri simpul secara mendalam dan BFS secara melebar. keterkaitan antara dasar teori dan implementasi kode memperlihatkan bahwa pemahaman algoritma dan struktur data sangat berpengaruh terhadap keberhasilan penulisan program yang benar, efisien, dan sesuai dengan kebutuhan pemodelan masalah nyata.

## Referensi
[1] Fakultas Informatika. (2025). Modul Praktikum Struktur Data Modul 14: Graph. Bandung: Telkom University.
[2] Tarjan, R. (1972). Depth-first search and linear graph algorithms. SIAM journal on computing, 1(2), 146-160.
[3] Gross, J. L., Yellen, J., & Anderson, M. (2018). Graph theory and its applications. Chapman and Hall/CRC.


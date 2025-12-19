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

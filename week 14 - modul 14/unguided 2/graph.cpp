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
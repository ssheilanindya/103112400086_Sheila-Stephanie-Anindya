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
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

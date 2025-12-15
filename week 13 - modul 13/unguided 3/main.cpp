#include "MLL.h"

#include <iostream>

using namespace std;

int main() {
    listParent L;
    createListParent(L);

    NodeParent p1 = allocNodeParent("G001", "aves");
    NodeParent p2 = allocNodeParent("G002", "mammalia");
    NodeParent p3 = allocNodeParent("G003", "pisces");
    NodeParent p4 = allocNodeParent("G004", "amfibi");
    NodeParent p5 = allocNodeParent("G005", "reptil");

    insertLastParent(L, p1);
    insertLastParent(L, p2);
    insertLastParent(L, p3);
    insertLastParent(L, p4);
    insertLastParent(L, p5);

    NodeChild ch1 = allocNodeChild("AV001", "cendrawasih", "hutan", true, 0.3f);
    NodeChild ch2 = allocNodeChild("AV002", "bebek", "air", true, 2.0f);

    insertLastChild(p1 -> L_Child, ch1);
    insertLastChild(p1 -> L_Child, ch2);

    NodeChild ch3 = allocNodeChild("M001", "harimau", "hutan", true, 200.0f);
    NodeChild ch4 = allocNodeChild("M003", "gorila", "hutan", false, 160.0f);
    NodeChild ch5 = allocNodeChild("M002", "kucing", "darat", true, 4.0f);

    insertLastChild(p2 -> L_Child, ch3);
    insertLastChild(p2 -> L_Child, ch4);
    insertLastChild(p2 -> L_Child, ch5);

    NodeChild ch6 = allocNodeChild("AM001", "kodok", "sawah", false, 0.2f);
    insertLastChild(p4 -> L_Child, ch6);

    deleteParentByID(L, "G004");
    printMLLStructure(L);

    while (!isEmptyParent(L)) {
        deleteFirstParent(L);
    }

    return 0;
}

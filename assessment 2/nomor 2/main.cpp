#include "mll.h"
#include <iostream>

using namespace std;

int main() {
    listParent MLL;
    createListParent(MLL);

    nodeParent *g4 = alokasiNodeParent("G004", "romance");
    insertFirstParent(MLL, g4);
    nodeParent *g3 = alokasiNodeParent("G003", "horror");
    insertFirstParent(MLL, g3);
    nodeParent *g2 = alokasiNodeParent("G002", "comedy");
    insertFirstParent(MLL, g2);
    nodeParent *g1 = alokasiNodeParent("G001", "action");
    insertFirstParent(MLL, g1);

    insertLastChild(g1 -> childs, alokasiNodeChild("FA001", "the raid", 101, 2011, 7.6));
    insertLastChild(g2 -> childs, alokasiNodeChild("FC001", "agak laen", 119, 2024, 8.0));
    insertLastChild(g2 -> childs, alokasiNodeChild("FC002", "my stupid boss", 108, 2016, 6.8));
    insertLastChild(g3 -> childs, alokasiNodeChild("FH001", "pengabdi aetan", 107, 2017, 8.4));
    insertLastChild(g4 -> childs, alokasiNodeChild("FR001", "habibie ainun", 118, 2012, 7.6));
    insertLastChild(g4 -> childs, alokasiNodeChild("FR002", "dilan 1990", 110, 2018, 6.6));

    printStrukturMLL(MLL);
    searchFilmByRatingRange(MLL, 8.0, 8.5);
    nodeParent *deletedNode;
    deleteAfterParent(MLL, g1, deletedNode);
    if (deletedNode != nullptr) {
        dealokasiNodeParent(deletedNode);
    }
    printStrukturMLL(MLL);

    return 0;
}
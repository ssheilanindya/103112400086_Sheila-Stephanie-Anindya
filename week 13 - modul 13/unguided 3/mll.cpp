#include "MLL.h"

bool isEmptyParent(listParent LParent) {
    return (LParent.first == nullptr);
}

bool isEmptyChild(listChild LChild) {
    return (LChild.first == nullptr);
}

void createListParent(listParent &LParent) {
    LParent.first = nullptr;
    LParent.last = nullptr;
}

void createListChild(listChild &LChild) {
    LChild.first = nullptr;
    LChild.last = nullptr;
}

NodeParent allocNodeParent(string idGol, string namaGol) {
    NodeParent NP = new nodeParent;
    NP -> isidata.idGolongan = idGol;
    NP -> isidata.namaGolongan = namaGol;
    NP -> next = nullptr;
    NP -> prev = nullptr;

    createListChild(NP -> L_Child);
    return NP;
}

NodeChild allocNodeChild(string idHwn, string namaHwn, string habitat, bool tail, float weight) {
    NodeChild NC = new nodeChild;
    NC -> isidata.idHewan = idHwn;
    NC -> isidata.namaHewan = namaHwn;
    NC -> isidata.habitat = habitat;
    NC -> isidata.ekor = tail;
    NC -> isidata.bobot = weight;
    NC -> next = nullptr;
    NC -> prev = nullptr;
    return NC;
}

void deallocNodeParent(NodeParent &NParent) {
    delete NParent;
    NParent = nullptr;
}

void deallocNodeChild(NodeChild &NChild) {
    delete NChild;
    NChild = nullptr;
}

void insertFirstParent(listParent &LParent, NodeParent newNParent) {
    if (isEmptyParent(LParent)) {
        LParent.first = newNParent;
        LParent.last = newNParent;
    } else {
        newNParent -> next = LParent.first;
        LParent.first -> prev = newNParent;
        LParent.first = newNParent;
    }
}

void insertLastParent(listParent &LParent, NodeParent newNParent) {
    if (isEmptyParent(LParent)) {
        insertFirstParent(LParent, newNParent);
    } else {
        LParent.last -> next = newNParent;
        newNParent -> prev = LParent.last;
        LParent.last = newNParent;
    }
}

void deleteFirstParent(listParent &LParent) {
    if (!isEmptyParent(LParent)) {
        NodeParent del = LParent.first;

        deleteListChild(del -> L_Child);

        if (LParent.first == LParent.last) {
            LParent.first = nullptr;
            LParent.last = nullptr;
        } else {
            LParent.first = del -> next;
            LParent.first -> prev = nullptr;
        }
        deallocNodeParent(del);
    }
}

void deleteAfterParent(listParent &LParent, NodeParent NPrev) {
    if (NPrev != nullptr && NPrev -> next != nullptr) {
        NodeParent del = NPrev -> next;

        deleteListChild(del -> L_Child);

        NPrev -> next = del -> next;
        if (del -> next != nullptr) {
            del -> next -> prev = NPrev;
        } else {
            LParent.last = NPrev;
        }
        deallocNodeParent(del);
    }
}

void insertFirstChild(listChild &LChild, NodeChild newNChild) {
    if (isEmptyChild(LChild)) {
        LChild.first = newNChild;
        LChild.last = newNChild;
    } else {
        newNChild -> next = LChild.first;
        LChild.first -> prev = newNChild;
        LChild.first = newNChild;
    }
}

void insertLastChild(listChild &LChild, NodeChild newNChild) {
    if (isEmptyChild(LChild)) {
        insertFirstChild(LChild, newNChild);
    } else {
        LChild.last -> next = newNChild;
        newNChild -> prev = LChild.last;
        LChild.last = newNChild;
    }
}

void deleteFirstChild(listChild &LChild) {
    if (!isEmptyChild(LChild)) {
        NodeChild del = LChild.first;

        if (LChild.first == LChild.last) {
            LChild.first = nullptr;
            LChild.last = nullptr;
        } else {
            LChild.first = del -> next;
            LChild.first -> prev = nullptr;
        }

        deallocNodeChild(del);
    }
}

void deleteAfterChild(listChild &LChild, NodeChild NPrev) {
    if (NPrev != nullptr && NPrev -> next != nullptr) {
        NodeChild del = NPrev -> next;

        NPrev -> next = del -> next;
        if (del->next != nullptr) {
            del -> next -> prev = NPrev;
        } else {
            LChild.last = NPrev;
        }

        deallocNodeChild(del);
    }
}

void deleteListChild(listChild &LChild) {
    while (!isEmptyChild(LChild)) {
        deleteFirstChild(LChild);
    }
}

void printMLLStructure(listParent LParent) {
    NodeParent P = LParent.first;
    int noParent = 1;

    while (P != nullptr) {
        cout << "=== parent " << noParent << " ===\n";
        cout << "ID golongan : " << P -> isidata.idGolongan << endl;
        cout << "nama golongan : " << P -> isidata.namaGolongan << endl;

        NodeChild C = P -> L_Child.first;
        int noChild = 1;

        if (C == nullptr) {
            cout << "- (tidak ada child)\n";
        } else {
            while (C != nullptr) {
                cout << "- child " << noChild << " :\n";
                cout << "  ID hewan   : " << C -> isidata.idHewan << endl;
                cout << "  nama hewan : " << C -> isidata.namaHewan << endl;
                cout << "  habitat    : " << C -> isidata.habitat << endl;
                cout << "  ekor       : " << (C -> isidata.ekor ? "1" : "0") << endl;
                cout << "  bobot      : " << C -> isidata.bobot << endl;
                cout << endl;

                C = C -> next;
                noChild++;
            }
        }

        cout << "---------------------------\n";

        P = P -> next;
        noParent++;
    }
}

void searchHewanByEkor(listParent LParent, bool tail) {
    NodeParent P = LParent.first;
    int posParent = 1;
    bool foundAny = false;

    while (P != nullptr) {

        NodeChild C = P -> L_Child.first;
        int posChild = 1;

        while (C != nullptr) {

            if (C -> isidata.ekor == tail) {
                foundAny = true;

                cout << "data ditemukan pada list anak dari node parent " << P -> isidata.namaGolongan << " pada posisi ke-" << posChild << "!" << endl;

                cout << "--- data child ---" << endl;
                cout << "ID child : " << C -> isidata.idHewan << endl;
                cout << "posisi dalam list anak : posisi ke-" << posChild << endl;
                cout << "nama hewan : " << C -> isidata.namaHewan << endl;
                cout << "habitat : " << C -> isidata.habitat << endl;
                cout << "ekor : " << (C -> isidata.ekor ? 1 : 0) << endl;
                cout << "bobot : " << C -> isidata.bobot << endl;
                cout << "---------------------" << endl;

                cout << "--- data parent ---" << endl;
                cout << "ID parent : " << P -> isidata.idGolongan << endl;
                cout << "posisi dalam list induk : posisi ke-" << posParent << endl;
                cout << "nama golongan : " << P -> isidata.namaGolongan << endl;
                cout << "---------------------" << endl;
            }

            C = C -> next;
            posChild++;
        }

        P = P -> next;
        posParent++;
    }

    if (!foundAny) {
        cout << "tidak ada data child dengan ekor = " << (tail ? 1 : 0) << endl;
    }
}

void deleteParentByID(listParent &LParent, string idGol) {
    NodeParent P = LParent.first;

    while (P != nullptr) {

        if (P -> isidata.idGolongan == idGol) {

            if (P == LParent.first) {
                deleteFirstParent(LParent);
            } else {
                deleteAfterParent(LParent, P -> prev);
            }
            return; // selesai karena node sudah dihapus
        }

        P = P->next;
    }

    cout << "parent dengan ID " << idGol << " tidak ditemukan.\n";
}


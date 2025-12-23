#include "bst.h"

int main() {
    bst T;
    createTree(T);

    insertNode(T, newNode("rizkina azizah", 60, "basic"));
    insertNode(T, newNode("hakan ismail", 50, "bronze"));
    insertNode(T, newNode("olivia saevali", 65, "silver"));
    insertNode(T, newNode("felix pedrosa", 47, "gold"));
    insertNode(T, newNode("gamel al ghifari", 56, "platinum"));
    insertNode(T, newNode("hanif al faiz", 70, "basic"));
    insertNode(T, newNode("mutiara fauziah", 52, "bronze"));
    insertNode(T, newNode("davi ilyas", 68, "silver"));
    insertNode(T, newNode("abdad mubarok", 81, "gold"));

    cout << "=== traversal in order ===\n";
    inOrder(T.root);
    cout << endl << endl;

    cout << "node most left : " << mostLeft(T) -> beratBadan << endl;
    cout << "node most right : " << mostRight(T) -> beratBadan << endl << endl;

    node *parent;
    node *hasil = searchByBeratBadan(T, 70, parent);

    if (hasil != NULL) {
        cout << "data ditemukan didalam bst\n";
        cout << "=== data node yang dicari ===" << endl;
        cout << "nama member : " << hasil -> namaMember << endl;
        cout << "berat badan : " << hasil -> beratBadan << endl;
        cout << "tier member : " << hasil -> tierMember << endl;
        cout << "------------------------------\n";

        cout << "=== data parent ===\n";
        cout << "nama member : " << parent -> namaMember << endl;
        cout << "berat badan : " << parent -> beratBadan << endl;
        cout << "tier member : " << parent -> tierMember << endl;
        cout << "------------------------------\n";

        if ((parent -> left != NULL && parent -> left != hasil) ||
            (parent -> right != NULL && parent -> right != hasil)) {
            cout << "memiliki sibling\n";
        } else {
            cout << "tidak memiliki sibling\n";
        }
        cout << "------------------------------\n";

        if (hasil -> left != NULL) {
            cout << "=== data child kiri ===\n";
            cout << "nama member : " << hasil -> left -> namaMember << endl;
            cout << "berat badan : " << hasil -> left -> beratBadan << endl;
            cout << "tier member : " << hasil -> left -> tierMember << endl;
            cout << "------------------------------\n";
        }

        if (hasil -> right != NULL) {
            cout << "=== data child kanan ===\n";
            cout << "nama member : " << hasil -> right -> namaMember << endl;
            cout << "berat badan : " << hasil -> right -> beratBadan << endl;
            cout << "tier member : " << hasil -> right -> tierMember << endl;
            cout << "------------------------------\n";
        }
    }

    return 0;
}

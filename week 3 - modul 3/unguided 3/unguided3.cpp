#include <iostream>
#include "unguided3.h"

using namespace std;

void tampil(array2D A){
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            cout << A.data[i][j] << " ";
        }
        cout << endl;
    }
}

#include "soal3.h"

bool isEmpty(stackMHS stack){
    return stack.top == -1;
}

bool isFull(stackMHS stack){
    return stack.top == MAX - 1;
}

void createStack(stackMHS &stack){
    stack.top = -1;
}

float hitungNilaiAkhir(mahasiswa m){
    return (m.nilaiTugas * 0.2f) + (m.nilaiUTS * 0.4f) + (m.nilaiUAS * 0.4f);
}

void push(stackMHS &stack){
    if (isFull(stack)){
        cout << "Stack penuh!\n";
    } else {
        mahasiswa m;
        cout << "nama        : ";
        cin >> m.nama;
        cout << "NIM         : ";
        cin >> m.NIM;
        cout << "nilai tugas : ";
        cin >> m.nilaiTugas;
        cout << "nilai UTS   : ";
        cin >> m.nilaiUTS;
        cout << "nilai UAS   : ";
        cin >> m.nilaiUAS;

        stack.data[++stack.top] = m;
        cout << "data berhasil ditambahkan!\n";
    }
}

void pop(stackMHS &stack){
    if(isEmpty(stack)){
        cout << "ttack kosong\n";
    } else {
        cout << "menghapus data mahasiswa bernama : " 
             << stack.data[stack.top].nama << endl;
        stack.top--;
    }
}

void update(stackMHS &stack, int posisi){
    if(posisi < 0 || posisi > stack.top){
        cout << "posisi tidak valid\n";
        return;
    }

    mahasiswa &m = stack.data[posisi];

    cout << "ppdate data mahasiswa index " << posisi << endl;
    cout << "nama        : ";
    cin >> m.nama;
    cout << "NIM         : ";
    cin >> m.NIM;
    cout << "nilai tugas : ";
    cin >> m.nilaiTugas;
    cout << "nilai UTS   : ";
    cin >> m.nilaiUTS;
    cout << "nilai UAS   : ";
    cin >> m.nilaiUAS;

    cout << "ppdate berhasil\n";
}

void view(stackMHS stack){
    if(isEmpty(stack)){
        cout << "stack kosong\n";
        return;
    }

    cout << "\nDATA MAHASISWA\n";
    for(int i = stack.top; i >= 0; i--){
        float akhir = hitungNilaiAkhir(stack.data[i]);
        cout << "Nama  : " << stack.data[i].nama << endl;
        cout << "NIM   : " << stack.data[i].NIM << endl;
        cout << "nilai akhir : " << akhir << endl;
    }
}

void searchNilaiAkhir(stackMHS stack, float minAkhir, float maxAkhir){
    bool found = false;

    cout << "\nhasil pencarian nilai akhir " << minAkhir 
         << " - " << maxAkhir << ":\n";

    for(int i = stack.top; i >= 0; i--){
        float akhir = hitungNilaiAkhir(stack.data[i]);
        if(akhir >= minAkhir && akhir <= maxAkhir){
            found = true;
            cout << stack.data[i].nama << " (" << akhir << ")\n";
        }
    }

    if(!found){
        cout << "tidak ada data.\n";
    }
}

void maxNilaiAkhir(stackMHS stack){
    if(isEmpty(stack)){
        cout << "stack kosong\n";
        return;
    }

    int idxMax = 0;
    float maxNilai = hitungNilaiAkhir(stack.data[0]);

    for(int i = 1; i <= stack.top; i++){
        float akhir = hitungNilaiAkhir(stack.data[i]);
        if(akhir > maxNilai){
            maxNilai = akhir;
            idxMax = i;
        }
    }

    cout << "\nmahasiswa nilai akhir tertinggi :\n";
    cout << "nama  : " << stack.data[idxMax].nama << endl;
    cout << "NIM   : " << stack.data[idxMax].NIM << endl;
    cout << "nilai : " << maxNilai << endl;
}

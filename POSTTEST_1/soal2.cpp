#include <iostream>
using namespace std;

int main() {
    int matriks[3][3];
    int nilai = 2;

    for (int baris = 0; baris < 3; baris++) {
        for (int kolom = 0; kolom < 3; kolom++) {
            matriks[baris][kolom] = nilai++;
        }
    }

    int jumlah = 0;
    for (int baris = 0; baris < 3; baris += 2) {
        for (int kolom = 0; kolom < 3; kolom++) {
            jumlah += matriks[baris][kolom];
        }
    }

    cout << "Matriks 3x3:" << endl;
    for (int baris = 0; baris < 3; baris++) {
        for (int kolom = 0; kolom < 3; kolom++) {
            cout << matriks[baris][kolom] << "\t";
        }
        cout << endl;
    }

    cout << "Jumlah elemen baris genap = " << jumlah << endl;
}

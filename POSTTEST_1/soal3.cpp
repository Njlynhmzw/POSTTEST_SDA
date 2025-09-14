#include <iostream>
#include <string>
using namespace std;

struct Mahasiswa {
    string nama;
    string nim;
    double ipk;
};

int main() {
    const int JUMLAH = 4;
    Mahasiswa data[JUMLAH];

    for (int i = 0; i < JUMLAH; i++) {
        cout << "Mahasiswa " << i+1 << endl;
        cout << "Nama : "; cin >> data[i].nama;
        cout << "NIM  : "; cin >> data[i].nim;
        cout << "IPK  : "; cin >> data[i].ipk;
    }

    for (int i = 0; i < JUMLAH - 1; i++) {
        for (int j = i + 1; j < JUMLAH; j++) {
            if (data[i].ipk > data[j].ipk) {
                Mahasiswa sementara = data[i];
                data[i] = data[j];
                data[j] = sementara;
            }
        }
    }

    cout << "\n=============================================\n";
    cout << " No\tNama\t\tNIM\t\tIPK\n";
    cout << "=============================================\n";

    for (int i = 0; i < JUMLAH; i++) {
        cout << " " << i+1 << "\t" 
             << data[i].nama << "\t\t" 
             << data[i].nim << "\t\t" 
             << data[i].ipk << endl;
    }

    cout << "=============================================\n";
}
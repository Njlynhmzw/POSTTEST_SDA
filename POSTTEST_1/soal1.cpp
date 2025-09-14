#include <iostream>
using namespace std;

bool bilanganPrima(int n) {
    if (n < 2) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

int* balikArray(int *data, int jumlah) {
    int *awal = data;
    int *akhir = data + jumlah - 1;
    while (awal < akhir) {
        int sementara = *awal;
        *awal = *akhir;
        *akhir = sementara;
        awal++;
        akhir--;
    }
    return data; 
}

int main() {
    const int JUMLAH = 7;
    int angka[JUMLAH];
    int kandidat = 2, indeks = 0;

    while (indeks < JUMLAH) {
        if (bilanganPrima(kandidat)) {
            angka[indeks] = kandidat;
            indeks++;
        }
        kandidat++;
    }

    cout << "Array sebelum dibalik: ";
    for (int i = 0; i < JUMLAH; i++) {
        cout << angka[i] << " ";
    }
    cout << endl;

    int* hasil = balikArray(angka, JUMLAH);

    cout << "Array sesudah dibalik: ";
    for (int i = 0; i < JUMLAH; i++) {
        cout << hasil[i] << " ";
    }
    cout << endl;
}

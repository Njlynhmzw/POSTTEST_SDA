#include <iostream>
using namespace std;

void tukar(int &a, int &b) {
    int sementara = a;
    a = b;
    b = sementara;
}

int main() {
    int x, y;

    cout << "Masukkan nilai pertama (x) : ";
    cin >> x;
    cout << "Masukkan nilai kedua (y)   : ";
    cin >> y;

    cout << "\nSebelum ditukar:" << endl;
    cout << "x = " << x << ", y = " << y << endl;

    tukar(x, y);

    cout << "\nSesudah ditukar:" << endl;
    cout << "x = " << x << ", y = " << y << endl;
}
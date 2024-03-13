#include <iostream>
using namespace std;

// Fungsi untuk menggeser nilai huruf alfabet
char geserHuruf(char huruf, int nilaiGeser) {
    // Jika karakter bukan huruf alfabet, kembalikan karakter aslinya
    if (!isalpha(huruf)) {
        return huruf;
    }

    // Konversi huruf ke huruf kecil untuk mempermudah operasi
    huruf = tolower(huruf);

    // Menggeser nilai huruf sesuai dengan nilaiGeser
    huruf = 'a' + (huruf - 'a' + nilaiGeser) % 26;

    return huruf;
}

int main() {
    char huruf;
    int nilaiGeser;

    cout << "Masukkan huruf alfabet: ";
    cin >> huruf;

    cout << "Masukkan nilai geser: ";
    cin >> nilaiGeser;

    // Memanggil fungsi untuk menggeser huruf
    char hasil = geserHuruf(huruf, nilaiGeser);

    cout << "Hasil geser: " << hasil << endl;

    return 0;
}

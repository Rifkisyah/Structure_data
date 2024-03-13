#include <iostream>
#include <string>
#include <conio.h>

using namespace std;

// Struktur data untuk KTP
struct KTP{
    string NIK;
    string nama;
    string tempat_tanggal_lahir;
    string jenis_kelamin;
    string alamat;
    string agama;
    string status_pernikahan;
    string pekerjaan;
    string kewarganegaraan;
    string berlaku_hingga;
}; 

string getInput(const string& output) {
    string input;
    cout << output;
    cin.ignore();
    getline(cin, input);
    return input;
}

// Fungsi untuk menambahkan data KTP
void tambahData(KTP data[], int& jumlahData) {
    data[jumlahData].NIK = getInput("Masukkan NIK: ");
    data[jumlahData].nama = getInput("Masukkan nama: ");
    data[jumlahData].tempat_tanggal_lahir = getInput("Masukkan tempat dan tanggal lahir: ");
    data[jumlahData].jenis_kelamin = getInput("Masukkan jenis kelamin: ");
    data[jumlahData].alamat = getInput("Masukkan alamat: ");
    data[jumlahData].agama = getInput("Masukkan agama: ");
    data[jumlahData].status_pernikahan = getInput("Masukkan status pernikahan: ");
    data[jumlahData].pekerjaan = getInput("Masukkan pekerjaan: ");
    data[jumlahData].kewarganegaraan = getInput("Masukkan kewarganegaraan: ");
    data[jumlahData].berlaku_hingga = getInput("Masukkan masa berlaku hingga: ");
    jumlahData++;
    cout << "Data berhasil ditambahkan." << endl;
}

// Fungsi untuk mencari data KTP
void cariData(const KTP data[], int jumlahData, string keyword) {
    bool ditemukan = false;
    for (int i = 0; i < jumlahData; ++i) {
        if (data[i].nama == keyword || data[i].NIK == keyword) {
            cout << "Data ditemukan:" << endl
             << "NIK: " << data[i].NIK << endl
             << "Nama: " << data[i].nama << endl
             << "Tempat dan tanggal lahir: " << data[i].tempat_tanggal_lahir << endl
             << "Jenis kelamin: " << data[i].jenis_kelamin << endl
             << "Alamat: " << data[i].alamat << endl
             << "Agama: " << data[i].agama << endl
             << "Status pernikahan: " << data[i].status_pernikahan << endl
             << "Pekerjaan: " << data[i].pekerjaan << endl
             << "Kewarganegaraan: " << data[i].kewarganegaraan << endl
             << "Berlaku hingga: " << data[i].berlaku_hingga << endl;
            ditemukan = true;
        }
    }
    if (!ditemukan) {
        cout << "Data tidak ditemukan." << endl;
    }
}

// Fungsi untuk menampilkan semua data KTP
void tampilkanData(const KTP data[], int jumlahData) {
    if (jumlahData == 0) {
        cout << "Tidak ada data yang tersedia." << endl;
    } else {
        cout << "Data KTP:" << endl;
        for (int i = 0; i < jumlahData; ++i) {
            cout << "Data ke-" << i + 1 << ":" << endl
             << "NIK: " << data[i].NIK << endl
             << "Nama: " << data[i].nama << endl
             << "Tempat dan tanggal lahir: " << data[i].tempat_tanggal_lahir << endl
             << "Jenis kelamin: " << data[i].jenis_kelamin << endl
             << "Alamat: " << data[i].alamat << endl
             << "Agama: " << data[i].agama << endl
             << "Status pernikahan: " << data[i].status_pernikahan << endl
             << "Pekerjaan: " << data[i].pekerjaan << endl
             << "Kewarganegaraan: " << data[i].kewarganegaraan << endl
             << "Berlaku hingga: " << data[i].berlaku_hingga << endl;
        }
    }
}

// Fungsi untuk menghapus data KTP
void hapusData(KTP data[], int& jumlahData, string NIK) {
    bool ditemukan = false;
    for (int i = 0; i < jumlahData; ++i) {
        if (data[i].NIK == NIK) {
            for (int j = i; j < jumlahData - 1; ++j) {
                data[j] = data[j + 1];
            }
            jumlahData--;
            ditemukan = true;
            cout << "Data berhasil dihapus." << endl;
            break;
        }
    }
    if (!ditemukan) {
        cout << "Data tidak ditemukan." << endl;
    }
}

int main() {
    int MAX_DATA;
    cout << "Berapa jumlah data KTP penduduk: ";
    cin >> MAX_DATA;

    KTP data[MAX_DATA];
    int jumlahData = 0;

    int pilihan;
    string keyword, NIK;

    do {
        cout << "\nMenu:\n"
         << "1. Tambah Data\n"
         << "2. Cari Data\n"
         << "3. Tampilkan Data\n"
         << "4. Hapus Data\n"
         << "0. Keluar\n"
         << "Pilih: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                system("cls");
                if (jumlahData < MAX_DATA) {
                    tambahData(data, jumlahData);
                } else {
                    cout << "Array penuh, tidak dapat menambahkan data." << endl;
                }
                break;
            case 2:
                system("cls");
                cout << "Masukkan nama atau NIK yang ingin dicari: ";
                cin >> keyword;
                cariData(data, jumlahData, keyword);
                break;
            case 3:
                system("cls");
                tampilkanData(data, jumlahData);
                break;
            case 4:
                system("cls");
                cout << "Masukkan NIK yang ingin dihapus: ";
                cin >> NIK;
                hapusData(data, jumlahData, NIK);
                break;
            case 0:
                cout << "Program selesai." << endl;
                break;
            default:
                cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
                break;
        }
    } while (pilihan != 0);

    return 0;
}

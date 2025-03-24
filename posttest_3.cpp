#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

// Maksimal jumlah data
const int MAX_DATA = 100;
const int MAX_USER = 50;

// Struktur data untuk alat berat
typedef struct {
    string nama;
    string tipe;
    int tahun;
} AlatBerat;

// Struktur data untuk user
typedef struct {
    string nama;
    string nim;
    bool isAdmin;
} User;

// Data array
AlatBerat alatBerat[MAX_DATA];
User users[MAX_USER];
int jumlahData = 0;
int jumlahUser = 2;

// Data user default
void inisialisasiUser() {
    users[0] = {"Willy", "120", true};
    users[1] = {"User", "user123", false};
}

// Fungsi untuk menampilkan tabel data
void tampilkanData() {
    if (jumlahData == 0) {
        cout << "Tidak ada data alat berat.\n";
        return;
    }
    cout << "============================================================\n";
    cout << "| No | Nama Alat         | Tipe Alat        | Tahun        |\n";
    cout << "============================================================\n";
    for (int i = 0; i < jumlahData; i++) {
        cout << "| " << setw(2) << i + 1 << " | "
             << setw(15) << alatBerat[i].nama << " | "
             << setw(15) << alatBerat[i].tipe << " | "
             << setw(10) << alatBerat[i].tahun << " |\n";
    }
    cout << "============================================================\n";
}

// Fungsi untuk menambah data
void tambahData() {
    if (jumlahData >= MAX_DATA) {
        cout << "Data sudah penuh!\n";
        return;
    }
    cout << "Masukkan Nama Alat: ";
    cin >> alatBerat[jumlahData].nama;
    cout << "Masukkan Tipe Alat: ";
    cin >> alatBerat[jumlahData].tipe;
    cout << "Masukkan Tahun Produksi: ";
    cin >> alatBerat[jumlahData].tahun;
    jumlahData++;
    cout << "Data berhasil ditambahkan!\n";
}

// Fungsi untuk mengedit data
void editData() {
    int index;
    tampilkanData();
    cout << "Masukkan nomor data yang ingin diedit: ";
    cin >> index;
    if (index < 1 || index > jumlahData) {
        cout << "Nomor tidak valid!\n";
        return;
    }
    index--;
    cout << "Masukkan Nama Alat Baru: ";
    cin >> alatBerat[index].nama;
    cout << "Masukkan Tipe Alat Baru: ";
    cin >> alatBerat[index].tipe;
    cout << "Masukkan Tahun Produksi Baru: ";
    cin >> alatBerat[index].tahun;
    cout << "Data berhasil diperbarui!\n";
}

// Fungsi untuk menghapus data
void hapusData() {
    int index;
    tampilkanData();
    cout << "Masukkan nomor data yang ingin dihapus: ";
    cin >> index;
    if (index < 1 || index > jumlahData) {
        cout << "Nomor tidak valid!\n";
        return;
    }
    index--;
    for (int i = index; i < jumlahData - 1; i++) {
        alatBerat[i] = alatBerat[i + 1];
    }
    jumlahData--;
    cout << "Data berhasil dihapus!\n";
}

// Fungsi untuk registrasi user
void registrasiUser() {
    if (jumlahUser >= MAX_USER) {
        cout << "Pendaftaran user penuh!\n";
        return;
    }
    cout << "Masukkan Nama: ";
    cin >> users[jumlahUser].nama;
    cout << "Masukkan NIM: ";
    cin >> users[jumlahUser].nim;
    users[jumlahUser].isAdmin = false; // User baru bukan admin
    jumlahUser++;
    cout << "Registrasi berhasil! Silakan login.\n";
}

// Fungsi untuk login
bool login(bool &isAdmin) {
    string nama, nim;
    int percobaan = 3;
    while (percobaan > 0) {
        cout << "Masukkan Nama: ";
        cin >> nama;
        cout << "Masukkan NIM: ";
        cin >> nim;
        
        for (int i = 0; i < jumlahUser; i++) {
            if (users[i].nim == nim) {
                isAdmin = users[i].isAdmin;
                return true;
            }
        }
        
        percobaan--;
        cout << "Login gagal! Sisa percobaan: " << percobaan << "\n";
    }
    return false;
}

// Fungsi utama
int main() {
    inisialisasiUser();
    int pilihanAwal;
    bool isAdmin;
    
    do {
        cout << "\n1. Login\n2. Registrasi\n3. Keluar\nPilihan: ";
        cin >> pilihanAwal;
        
        if (pilihanAwal == 2) {
            registrasiUser();
        }
    } while (pilihanAwal != 1 && pilihanAwal != 3);
    
    if (pilihanAwal == 3) {
        cout << "Terima kasih!\n";
        return 0;
    }
    
    if (!login(isAdmin)) {
        cout << "Terlalu banyak kesalahan! Program berhenti.\n";
        return 0;
    }
    
    int pilihan;
    do {
        cout << "\nMenu:\n";
        cout << "1. Tampilkan Data\n";
        if (isAdmin) {
            cout << "2. Tambah Data\n";
            cout << "3. Edit Data\n";
            cout << "4. Hapus Data\n";
        }
        cout << "5. Keluar\n";
        cout << "Pilihan: ";
        cin >> pilihan;
        
        switch (pilihan) {
            case 1: tampilkanData(); break;
            case 2: if (isAdmin) tambahData(); else cout << "Akses ditolak!\n"; break;
            case 3: if (isAdmin) editData(); else cout << "Akses ditolak!\n"; break;
            case 4: if (isAdmin) hapusData(); else cout << "Akses ditolak!\n"; break;
            case 5: cout << "Terima kasih!\n"; break;
            default: cout << "Pilihan tidak valid!\n";
        }
    } while (pilihan != 5);
    
    return 0;
}

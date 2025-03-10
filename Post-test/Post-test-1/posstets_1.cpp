#include <iostream>
#include <string>

using namespace std;

bool isPrime(int num) {
    if (num < 2) return false;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return false;
    }
    return true;
}

bool isValidDivision(int num) {
    return (num % 2 == 0 && num % 3 == 0 && num % 5 != 0);
}

bool isPalindrome(int num) {
    int reversed = 0, original = num;
    while (num > 0) {
        reversed = reversed * 10 + num % 10;
        num /= 10;
    }
    return original == reversed;
}

int main() {
    string username, password;
    int kodeSandi;

    cout << "Masukkan Nama Lengkap: ";
    getline(cin, username);
    cout << "Masukkan NIM: ";
    cin >> password;

    while (true) {
        cout << "\nMasukkan kode sandi (harus antara 101 - 99999): ";
        cin >> kodeSandi;

        if (kodeSandi < 101 || kodeSandi > 99999) {
            cout << "Kode sandi tidak valid! Harus antara 101 - 99999.\n";
            continue;
        }
        
        int pilihan;
        while (true) {
            cout << "\nMenu Verifikasi:\n";
            cout << "1. Cek apakah kode sandi bilangan prima\n";
            cout << "2. Cek apakah kode sandi habis dibagi 2 dan 3 tetapi tidak 5\n";
            cout << "3. Cek apakah kode sandi palindrome\n";
            cout << "4. Keluar\n";
            cout << "Pilih menu: ";
            cin >> pilihan;

            if (pilihan == 1) {
                cout << (isPrime(kodeSandi) ? "Kode sandi adalah bilangan prima.\n" : "Kode sandi bukan bilangan prima.\n");
            } else if (pilihan == 2) {
                cout << (isValidDivision(kodeSandi) ? "Kode sandi valid berdasarkan aturan pembagian.\n" : "Kode sandi tidak memenuhi aturan pembagian.\n");
            } else if (pilihan == 3) {
                cout << (isPalindrome(kodeSandi) ? "Kode sandi adalah palindrome.\n" : "Kode sandi bukan palindrome.\n");
            } else if (pilihan == 4) {
                cout << "Terima kasih! Program selesai.\n";
                return 0;
            } else {
                cout << "Pilihan tidak valid. Silakan coba lagi.\n";
            }
        }
    }
    return 0;
}

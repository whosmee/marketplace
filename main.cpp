#include <iostream>
#include <unordered_map>
#include <queue>
#include <stack>
#include <string>

using namespace std;

// =========================
//   HASH TABLE = PRODUK
// =========================
unordered_map<string, pair<string, int>> produk = {
    {"P001", {"Laptop", 8500000}},
    {"P002", {"Headset", 250000}},
    {"P003", {"Mouse", 80000}},
    {"P004", {"Keyboard", 150000}}
};

// =========================
//   QUEUE = ANTRIAN PESANAN
// =========================
queue<string> antrianPesanan;

// =========================
//   STACK = RIWAYAT AKSI
// =========================
stack<string> riwayatAksi;

// =========================
//   FUNGSI
// =========================

void tampilkanProduk() {
    cout << "\n===== DAFTAR PRODUK (HASH TABLE) =====\n";
    for (auto &p : produk) {
        cout << p.first << " - " << p.second.first << " : Rp " << p.second.second << endl;
    }
    cout << "--------------------------------------\n";
}

void tambahPesanan() {
    tampilkanProduk();
    cout << "Masukkan kode produk yang ingin dipesan: ";
    string kode;
    cin >> kode;

    if (produk.find(kode) != produk.end()) {
        antrianPesanan.push(kode);
        riwayatAksi.push("Tambah pesanan " + kode);
        cout << "Pesanan " << produk[kode].first << " berhasil ditambahkan ke antrian!\n";
    } else {
        cout << "Kode produk tidak ditemukan!\n";
    }
}

void prosesPesanan() {
    if (antrianPesanan.empty()) {
        cout << "Tidak ada pesanan dalam antrian.\n";
    } else {
        string kode = antrianPesanan.front();
        antrianPesanan.pop();
        riwayatAksi.push("Proses pesanan " + kode);
        cout << "Pesanan " << produk[kode].first << " telah diproses!\n";
    }
}

void lihatAntrian() {
    cout << "\n===== ANTRIAN PESANAN (QUEUE) =====\n";
    if (antrianPesanan.empty()) {
        cout << "Antrian kosong.\n";
    } else {
        queue<string> temp = antrianPesanan;
        while (!temp.empty()) {
            string kode = temp.front(); temp.pop();
            cout << kode << " - " << produk[kode].first << endl;
        }
    }
    cout << "-----------------------------------\n";
}

void lihatRiwayat() {
    cout << "\n===== RIWAYAT AKSI (STACK) =====\n";
    if (riwayatAksi.empty()) {
        cout << "Belum ada riwayat aksi.\n";
    } else {
        stack<string> temp = riwayatAksi;
        while (!temp.empty()) {
            cout << temp.top() << endl;
            temp.pop();
        }
    }
    cout << "--------------------------------\n";
}

// =========================
//   MAIN PROGRAM
// =========================

int main() {
    int pilihan;
    do {
        cout << "\n====================================\n";
        cout << "       SISTEM MARKETPLACE MINI      \n";
        cout << "====================================\n";
        cout << "1. Lihat Produk (Hash Table)\n";
        cout << "2. Tambah Pesanan (Queue)\n";
        cout << "3. Proses Pesanan (Queue)\n";
        cout << "4. Lihat Antrian Pesanan\n";
        cout << "5. Lihat Riwayat Aksi (Stack)\n";
        cout << "6. Keluar\n";
        cout << "Pilih menu (1-6): ";
        cin >> pilihan;

        switch(pilihan) {
            case 1: tampilkanProduk(); break;
            case 2: tambahPesanan(); break;
            case 3: prosesPesanan(); break;
            case 4: lihatAntrian(); break;
            case 5: lihatRiwayat(); break;
            case 6: cout << "Terima kasih sudah menggunakan Marketplace Mini!\n"; break;
            default: cout << "Pilihan tidak valid.\n"; break;
        }
    } while(pilihan != 6);

    return 0;
}
#include <iostream>

using namespace std;

#include "Tree.h"

int main() {
    Node* root = nullptr;
    int pilihan;

    do {
        cout << "\n=== SISTEM INVENTARIS GEDUNG ===\n";
        cout << "1. Tambah Ruangan\n";
        cout << "2. Tambah Barang\n";
        cout << "3. Tampilkan Barang per Ruangan\n";
        cout << "4. Update Barang\n";
        cout << "5. Hapus Barang\n";
        cout << "6. Traversal Inorder\n";
        cout << "7. Traversal Preorder\n";
        cout << "8. Traversal Postorder\n";
        cout << "0. Keluar\n";
        cout << "Pilih: ";
        cin >> pilihan;

        if (pilihan == 1) {
            int id;
            cout << "Masukkan ID Ruangan: ";
            cin >> id;
            root = insertRuangan(root, id);
        }

        else if (pilihan == 2) {
            int id, jumlah;
            string nama;
            cout << "ID Ruangan: ";
            cin >> id;

            Node* ruang = cariRuangan(root, id);
            if (!ruang) {
                cout << "Ruangan tidak ditemukan.\n";
            } else {
                cin.ignore();
                cout << "Nama Barang: ";
                getline(cin, nama);
                cout << "Jumlah: ";
                cin >> jumlah;
                tambahBarang(ruang, nama, jumlah);
            }
        }

        else if (pilihan == 3) {
            int id;
            cout << "Masukkan ID Ruangan: ";
            cin >> id;

            Node* ruang = cariRuangan(root, id);
            if (!ruang) cout << "Ruangan tidak ditemukan.\n";
            else tampilBarang(ruang);
        }

        else if (pilihan == 4) {
            int id;
            string nama;

            cout << "ID Ruangan: ";
            cin >> id;

            Node* ruang = cariRuangan(root, id);

            if (!ruang) {
                cout << "Ruangan tidak ditemukan.\n";
            } else {
                cin.ignore();
                cout << "Nama Barang yang diupdate: ";
                getline(cin, nama);

                if (updateBarang(ruang, nama))
                    cout << "Berhasil diperbarui.\n";
                else
                    cout << "Barang tidak ditemukan.\n";
            }
        }

        else if (pilihan == 5) {
            int id;
            string nama;

            cout << "ID Ruangan: ";
            cin >> id;
            Node* ruang = cariRuangan(root, id);

            if (!ruang) cout << "Ruangan tidak ditemukan.\n";
            else {
                cin.ignore();
                cout << "Nama barang yang dihapus: ";
                getline(cin, nama);

                if (hapusBarang(ruang, nama))
                    cout << "Berhasil dihapus.\n";
                else
                    cout << "Barang tidak ditemukan.\n";
            }
        }

        else if (pilihan == 6) tampilkanInorder(root);
        else if (pilihan == 7) tampilkanPreorder(root);
        else if (pilihan == 8) tampilkanPostorder(root);

        else {
            cout << "Pilihan tidak tersedia. Masukkan angka 1-8";
        }

    } while (pilihan != 0);

    cout << "Anda berhasil keluar dari sistem.";

    return 0;
}

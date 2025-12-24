#include "Tree.h"
#include <iostream>
using namespace std;

// Constructor node ruangan
Node::Node(int id) {
    idRuangan = id;
    jumlahBarang = 0;
    left = right = nullptr;
}

// Insert ruangan ke BST
Node* insertRuangan(Node* root, int idRuangan) {
    if (idRuangan < 1) {
        cout << "Kode ruangan tidak valid. Kode ruangan harus lebih dari 1.\n";
        return root;
    }

    if (root == nullptr) {
        cout << "Ruangan " << idRuangan << " berhasil ditambahkan.\n";
        return new Node(idRuangan);
    }

    if (idRuangan < root->idRuangan)
        root->left = insertRuangan(root->left, idRuangan);
    else if (idRuangan > root->idRuangan)
        root->right = insertRuangan(root->right, idRuangan);
    else
        cout << "Ruangan " << idRuangan << " sudah terdaftar! Penambahan dibatalkan.\n";

    return root;
}


// Cari ruangan
Node* cariRuangan(Node* root, int id) {
    if (!root) return nullptr;
    if (root->idRuangan == id) return root;
    if (id < root->idRuangan) return cariRuangan(root->left, id);
    return cariRuangan(root->right, id);
}

// Traversal
void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);

    cout << "Ruangan: " << root->idRuangan
         << " (" << root->jumlahBarang << " barang)\n";

    for (int i = 0; i < root->jumlahBarang; i++) {
        cout << "   - " << root->daftar[i].nama
             << " (Jumlah: " << root->daftar[i].jumlah << ")\n";
    }
    cout << endl;

    inorder(root->right);
}

void preorder(Node* root) {
    if (!root) return;

    cout << "Ruangan: " << root->idRuangan
         << " (" << root->jumlahBarang << " barang)\n";

    for (int i = 0; i < root->jumlahBarang; i++) {
        cout << "   - " << root->daftar[i].nama
             << " (Jumlah: " << root->daftar[i].jumlah << ")\n";
    }
    cout << endl;

    preorder(root->left);
    preorder(root->right);
}

void postorder(Node* root) {
    if (!root) return;
    postorder(root->left);
    postorder(root->right);

    cout << "Ruangan: " << root->idRuangan
         << " (" << root->jumlahBarang << " barang)\n";

    for (int i = 0; i < root->jumlahBarang; i++) {
        cout << "   - " << root->daftar[i].nama
             << " (Jumlah: " << root->daftar[i].jumlah << ")\n";
    }
    cout << endl;
}

void tampilkanInorder(Node* root) {
    if (!root) {
        cout << "Tidak ada ruangan yang terdaftar.\n";
        return;
    }
    inorder(root);
}

void tampilkanPreorder(Node* root) {
    if (!root) {
        cout << "Tidak ada ruangan yang terdaftar.\n";
        return;
    }
    preorder(root);
}

void tampilkanPostorder(Node* root) {
    if (!root) {
        cout << "Tidak ada ruangan yang terdaftar.\n";
        return;
    }
    postorder(root);
}


// CRUD BARANG
void tambahBarang(Node* ruang, string nama, int jumlah) {
    if (!ruang) return;

    // Cek kapasitas penuh
    if (ruang->jumlahBarang >= MAX_BARANG) {
        cout << "Kapasitas barang di ruangan ini sudah penuh!\n";
        return;
    }

    // Cek barang duplikat
    for (int i = 0; i < ruang->jumlahBarang; i++) {
        if (ruang->daftar[i].nama == nama) {
            cout << "Barang \"" << nama
                 << "\" sudah ada di ruangan ini! Gunakan update jika ingin mengubah jumlah.\n";
            return;
        }
    }

    // Jika tidak duplikat → tambahkan
    ruang->daftar[ruang->jumlahBarang].nama = nama;
    ruang->daftar[ruang->jumlahBarang].jumlah = jumlah;
    ruang->jumlahBarang++;

    cout << "Barang \"" << nama << "\" berhasil ditambahkan.\n";
}


void tampilBarang(Node* ruang) {
    if (!ruang) return;

    if (ruang->jumlahBarang == 0) {
        cout << "Tidak ada barang.\n";
        return;
    }

    cout << "--- Daftar Barang di ruangan " << ruang->idRuangan << " ---\n";
    for (int i = 0; i < ruang->jumlahBarang; i++) {
        cout << i+1 << ". " << ruang->daftar[i].nama
             << " (Jumlah: " << ruang->daftar[i].jumlah << ")\n";
    }
}

bool updateBarang(Node* ruang, string nama) {
    for (int i = 0; i < ruang->jumlahBarang; i++) {
        if (ruang->daftar[i].nama == nama) {
            int jumlahBaru;
            cout << "Jumlah baru: ";
            cin >> jumlahBaru;

            ruang->daftar[i].jumlah = jumlahBaru;
            return true;
        }
    }
    return false;
}

bool hapusBarang(Node* ruang, string nama) {
    for (int i = 0; i < ruang->jumlahBarang; i++) {
        if (ruang->daftar[i].nama == nama) {
            // Geser array
            for (int j = i; j < ruang->jumlahBarang - 1; j++) {
                ruang->daftar[j] = ruang->daftar[j+1];
            }
            ruang->jumlahBarang--;
            return true;
        }
    }
    return false;
}

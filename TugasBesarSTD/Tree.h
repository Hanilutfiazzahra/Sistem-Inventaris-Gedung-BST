#ifndef TREE_H_INCLUDED
#define TREE_H_INCLUDED

#include <iostream>
using namespace std;

const int MAX_BARANG = 50;

struct Barang {
    string nama;
    int jumlah;
};

struct Node {
    int idRuangan;                 // key BST
    Barang daftar[MAX_BARANG];     // array barang
    int jumlahBarang;              // banyak jenis barang
    Node* left;
    Node* right;

    Node(int id);
};

// Operasi BST
Node* insertRuangan(Node* root, int idRuangan);
Node* cariRuangan(Node* root, int idRuangan);

void inorder(Node* root);
void preorder(Node* root);
void postorder(Node* root);
void tampilkanInorder(Node* root);
void tampilkanPreorder(Node* root);
void tampilkanPostorder(Node* root);

// CRUD Barang
void tambahBarang(Node* ruang, string nama, int jumlah);
void tampilBarang(Node* ruang);
bool updateBarang(Node* ruang, string nama);
bool hapusBarang(Node* ruang, string nama);

#endif


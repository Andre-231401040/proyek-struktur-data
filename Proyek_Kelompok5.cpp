#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <windows.h>
using namespace std;

struct identitasPelanggan{
    int nomorMeja;
    string namaPelanggan;
};

struct pesanan{
    int nomorMeja, harga, total, jumlah;
    string namaMenu;
};

struct menuKomponen
{
    string nama;
    string deskripsi;
    int harga;

    bool operator < (const menuKomponen& other) const {
        return harga < other.harga;
    }
};

char yn;
bool statusMeja[10] = {0};
string namaPelangganDiMeja[10];
queue<string> pelangganDalamAntrian;
int pilih, jumlah_makanan, jumlah_minuman;
vector<pesanan> daftarPesanan;
menuKomponen makanan[100], minuman[100];

void gotoxy(int x, int y){
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void urutkanMenu(){
    sort(makanan, makanan + jumlah_makanan);
    sort(minuman, minuman + jumlah_minuman);
}

void menambahMenu(){
    ulangTambah:
    string temp;
    cout << "=============" << endl;
    cout << "Menambah Menu" << endl;
    cout << "=============" << endl;
    cout << endl;
    cout << "Ingin menambahkan makanan atau minuman? "; cin >> temp;
    system("cls");
    cout << "=============" << endl;
    cout << "Menambah Menu" << endl;
    cout << "=============" << endl;
    cout << endl;
    
    if (temp == "makanan"){
        getchar();
        cout << "Nama : "; getline(cin, makanan[jumlah_makanan].nama);
        cout << "Deskripsi : "; getline(cin, makanan[jumlah_makanan].deskripsi);
        cout << "Harga : "; cin >> makanan[jumlah_makanan].harga; 
        jumlah_makanan++;
    }else if (temp == "minuman"){
        getchar();
        cout << "Nama : "; getline(cin, minuman[jumlah_minuman].nama);
        cout << "Deskripsi : "; getline(cin, minuman[jumlah_minuman].deskripsi);
        cout << "Harga : "; cin >> minuman[jumlah_minuman].harga; 
        jumlah_minuman++;
    }else{
        cout << "Hanya bisa memasukkan makanan atau minuman" << endl << endl;
        cout << "Silakan coba sekali lagi" << endl;
        system("pause");
        goto ulangTambah;
    }

    system("cls");
    cout << "=========================" << endl;
    cout << "Menu berhasil Ditambahkan" << endl;
    cout << "=========================" << endl;
    cout << endl;
    system("pause");
}

void mengubahMenu(){
    ulangUbah:
    int ubah;
    string temp;
    cout << "=============" << endl;
    cout << "Mengubah Menu" << endl;
    cout << "=============" << endl;
    cout << endl;
    cout << "Makanan" << endl << endl;
    for (int i = 0; i < jumlah_makanan; i++) {
        cout << i + 1 << ". " << makanan[i].nama << "...........Rp" << makanan[i].harga << endl;
    }
    cout << endl;
    cout << "Minuman" << endl;
    cout << endl;
    for (int i = 0; i < jumlah_minuman; i++) {
        cout << i + 1 << ". " << minuman[i].nama << "...........Rp" << minuman[i].harga << endl;
    }
    cout << endl;
    cout << "Ingin mengubah kategori makanan atau minuman? "; cin >> temp;
    
    if(temp != "makanan" && temp != "minuman" ){
        cout << "\nHanya bisa memasukkan makanan atau minuman" << endl << endl;
        cout << "Silakan coba sekali lagi" << endl;
        system("pause");
        goto ulangUbah;
    }

    cout << "Pilih nomor menu yang mau diubah : "; cin >> ubah;
    
    system("cls");
    
    cout << "=============" << endl;
    cout << "Mengubah Menu" << endl;
    cout << "=============" << endl;
    cout << endl;
    cout << "Ubah : " << endl;
    cout << "1. Nama " << endl;
    cout << "2. Deskripsi " << endl;
    cout << "3. Harga " << endl;
    cout << endl;
    cout << "Pilih nomor : "; cin >> pilih;
    system("cls");
    if(temp == "makanan"){
        switch (pilih){
            case 1:
                cout << "=============" << endl;
                cout << "Mengubah Menu" << endl;
                cout << "=============" << endl;
                cout << endl; getchar();
                cout << "Nama yang baru : "; getline(cin, makanan[ubah - 1].nama);
                break;
            case 2:
                cout << "=============" << endl;
                cout << "Mengubah Menu" << endl;
                cout << "=============" << endl;
                cout << endl; getchar();
                cout << "Deskripsi yang baru : "; getline(cin, makanan[ubah - 1].deskripsi);
                break;
            case 3:
                cout << "=============" << endl;
                cout << "Mengubah Menu" << endl;
                cout << "=============" << endl;
                cout << endl;
                cout << "Harga yang baru : "; cin >> makanan[ubah - 1].harga;
                break;
            default:
                cout << "=============" << endl;
                cout << "Mengubah Menu" << endl;
                cout << "=============" << endl;
                cout << endl;
                cout << "Nomor tidak valid" << endl;
                cout << "Silakan coba sekali lagi" << endl;
                cout << endl;
                system("pause");
                goto ulangUbah;
                break;
        }
    }else{
        switch (pilih){
            case 1:
                cout << "=============" << endl;
                cout << "Mengubah Menu" << endl;
                cout << "=============" << endl;
                cout << endl; getchar();
                cout << "Nama yang baru : "; getline(cin, minuman[ubah - 1].nama);
                break;
            case 2:
                cout << "=============" << endl;
                cout << "Mengubah Menu" << endl;
                cout << "=============" << endl;
                cout << endl; getchar();
                cout << "Deskripsi yang baru : "; getline(cin, minuman[ubah - 1].deskripsi);
                break;
            case 3:
                cout << "=============" << endl;
                cout << "Mengubah Menu" << endl;
                cout << "=============" << endl;
                cout << endl;
                cout << "Harga yang baru : "; cin >> minuman[ubah - 1].harga;
                break;
            default:
                cout << "=============" << endl;
                cout << "Mengubah Menu" << endl;
                cout << "=============" << endl;
                cout << endl;
                cout << "Nomor tidak valid" << endl;
                cout << "Silakan coba sekali lagi" << endl;
                cout << endl;
                system("pause");
                goto ulangUbah;
                break;
        }
    }
    
    system("cls");
    cout << "====================" << endl;
    cout << "Menu berhasil Diubah" << endl;
    cout << "====================" << endl;
    cout << endl; 
    cout << "Ingin mengubah yang lain (y/n) : "; cin >> yn;
    if(yn == 'Y' || yn == 'y') goto ulangUbah;
}

void tampilanMenuTerurut(){
    urutkanMenu();
    cout << "Makanan" << endl << endl;
    for (int i = 0; i < jumlah_makanan; i++) {
        cout << i + 1 << ". " << makanan[i].nama << "...........Rp" << makanan[i].harga << endl;
    }
    cout << endl;
    cout << "Minuman" << endl;
    cout << endl;
    for (int i = 0; i < jumlah_minuman; i++) {
        cout << i + 1 << ". " << minuman[i].nama << "...........Rp" << minuman[i].harga << endl;
    }
    cout << endl;
}

void daftarMenu(){
    
    cout << "===========" << endl;
    cout << "Daftar Menu" << endl;
    cout << "===========" << endl;
    cout << endl;
    
    tampilanMenuTerurut();

    cout << "Ingin melihat lebih detail (y/n) "; cin >> yn;
    system("cls");
    if (yn == 'Y' || yn == 'y'){
        cout << "===========" << endl;
        cout << "Detail Menu" << endl;
        cout << "===========" << endl;
        cout << endl;
        cout << "Makanan" << endl << endl;
        for (int i = 0; i < jumlah_makanan; i++) {
            cout << i + 1 << ". " << makanan[i].nama << "...........Rp" << makanan[i].harga << endl;
            cout << "Deskripsi : " << makanan[i].deskripsi << endl;
        }
        cout << endl;
        cout << "Minuman" << endl;
        cout << endl;
        for (int i = 0; i < jumlah_minuman; i++) {
            cout << i + 1 << ". " << minuman[i].nama << "...........Rp" << minuman[i].harga << endl;
            cout << "Deskripsi : " << minuman[i].deskripsi << endl;
        }
        cout << endl;
        system("pause");
        system("cls");
    }
}

void tambahPelanggan(){
    cout << "=====================================================" << endl;
    cout << "Memasukkan pelanggan dalam antrian ke meja kosong" << endl;
    cout << "=====================================================" << endl;
    if(pelangganDalamAntrian.size() > 0){
        for(int i = 0; i < 10; i++){
            if(statusMeja[i] == false){
                if(pelangganDalamAntrian.size() > 0){
                    statusMeja[i] = true;
                    namaPelangganDiMeja[i] = pelangganDalamAntrian.front();
                    cout << namaPelangganDiMeja[i] << " sudah dimasukkan ke meja ke-" << i + 1 << endl;
                    pelangganDalamAntrian.pop();
                }
            }
        }
    }else{
        cout << "Tidak ada pelanggan di dalam antrian" << endl;
    }

    system("pause");
    system("cls");

    string nama;
    int nomorMeja;
    cout << "============================================" << endl;
    cout << "Tambah Pelanggan" << endl;
    cout << "============================================" << endl;
    cout << "Berikan nomor meja yang ingin ditempati: ";
    cin >> nomorMeja;
    if(pelangganDalamAntrian.size() > 0){
        char pilihan;
        cout << endl << "Semua meja sudah terisi" << endl;
        cout << endl << "Ingin mengantri? (y/n): ";
        cin >> pilihan;
        if(pilihan == 'Y' || pilihan == 'y'){
            cout << "Masukkan nama: ";
            cin >> nama;
            pelangganDalamAntrian.push(nama);
            system("cls");
            cout << "====================================================" << endl;
            cout << nama << " sudah dimasukkan ke dalam antrian" << endl;
            cout << "====================================================" << endl;
        }
    }else{
        if(!statusMeja[nomorMeja - 1]){
            cout << "Masukkan nama: ";
            cin >> nama;
            namaPelangganDiMeja[nomorMeja - 1] = nama;
            statusMeja[nomorMeja - 1] = true;
            system("cls");
            cout << "===========================================" << endl;
            cout << nama << " sudah dimasukkan ke meja ke-" << nomorMeja << endl;
            cout << "===========================================" << endl;
        }else{
            char pilihan;
            cout << endl << "Meja ke-" << nomorMeja << " sudah terisi" << endl;
            cout << endl << "Ingin mengantri? (y/n): ";
            cin >> pilihan;
            if(pilihan == 'Y' || pilihan == 'y'){
                cout << "Masukkan nama: ";
                cin >> nama;
                pelangganDalamAntrian.push(nama);
                system("cls");
                cout << "====================================================" << endl;
                cout << nama << " sudah dimasukkan ke dalam antrian" << endl;
                cout << "====================================================" << endl;
            }
        }
    }

    system("pause");
    system("cls");
}

void tambahPesanan(){
    int jumlahMenu;
    cout << "============================" << endl;
    cout << "Tambah Pesanan" << endl;
    cout << "============================" << endl;
    cout << endl;
    tampilanMenuTerurut();
    
    cout << endl << "Banyak menu yang dipesan: ";
    cin >> jumlahMenu;

    for(int i = 1; i <= jumlahMenu; i++){
        ulangPesan:
        system("cls");
        string kategori;
        pesanan infoPesanan;
        int nomorMeja, nomorMenu;
        cout << "============================" << endl;
        cout << "Tambah Pesanan" << endl;
        cout << "============================" << endl;
        cout << endl;
        tampilanMenuTerurut();

        cout << "Nomor meja: ";
        cin >> nomorMeja;
        if(!statusMeja[nomorMeja - 1]){
            cout << "Meja masih kosong" << endl;
            break;
        }

        cout << "Nomor menu: ";
        cin >> nomorMenu;
        cout << "Kategori (makanan/minuman): ";
        cin >> kategori;
        if(kategori == "makanan"){
            if (nomorMenu > jumlah_makanan) {
                cout << "Nomor Menu tidak valid" << endl;
                cout << "Silakan coba sekali lagi" << endl << endl;
                system("pause");
                system("cls");
                goto ulangPesan;
            }
        }else if(kategori == "minuman"){
            if (nomorMenu > jumlah_minuman) {
                cout << "Nomor Menu tidak valid" << endl;
                cout << "Silakan coba sekali lagi" << endl << endl;
                system("pause");
                system("cls");
                goto ulangPesan;
            }
        }else {
            cout << "Kategori tidak valid" << endl;
            cout << "Silakan coba sekali lagi" << endl << endl;
            system("pause");
            system("cls");
            goto ulangPesan;
        }
        
        cout << "Jumlah: ";
        cin >> infoPesanan.jumlah;
        infoPesanan.nomorMeja = nomorMeja;
        if(kategori == "makanan"){
            infoPesanan.harga = makanan[nomorMenu - 1].harga;
            infoPesanan.total = makanan[nomorMenu - 1].harga * infoPesanan.jumlah;
            infoPesanan.namaMenu = makanan[nomorMenu - 1].nama;
            daftarPesanan.push_back(infoPesanan);
            if(i < jumlahMenu){
                cout << endl << "Silahkan masukkan pesanan berikutnya" << endl;
                system("pause");
            }
        }else if(kategori == "minuman"){
            infoPesanan.harga = minuman[nomorMenu - 1].harga;
            infoPesanan.total = minuman[nomorMenu - 1].harga * infoPesanan.jumlah;
            infoPesanan.namaMenu = minuman[nomorMenu - 1].nama;
            daftarPesanan.push_back(infoPesanan);
            if(i < jumlahMenu){
                cout << "Silahkan masukkan pesanan berikutnya" << endl;
                system("pause");
            }            
        }
    }

    system("pause");
    system("cls");
}

void cekMeja(){
    cout << "======================" << endl;
    cout << "Daftar Status Meja" << endl;
    cout << "======================" << endl;
    for(int i = 0; i < 10; i++){
        cout << i + 1 << ". ";
        cout << (statusMeja[i] ? "Terisi" : "Kosong") << endl;
    }
    system("pause");
    system("cls");
}

void cekAntrian(){
    cout << "==========================================" << endl;
    cout << "Antrian" << endl;
    cout << "==========================================" << endl;
    cout << "Jumlah pelanggan yang sedang mengantri: " << pelangganDalamAntrian.size() << endl;
    system("pause");
    system("cls");
}

void cekPesanan(){
    int nomorMeja;
    vector<pesanan> hasilCekPesanan;
    cout << "==========================" << endl;
    cout << "Cek Pesanan Pelanggan" << endl;
    cout << "==========================" << endl;

    cout << endl << "Masukkan nomor meja: ";
    cin >> nomorMeja;
    for(int i = 0; i < daftarPesanan.size(); i++){
        if(daftarPesanan[i].nomorMeja == nomorMeja){
            hasilCekPesanan.push_back(daftarPesanan[i]);
        }
    }

    system("cls");
    cout << "=========================" << endl;
    cout << "Pesanan meja ke-" << nomorMeja << endl;
    cout << "=========================" << endl;
    if(hasilCekPesanan.size() == 0){
        cout << endl << "Tidak ada pesanan" << endl;
    }else{
        cout << "Jumlah pesanan: " << hasilCekPesanan.size() << endl;
        cout << endl;
        for(int i = 0; i < hasilCekPesanan.size(); i++){
            cout << "Pesanan ke-" << i + 1 << endl;
            cout << hasilCekPesanan[i].namaMenu << endl;
            cout << "Harga: Rp" << hasilCekPesanan[i].harga << endl;
            cout << "Jumlah: " << hasilCekPesanan[i].jumlah << endl;
            cout << "Total: Rp" << hasilCekPesanan[i].total << endl;
            cout << endl;
        }
    }
    system("pause");
    system("cls");
}

void bayar(){
    ulangBayar:
    int temp2, cnt = -1, total = 0;
    cout << "==========================" << endl;
    cout << "Bayar" << endl;
    cout << "==========================" << endl;
    cout << endl;
    cout << "Berikan nomor meja : "; cin >> temp2;
    if(!statusMeja[temp2 - 1]){
        cout << "\nMeja tidak terisi" << endl;
        cout << "Silakan coba sekali lagi" << endl;
        system("pause");
        system("cls");
        goto ulangBayar;
    }
    system("cls");
    cout << "=======================================" << endl;
    cout << "Bayar" << endl;
    cout << "=======================================" << endl;
    cout << endl; 
    for(int i = 0; i < daftarPesanan.size(); i++){
        if(daftarPesanan[i].nomorMeja == temp2){
            cnt++;
            total += daftarPesanan[i].total;
            cout << daftarPesanan[i].jumlah << " " << daftarPesanan[i].namaMenu;
            gotoxy(30, cnt + 4);
            cout << "Rp" << daftarPesanan[i].total << endl;
        }
    }
    cout << endl << "---------------------------------------" << endl;
    cout << "Harga Pesanan : Rp" << total << endl;
    cout << "Pajak Restoran : Rp" << 0.1 * total << endl;
    cout << "---------------------------------------" << endl;
    cout << "Harga Total : Rp" << 1.1 * total << endl;
    cout << endl;
    system("pause");

    statusMeja[temp2 - 1] = 0;
    namaPelangganDiMeja[temp2 - 1] = "";
    for(int i = 0; i < daftarPesanan.size(); i++){
        if(daftarPesanan[i].nomorMeja == temp2){
            auto it = daftarPesanan.begin() + i;
            daftarPesanan.erase(it);
            i--;
        }
    }

    system("cls");
    cout << "====================================" << endl;
    cout << "Pembayaran Selesai" << endl;
    cout << "====================================" << endl;
    cout << endl;
    cout << "Meja nomor " << temp2 << " telah dikosongkan" << endl;
    cout << endl;
    system("pause");
    system("cls");

}

void manajemenRestoran(){
    kembali2:
    cout << "==================" << endl;
    cout << "Manajemen Restoran" << endl;
    cout << "==================" << endl;
    cout << endl;
    cout << "1. Daftar Menu" << endl;
    cout << "2. Tambah Pelanggan" << endl;
    cout << "3. Tambah Pesanan" << endl;
    cout << "4. Cek Meja" << endl;
    cout << "5. Cek Antrian" << endl;
    cout << "6. Cek Pesanan" << endl;
    cout << "7. Bayar" << endl;
    cout << "8. Kembali" << endl;
    cout << endl;
    cout << "Pilih nomor : "; cin >> pilih;
    system("cls");
    switch (pilih)
    {
    case 1:
        daftarMenu();
        goto kembali2;
        break;
    case 2:
        tambahPelanggan();
        goto kembali2;
        break;
    case 3:
        tambahPesanan();
        goto kembali2;
        break;
    case 4:
        cekMeja();
        goto kembali2;
        break;
    case 5:
        cekAntrian();
        goto kembali2;
        break;
    case 6:
        cekPesanan();
        goto kembali2;
        break;
    case 7:
        bayar();
        goto kembali2;
        break;
    default:
        system("cls");
        break;
    }

}

int main(){
    system("cls");
    cout << "=========================" << endl;
    cout << "Sistem Pemesanan Restoran" << endl;
    cout << "=========================" << endl;
    cout << endl;
    cout << "Selamat Datang" << endl;
    cout << endl;
    system("pause");

    kembali:
    system("cls");
    cout << "=========================" << endl;
    cout << "Sistem Pemesanan Restoran" << endl;
    cout << "=========================" << endl;
    cout << endl;
    cout << "1. Menambah menu" << endl;
    cout << "2. Mengubah menu" << endl;
    cout << "3. Manajemen Restoran" << endl;
    cout << "4. Keluar" << endl;
    cout << endl;
    cout << "Pilih nomor : "; cin >> pilih;
    getchar();
    system("cls");

    switch(pilih){
        case 1:
            menambahMenu();
            goto kembali;
            break;
        
        case 2:
            mengubahMenu();
            goto kembali;
            break;

        case 3 :
            manajemenRestoran();
            goto kembali;
            break;

        default:
            cout << "=========================" << endl;
            cout << "Terima Kasih telah Mampir" << endl;
            cout << "=========================" << endl;
            cout << endl;
            system("pause");
            break;
    }

    return 0;
 }

#include <iostream>
using namespace std;

class Perkuliahan {
public:
    void inputIdentitasMahasiswa() {
        cout << "==============================================" << endl;
        cout << "         PROGRAM HITUNG UKT MAHASISWA         " << endl;
        cout << "==============================================" << endl;
        cout << "Masukkan Nama              : ";
        cin >> namaMahasiswa;
        cout << "Masukkan NIM               : ";
        cin >> nimMahasiswa;
        cout << "Masukkan jumlah matakuliah	: ";
        cin >> jumlahMatakuliah;
    }

    void inputDataMatakuliah(int indeks = 0) {
        if (indeks >= jumlahMatakuliah) return;

        cout << "\nMasukkan nama mata kuliah ke-" << indeks + 1 << " : ";
        cin >> daftarNamaMatakuliah[indeks];
        cout << "Masukkan jumlah SKS mata kuliah ke-" << indeks + 1 << " : ";
        cin >> daftarSKS[indeks];

        inputDataMatakuliah(indeks + 1);
    }

    int hitungTotalSKS(int indeks = 0) {
        if (indeks >= jumlahMatakuliah) return 0;
        return daftarSKS[indeks] + hitungTotalSKS(indeks + 1);
    }

    void tampilkanTagihanUKT() {
        cout << "----------------------------------------------" << endl;
        int totalSKS = hitungTotalSKS();
        int hargaPerSKS = 125000;
        int totalBiaya = totalSKS * hargaPerSKS;
        int totalDiskon = totalBiaya * 15 / 100;
        int totalBayar = totalBiaya - totalDiskon;

        cout << "Total pembayaran        : Rp " << totalBayar << endl;
    }

private:
    string namaMahasiswa, nimMahasiswa;
    int jumlahMatakuliah;
    string daftarNamaMatakuliah[100];
    int daftarSKS[100];
};

int main() {
    Perkuliahan perkuliahan;
    perkuliahan.inputIdentitasMahasiswa();
    perkuliahan.inputDataMatakuliah();
    perkuliahan.tampilkanTagihanUKT();

    return 0;
}

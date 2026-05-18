#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

// Abstract Base Class
class RekeningBank
{
protected:
    string namaNasabah;
    double saldo;

public:
    RekeningBank(string nama, double saldoAwal)
    {
        namaNasabah = nama;
        saldo = saldoAwal;
    }

    // Pure Virtual Function
    virtual void potongAdmin() = 0;

    void tampilkanSaldo()
{
    cout << fixed << setprecision(0);

    cout << "Nasabah : " << namaNasabah << endl;
    cout << "Saldo   : Rp " << saldo << endl;
}
    virtual ~RekeningBank() {}
};

// Rekening Syariah
class RekeningSyariah : public RekeningBank
{
public:
    RekeningSyariah(string nama, double saldoAwal)
        : RekeningBank(nama, saldoAwal) {}

    void potongAdmin() override
    {
        cout << "Rekening Syariah bebas biaya admin." << endl;
    }
};

// Rekening Konvensional
class RekeningKonvensional : public RekeningBank
{
public:
    RekeningKonvensional(string nama, double saldoAwal)
        : RekeningBank(nama, saldoAwal) {}

    void potongAdmin() override
    {
        saldo -= 15000;
        cout << "Biaya admin Rp 15.000 dipotong." << endl;
    }
};

// Rekening Premium
class RekeningPremium : public RekeningBank
{
public:
    RekeningPremium(string nama, double saldoAwal)
        : RekeningBank(nama, saldoAwal) {}

    void potongAdmin() override
    {
        if (saldo > 10000000)
        {
            cout << "Saldo di atas Rp 10.000.000, bebas biaya admin." << endl;
        }
        else
        {
            saldo -= 50000;
            cout << "Biaya admin Rp 50.000 dipotong." << endl;
        }
    }
};

int main()
{
    RekeningBank *r1 = new RekeningSyariah("Andi", 5000000);
    RekeningBank *r2 = new RekeningKonvensional("Budi", 3000000);
    RekeningBank *r3 = new RekeningPremium("Citra", 8000000);
    RekeningBank *r4 = new RekeningPremium("Dewi", 15000000);

    RekeningBank *daftarRekening[] = {r1, r2, r3, r4};

    for (int i = 0; i < 4; i++)
    {
        cout << "==========================" << endl;

        daftarRekening[i]->tampilkanSaldo();

        cout << "Proses Potong Admin :" << endl;
        daftarRekening[i]->potongAdmin();

        cout << "Saldo Setelah Proses :" << endl;
        daftarRekening[i]->tampilkanSaldo();

        cout << endl;
    }

    // Hapus memory
    for (int i = 0; i < 4; i++)
    {
        delete daftarRekening[i];
    }

    return 0;
}
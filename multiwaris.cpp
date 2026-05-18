#include <iostream>
using namespace std;

class orang
{
    public:
        int umur;
        orang (int pUmur) :
        umur (pUmur)
    
    {
        cout << "Orang Dibuat Dengan Umur " << umur << "\n" << endl;
    }
};
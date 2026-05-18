#include <iostream>
using namespace std;

class abstraksiklass
{
    private: 
        string x, y;

    public:
        void setXY(string a, string b)
        {
            x = a;
            y = b;
        }
    
    void display ()
    {
        cout << "X = " << x << endl;
        cout << "Y = " << y << endl;
    }
};
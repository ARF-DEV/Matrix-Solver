#include "lib.h"

using namespace std;
//prototype biar fungsi bisa ditaro dibawah int main
int main()
{    
    int p;
    cout << "MENU" << endl;
    cout << "1.\tSistem Persamaan Linier" << endl;
    cout << "2.\tDeterminan" << endl;
    cout << "3.\tMatriks Balikan " << endl;
    cout << "4.\tKeluar" << endl;
    cout << "N = "; cin >> p;
    int k;
    switch (p)
    {
    case 1:
        
        cout << "1.\tEliminasi Gauss\n";
        cout << "2.\tEliminasi Gauss-Jordan\n";
        cout << "3.\tMatriks Balikan\n";
        cout << "4.\tKaidah Cramer\n";
        cout << "N = ";
        cin >> k;
        switch (k)
        {
            case 1:
                SplGauss();
                break;
            case 2:
                SplGaussJordan();
                break;
            case 3:
                SplMatriksBalikan();
                break;
            case 4:
                SplCramer();
                break;
        }
        break;
    case 2:
        cout << "1.\tReduksi Baris\n";
        cout << "2.\tEkspansi Kofaktor\n";
        cout << "N = ";
        cin >> k;
        switch (k)
        {
            case 1:
                DetReduksiBaris();
                break;
            case 2:
                DetEkspansiKofaktor();
                break;
        }
        break;
    case 3:
        Invers();
        break;
    case 4:
        cout << "ERROR : INVALID INPUT\n";
        return 0;
        break;
    }
    // INI CUMA TEST IMPLEMENTASI FUNGSI

}
/*

4 4
1 0 0 -1
3 1 2 2
1 0 -2 1
2 0 0 1

3 3
2 3 -1 5
4 4 -3 3
-2 3 -1 1

3 3
0 1 5 8
7 8 9 0
2 10 4 8

3 3
0 1 2 5
1 0 2 2
5 5 0 7

JIKA ADA NILAI DITEMPAT 1 UTAMA YANG BERNILAI 0 MAKA TUKAR DENGAN BARIS LAIN

*/
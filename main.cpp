#include <fstream>
#include "lib.h"

using namespace std;
//prototype biar fungsi bisa ditaro dibawah int main
void SplGauss()
{
    int n, m;
    cin >> m >> n;

    float **A = SetArray2d(n + 1, m); 

    int l = calculateEselonBaris(A, n + 1, m);
    
    if (l == -1)
    {
        cout << "Solusi Banyak\n";
        return;
    }
    else if (l == -2)
    {
        cout << "Tidak ada Solusi\n";
    }

    float* hasil = FindAnswerSPL(A, n + 1, m);
    
    for (int i = 0; i < n; i++)
    {
        cout << "x[" << i + 1 << "] = " << hasil[i] << endl; 
    }
}
void SplGaussJordan()
{
    int n, m;
    cin >> m >> n;

    float **A = SetArray2d(n + 1, m); 

    int l = calculateEselonBarisTereduksi(A, n + 1, m);
    
    if (l == -1)
    {
        cout << "Solusi Banyak\n";
        return;
    }
    else if (l == -2)
    {
        cout << "Tidak ada Solusi\n";
    }

    float* hasil = FindAnswerSPL(A, n + 1, m);
    
    for (int i = 0; i < n; i++)
    {
        cout << "x[" << i + 1 << "] = " << hasil[i] << endl; 
    }
}
void SplMatriksBalikan()
{
    int n, m;
    cin >> m >> n;
    
    float **A = SetArray2d(n + 1, m);
    int out;
    float det = Determinan(A, n, m, &out);

    if (out == -1)
    {
        cout << "ERROR : det = 0\n";
        return;
    }
    float *hasil = MetodeMatriksBalikan(A, n + 1, m);
    for (int i = 0; i < n; i++)
    {
        cout << "x[" << i + 1 << "] = " << hasil[i] << endl; 
    }
}
void Invers()
{
    int n, m;
    cin >> m >> n;

    float **A = SetArray2d(n, m);

    float **B = inversMatriks(A, n, m);

    PrintMatriks(B, n, m);
}
void Det()
{
    int n, m;
    cin >> m >> n;
    
    float **A = SetArray2d(n, m);
    int flag = 0;
    float P = Determinan(A, n, m, &flag);

    if (flag == -1)
    {
        cout << "Determinan harus berupa matriks N x N" << endl;
        return;
    }
    cout << P << endl;
}

int main()
{    
    int p;
    cout << "MENU" << endl;
    cout << "1.\tSistem Persamaan Linier" << endl;
    cout << "2.\tDeterminan" << endl;
    cout << "3.\tMatriks Balikan " << endl;
    cout << "4.\tKeluar" << endl;
    cout << "N = "; cin >> p;

    switch (p)
    {
    case 1:
        int k;
        cout << "1.\tEliminasi Gauss\n";
        cout << "2.\tEliminasi Gauss-Jordan\n";
        cout << "3.\tMatriks Balikan\n";
        cout << "4.\tKaidah Cramer\n";
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
                //Cramer
                break;
        }
        break;
    case 2:
        Det();
        break;
    case 3:
        Invers();
        break;
    case 4:
        return 0;
        break;
    }
    // INI CUMA TEST IMPLEMENTASI FUNGSI
    
    
    
}
/*

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
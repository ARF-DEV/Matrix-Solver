#include <iostream>
#include <fstream>

using namespace std;
//prototype biar fungsi bisa ditaro dibawah int main
void InputKeyboard2d(float **A, int n, int m);
float** SetArray2d(int n, int m);
void calculateEselonBaris(float **A, int n, int m);
void AddRow(float *A, float *B, int n, float k);
void PrintMatriks(float **A, int n, int m);
void MulRow(float *A, int n, float k);
void SwapRow(float *A, float *B, int n);

int main()
{
    // INI CUMA TEST IMPLEMENTASI FUNGSI
    int n, m;
    cin >> n >> m;
    // n + 1 karena n itu jumlah variable dan hasil dari persamaan blom masuk
    float **A = SetArray2d(n + 1, m); 

    calculateEselonBaris(A, n + 1, m);

    PrintMatriks(A, n + 1, m);
        
}

void InputKeyboard2d(float **A, int n, int m)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> A[i][j];
        }
    }   
}

float** SetArray2d(int n, int m)
{
    float **arr = new float* [m];
    for (int i = 0; i < m; i++)
    {
        arr[i] = new float[n];
    }

    //TODO FILE ATO KEYBOARD
    InputKeyboard2d(arr, n, m);   
    
    return arr;
}

void calculateEselonBaris(float **A, int n, int m)
{
    for (int i = 0; i < m; i++)
    {
        if (A[i][i] == 0)
        {
            for (int j = 0; j < m; j++)
            {
                if (A[j][i] != 0)
                {
                    SwapRow(A[i], A[j], n);
                    break;
                }
            }
            
        }
    }

    PrintMatriks(A, n, m);

    for (int i = 0; i < m; i++)
    {
        float pembagi = A[i][i];
        MulRow(A[i], n, 1 / pembagi);

        for (int j = i + 1; j < m; j++)
        {
            float pengurang = A[j][i];
            AddRow(A[j], A[i], n, -pengurang);
        }
        
        
    }
    
              
    
    
}

void AddRow(float *A, float *B, int n, float k)
{
    for (int i = 0; i < n; i++)
    {
        A[i] += k * B[i];
    }
    
}
void MulRow(float *A, int n, float k)
{
    for (int i = 0; i < n; i++)
    {
        A[i] *= k;
    }
}

void SwapRow(float *A, float *B, int n)
{
    for (int i = 0; i < n; i++)
    {
        swap(A[i], B[i]);
    }
    
}
void PrintMatriks(float **A, int n, int m)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << A[i][j] << "\t";
        }
        cout << endl;
    }
}

/*

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
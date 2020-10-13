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
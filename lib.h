#include <iostream>
#include <cstring>

using namespace std;

void InputKeyboard2d(float **A, int n, int m);
float** SetArray2d(int n, int m);
int calculateEselonBaris(float **A, int n, int m);
void AddRow(float *A, float *B, int n, float k);
void PrintMatriks(float **A, int n, int m);
void MulRow(float *A, int n, float k);
void SwapRow(float *A, float *B, int n);
float* FindAnswerSPL(float **A, float n, float m);
int calculateEselonBarisTereduksi(float **A, int n, int m);

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

int calculateEselonBaris(float **A, int n, int m)
{
    for (int i = 0; i < m; i++)
    {
        if (A[i][i] == 0)
        {
            for (int j = i + 1; j < m; j++)
            {
                if (A[j][i] != 0)
                {
                    SwapRow(A[i], A[j], n);
                    break;
                }
            }
        }
    }
    for (int i = 0; i < m; i++)
    {
        float pembagi = A[i][i];
        

        for (int j = i + 1; j < m; j++)
        {
            float pengurang = A[j][i] / pembagi;
            AddRow(A[j], A[i], n, -pengurang);
        }
    }
    
    for (int i = 0; i < m; i++)
    {
        if (A[i][i] == 0)
        {
            if (A[i][n - 1] == 0)
            {
                return -1;
            }
            else
            {
                return -2;
            }
        }
        
    }

    return 0;
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

float* FindAnswerSPL(float **A, float n, float m)
{
    int p = n - 1; 
    float* hasil = new float[p];
    for (int i = p - 1, a = 0; i >= 0; i--, a++)
    {
        hasil[i] = A[i][p];
        for (int j = i + 1; j < p; j++)
        {
            hasil[i] = hasil[i] - (A[i][j] * hasil[j]);    
        }
        hasil[i] /= A[i][i]; 
    }
    return hasil;
}

int calculateEselonBarisTereduksi(float **A, int n, int m)
{
    int a = calculateEselonBaris(A, n, m);
    for (int i = m - 1; i > 0; i--)
    {
        float pembagi = A[i][i];
        for (int j = i - 1; j >= 0; j--)
        {
            float pengurang = A[j][i] / pembagi;
            AddRow(A[j], A[i], n, -pengurang);
        }
    }   
    return a;
}

float** inversMatriks(float **A, int n, int m)
{
    float **hasil = new float* [m];
    float **inv = new float* [m];
    for (int i = 0; i < m; i++)
    {
        hasil[i] = new float[n*2];
        inv[i] = new float[n];
        for (int j = 0; j < n; j++)
        {
            hasil[i][j] = A[i][j];
        }

        for (int j = n; j < n * 2; j++)
        {
            if (i == (j - n))
            {
                hasil[i][j] = 1;
            }
            else
            {
                hasil[i][j] = 0;
            }
            
        }
        
               
    }

    calculateEselonBarisTereduksi(hasil, n*2, m);

    

    for (int i = 0; i < m; i++)
    {
        if (hasil[i][i] != 1)
        {
            MulRow(hasil[i], n * 2, 1 / hasil[i][i]);
        }
    }
    //PrintMatriks(hasil, n * 2, m);
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            inv[i][j] = hasil[i][n + j]; 
        }
        
    }
    
    cout << endl;
    PrintMatriks(inv, n, m);
    
    return inv;
}


float Determinan(float **A, int n, int m, int *flag)
{
    if (n != m)
    {
        *flag = -1;
        return -1;
    }
    float **B = new float* [m];

    for (int i = 0; i < m; i++)
    {
        B[i] = new float [n];
        memcpy(B[i], A[i], n*(sizeof(float)));
    }
    
    
    calculateEselonBaris(B, n, m);
    
    // PrintMatriks(A, n, m);
    // cout << endl;
    // PrintMatriks(B, n, m);
    float hasil = 1;
    for (int i = 0; i < m; i++)
    {
        hasil *= B[i][i];
    }
    
    return hasil;
}

float* MetodeMatriksBalikan(float** A, int n, int m)
{
    float** B = inversMatriks(A, n - 1, m);
    float C[m];
    float* hasil = new float[m];
    //PrintMatriks(B, n, m);
    for (int i = 0; i < m; i++)
    {
        C[i] = A[i][n-1];
        hasil[i] = 0;
        //cout << A[i][n-1] << ' ' << n << endl;
    }
    
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            hasil[i] += B[i][j] * C[j];
        }
    }
    
    return hasil;
    
} 
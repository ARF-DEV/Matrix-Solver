#include <iostream>
#include <cstring>
#include <string>
#include <fstream>
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
//float **SetMatriks(int* n, int* m, int offset = 0);

float **FileArray2d(int* n, int* m)
{
    //cout << "test" << endl;
    *n = 0;
    *m = 0;
    string namafile;
    cout << "Masukan Nama File : ";
    cin >> namafile;
    float **A;
    bool firstrow = true;
    ifstream file(namafile);
    char c;
    
    do
    {
        c = file.get();
        if (c == ' ' && firstrow)
        {
            //cout << 't' << endl;
            (*n)++;
        }
        else if (c == '\n')
        {
            firstrow = false;
            (*m)++;
        }
        
        //cout << c << endl;
    } while (!file.eof());
    (*m)++;
    (*n)++;

    A = new float* [*m];
    for (int i = 0; i < *m; i++)
    {
        A[i] = new float[*n];
    }
    
    //cout << *n << ' ' <<*m << endl;
    //cout << "PPP" << endl;
    file.clear();
    file.seekg(0);
    string str = "";
    int i = 0;
    do
    {
        c = file.get();
        //cout << c << endl;
        if (c == ' ' || c == '\n')
        {
            //cout << str << endl;
            A[i / *n][i % *n] = stof(str);
            i++;
            str = "";
        }
        else
        {
            str += c;
        }
        
    } while (!file.eof());
    
    A[i / *n][i % *n] = stof(str);

    PrintMatriks(A, *n, *m);
    
    
    //TODO BUAT 2D MATRIKS NYA BELOM

    return A;


}

float **SetMatriks(int* n, int* m, int offset = 0)
{
    int p;
    float **A;
    cout << "1. Keyboard\n";
    cout << "2. File\n";
    cout << "N = ";
    cin >> p;
    if (p == 1)
    {
        cin >> *m >> *n;
        *n += offset;
        A = SetArray2d(*n, *m);
    }
    else if (p == 2)
    {
        A = FileArray2d(n, m);
    }
    return A;
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

int calculateEselonBaris(float **A, int n, int m)
{
    int p = 0;
    for (int i = 0; i < m; i++)
    {
        if (A[i][i] == 0)
        {
            for (int j = i + 1; j < m; j++)
            {
                if (A[j][i] != 0)
                {
                    SwapRow(A[i], A[j], n);
                    p++;
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

    return p;
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
            //PrintMatriks(A, n , m); 
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
    //cout << "[]" << endl;
    calculateEselonBarisTereduksi(hasil, n*2, m);

    //PrintMatriks(hasil, n * 2, m);

    for (int i = 0; i < m; i++)
    {
        if (hasil[i][i] != 1)
        {
            MulRow(hasil[i], n * 2, 1 / hasil[i][i]);
        }
    }
    
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            inv[i][j] = hasil[i][n + j]; 
        }
        
    }
    
    cout << endl;
    //PrintMatriks(inv, n, m);
    
    return inv;
}


float Determinan(float **A, int n, int m, int *flag)
{
    //cout << n << ' ' << m << endl;
    if (n != m && flag != NULL)
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
    
    
    int p = calculateEselonBaris(B, n, m);
    
    // PrintMatriks(A, n, m);
    // cout << endl;
    // PrintMatriks(B, n, m);
    float hasil = 1;
    hasil *= (p % 2 == 1) ? -1 : 1;

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
    PrintMatriks(B, n, m);
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

float** GetSubMatriks(float **A, int n, int baris, int kolom)
{
    float **B = new float* [n - 1];
    for (int i = 0; i < n - 1; i++)
    {
        B[i] = new float [n - 1];
    }
    
    int m = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == baris || j == kolom) continue;
            B[m / (n - 1)][m % (n - 1)] = A[i][j];
            m++;
        }
        
    }
    return B;
}

float EkspansiKofaktor(float **A, int n)
{
    if (n == 2)
    {
        return A[0][0] * A[1][1] - A[0][1] * A[1][0];
    }
    else
    {
        
        int Nnew = n - 1;
        float hasil = 0;
        float mul = 1;
        for (int i = 0; i < n; i++)
        {
            //cout << i << endl;
            float** B = GetSubMatriks(A, n, 0, i);
            hasil += mul * A[0][i] * EkspansiKofaktor(B, Nnew);
            //cout << i << endl;
            mul *= -1;
        }
        
        //PrintMatriks(B, n - 1, n - 1);
        return hasil;
        
        
    }
    
    
    
}

float* Cramer(float** A, int n, int m, int *flag)
{
    float **X[m]; //Array Matriks 2Dimensi
    float **P = new float* [m];
    for (int i = 0; i < m; i++)
    {
        X[i] = new float* [m];
    }
    
    float *hasil = new float [m];

    for (int j = 0; j < m; j++)
    {
        for (int i = 0; i < m; i++)
        {
            X[j][i] = new float[n - 1];
            memcpy(X[j][i], A[i], (n - 1)*sizeof(float));
            //X[j][0] = A[j][n - 1];

            // X[j][i] = new float[n - 1];
            // memcpy(X[j][i], A[i], (n - 1)*sizeof(float));
            // //Y[j][1] = A[j][n - 1];

            // X[j][i] = new float[n - 1];
            // memcpy(X[j][i], A[i], (n - 1)*sizeof(float));
            // //Z[i][2] = A[i][n - 1];

            P[i] = new float[n - 1];
            memcpy(P[i], A[i], (n - 1)*sizeof(float));
            //P[i][0] = A[i][n - 1];
        }
    }
    
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < m; j++)
        {
            X[i][j][i] = A[j][n - 1]; 
            
        }
        
        //PrintMatriks(X[i], n - 1, m);
    }
    
    float DetP = Determinan(P, n - 1, m, NULL);
    if (DetP == 0)
    {
        *flag = -1;
        return 0;
    }

    for (int i = 0; i < m; i++)
    {
        //int out;
        hasil[i] = Determinan(X[i], n - 1, m, NULL) / DetP;    
    }
    
    
    return hasil;
}

void SplGauss()
{
    int n, m;

    float **A = SetMatriks(&n, &m, 1); 

    int l = calculateEselonBaris(A, n, m);
    
    if (l == -1)
    {
        cout << "Solusi Banyak\n";
        return;
    }
    else if (l == -2)
    {
        cout << "Tidak ada Solusi\n";
    }

    float* hasil = FindAnswerSPL(A, n, m);
    
    for (int i = 0; i < m; i++)
    {
        cout << "x[" << i + 1 << "] = " << hasil[i] << endl; 
    }
}
void SplGaussJordan()
{
    int n, m;
    //cin >> m >> n;

    float **A = SetMatriks(&n, &m, 1); 

    int l = calculateEselonBarisTereduksi(A, n, m);
    
    if (l == -1)
    {
        cout << "Solusi Banyak\n";
        return;
    }
    else if (l == -2)
    {
        cout << "Tidak ada Solusi\n";
    }

    float* hasil = FindAnswerSPL(A, n, m);
    
    for (int i = 0; i < m; i++)
    {
        cout << "x[" << i + 1 << "] = " << hasil[i] << endl; 
    }
}
void SplMatriksBalikan()
{
    int n, m;
    // cin >> m >> n;
    
    // float **A = SetArray2d(n + 1, m);
    float **A = SetMatriks(&n, &m, 1);
    
    //PrintMatriks(A, n, m);
    int out;
    float det = Determinan(A, n - 1, m, &out);

    if (out == -1)
    {
        cout << "ERROR : det = 0\n";
        return;
    }
    float *hasil = MetodeMatriksBalikan(A, n, m);
    for (int i = 0; i < m; i++)
    {
        cout << "x[" << i + 1 << "] = " << hasil[i] << endl; 
    }
}
void Invers()
{
    int n, m;
    

    float **A = SetMatriks(&n, &m);

    float **B = inversMatriks(A, n, m);
    cout << "invers :" << endl;
    PrintMatriks(B, n, m);
}
void DetReduksiBaris()
{
    int n, m;
    
    float **A = SetMatriks(&n, &m);
    //PrintMatriks(A, n, m);
    int flag = 0;
    float P = Determinan(A, n, m, &flag);

    if (flag == -1)
    {
        cout << "Determinan harus berupa matriks N x N" << endl;
        return;
    }
    cout <<"Det = "<< P << endl;
}
void DetEkspansiKofaktor()
{
    int n, m;
    //cin >> m >> n;
    float **A = SetMatriks(&n, &m);
    if (n != m)
    {
        cout << "ERROR : Matriks Harus Matriks NxN" << endl;
    }
    
    // cin >> baris >> kolom;
    float b = EkspansiKofaktor(A, n);

    cout <<"Det = "<< b << endl;
}
void SplCramer()
{
    int n, m;
    //cin >> m >> n;
    int out;
    float **A = SetMatriks(&n, &m, 1);
    float *hasil = Cramer(A, n, m, &out);
    if (out == -1)
    {
        cout << "ERROR : Solusi Tidak dapat ditemukan (Det == 0)" << endl;
        return;
    }
    for (int i = 0; i < m; i++)
    {
        cout << "x[" << i + 1 << "] = " << hasil[i] << endl; 
    }
}


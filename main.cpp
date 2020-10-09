#include <iostream>


using namespace std;


void InputKeyboard2d(int **A, int n, int m)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> A[i][j];
        }
    }   
}

int** SetArray2d(int n, int m)
{
    int **arr = new int* [m];
    for (int i = 0; i < m; i++)
    {
        arr[i] = new int[n];
    }

    //TODO FILE ATO KEYBOARD
    InputKeyboard2d(arr, n, m);   
    
    return arr;
}


int main()
{
    // INI CUMA TEST IMPLEMENTASI FUNGSI
    int n, m;
    cin >> n >> m;
    // n + 1 karena n itu jumlah variable dan hasil dari persamaan blom masuk
    int **A = SetArray2d(n + 1, m); 

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << A[i][j] << ' ';
        }
        cout << endl;
    }
    
    
    
    
    
}
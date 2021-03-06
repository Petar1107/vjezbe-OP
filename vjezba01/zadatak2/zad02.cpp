/*. Definirati strukturu koja opisuje matricu. Napisati program za osnovne
operacije s matricama čiji su elementi decimalni brojevi (float). Program
treba imati sljedeće funkcije:
• funkciju za unos matrice mxn,
• funkciju za generiranje matrice mxn s elementima u rasponu [a,b],
• funkcije za zbarajanje, oduzimanje, množenje matrica,
• funkciju za trasponiranje matrice,
• funkciju za ispisivanje matrice. Elementi matrice se ispisuju na četiri
decimale, poravnati udesno*/

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

struct matrix
{
    int m;
    int n;
    float a;
    float b;
    float **mat_i_j;
};
void input(matrix* arr, int z)
{
    cout << "Enter m and n:" << endl;
    cin >> arr[z].m;
    cin >> arr[z].n;
    cout << "Enter a and b:" << endl;
    cin >> arr[z].a;
    cin >> arr[z].b;
    cout << endl;
}

void generating(matrix* arr, int z)
{
    float member;
    if(z==5 || z==6)
    {
        arr[z].mat_i_j = new float*[arr[z-5].n];

        for (int counter = 0; counter < arr[z-5].n; counter++)
        {
            arr[z].mat_i_j[counter] = new float[arr[counter].m];
        }
    }
    if(z==3)
    {
        arr[z].mat_i_j = new float*[arr[0].m];

        for (int counter = 0; counter < arr[1].n; counter++)
        {
            arr[z].mat_i_j[counter] = new float[arr[counter].n];
        }
    }

    if(z==2 || z==4)
    {
        arr[z].mat_i_j = new float*[arr[0].m];

        for (int counter = 0; counter < arr[0].m; counter++)
        {
            arr[z].mat_i_j[counter] = new float[arr[counter].n];
        }
    }

    if(z<2)
    {
        arr[z].mat_i_j = new float*[arr[z].m];

        for (int counter = 0; counter < arr[z].m; counter++)
        {
            arr[z].mat_i_j[counter] = new float[arr[counter].n];
        }
        srand(time(NULL));

        for (int i = 0; i < arr[z].m; i++)
        {
            for (int j = 0; j < arr[z].n; j++)
            {
                member =  (arr[z].b - arr[z].a) * ((((float) rand()) / (float) RAND_MAX)) + arr[z].a ;;
                arr[z].mat_i_j[i][j] = member;
            }
        }
        cout << endl;
    }
}

void addition(matrix* arr)
{
    if((arr[0].m == arr[1].m) && (arr[0].n == arr[1].n))
    {
        for(int i = 0; i < arr[1].m; ++i)
            for(int j = 0; j < arr[1].n; ++j)
            {
                 arr[2].mat_i_j[i][j] = arr[0].mat_i_j[i][j] + arr[1].mat_i_j[i][j];
            }
    }
    else
        cout<<"The matrixes are not compatable for addition"<<endl<<endl;
}

void subtraction(matrix* arr)
{
    if((arr[0].m == arr[1].m) && (arr[0].n == arr[1].n))
    {
        for(int i = 0; i < arr[1].m; ++i)
            for(int j = 0; j < arr[1].n; ++j)
            {
                 arr[4].mat_i_j[i][j] = arr[0].mat_i_j[i][j] - arr[1].mat_i_j[i][j];
            }
    }
    else
        cout<<"The matrixes are not compatable for subtraction"<<endl<<endl;
}

void multiplication(matrix* arr)
{
    if(arr[0].n == arr[1].m)
    {
        for(int i = 0; i < arr[0].m; ++i)
            for(int j = 0; j < arr[1].n; ++j)
            {
                arr[3].mat_i_j[i][j]=0;
            }

        for(int i = 0; i < arr[0].m; ++i)
            for(int j = 0; j < arr[1].n; ++j)
            {
                for(int k = 0; k < arr[0].n; ++k)
                {
                    arr[3].mat_i_j[i][j] += arr[0].mat_i_j[i][k] * arr[1].mat_i_j[k][j];
                }
            }
    }
    else
        cout<<"The matrixes are not compatable for multiplication"<<endl<<endl;
}

void transponed_matrix(matrix* arr, int trans)
{
    for (int i = 0; i < arr[trans].m; ++i)
        for (int j = 0; j < arr[trans].n; ++j)
        {
            arr[5+trans].mat_i_j[j][i] = arr[trans].mat_i_j[i][j];
        }
}

void output(matrix* arr)
{
    for(int z=0; z<2; z++)
    {
        cout<<z+1<<". Matrix: "<<endl;
        for (int i = 0; i < arr[z].m; i++)
        {
            for (int j = 0; j < arr[z].n; j++)
            {
                cout << arr[z].mat_i_j[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    if((arr[0].m == arr[1].m) && (arr[0].n == arr[1].n))
    {
        cout << endl << "Sum of the matrixes is: " << endl;
        for(int i = 0; i < arr[0].m; ++i)
            for(int j = 0; j < arr[0].n; ++j)
            {
                cout << arr[2].mat_i_j[i][j] << "  ";
                if(j == arr[0].n - 1)
                    cout << endl;
            }
        cout << endl;

        cout << endl << "Difference of the matrixes is: " << endl;
        for(int i = 0; i < arr[0].m; ++i)
            for(int j = 0; j < arr[0].n; ++j)
            {
                cout << arr[4].mat_i_j[i][j] << "  ";
                if(j == arr[0].n - 1)
                    cout << endl;
            }
        cout << endl;
    }
    if(arr[0].n == arr[1].m)
    {
        cout<<"Product of the matrixes is:"<<endl;
        for(int i=0;i<arr[0].m;i++)
        {
            for(int j=0;j<arr[1].n;j++)
            {
                cout<<arr[3].mat_i_j[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
    }


    for(int trans=0; trans<2; trans++)
    {
        cout << "Transpose of the "<<trans+1<<". Matrix is:" << endl;
        for (int i = 0; i < arr[trans].n; ++i)
            for (int j = 0; j < arr[trans].m; ++j)
            {
                cout << " " << arr[5+trans].mat_i_j[i][j];
                if (j == arr[trans].m - 1)
                cout << endl << endl;
            }
    }

}

void free_memory(matrix* arr)
{
    delete arr;
}

int main(void)
{
    int number_or_matrixes = 7;
    matrix* arr = new matrix[7];

    for(int z=0; z<number_or_matrixes; z++)
    {
        if(z<2)
        {
            input(arr, z);
        }
        generating(arr, z);
    }
    addition(arr);
    subtraction(arr);
    multiplication(arr);

    for(int trans=0; trans<2; trans++)
        transponed_matrix(arr, trans);

    output(arr);
    free_memory(arr);
    return 0;
}

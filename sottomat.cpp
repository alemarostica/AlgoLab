/*
Basato su idea di Marostica Alessandro
Perfezionato da Cappellato Ludovico e Zanibellato Giovanni
 */

#include <fstream>
using namespace std;

int max(int a, int b)
{
    if (a > b)
    {
        return a;
    }
    return b;
}

int sottoSomma(int matrix[][2000], int row, int col)
{
    int sommeParziali[(col * (col + 1)) / 2];
    int sommeMassime[(col * (col + 1)) / 2];
    // inizializzo l'array
    for (int i = 0; i < (col * (col + 1)) / 2; i++)
    {
        sommeParziali[i] = 0;
        sommeMassime[i] = 0;
    }
    for (int i = 0; i < row; i++)
    {
        int count = 0;
        for (int j = 0; j < col; j++)
        {
            int prev = 0;
            for (int k = j; k < col; k++)
            {
                prev += matrix[i][k];
                sommeParziali[count] = max(sommeParziali[count] + prev, 0);
                sommeMassime[count] = max(sommeParziali[count], sommeMassime[count]);
                count++;
            }
        }
    }
    int massimo = 0;
    for (int i = 0; i < (col * (col + 1)) / 2; i++)
    {
        massimo = max(massimo, sommeMassime[i]);
    }
    return massimo;
}

int main()
{
    ifstream input("input.txt");
    int col, row;
    input >> row >> col;
    int matrix[row][2000];
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            input >> matrix[i][j];
        }
    }
    input.close();
    ofstream output("output.txt");
    output << sottoSomma(matrix, row, col);
    output.close();
    return 0;
}

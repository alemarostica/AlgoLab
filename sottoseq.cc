#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

int maxSeq(int *, int&);

int main(int argc, char **argv)
{
    ifstream input("input.txt");

    int dim;
    input >> dim;

    int *array = new int[dim];

    for (int i = 0; !input.eof() && i < dim; i++)
    {
        input >> array[i];
    }

    int somma = maxSeq(array, dim);

    ofstream output("output.txt");
    output << somma << "\n";

    input.close();
    output.close();

    delete[] array;

    return 0;
}

int maxSeq(int *array, int & dim)
{
    int maxSoFar = 0;
    int maxHere = 0;
    for (int i = 0; i < dim; i++)
    {
        maxHere = max(maxHere + array[i], 0);
        maxSoFar = max(maxSoFar, maxHere);
    }
    return maxSoFar;
}

// #include "tsp.h"

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string tsp(int **grafo, int N)
{
    bool visited[N] = {false};
    visited[0] = true;
    bool changed;
    string result = "0";
    int node = 0;
    do
    {
        int minimo = 1001, index;
        changed = false;

        //cout << "index before: " << index << endl;

        for (int i = 0; i < N; i++)
        {
            if (!visited[i] && grafo[i][node] < minimo)
            {
                index = i;
                minimo = grafo[i][node];
                changed = true;
            }
        }

        // cout << "index: " << index << endl;
        // cout << "minimo: " << minimo << endl;

        node = index;
        visited[index] = true;
        if (changed)
        {
            result.append(" ");
            result.append(to_string(index));
        }
    } while (changed);
    return (result.append(" 0#"));
}

int main(void)
{
    ifstream input("input.txt");

    int N, tmp;

    input >> N;

    int **grafo = new int *[N];

    for (int i = 0; i < N; i++)
    {
        grafo[i] = new int[N];
        for (int j = 0; j <= i; j++)
        {
            if (i == j)
            {
                grafo[i][j] = 1001;
            }
            else
            {
                input >> tmp;
                grafo[i][j] = tmp;
                grafo[j][i] = tmp;
            }
        }
    }
    input.close();
    ofstream output("output.txt");

    // for (int i = 0; i < N; i++)
    // {
    //     for (int j = 0; j < N; j++)
    //     {
    //         cout << grafo[i][j] << "\t";
    //     }
    //     cout << endl;
    // }

    string res = tsp(grafo, N);

    output << res;

    output.close();

    return EXIT_SUCCESS;
}
#include "tsp.h"

#include <fstream>
#include <string>

using namespace std;

int tsp(int **grafo, int* percorso, int N, int start)
{
    bool visited[N]; //= {false};
    for(int i=0; i<N; i++){
        visited[i] = false;
    }
    visited[start] = true;
    percorso[0] = start;
    int node = start, costo = 0;
    for(int i = 1; i < N; i++)
    {
        int index = 0, mini = 10001;
        for (int j = 0; j < N; j++) //trovo vicino non visitato con peso minore
        {
            if (!visited[j] && grafo[j][node] < mini)
            {
                index = j;
                mini = grafo[j][node];
            }
        }
        costo += mini;
        node = index;
        visited[index] = true;
        percorso[i] = index;
    }
    percorso[N] = start;
    costo += grafo[percorso[N-1]][start];
    return costo;
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
    int percorso[N+1];
    int min = 10001;
    for(int i=0; i<N; i++){
        int tmp = tsp(grafo, percorso, N, i);
        if(tmp < min){
            min = tmp;
            output << percorso[0];
            for(int i=1; i<=N; i++){
                output << " " << percorso[i];
            }
            output << "#" << endl;
        }
    }

    output.close();

    return EXIT_SUCCESS;
}
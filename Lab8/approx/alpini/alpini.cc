#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <vector>
#include <queue>

using namespace std;

typedef vector<nodo> graph;

struct nodo
{
    vector<int> vicini;
    bool visited = false;
};

void alpini(graph &grafo, vector<int> incrociAperti)
{
    incrociAperti.push_back(0);
    queue<int> coda;
    coda.push(0);
    grafo[0].visited = true;
    while (!coda.empty())
    {
        int index = coda.front();
        coda.pop();
        for (int n : grafo[index].vicini)
        {
            bool idoneo = true;
            for (int i = 0; i < grafo[n].vicini.size() && idoneo; i++)
            {
                idoneo = idoneo && (!grafo[grafo[n].vicini[i]].visited || grafo[n].vicini[i] == index);
            }
            if (idoneo)
            {
                grafo[n].visited = true;
                coda.push(n);
            }
        }
    }
}

int main(void)
{

    ifstream input("input.txt");
    ofstream output("output.txt");

    int ni, ns, from, to;

    input >> ni >> ns;

    graph grafo;
    grafo.resize(ni);
    for (int i = 0; i < ns; i++)
    {
        input >> from >> to;
        grafo[from].vicini.push_back(to);
        grafo[to].vicini.push_back(from);
    }

    input.close();
    //alpini(grafo, solNegata)
    output.close();

    return EXIT_SUCCESS;
}
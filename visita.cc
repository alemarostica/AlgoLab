#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>

using namespace std;

struct nodo{
    vector<int> vicini;
    bool visited = false;
};

void conta(vector<nodo>& grafo, nodo& part, int & n){
    if(!part.visited){
        n++;
        part.visited = true;
        for(int i : part.vicini){
            conta(grafo, grafo[i], n);
        }
    }
}

int main(void){
    fstream input, output;
    input.open("input.txt", ios::in);
    output.open("output.txt", ios::out);

    int n, m, s;
    input >> n >> m >> s;

    vector<nodo> grafo;
    int start, dest;
    grafo.resize(n);

    for(int i = 0; i < m; i++){
        input >> start >> dest;
        grafo[start].vicini.push_back(dest);
    }

    int howmany = 0;

    conta(grafo, grafo[s], howmany);

    output << howmany;

    input.close();
    output.close();
}   
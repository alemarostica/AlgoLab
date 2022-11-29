#include <fstream>
#include <vector>
#include <queue>
using namespace std;

const int INFINITO = 10001;

struct nodo{
    vector<int> vicini;
    int distanza = INFINITO;
    int cammini = 0;
};
int max(int a, int b){
    if(a > b){
        return a;
    }
    return b;
}
int* componentiFConnesse(vector<nodo>& g, int start){
   // Algoritmo di Kosaraju
}
int main(){
    vector<nodo> grafo;
    ifstream input("input.txt");
    int N, M;
    input >> N >> M;
    grafo.resize(N);
    for(int i=0;i<M;i++){
        int from, to;
        input >> from >> to;
        grafo[from].vicini.push_back(to);
    }
    input.close();
    ofstream output("output.txt");
    
    output.close();
}
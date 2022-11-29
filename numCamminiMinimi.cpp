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
void camminoMinimo(vector<nodo>& grafo, int start){
    queue<int> coda; //meglio usare una queue di int, altrimenti passa per copia di ogni node che si aggiunge
    grafo[start].distanza = 0;
    grafo[start].cammini = 1;
    coda.push(start);
    while(!coda.empty()){
        int n = coda.front();
        coda.pop();
        for(int i : grafo[n].vicini){
            if(grafo[i].distanza > grafo[n].distanza+1){
                grafo[i].distanza = grafo[n].distanza+1;
                grafo[i].cammini = grafo[n].cammini;
                coda.push(i);
            }else if(grafo[i].distanza == grafo[n].distanza+1){
                grafo[i].cammini += grafo[n].cammini;
            }
        }
    }
}
int main(){
    vector<nodo> grafo;
    ifstream input("input.txt");
    int N, M, S, T;
    input >> N >> M >> S >> T;
    grafo.resize(N);
    for(int i=0;i<M;i++){
        int from, to;
        input >> from >> to;
        grafo[from].vicini.push_back(to);
    }
    input.close();
    ofstream output("output.txt");
    camminoMinimo(grafo, S);
    output << grafo[T].distanza << " " << grafo[T].cammini;
    output.close();
}
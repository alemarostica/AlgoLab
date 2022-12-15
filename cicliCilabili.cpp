#include <fstream>
#include <vector>
#include <queue>
using namespace std;

struct nodo{
    vector<int> vicini;
};

typedef vector<nodo> graph;

int minDistance(graph& g, int start, int end){
    int marker[g.size()];
    for(int i=0; i< g.size(); i++){
        marker[i] = -1;
    }
    queue<int> coda;
    coda.push(start);
    marker[start] = 0;
    while(!coda.empty()){//non dovrebbe mai verificarsi
        int n = coda.front();
        coda.pop();
        for(int index : g[n].vicini){
            if(index == end){
                return marker[n] + 1;
            }else if(marker[index]==-1){
                coda.push(index);
                marker[index] = marker[n] + 1;
            }
        }
    }
    return -1;
}

int main(){
    graph grafo;
    ifstream input("input.txt");
    int N, M, Q;
    input >> N >> M >> Q;
    grafo.resize(N);
    for(int i=0;i<M;i++){
        int from, to;
        input >> from >> to;
        grafo[from].vicini.push_back(to);
        grafo[to].vicini.push_back(from);
    }
    ofstream output("output.txt");
    for(int i=0;i<Q;i++){
        int start, end;
        input >> start >> end;
        output << minDistance(grafo, start, end) << endl;
    }
    input.close();
    output.close();
}
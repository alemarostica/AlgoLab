#include <fstream>
#include <vector>
#include <queue>
using namespace std;

struct nodo{
    vector<int> vicini;
    int distanza = 10001;
};
int max(int a, int b){
    if(a > b){
        return a;
    }
    return b;
}
void camminoMinimo(vector<nodo>& grafo, nodo& node){
    queue<nodo> coda;
    node.distanza = 0;
    coda.push(node);
    while(!coda.empty()){
        nodo n = coda.front();
        coda.pop();
        for(int i : n.vicini){
            if(grafo[i].distanza > n.distanza+1){
                grafo[i].distanza = n.distanza+1;
                coda.push(grafo[i]);
            }
        }
    }
}
int maxCamminoMinimo(vector<nodo> grafo, int index){
    camminoMinimo(grafo, grafo[index]);
    int res = 0;
    for(nodo n : grafo){
        if(n.distanza < 10001)
        res = max(res, n.distanza);
    }
    return res;
}
int diametro(vector<nodo>& grafo){
    int res = 0;
    for(int i=0; i<grafo.size()-1; i++){
        res = max(res, maxCamminoMinimo(grafo, i));
    }
    return res;
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
        grafo[to].vicini.push_back(from);
    }
    input.close();
    ofstream output("output.txt");
    output << diametro(grafo);
    output.close();
}
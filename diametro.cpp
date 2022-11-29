/* 
Idea di funzionamento: uso l'algoritmo di calcolo dei cammini minimi da un nodo agli altri (Erdos) e lo applico a tutti
i nodi (tranne l'ultimo che tanto è già stato considerato calcolando i cammini minimi da tutti gli altri). Applico quindi cammino minimo
ad un nodo, scorro nel grafo e prendo il nodo con valore di distanza più grande (non considerando infinito) che mi rappresenta il nodo più
distante da quello. Prendo il massimo tra tutti quelli trovati nel punto precedente e ho la massima distanza assoluta tra due nodi (diametro)
*/
#include <fstream>
#include <vector>
#include <queue>
using namespace std;

const int INFINITO = 10001;

struct nodo{
    vector<int> vicini;
    int distanza = INFINITO;
};
int max(int a, int b){
    if(a > b){
        return a;
    }
    return b;
}
void camminoMinimo(vector<nodo>& grafo, int index){
    queue<int> coda; //meglio usare una queue di int, altrimenti passa per copia di ogni node che si aggiunge
    grafo[index].distanza = 0;
    coda.push(index);
    while(!coda.empty()){
        int n = coda.front();
        coda.pop();
        for(int i : grafo[n].vicini){
            if(grafo[i].distanza > grafo[n].distanza+1){
                grafo[i].distanza = grafo[n].distanza+1;
                coda.push(i);
            }
        }
    }
}
int maxCamminoMinimo(vector<nodo>& grafo, int index){
    camminoMinimo(grafo, index);
    int res = 0;
    for(nodo& n : grafo){ //fare per references altrimenti fa per copia
        if(n.distanza < INFINITO){ //per evitare di calcolare componenti isolate
            res = max(res, n.distanza);
            n.distanza = INFINITO;
        }
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
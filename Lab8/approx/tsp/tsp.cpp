#include "tsp.h"

#include <fstream>
#include <string>

using namespace std;

ofstream output("output.txt");
int mini = 50001;
int costo = 0;
int livello;
int N;
int arcoMin = 1001;

int partition(int*** arr, int start, int end, int row)
{
 
    int pivot = arr[0][row][start];
 
    int count = 0;
    for (int i = start + 1; i <= end; i++) {
        if (arr[0][row][i] <= pivot)
            count++;
    }
 
    // Giving pivot element its correct position
    int pivotIndex = start + count;
    swap(arr[0][row][pivotIndex], arr[0][row][start]);
    swap(arr[1][row][pivotIndex], arr[1][row][start]);
    // Sorting left and right parts of the pivot element
    int i = start, j = end;
 
    while (i < pivotIndex && j > pivotIndex) {
 
        while (arr[0][row][i] <= pivot) {
            i++;
        }
 
        while (arr[0][row][j] > pivot) {
            j--;
        }
 
        if (i < pivotIndex && j > pivotIndex) {
            swap(arr[0][row][i], arr[0][row][j]);
            swap(arr[1][row][i++], arr[1][row][j--]);
        }
    }
 
    return pivotIndex;
}
 
void quickSort(int*** arr, int start, int end, int row)
{
    // base case
    if (start >= end)
        return;
 
    // partitioning the array
    int p = partition(arr, start, end, row);
 
    // Sorting the left part
    quickSort(arr, start, p - 1, row);
 
    // Sorting the right part
    quickSort(arr, p + 1, end, row);
}

void printPath(int* percorso){
    for(int i=0; i<N; i++){
        output << percorso[i] << " ";
    }
    output << percorso[0] << "#" << endl;
}

void tsp(int ***grafo, int* percorso, bool* visited, int start){
    percorso[N-livello-1] = start;
    if(livello == 0){
        int i=0;
        for(i=0; grafo[1][start][i] != percorso[0]; i++);
        if(costo + grafo[0][start][i] < mini){
            printPath(percorso);
            mini = costo + grafo[0][start][i];
        }
        return;
    }
    visited[start] = true;
    for(int i=0; i<N-1 && costo + grafo[0][start][i] + (livello*arcoMin) < mini; i++){
        if(!visited[grafo[1][start][i]]){
            costo += grafo[0][start][i];
            livello--;
            tsp(grafo, percorso, visited, grafo[1][start][i]);
            livello++;
            costo -= grafo[0][start][i];
        }
    }
    visited[start] = false;
}

int main(void)
{
    ifstream input("input.txt");

    int tmp;

    input >> N;

    livello = N-1;

    int ***grafo = new int **[2];
    grafo[0] = new int *[N];
    grafo[1] = new int *[N];
/* Aggiungo una terza dim in cui spefico l'indice della riga, ordino ogni riga dall'arco più leggero al più pesante
   mantenendo la coppia peso-indice in modo da risalire a quale arco si riferisce. Poi visito gli archi in ordine
   crescente (prima scelta greey e poi esploro). Appena trovo un arco che eccede escludo tutti quelli dopo*/
    for (int i = 0; i < N; i++)
    {
        grafo[0][i] = new int[N];
        grafo[1][i] = new int[N];
        for (int j = 0; j <= i; j++)
        {
            grafo[1][i][j] = j;
            grafo[1][j][i] = i;
            if (i == j)
            {
                grafo[0][i][j] = 1001;
            }
            else
            {
                input >> tmp;
                arcoMin = min(arcoMin, tmp);
                grafo[0][i][j] = tmp;
                grafo[0][j][i] = tmp;
            }
        }
    }
    input.close();

    /*for (int i = 0; i < N; i++)
     {
         for (int j = 0; j < N; j++)
         {
             cout << grafo[0][i][j] << "\t";
         }
         cout << endl;
     }*/
    int percorso[N];
    bool visited[N]; //= {false};
    for(int i=0; i<N; i++){
        quickSort(grafo, 0, N-1, i);
        visited[i] = false;
    }
    tsp(grafo, percorso, visited, 0);
    output.close();

    return EXIT_SUCCESS;
}
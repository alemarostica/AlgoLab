#include <fstream>
#include <iostream>
using namespace std;

void swap(int array[], int i, int j){
    int tmp = array[i];
    array[i] = array[j];
    array[j] = tmp;
}

int countSort(int array[], int dim, int& prezzo){
    int count = 0;
    prezzo = 0;
    int j=0;
    while(dim-j > 1){
        int i=dim-1-j;
        while(array[i] != dim-j){
            i--;
        }
        if(i+1 != dim-j){
            swap(array, i, dim-j-1);
            prezzo += array[i] + array[dim-j-1];
            count++;
        }
        j++;
    }
    return count;
}

int main(){
    ifstream input("input.txt");
    int buffer;
    input >> buffer;
    int array[buffer];
    for(int i=0; i<buffer; i++){
        input >> array[i];
    }
    input.close();
    ofstream output("output.txt");
    int prezzo = 0;
    output << countSort(array, buffer, prezzo) << " " << prezzo;
    output.close();
}
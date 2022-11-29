#include <fstream>
using namespace std;

void merge(int array[], int startPos, int middlePos, int endPos){
    int dim = endPos-startPos+1;
    int tmp[dim];
    int i1=startPos, i2=middlePos+1;
    for(int i=0; i<dim; i++){
        if((array[i1] > array[i2] && i2<=endPos) || i1>middlePos){
            tmp[i] = array[i2++];
        }else{
            tmp[i] = array[i1++];
        }
    }
    for(int i=0; i<dim; i++){
        array[i+startPos] = tmp[i];
    }
}

void sort(int array[], int startPos, int endPos){
    if(endPos > startPos){
        int center = (startPos + endPos)/2;
        sort(array, startPos, center);
        sort(array, center+1, endPos);
        merge(array, startPos, center, endPos);
    }
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
    sort(array, 0, buffer-1);
    ofstream output("output.txt");
    for(int i=0; i<buffer; i++){
        output << array[i] << " ";
    }
    output.close();
}
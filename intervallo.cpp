#include <fstream>
using namespace std;
struct Intervallo{
    int min;
    int max;
};

int max(int a, int b){
    if(b > a){
        return b;
    }
    return a;
}

void merge(Intervallo array[], int startPos, int middlePos, int endPos){
    int dim = endPos-startPos+1;
    Intervallo tmp[dim];
    int i1=startPos, i2=middlePos+1;
    for(int i=0; i<dim; i++){
        if((array[i1].min > array[i2].min && i2<=endPos) || i1>middlePos){
            tmp[i] = array[i2++];
        }else{
            tmp[i] = array[i1++];
        }
    }
    for(int i=0; i<dim; i++){
        array[i+startPos] = tmp[i];
    }
}

void sortMin(Intervallo array[], int startPos, int endPos){
    if(endPos > startPos){
        int center = (startPos + endPos)/2;
        sortMin(array, startPos, center);
        sortMin(array, center+1, endPos);
        merge(array, startPos, center, endPos);
    }
}

bool max_gap(Intervallo array[], int dim, int& start, int& end){
    int max_gap = 0;
    for(int i=0; i<dim-1; i++){
        if(array[i].max >= array[i+1].min){
            array[i+1].max = max(array[i+1].max, array[i].max);
        }else if(max_gap < max(max_gap, array[i+1].min - array[i].max)){
            max_gap = max(max_gap, array[i+1].min - array[i].max);
            start = array[i].max;
            end = array[i+1].min;
        }
    }
    return max_gap != 0;
}

int main(){
    ifstream input("input.txt");
    int buffer;
    input >> buffer;
    Intervallo array[buffer];
    for(int i=0; i<buffer*2; i++){
        input >> array[i].min;
        input >> array[i].max;
    }
    input.close();
    sortMin(array, 0, buffer-1);
    ofstream output("output.txt");
    int start = 0, end = 0;
    if(max_gap(array, buffer, start, end)){
        output << start << " " << end << endl;
    }else{
        output << 0 << endl;
    }
    output.close();
}
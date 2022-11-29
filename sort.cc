//InsertionSort for fun
#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

bool isOrdered(int * array, int l){
    for(int i = 1; i < l; i++){
        if(array[i] < array[i - 1]) return false;
    }
    return true;
}

void print(int * array, int l){
    for(int i = 0; i < l; i++){
        cout << array[i] << "\t";
    }
    cout << endl;
}

void swap(int& a, int& b){
    int tmp = a;
    a = b;
    b = tmp;
}

void sort(int *& array, int l){
    int c, j;

    for(int i = 1; i < l; i++){
        c = array[i];
        j = i - 1;

        while(j >= 0 && array[j] > c){
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = c;
    }
}

int main(int argc, char ** argv){

    srand(time(NULL));
    fstream input, output;
    input.open("input.txt", ios::in);
    output.open("output.txt", ios::out);

    int l;
    input >> l;

    int * array = new int[l];

    for(int i = 0; !input.eof(); i++){
        input >> array[i];
    }

    print(array, l);

    sort(array, l);

    print(array, l);

    for(int i = 0; i < l; i++){
        output << array[i] << " ";
    }

    delete[] array;
    input.close();
    output.close();

    return EXIT_SUCCESS;
}
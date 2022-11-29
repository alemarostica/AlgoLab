#include <fstream>

using namespace std;

int main(int argc, char ** argv){
    ifstream input ("input.txt");

    int n, m;
    input >> n >> m;
    n += m;

    ofstream output ("output.txt");
    output << n << "\n";

    return 0;
}
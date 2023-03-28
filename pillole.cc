#include <iostream>
#include <fstream>
#include <vector>
 
using namespace std;
 
long long int pills(int);
long long int pillsRec(int, int, vector<vector<long long int>> &);
 
int main(){
    ifstream f("input.txt");
    ofstream g("output.txt");
    int n;
 
    f >> n;
    f.close();
 
    g << pills(n);
    g.close();
}
 
long long int pills(int n){
    vector<vector<long long int>> dp(n+1, vector<long long int>(n+1, -1));
    for(int i=0; i<n; i++)
        dp[0][i] = 1;
    return pillsRec(n, 0, dp);
}
 
long long int pillsRec(int full, int half, vector<vector<long long int>> &DP){
    if(DP[full][half] == -1)
        DP[full][half] = 
        (full==0 ? 0 : pillsRec(full-1, half+1, DP)) + 
        (half==0 ? 0 : pillsRec(full, half-1, DP));
    return DP[full][half];
}

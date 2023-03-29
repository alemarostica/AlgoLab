#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> adj; // vettore delle adiacenze
vector<int> visited;     // vettore di visitati
vector<int> dp;          // vettore di programmazione dinamica
vector<int> answer;      // vettore che conterrà la soluzione

void dfs(int v)
{
    visited[v] = 1;
    dp[v] = 0;
    for (int i = 0; i < adj[v].size(); ++i)
    {
        int to = adj[v][i];
        if (!visited[to])
        {
            dfs(to);
            dp[v] += dp[to] + 1;
        }
    }
}

void build_answer(int v, int parent, int parent_val)
{
    visited[v] = 1;
    if (parent_val == 0 && dp[v] == 0)
    {
        answer.push_back(v);
        return;
    }
    for (int i = 0; i < adj[v].size(); ++i)
    {
        int to = adj[v][i];
        if (to != parent)
        {
            build_answer(to, v, parent_val - dp[to] - 1);
            if (dp[to] == 0 && parent_val - dp[to] - 1 > 0)
            {
                answer.push_back(to);
                parent_val = parent_val - 1;
            }
        }
    }
}

int main()
{
    int n;
    cin >> n;
    adj.resize(n);
    visited.resize(n);
    dp.resize(n);
    for (int i = 0; i < n - 1; ++i)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(0);
    visited.assign(n, 0);
    build_answer(0, -1, dp[0]);
    sort(answer.begin(), answer.end());
    cout << answer.size() << endl;
    return 0;
}
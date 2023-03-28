#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <cstring>

using namespace std;

int lcs(string, string);

int main(void)
{
    ifstream input("input.txt");
    ofstream output("output.txt");

    string str1, str2;

    input >> str1 >> str2;

    output << lcs(str1, str2);

    input.close();
    output.close();

    return EXIT_SUCCESS;
}

int lcs(string str1, string str2)
{
    int DP[str1.size()][str2.size()] = {};

    DP[0][0] = str1[0] == str2[0];

    for (int i = 1; i < str1.size(); i++)
    {
        DP[i][0] = max(DP[i - 1][0], (int)(str1[i] == str2[0]));
    }

    for (int i = 1; i < str2.size(); i++)
    {
        DP[0][i] = max(DP[0][i - 1], (int)(str1[0] == str2[i]));
    }

    for (int i = 1; i < str1.size(); i++)
    {
        for (int j = 1; j < str2.size(); j++)
        {
            if (str1[i] == str2[j])
            {
                DP[i][j] = DP[i - 1][j - 1] + 1;
            }
            else
            {
                DP[i][j] = max(DP[i - 1][j], DP[i][j - 1]);
            }
        }
    }

    // for (int i = 0; i <= str1.size(); i++)
    // {
    //     for (int j = 0; j <= str2.size(); j++)
    //     {
    //         cout << DP[i][j] << "\t";
    //     }
    //     cout << "\n";
    // }

    return DP[str1.size() - 1][str2.size() - 1];
}
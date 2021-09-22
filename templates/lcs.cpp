#include <bits/stdc++.h>
using namespace std;

#define big long long

big lcs(string &s1, string &s2)
{
    big l1 = s1.length();
    big l2 = s2.length();

    vector<vector<big>> dp(l1 + 1, vector<big>(l2 + 1, 0));

    for (big i = 1; i <= l1; i++)
    {
        for (big j = 1; j <= l2; j++)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    return dp[l1][l2];
}
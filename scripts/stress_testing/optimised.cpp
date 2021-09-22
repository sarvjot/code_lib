#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define big long long

#ifndef ONLINE_JUDGE
#define ds(statement) cerr << statement << endl
#define dv(var) cerr << (#var) << ": " << var << endl
#else
#define ds(statement)
#define dv(var)
#endif

const big MOD = 1e9 + 7;
const big INF = INT64_MAX;

big add_mod(big a, big b)
{
    return (a % MOD + b % MOD) % MOD;
}

big mult_mod(big a, big b)
{
    return ((long long)a % MOD * b % MOD) % MOD;
}

big solve()
{
    big n, res = 0;
    string s, nw;

    cin >> n >> s;

    for (big i = 0; i < n; i++)
    {
        if (s[i] == '.')
        {
            nw += nw;
        }
        else
        {
            nw += s[i];
        }
    }

    n = nw.length();
    s = nw;

    char prev = '0';
    big prev_i = -1;
    for (big i = 0; i < n; i++)
    {
        if (s[i] == 'F')
        {
            continue;
        }
        else
        {
            if (prev != '0' && prev != s[i])
            {
                res = add_mod(res, mult_mod(prev_i + 1, n - i));
            }
            prev = s[i];
            prev_i = i;
        }
    }

    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int test = 1;
    cin >> test;
    for (int i = 1; i <= test; i++)
    {
        cout << "Case #" << i << ": " << solve() << nl;
    }
    return 0;
}

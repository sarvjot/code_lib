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

big solve()
{
    big n, res = 0;
    cin >> n;

    vector<big> v(n);
    for (big i = 0; i < n; i++)
    {
        cin >> v[i];
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
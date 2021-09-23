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

void solve()
{
    big n;
    cin >> n;
    vector<big> v(n);

    for (big i = 0; i < n; i++)
    {
        cin >> v[i];
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int test = 1;
    cin >> test;
    while (test-- > 0)
    {
        solve();
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define big long long
#define precision(x) fixed << setprecision(x)
#define get_set_bits(x) __builtin_popcountll(x) 

#ifndef ONLINE_JUDGE
#define ds(statement) cerr << "\033[31m" << statement << "\033[37m" << endl
#define dv(var) cerr << "\033[31m" << (#var) << ": " << var << "\033[37m" << endl
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
    for (int i = 1; i <= test; i++)
    {
        cout << "Case #" << i << ": ";
        solve();
    }
    return 0;
}

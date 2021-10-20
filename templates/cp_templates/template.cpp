#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define big long long
#define precision(x) fixed << setprecision(x)
#define get_set_bits(x) __builtin_popcountll(x) 

#ifndef ONLINE_JUDGE
#define ds(statement) cerr << "\033[32m" << statement << "\033[37m" << endl
#define dv(var) cerr << "\033[34m" << (#var) << ": " << var << "\033[37m" << endl
#define sm_line  cerr << "\033[33m" << "---------X--------" << "\033[37m" << endl
#define lg_line  cerr << "\033[31m" << "------X----------X------" << "\033[37m" << endl
#else
#define ds(statement)
#define dv(var)
#define sm_line
#define lg_line
#endif

const big MOD = 1e9 + 7;
const big INF = INT64_MAX;

void solve()
{

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

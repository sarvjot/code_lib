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

void solve() {
    big n;
    cin >> n;

    vector<big> v(n);

    for (big i = 0; i < n; i++) {
        cin >> v[i];
    }

    sort(v.begin(), v.end());

    if (n % 2 == 1) {
        cout << n / 2 << nl;
        big p1 = 0, p2 = n / 2;
        for (big i = 0; i < n; i++) {
            if (i % 2 == 0) {
                cout << v[p2++] << " ";
            } else {
                cout << v[p1++] << " ";
            }
        }
    } else {
        cout << (n / 2) - 1 << nl;
        big p1 = 0, p2 = n / 2;
        for (big i = 0; i < n; i++) {
            if (i % 2 == 0) {
                cout << v[p1++] << " ";
            } else {
                cout << v[p2++] << " ";
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int test = 1;
    // cin >> test;
    while (test-- > 0) {
        solve();
    }
    return 0;
}
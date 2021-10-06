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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int ans[n];
    sort(a, a + n);
    int j = 0;
    for (int i = 1; i < n; i += 2) {
        ans[i] = a[j];
        j++;
    }
    for (int i = 0; i < n; i += 2) {
        ans[i] = a[j];
        j++;
    }
    int cnt = 0;
    for (int i = 1; i < n - 1; i++) {
        if (ans[i] < ans[i - 1] && ans[i] < ans[i + 1]) {
            cnt++;
        }
    }
    cout << cnt << "\n";
    for (int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }
}
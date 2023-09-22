// prefix: sqrtdecomposition
// description: square root decomposition
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

void build(vector<big> &v, vector<big> &b, big n, big len){
	for (big i = 0; i < n; ++i){
		b[i / len] += v[i];
	}
}

big query(vector<big> &v, vector<big> &b, big n, big len, big l, big r){
	big sum = 0;

	big bl = l / len, br = r / len;

	if (bl == br){
		for (big i = l; i <= r; ++i){
			sum += v[i];
		}
	}
	else{
		for (big i = l; i < (bl + 1) * len; ++i){
			sum += v[i];
		}
		for (big i = bl + 1; i < br; ++i){
			sum += b[i];
		}
		for (big i = br * len; i <= r; ++i){
			sum += v[i];
		}
	}

	return sum;
}

void solve(){
	big n;
	cin >> n;
	vector<big> v(n);

	for (big i = 0; i < n; ++i){
		cin >> v[i];
	}

	big len = (big)sqrt(1.0 * n) + 1;
	vector<big> b(len);

	build(v, b, n, len);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int test = 1;
	cin >> test;
	while (test-- > 0){
		solve();
	}
	return 0;
}

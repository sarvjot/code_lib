// prefix: matrixexponentiation
// description: matrix exponentiation
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

big add(big a, big b){
	big ans = a + b;
	if(ans >= MOD) ans -= MOD;
	return ans;
}

big mult(big a, big b){
	return (a * 1LL * b) % MOD;
}

struct Matrix{
	big a[2][2] = {{0, 0}, {0, 0}};
	Matrix operator*(const Matrix &other){
		Matrix prod;
		for (big i = 0; i < 2; ++i){
			for (big j = 0; j < 2; ++j){
				for (big k = 0; k < 2; ++k){
					prod.a[i][j] = add(prod.a[i][j], mult(a[i][k], other.a[k][j]));
				}
			}
		}
		return prod;
	}
};

Matrix power(Matrix a, big k){
	Matrix prod;

	for (int i = 0; i < 2; ++i){
		prod.a[i][i] = 1;
	}

	while (k > 0){
		if (k % 2 == 1){
			prod = prod * a;
		}
		a = a * a;
		k /= 2;
	}

	return prod;
}

void solve(){
	big n;
	cin >> n;

	Matrix ans;
	ans.a[0][0] = 0;
	ans.a[0][1] = 1;
	ans.a[1][0] = 1;
	ans.a[1][1] = 1;

	ans = power(ans, n);

	cout << ans.a[0][1] << nl;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int test = 1;
	// cin >> test;
	while (test-- > 0){
		solve();
	}
	return 0;
}

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

const big mod = 1e9 + 7;
const big inf = INT64_MAX;

const big len = 2e5 + 10;
big dp[len], ans[len], color[len];
vector<big> g[len];

void init_root(big node, big par)
{
	dp[node] = color[node];
	for (big nebr : g[node])
	{
		if (nebr != par)
		{
			init_root(nebr, node);
			dp[node] += max(0ll, dp[nebr]);
		}
	}
}

void reroot(big node, big par)
{
	ans[node] = dp[node];

	for (auto nebr : g[node])
	{
		if (nebr != par)
		{
			dp[node] -= max(0ll, dp[nebr]);
			dp[nebr] += max(0ll, dp[node]);

			reroot(nebr, node);

			dp[nebr] -= max(0ll, dp[node]);
			dp[node] += max(0ll, dp[nebr]);
		}
	}
}

void solve()
{
	big n, a, b, t;
	cin >> n;

	for (big i = 0; i < n; i++)
	{
		cin >> t;
		color[i] = (t == 1) ? 1 : -1;
	}

	for (big i = 0; i < n - 1; i++)
	{
		cin >> a >> b;
		g[a - 1].push_back(b - 1);
		g[b - 1].push_back(a - 1);
	}

	init_root(0, -1);
	reroot(0, -1);

	for (big i = 0; i < n; i++)
	{
		cout << ans[i] << " ";
	}
	cout << nl;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int test = 1;
	// cin >> test;
	while (test-- > 0)
	{
		solve();
	}
	return 0;
}

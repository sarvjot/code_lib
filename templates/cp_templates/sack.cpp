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

//--------------------------------------------------------------------------------------
const int max_n = 5e5 + 10;
vector<vector<int>> adj;
int vals[max_n];
int sz[max_n];
int heavy = -1;

int sack_size(int node, int parent = 0)
{
	sz[node] = 1;
	int max_sz = 0;
	for (int i = 0; i < (int)adj[node].size(); i++)
	{
		if (adj[node][i] == parent)
		{
			continue;
		}
		int temp = sack_size(adj[node][i], node);
		sz[node] += temp;
		if (temp > max_sz)
		{
			max_sz = temp;
			swap(adj[node][0], adj[node][i]);
		}
	}
	return sz[node];
}

void sack_add(int node, int parent)
{
	// Do Something Here to change the value
	for (int i = 0; i < (int)adj[node].size(); i++)
	{
		if (adj[node][i] != parent && adj[node][i] != heavy)
		{
			sack_add(adj[node][i], node);
		}
	}
}

void sack_dfs(int node, int parent, int keep)
{
	for (int i = 1; i < (int)adj[node].size(); i++)
	{
		if (adj[node][i] != parent)
		{
			sack_dfs(adj[node][i], node, 0);
		}
	}

	if (sz[node] != 1)
	{
		sack_dfs(adj[node][0], node, 1);
		heavy = adj[node][0];
	}

	sack_add(node, parent);

	// Answer Queries Here

	heavy = -1;
	if (!keep)
	{
		sack_add(node, parent);
	}
}

//--------------------------------------------------------------------------------------

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
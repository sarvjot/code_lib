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

vector<big> tree, lazy;

big combine(big a, big b)
{
	return max(a, b);
}

void build(vector<big> &arr, big node, big tl, big tr)
{
	if (tl == tr)
	{
		tree[node] = arr[tl];
	}
	else
	{
		big tm = (tr - tl) / 2 + tl;

		build(arr, 2 * node, tl, tm);
		build(arr, 2 * node + 1, tm + 1, tr);

		tree[node] = combine(tree[2 * node], tree[2 * node + 1]);
	}
}

void push(big node)
{
	tree[node * 2] += lazy[node];
	tree[node * 2 + 1] += lazy[node];

	lazy[node * 2] += lazy[node];
	lazy[node * 2 + 1] += lazy[node];

	lazy[node] = 0;
}

void update(big node, big tl, big tr, big l, big r, big x)
{
	if (l > r)
	{
		return;
	}
	if (l == tl && tr == r)
	{
		tree[node] += x;
		lazy[node] += x;
	}
	else
	{
		push(node);
		big tm = (tr - tl) / 2 + tl;
		update(2 * node, tl, tm, l, min(r, tm), x);
		update(2 * node + 1, tm + 1, tr, max(l, tm + 1), r, x);
		tree[node] = combine(tree[2 * node], tree[2 * node + 1]);
	}
}

big query(big node, big tl, big tr, big l, big r)
{
	if (l > r)
	{
		return -inf;
	}
	if (l == tl && tr == r)
	{
		return tree[node];
	}
	else
	{
		push(node);
		big tm = (tr - tl) / 2 + tl;
		big q1 = query(2 * node, tl, tm, l, min(r, tm));
		big q2 = query(2 * node + 1, tm + 1, tr, max(l, tm + 1), r);
		return combine(q1, q2);
	}
}

void solve()
{
	big n;
	cin >> n;

	tree = vector<big>(4 * n);
	lazy = vector<big>(4 * n, 0);
	vector<big> arr(n);

	for (big i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	build(arr, 1, 0, n - 1);
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
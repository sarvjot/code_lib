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

vector<big> seg_tree;

big combine(big a, big b)
{
	return a + b;
}

void build(vector<big> &arr, big node, big tl, big tr)
{
	if (tl == tr)
	{
		seg_tree[node] = arr[tl];
	}
	else
	{
		big tm = (tr - tl) / 2 + tl;

		build(arr, 2 * node, tl, tm);
		build(arr, 2 * node + 1, tm + 1, tr);

		seg_tree[node] = combine(seg_tree[2 * node], seg_tree[2 * node + 1]);
	}
}

void update(big node, big tl, big tr, big pos, big new_val)
{
	if (tl == tr)
	{
		seg_tree[node] = new_val;
	}
	else
	{
		big tm = (tr - tl) / 2 + tl;

		if (pos <= tm)
		{
			update(2 * node, tl, tm, pos, new_val);
		}
		else
		{
			update(2 * node + 1, tm + 1, tr, pos, new_val);
		}

		seg_tree[node] = combine(seg_tree[2 * node], seg_tree[2 * node + 1]);
	}
}

big query(big node, big tl, big tr, big l, big r)
{
	if (l > r)
	{
		return 0;
	}

	if (l == tl && r == tr)
	{
		return seg_tree[node];
	}

	big tm = (tr - tl) / 2 + tl;

	big q1 = query(2 * node, tl, tm, l, min(r, tm));
	big q2 = query(2 * node + 1, tm + 1, tr, max(l, tm + 1), r);

	return combine(q1, q2);
}

void solve()
{
	big n;
	cin >> n;

	seg_tree = vector<big>(4 * n);
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
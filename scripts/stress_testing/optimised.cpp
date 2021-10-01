#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
const int INF = INT32_MAX;

vector<int> seg_tree;

int combine(int a, int b)
{
    return min(a, b);
}

void build(vector<int> &aux, int node, int tl, int tr)
{
    if (tl == tr)
    {
        seg_tree[node] = aux[tl];
    }
    else
    {
        int tm = (tr - tl) / 2 + tl;

        build(aux, 2 * node, tl, tm);
        build(aux, 2 * node + 1, tm + 1, tr);

        seg_tree[node] = combine(seg_tree[2 * node],
                                 seg_tree[2 * node + 1]);
    }
}

void update(int node, int tl, int tr, int pos, int new_val)
{
    if (tl == tr)
    {
        seg_tree[node] = new_val;
    }
    else
    {
        int tm = (tr - tl) / 2 + tl;

        if (pos <= tm)
        {
            update(2 * node, tl, tm, pos, new_val);
        }
        else
        {
            update(2 * node + 1, tm + 1, tr, pos, new_val);
        }

        seg_tree[node] = combine(seg_tree[2 * node],
                                 seg_tree[2 * node + 1]);
    }
}

int query(int node, int tl, int tr, int l, int r)
{
    if (l > r)
    {
        return INF;
    }

    if (l == tl && r == tr)
    {
        return seg_tree[node];
    }

    int tm = (tr - tl) / 2 + tl;

    int q1 = query(2 * node, tl, tm, l, min(r, tm));
    int q2 =
        query(2 * node + 1, tm + 1, tr, max(l, tm + 1), r);

    return combine(q1, q2);
}

void solve()
{
    int n;
    cin >> n;

    vector<int> original(n), sorted(n);
    map<int, int> encode;

    for (int i = 0; i < n; i++)
    {
        cin >> original[i];
        sorted[i] = original[i];
    }

    // Index Compression

    sort(sorted.begin(), sorted.end());
    int ctr = 0;
    for (int i = 0; i < n; i++)
    {
        if (encode.count(sorted[i]) == 0)
        {
            encode[sorted[i]] = ++ctr;
        }
    }

    vector<int> compressed(n);
    for (int i = 0; i < n; i++)
    {
        compressed[i] = encode[original[i]];
    }

    // Build Segment Tree

    seg_tree = vector<int>(4 * ctr);
    vector<int> aux(ctr, INF);

    build(aux, 1, 0, ctr - 1);

    vector<int> ans(n);
    for (int i = n - 1; i >= 0; i--)
    {
        ans[i] = query(1, 0, ctr - 1, 0, compressed[i] - 1);
        update(1, 0, ctr - 1, compressed[i], i);
    }

    for (int i = 0; i < n; i++)
    {
        if (ans[i] == INF)
        {
            cout << -1 << " ";
        }
        else
        {
            cout << original[ans[i]] << " ";
        }
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
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

struct trie
{
    vector<trie *> children;

    trie()
    {
        children = vector<trie *>(26, NULL);
    }
};

trie *root;

void insert(string &str)
{
    trie *cur = root;

    for (char ch : str)
    {
        big ind = ch - 'a';

        if (cur->children[ind] == NULL)
        {
            cur->children[ind] = new trie;
        }

        cur = cur->children[ind];
    }
}

void generate_trie(string &str)
{
    big n = str.size();
    for (big i = 0; i < n; i++)
    {
        string t = str.substr(i);
        insert(t);
    }
}

big dfs_trie(string &s, trie *cur, big k)
{
    big ans = 0;

    if (cur != root)
    {
        ans = 1;
    }

    for (big i = 0; i < 26; i++)
    {
        if (cur->children[i] != NULL)
        {
            if (s[i] == '0')
            {
                if (k > 0)
                {
                    ans += dfs_trie(s, cur->children[i], k - 1);
                }
            }
            else
            {
                ans += dfs_trie(s, cur->children[i], k);
            }
        }
    }

    return ans;
}

void solve()
{
    root = new trie();

    string s1, s2;
    big k;
    cin >> s1 >> s2 >> k;

    generate_trie(s1);
    big ans = dfs_trie(s2, root, k);

    cout << ans << nl;
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
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

big lim = 1e5 + 100;
vector<bool> sieve(lim + 1, true);

void precomputeSieve()
{
    sieve[0] = false;
    sieve[1] = false;
    big sn = sqrt(lim);

    for (big i = 2; i <= sn; i++)
    {
        if (sieve[i])
        {
            for (big j = i * i; j <= lim; j += i)
            {
                sieve[j] = false;
            }
        }
    }
}

big solve_sub(big n, big x, vector<big> &facs)
{
    big len, div, ans = 0;

    len = facs.size();

    for (big i = 0; i < (1 << len); i++)
    {
        div = 1;
        for (big j = 0; j < len; j++)
        {
            div *= ((1 << j) & i) == 0 ? 1 : facs[j];
        }

        if (__builtin_popcount(i) % 2 == 0)
        {
            ans += x / div;
        }
        else
        {
            ans -= x / div;
        }
    }

    return ans;
}

big solve()
{
    // Find frequency of numbers which are non-coprime to n, and lie between l and r

    big n, l, r, t;
    cin >> l >> r >> n;

    vector<big> facs;
    t = n;

    for (big i = 2; i * i <= n; i++)
    {
        if (sieve[i] && t % i == 0)
        {
            facs.push_back(i);
            while (t % i == 0)
            {
                t /= i;
            }
        }
    }

    if (t != 1)
    {
        facs.push_back(t);
    }

    return solve_sub(n, r, facs) - solve_sub(n, l - 1, facs);
}

int main()
{
    precomputeSieve();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int test = 1;
    cin >> test;

    for (big i = 1; i <= test; i++)
    {
        cout << "Case #" << i << ": " << solve() << nl;
    }

    return 0;
}

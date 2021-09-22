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

big add(big a, big b)
{
    return (a % MOD + b % MOD) % MOD;
}

big mult(big a, big b)
{
    return ((long long)a % MOD * b % MOD) % MOD;
}

big sub(big a, big b)
{
    return ((a % MOD - b % MOD) % MOD + MOD) % MOD;
}

big solve()
{
    big n, res = 0;
    string s;

    cin >> n >> s;

    char prev = '0', first = '0';
    big prev_i = -1, first_i = -1, cur_len = 0, len = 0, sum = INF, cnt = 0;

    for (big i = 0; i < n; i++)
    {
        if (s[i] == '.')
        {
            len = mult(len, 2ll);
        }
        else
        {
            len = add(len, 1ll);
        }
    }

    for (big i = 0; i < n; i++)
    {
        if (s[i] == '.')
        {
            if (sum != INF)
            {
                res = mult(res, 2ll);
                res = add(res, mult(cur_len, sub(mult(cnt, sub(len, cur_len)), add(sum, cnt))));
                sum = mult(2ll, add(sum, mult(cur_len, cnt)));
                cnt = mult(cnt, 2ll);
            }

            if (prev != '0' && first != '0' && prev != first)
            {
                res = add(res, mult(add(prev_i, 1ll), sub(len, add(cur_len, first_i))));
                sum = add(add(sum, prev_i), add(cur_len, first_i));
                cnt = add(cnt, 1ll);
            }

            prev_i = add(prev_i, cur_len);
            cur_len = mult(cur_len, 2ll);
        }
        else
        {
            if (s[i] != 'F')
            {
                if (first == '0')
                {
                    first = s[i];
                    first_i = cur_len;
                }
                if (prev != '0' && prev != s[i])
                {
                    res = add(res, mult(add(prev_i, 1ll), sub(len, cur_len)));
                    if (sum == INF)
                    {
                        sum = add(prev_i, cur_len);
                    }
                    else
                    {
                        sum = add(sum, add(prev_i, cur_len));
                    }
                    cnt = add(cnt, 1ll);
                }
                prev = s[i];
                prev_i = cur_len;
            }
            cur_len = add(cur_len, 1ll);
        }
    }

    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int test = 1;
    cin >> test;
    for (int i = 1; i <= test; i++)
    {
        cout << "Case #" << i << ": " << solve() << nl;
    }
    return 0;
}

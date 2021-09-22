#include <bits/stdc++.h>
using namespace std;

#define big long long

const big mod = 1e9 + 7;

big add_mod(big a, big b)
{
    return (a % mod + b % mod) % mod;
}

big mult_mod(big a, big b)
{
    return (a % mod * b % mod) % mod;
}

struct Matrix
{
    big a[2][2] = {{0, 0}, {0, 0}};
    Matrix operator*(const Matrix &other)
    {
        Matrix prod;
        for (big i = 0; i < 2; i++)
        {
            for (big j = 0; j < 2; j++)
            {
                for (big k = 0; k < 2; k++)
                {
                    prod.a[i][j] = add_mod(prod.a[i][j], mult_mod(a[i][k], other.a[k][j]));
                }
            }
        }
        return prod;
    }
};

Matrix power(Matrix a, big k)
{
    Matrix prod;

    for (int i = 0; i < 2; i++)
    {
        prod.a[i][i] = 1;
    }

    while (k > 0)
    {
        if (k % 2 == 1)
        {
            prod = prod * a;
        }
        a = a * a;
        k /= 2;
    }

    return prod;
}
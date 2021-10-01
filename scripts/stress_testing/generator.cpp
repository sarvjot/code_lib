#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define big long long

int rnd(int a, int b)
{
    return a + rand() % (b - a + 1);
}

int main()
{
    srand(time(0));

    big n = rnd(1ll, 20);
    cout << n << nl;

    for (big i = 0; i < n; i++)
    {
        cout << rnd(1ll, 100) << " ";
    }
    cout << nl;
}

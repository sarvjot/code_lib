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

    cout << 1 << nl;

    big n = rnd(1ll, 20), r;
    cout << n << nl;

    vector<char> v = {'X', 'O', 'F', '.'};

    for (big i = 0; i < n; i++)
    {
        do
        {
            r = rnd(0, 3);
        } while (i == 0 && r == 3);

        cout << v[r];
    }
    cout << nl;
}

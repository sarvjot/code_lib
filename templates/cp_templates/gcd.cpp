#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define big long long

big gcd(big a, big b)
{
	if (b == 0)
	{
		return a;
	}
	return gcd(b, a % b);
}

int main()
{
	cout << gcd(12, 8);
	return 0;
}
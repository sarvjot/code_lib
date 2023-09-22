// prefix: sieve
// description: sieve of eratosthenes
big lim = 1e6;
vector<bool> sieve(lim + 1, true);
vector<big> sieveCount(lim + 1, 0);
vector<big> primeNumbers;
vector<big> spf(lim + 1, 1);

void precomputeSieve(){
	sieve[0] = false;
	sieve[1] = false;
	big sn = sqrt(lim);

	// initialising spf - O(n)
	for (big i = 1; i <= lim; ++i){
		spf[i] = i;
	}

	// primary sieve and calculating Smallest Prime Factor - O(nloglogn)
	for (big i = 2; i <= sn; ++i){
		if (sieve[i]){
			for (big j = i * i; j <= lim; j += i){
				if (spf[j] == j){
					spf[j] = i;
				}
				sieve[j] = false;
			}
		}
	}

	// storing prime numbers - O(N)
	big ctr = 0;
	for (big i = 0; i < lim; ++i){
		if (sieve[i]){
			++ctr;
			primeNumbers.push_back(i);
		}
		sieveCount[i] = ctr;
	}
}

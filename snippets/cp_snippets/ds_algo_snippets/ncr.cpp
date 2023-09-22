// prefix: ncr
// description: out of n objects, choose r objects
vector<big> factorials;
vector<big> mmi;
big lim_fac = 1e6 + 1;

void precompute_factorials(){
	factorials = vector<big>(lim_fac);
	mmi = vector<big>(lim_fac);
	factorials[0] = 1;
	factorials[1] = 1;
	mmi[0] = 1;
	mmi[1] = 1;

	for (big i = 2; i < lim_fac; ++i){
		factorials[i] = mult(factorials[i - 1], i);
		mmi[i] = inv(factorials[i]);
	}
}

big ncr(big n, big r){
	if (n < r)
		return 0;
	if (r == 0)
		return 1;

	big a = factorials[n];
	big b = mmi[r];
	big c = mmi[n - r];

	big ans = mult(mult(a, b), c);

	return ans;
}

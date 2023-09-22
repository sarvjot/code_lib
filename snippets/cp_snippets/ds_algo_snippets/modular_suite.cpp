// prefix: modsuite
// description: modular arithmetic suite of functions
const big MOD = 1e9 + 7;

big add(big a, big b){
	big ans = a + b;
	if(ans >= MOD) ans -= MOD;
	return ans;
}

big sub(big a, big b){
	big ans = a - b;
	if(ans < 0) ans += MOD;	
	return ans;
}

big mult(big a, big b){
	return (a * 1LL * b) % MOD;
}

// Don't mod this exponent!!
big power(big base, big exp){
	base = base % MOD;
	big res = 1;
	while (exp > 0){
		if (exp & 1){
			res = mult(res, base);
		}
		base = mult(base, base);
		exp = exp >> 1;
	}

	return res;
}

big inv(big n){
	return power(n, MOD - 2);
}

big divi(big a, big b){
	return mult(a, inv(b));
}

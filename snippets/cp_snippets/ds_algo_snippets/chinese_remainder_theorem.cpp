// prefix: chinesereamindertheorem
// description: chinese remainder theorem
big mult(big a, big b, big mod){
	big ans = 0;
	while (b){
		if (b & 1){
			ans += a;
			ans %= mod;
		}
		a += a;
		a %= mod;
		b >>= 1;
	}
	return ans;
}

big power(big a, big b, big mod){
	big ans = 1;
	while (b){
		if (b & 1){
			ans = mult(ans, a, mod);
		}
		a = mult(a, a, mod);
		b >>= 1;
	}
	return ans;
}

big modinv(big a, big mod){
	return power(a, mod - 2, mod);
}

big crt(vector<big> &p, vector<big> &k){
	big ans = 0; 
	big n = p.size();

	big prod = 1;
	for (auto x : p){
		prod *= x;
	}

	for (big i = 0; i < n; ++i){
		big t = 1;
		for (big j = 0; j < i; ++j){
			t *= p[j];
			t *= modinv(p[j], p[i]);
			t %= prod;
		}
		ans += mult(t, k[i] - ans + prod, prod);
		ans %= prod;
	}

	return ans;
}

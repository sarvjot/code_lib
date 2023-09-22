// prefix: powerbinexp
// description: binary exponentiation
big power(big base, int exp){
	big res = 1;
	while (exp > 0){
		if (exp & 1){
			res = res * base;
		}
		base *= base;
		exp = exp >> 1;
	}

	return res;
}

// prefix: zfunction
// description: z function
vector<big> z_function(string &s){
	big n = s.size();
	// z[i] = length of largest substring starting at i which also is a prefix of s
	vector<big> z(n, 0);

	big l = 0, r = 0;
	for(big i = 1; i < n; ++i){
		if(i <= r){
			z[i] = min(z[i - l], r - i + 1);
		}

		while(i + z[i] < n && s[i + z[i]] == s[z[i]]){
			++z[i];
		}

		if(i + z[i] - 1 > r){
			l = i;
			r = i + z[i] - 1;
		}
	}

	return z;
}

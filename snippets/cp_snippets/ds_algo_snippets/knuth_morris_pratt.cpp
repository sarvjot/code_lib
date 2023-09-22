// prefix: kmp
// description: knuth morris pratt algorithm for pattern matching [O(n + m)]
void prefix_function(char *s, vector<big> &pi){
	big m = (big)pi.size();
	for (big i = 1; i < m; ++i){
		big j = pi[i - 1];

		while (j > 0 && s[i] != s[j]){
			j = pi[j - 1];
		}

		if (s[i] == s[j]){
			++j;
		}

		pi[i] = j;
	}
}

void kmp(char *pat, char *txt){
	big m = strlen(pat);
	big n = strlen(txt);

	vector<big> pi(m);
	prefix_function(pat, pi);

	big i = 0, j = 0;

	while (i < n){
		if (pat[j] == txt[i]){
			++i;
			++j;
		}

		if (j == m){
			cout << (i - j) << " ";
			j = pi[j - 1];
		}
		else if (i < n && pat[j] != txt[i]){
			if (j != 0){
				j = pi[j - 1];
			}
			else{
				++i;
			}
		}
	}
}

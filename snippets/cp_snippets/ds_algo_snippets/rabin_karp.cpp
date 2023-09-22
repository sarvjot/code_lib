// prefix: rabin_karp
// description: rabin karp algorithm for string matching
int m, p; 

int mult(int a, int b){
	return (a * 1ll * b) % m;
}

int add(int a, int b){
	int s = a + b;
	if(s > m){
		s -= m;
	}
	return s;
}

int sub(int a, int b){
	int d = a - b; 
	if(d < 0){
		d += m;
	}
	return d;
}

int power(int a, int b){
	int x = 1;
	while(b > 0){
	   if(b % 2 == 1){
		   x = (x * 1ll * a) % m;
	   } 
	   
	   a = (a * 1ll * a) % m;
	   b /= 2;
	}
	
	return x;
}    

int divi(int a, int b){
	return mult(a, power(b, m - 2));
}

void precompute_hash(string &str, vector<int> &hash){
	int n = str.size();
	hash.assign(n, 0);
	
	for(int i = 0; i < n; i++){
		hash[i] = mult(power(p, i), str[i] - 'a' + 1);
		if(i != 0)
			hash[i] = add(hash[i - 1], hash[i]);
	}
}

int give_hash(int l, int r, vector<int> &hash){
	if(l == 0){
		return hash[r];
	} else{
		return divi(sub(hash[r], hash[l - 1]), power(p, l));
	}
}

int give_hash(string &str){
	int n = str.size();
	int x = 0;
	
	for(int i = 0; i < n; i++){
		x = add(x, mult(power(p, i), str[i] - 'a' + 1));
	}
	
	return x;
}

int rabin_karp(string haystack, string needle) {
	m = 1e9 + 7;
	p = 33;
	
	int nl = needle.size();
	int nh = haystack.size();
	
	if(nl == 0) return 0;
	
	vector<int> hash;
	
	int needle_hash = give_hash(needle);
	precompute_hash(haystack, hash);
	
	for(int i = 0; i < nh - nl + 1; i++){
		if(needle_hash == give_hash(i, i + nl - 1, hash)){
			return i;
		}
	}
	
	return -1;
}

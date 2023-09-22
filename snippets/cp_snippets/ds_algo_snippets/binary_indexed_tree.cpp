// prefix: binaryindexedtree
// description: binary indexed tree/fenwick tree
struct binaryindexedtree{
	big n;
	vector<big> BIT;

	binaryindexedtree(vector<big> &v){
		n = v.size();
		build(v);
	}

	big query(big i){
		big sum = 0;
		for(; i > 0; i -= i & -i){
			sum += BIT[i]; 
		}
		return sum;
	}

	big query(big l, big r){
		return query(r) - query(l - 1);
	}

	void update(big i, big x){
		for(; i <= n; i += i & -i){
			BIT[i] += x;
		}
	}   

	void build(vector<big> &v){
		BIT.assign(n + 1, 0);
		for(big i = 0; i < n; ++i){
			update(i + 1, v[i]);    
		}
	}
};

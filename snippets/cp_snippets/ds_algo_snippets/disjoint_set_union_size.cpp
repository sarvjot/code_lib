// prefix: dsusize
// description: disjoint set union with size
struct DSU{
	vector<big> par, size;    
	big num_comps;

	DSU(big n){
		size.assign(n, 1);
		par.resize(n);
		iota(all(par), 0);
		num_comps = n;
	}

	void union_(big a, big b){
		a = find(a);
		b = find(b);

		if (a != b){
			num_comps--;

			if (size[a] < size[b]) swap(a, b);
			par[b] = a;
			size[a] += size[b];
		}
	}   

	big find(big node){
		if(par[node] != node) par[node] = find(par[node]);
		return par[node];
	}
};

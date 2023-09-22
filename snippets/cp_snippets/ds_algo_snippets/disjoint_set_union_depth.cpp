// prefix: dsudepth
// description: disjoint set union with depth
struct DSU{
	vector<big> par, depth;    
	big num_comps;

	DSU(big n){
		depth.assign(n, 1);
		par.resize(n);
		iota(all(depth), 0);
		num_comps = n;
	}

	void union_(big a, big b){
		a = find(a);
		b = find(b);

		if (a != b){
			num_comps--;

			if (depth[a] < depth[b]) swap(a, b);
			par[b] = a;
			if(depth[a] == depth[b]) ++depth[a];
		}
	}   

	big find(big node){
		if(par[node] != node) par[node] = find(par[node]);
		return par[node];
	}
};

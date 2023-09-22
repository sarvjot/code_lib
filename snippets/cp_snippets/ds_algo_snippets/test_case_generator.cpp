// prefix: tcgen
// description: test case generator for problems
struct testcase_generator{
	big rnd(big a, big b) {
		return a + rand() % (b - a + 1);
	}

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

	void generate_tree(big n){
		DSU dsu = DSU(n);
		vector<pair<big, big>> tree_edges;
		tree_edges.reserve(n - 1);

		while(dsu.num_comps > 1){
			big a = rnd(0, n - 1);
			big b = rnd(0, n - 1);

			if(dsu.find(a) != dsu.find(b)){
				tree_edges.push_back({a, b});
				dsu.union_(a, b);
			}
		}

		for(big i = 0; i < n - 1; ++i){
			cout << tree_edges[i].first + 1 << " " << tree_edges[i].second + 1 << nl;
		}
	}
	
	void generate_array(big n, big lower_limit, big upper_limit){
		for(big i = 0; i < n; ++i){
			cout << rnd(lower_limit, upper_limit) << " ";
		}
		cout << nl;
	}

	void generate_set(big n, big lower_limit, big upper_limit){
		set<big> s;
		for(big i = 0; i < n; ++i){
			big x;    
			do{
				x = rnd(lower_limit, upper_limit);
			}while(s.count(x) > 0);
			s.insert(x);
			cout << x << " ";
		}
		cout << nl;
	}
};

// prefix: kruskal
// description: kruskal's algorithm for finding the minimum spanning tree of a graph
struct edge{
	big a, b, c;

	bool operator < (const edge &other){
		return c < other.c;
	}
	
};

struct kruskal{
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

	vector<edge> g, t;
	big n, cost, pos;

	kruskal(big n1){
		cost = 0;
		pos = 1;
		n = n1;
	}

	void init(){
		assert((big)g.size() == n);

		DSU dsu_s(n);
		sort(all(g));

		for(auto &e : g){
			if(dsu_s.find(e.a) != dsu_s.find(e.b)){
				dsu_s.union_(e.a, e.b);
				cost += e.c;
				t.push_back(e);
			}
		}

		// check if its possible to generate a MST
		big p = dsu_s.find(0);
		for(big i = 1; i < n; ++i){
			big cp = dsu_s.find(i); 
			if(cp != p){
				pos = 0;
				break;
			}
		}
	}
};

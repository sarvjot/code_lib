// prefix: centroiddecomposition
// description: takes a tree and decomposes it into a centroid tree and root
struct CD{
	big n, root;
	vector<bool> removed;
	vector<big> size;
	vector<vector<big>> g, centroid_t;

	CD(big n1){
		n = n1;
		removed.assign(n, false);
		size.resize(n);
		centroid_t.resize(n);
		g.resize(n);
	}

	void edge(big u, big v){
		g[u].push_back(v);
		g[v].push_back(u);
	}

	void edge_ct(big u, big v){
		centroid_t[u].push_back(v);
		centroid_t[v].push_back(u);
	}

	// O(nlogn)
	void decompose(big node, big par){
		get_size(node, -1); // O(n)

		big c = get_centroid(node, par, size[node]); // O(n)
		removed[c] = true;

		if(par != -1){
			edge_ct(c, par);
		}

		for(auto nebr : g[c]){
			if(!removed[nebr]){
				decompose(nebr, c);
			}
		}

		if(par == -1){
			root = c;
		}
	}

	big get_size(big node, big par){
		if(removed[node]) return 0;
		size[node] = 1;

		for(auto nebr : g[node]){
			if(nebr != par){
				size[node] += get_size(nebr, node);
			}
		}

		return size[node];
	}

	big get_centroid(big node, big par, big sz){
		for(auto nebr : g[node]){
			if(nebr != par && !removed[nebr] && size[nebr] > sz / 2){
				return get_centroid(nebr, node, sz);
			}
		}
		return node;
	}
};

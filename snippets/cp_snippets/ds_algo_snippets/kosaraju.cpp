// prefix: kosaraju
// description: kosaraju's algorithm for strongly connected components
void dfstopo(big node, vector<vector<big>> &g, vector<big> &vis, vector<big> &topo){
	vis[node] = 1;

	for(auto &nebr : g[node]){
		if(!vis[nebr]){
			dfstopo(nebr, g, vis, topo);
		}
	}
	topo.push_back(node);
}

void dfscomp(big node, vector<vector<big>> &g, vector<big> &vis, vector<big> &comp){
	vis[node] = 1;
	comp.push_back(node);

	for(auto &nebr : g[node]){
		if(!vis[nebr]){
			dfscomp(nebr, g, vis, comp);
		}
	}
}

void kosaraju(vector<vector<big>> &g, vector<vector<big>> &ig, vector<big> &root, vector<big> &roots, vector<vector<big>> &cg){
	big n = root.size(), r;
	vector<big> vis(n), topo, comp;

	for(big i = 0; i < n; ++i){
		if(!vis[i]){
			dfstopo(i, g, vis, topo); 
		}
	}

	reverse(all(topo));
	vis.assign(n, 0);
	for(big i = 0; i < n; ++i){
		if(!vis[topo[i]]){
			comp.clear(); 

			dfscomp(topo[i], ig, vis, comp);

			r = comp.back(); 
			for(auto &c : comp){
				root[c] = r;
			}
			roots.push_back(r); 
		}
	}
	
	for(big i = 0; i < n; ++i){
		for(auto &nebr : g[i]){
			if(root[i] != root[nebr]){
				cg[root[i]].push_back(root[nebr]); 
			}
		}
	}
} 

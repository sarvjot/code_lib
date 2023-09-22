// prefix: twosat
// description: boolean satisfiability problem
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
 
bool twosat(vector<vector<big>> &g, vector<vector<big>> &ig, vector<big> &root, vector<big> &ans){
	big n = root.size(), j = 0;
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
 
			for(auto &c : comp){
				root[c] = j;
			}
			++j;
		}
	}

	for(big i = 0; i < n; i += 2){
		if(root[i] == root[i + 1]){
			return false;
		}
		ans[i / 2] = root[i] > root[i + 1];
	}
	return true;
} 

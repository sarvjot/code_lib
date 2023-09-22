// prefix: lca
// description: get lca of two nodes in a tree, binary lifting is a byproduct
struct LCA{
	big n, logn;
	vector<vector<big>> up;
	vector<big> depth, par;

	LCA(big root, big logn1, G &gr){
		n = gr.g.size();
		logn = logn1;

		up = vector<vector<big>>(n, vector<big>(logn));
		depth.resize(n);
		par.resize(n);

		dfs(root, root, gr);
		bin_lift();
	}

	void dfs(big node, big par1, G &gr){
		par[node] = par1;

		for(auto nebr : gr.g[node]){
			if(nebr != par1){
				depth[nebr] = depth[node] + 1;
				dfs(nebr, node, gr);
			}
		}
	}

	void bin_lift(){
		for(big i = 0; i < n; ++i){
			up[i][0] = par[i];    
		}

		for(big j = 1; j < logn; ++j){
			for(big i = 0; i < n; ++i){
				up[i][j] = up[up[i][j - 1]][j - 1];
			}
		}
	}

	big get_lca(big a, big b){
		// bringing a and b at same level

		if(depth[a] > depth[b]){
			swap(a, b);
		}
		big d = depth[b] - depth[a];

		for(big j = 0; j < logn && a != -1; ++j){
			if(((1 << j) & d) != 0){
				b = up[b][j];
			}
		}

		if(a == b){
			return a;
		}

		// now binary searching for level just lower than LCA

		for (big j = logn - 1; j >= 0; j--){
			if(up[a][j] != up[b][j]){
				a = up[a][j];
				b = up[b][j];
			}
		}

		return up[a][0];
	}
};

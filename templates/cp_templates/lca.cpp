 
void dfs(big node, big par, vector<vector<big>> &g, vector<big> &d){
	for(auto nebr : g[node]){
		if(nebr != par){
			d[nebr] = d[node] + 1;
			dfs(nebr, node, g, d);
		}
	}
}

void bin_lift(big n, big lim, vector<vector<big>> &up, vector<big> &par){
	for(big i = 0; i < n; i++)
	{
		up[i][0] = par[i];	  
	}

	for(big j = 1; j < lim; j++)
	{
		for(big i = 0; i < n; i++)
		{
			if(up[i][j - 1] == -1){
				up[i][j] = -1;
			}else{
				up[i][j] = up[up[i][j - 1]][j - 1];
			}
		}
	}
}

big lca(big a, big b, big lim, vector<big> &depth, vector<vector<big>> &up){
	// bringing a and b at same level

	if(depth[a] > depth[b]){
		swap(a, b);
	}
	big d = depth[b] - depth[a];

	for(big j = 0; j < lim && a != -1; j++)
	{
		if(((1 << j) & d) != 0){
			b = up[b][j];
		}
	}

	dv(a, b);
	if(a == b){
		return a + 1;
	}

	// now binary searching for level just lower than LCA

	for (big j = lim - 1; j >= 0; j--)
	{
		if(up[a][j] != up[b][j]){
			a = up[a][j];
			b = up[b][j];
		}
	}

	return up[a][0] + 1;
}

// prefix: eulertourtraversal
// description: euler tour traversal of a tree
struct ETT{
	big t, n, r;
	vector<big> st, end, ett;

	ETT(big r1, vector<big> &val, G &gr){
		t = 0;
		r = r1;
		n = val.size();

		st.resize(n);
		end.resize(n);
		ett.reserve(2 * n);
		
		build(r, -1, val, gr);
	}

	void build(big node, big par, vector<big> &val, G &gr){
		st[node] = t++;
		ett.push_back(val[node]);

		for(auto nebr : gr.g[node]){
			if(nebr != par){
				build(nebr, node, val, gr);
			}
		}

		end[node] = t++;
		ett.push_back(val[node]);
	}
};

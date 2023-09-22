// prefix: segmenttree
// description: segment tree
struct segtree{
	big n;
	vector<big> seg_t;

	segtree(vector<big> &v){
		n = v.size();
		seg_t = vector<big>(4 * n);
		build(v, 1, 0, n - 1);
	}

	big combine(big a, big b){
		return a + b;
	}

	void build(vector<big> &arr, big node, big tl, big tr){
		if (tl == tr){
			seg_t[node] = arr[tl];
		}
		else{
			big tm = (tr - tl) / 2 + tl;

			build(arr, 2 * node, tl, tm);
			build(arr, 2 * node + 1, tm + 1, tr);

			seg_t[node] = combine(seg_t[2 * node], seg_t[2 * node + 1]);
		}
	}

	void update(big node, big tl, big tr, big pos, big new_val){
		if(!(tl <= pos && pos <= tr)){
			return; 
		}

		if(tl == tr){
			seg_t[node] = new_val;
		}else{
			big tm = (tr - tl) / 2 + tl;

			update(2 * node, tl, tm, pos, new_val);
			update(2 * node + 1, tm + 1, tr, pos, new_val);

			seg_t[node] = combine(seg_t[2 * node], seg_t[2 * node + 1]);
		}
	}

	void update(big pos, big r, big new_val){
		update(1, 0, n - 1, pos, new_val);
	}

	big query(big node, big tl, big tr, big l, big r){
		if (l > r){
			return;
		}else if(l == tl && r == tr){
			return seg_t[node];
		}else{
			big tm = (tr - tl) / 2 + tl;

			big q1 = query(2 * node, tl, tm, l, min(r, tm));
			big q2 = query(2 * node + 1, tm + 1, tr, max(l, tm + 1), r);

			return combine(q1, q2);
		}
	}

	big query(big l, big r){
		return query(1, 0, n - 1, l, r);
	}
};

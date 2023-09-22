// prefix: lazysegmenttree
// description: segment tree with lazy propagation
struct segtree{
	big n;
	vector<big> seg_t, lazy_t;

	segtree(vector<big> &v){
		n = v.size();
		seg_t = vector<big>(4 * n);
		lazy_t = vector<big>(4 * n, 0);
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

	void push(big node){
		big x = lazy_t[node];

		seg_t[2 * node] += x;
		seg_t[2 * node + 1] += x;

		lazy_t[2 * node] += x;
		lazy_t[2 * node + 1] += x;

		lazy_t[node] = 0;
	}

	void update(big node, big tl, big tr, big l, big r, big new_val){
		if(l > r){
			return;
		}else if(l == tl && tr == r){
			seg_t[node] += new_val;
			lazy_t[node] += new_val;
		}
		else{
			if(lazy_t[node] != 0){
				push(node);
			}

			big tm = (tr - tl) / 2 + tl;

			update(2 * node, tl, tm, l, min(r, tm), new_val);
			update(2 * node + 1, tm + 1, tr, max(l, tm + 1), r, new_val);

			seg_t[node] = combine(seg_t[2 * node], seg_t[2 * node + 1]);
		}
	}

	void update(big l, big r, big new_val){
		update(1, 0, n - 1, l, r, new_val);
	}

	big query(big node, big tl, big tr, big l, big r){
		if (l > r){
			return;
		}else if(l == tl && r == tr){
			return seg_t[node];
		}else{
			if(lazy_t[node] != 0){
				push(node);
			}

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

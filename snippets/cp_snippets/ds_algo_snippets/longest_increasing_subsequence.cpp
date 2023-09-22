// prefix: lis 
// description: longest increasing subsequence
void lis(vector<big> &v, vector<big> &dp){
	big n = v.size();

	// dp[i] = last element in increasing subsequence of length i - 1
	for(big i = 0; i < n; ++i){
		auto it = upper_bound(all(dp), v[i]); 
		if(it == dp.end()){
			dp.push_back(v[i]);
		}else{
			*it = v[i];
		}
	}
}

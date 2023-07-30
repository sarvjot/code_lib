#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

template<typename T>char delim_fun(T t){string s=typeid(t).name();set<string>st={"set", "vector","map"};for(auto a:st){if(s.find(a)!=std::string::npos)return'\n';}return' ';}
template<typename T,typename S,typename Q>ostream &operator<<(ostream &os,tuple<T,S,Q> &t){os<<"("<<get<0>(t)<<", "<<get<1>(t)<<", "<<get<2>(t)<<")";return os;}
template<typename T,typename S>ostream &operator<<(ostream &os,pair<T,S>&p){os<<"("<<p.first<<", "<<p.second<<")";return os;}
template<typename T,typename S>ostream &operator<<(ostream &os,map<T,S>&v){os<<"[ ";for(auto it=v.begin();it!=v.end();it++){os<<"("<<(*it).first<<", "<<(*it).second <<") ";}os <<"]";return os;}
template<typename T>ostream &operator<<(ostream &os,vector<T>&v){char ch=delim_fun(v[0]);if(ch==' ')os<<"[ ";for(auto element:v){os<<element;os<<ch;}if(ch==' ')os<<"]";return os;}
template<typename T>ostream &operator<<(ostream &os,set<T> &v){char ch=delim_fun(*(v.begin()));if(ch==' ')os<<"[ ";for(auto element:v){os<<element;os<<ch;}if(ch==' ')os<<"]";return os;}
template<typename T>ostream &operator<<(ostream &os,multiset<T> &v){char ch=delim_fun(*(v.begin()));if(ch==' ')os<<"[ ";for(auto element:v){os<<element;os<<ch;}if(ch==' ')os<<"]";return os;}
template<typename...Args>void logger(string vars,Args&&...values){cerr<<"\033[31m"<<vars<<" : ";string delim;(...,(cerr<<delim<<values,delim=", "));cerr<<"\033[37m"<<endl;}

#define nl "\n"
#define big long long
#define all(x) (x).begin(), (x).end()
#define precision(x) fixed << setprecision(x)
#define get_set_bits(x) __builtin_popcountll(x) 
#define ordered tree<big, null_type, less<big>, rb_tree_tag, tree_order_statistics_node_update>
#define ordered_ms tree<pair<big, big>, null_type, less<pair<big, big>>, rb_tree_tag, tree_order_statistics_node_update>

#ifdef SARVJOT 
#define ds(statement) cerr << "\033[32m" << statement << "\033[37m" << endl
#define dv(args...) logger(#args, args)
#define sm_line	 cerr << "\033[33m" << "---------X--------" << "\033[37m" << endl
#define lg_line	 cerr << "\033[34m" << "------X----------X------" << "\033[37m" << endl
void print_pbds(ordered &v){cerr<<"\033[31m"<<"[ ";for(auto a:v){cerr<<a<<" ";}cerr<<"]"<<"\033[37m"<<endl;}
void print_pbdsms(ordered_ms &v){cerr<<"\033[31m"<<"[ ";for(auto a:v){cerr<<a<<" ";}cerr<<"]"<<"\033[37m"<<endl;}
#else
#define ds(statement)
#define dv(...)
#define sm_line
#define lg_line
void print_pbds(ordered &v){;}
void print_pbdsms(ordered_ms &v){;}
#endif

const big MOD = 1e9 + 7;
const big INF = INT64_MAX;

struct testcase_generator{
	big rnd(big a, big b) {
		return a + rand() % (b - a + 1);
	}

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

	void generate_tree(big n){
		DSU dsu = DSU(n);
		vector<pair<big, big>> tree_edges;
		tree_edges.reserve(n - 1);

		while(dsu.num_comps > 1){
			big a = rnd(0, n - 1);
			big b = rnd(0, n - 1);

			if(dsu.find(a) != dsu.find(b)){
				tree_edges.push_back({a, b});
				dsu.union_(a, b);
			}
		}

		for(big i = 0; i < n - 1; ++i){
			cout << tree_edges[i].first + 1 << " " << tree_edges[i].second + 1 << nl;
		}
	}
	
	void generate_array(big n, big lower_limit, big upper_limit){
		for(big i = 0; i < n; ++i){
			cout << rnd(lower_limit, upper_limit) << " ";
		}
		cout << nl;
	}

	void generate_set(big n, big lower_limit, big upper_limit){
		set<big> s;
		for(big i = 0; i < n; ++i){
			big x;	  
			do{
				x = rnd(lower_limit, upper_limit);
			}while(s.count(x) > 0);
			s.insert(x);
			cout << x << " ";
		}
		cout << nl;
	}
};

void solve()
{
	srand(time(0));
	testcase_generator tcg;

	// generate testcases here
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	solve();
}

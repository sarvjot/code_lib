#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

template<typename T>char delim_fun(T t){string s=typeid(t).name();set<string> st={"set","vector","map"};for(auto a:st){if(s.find(a)!=std::string::npos)return'\n';}return' ';}
template<typename T,typename S>ostream &operator<<(ostream &os,pair<T,S>&p){os<<"("<<p.first<<", "<<p.second<<")";return os;}
template<typename T,typename S,typename Q>ostream &operator<<(ostream &os,tuple<T,S,Q>&t){os<<"("<<get<0>(t)<<", "<<get<1>(t)<<", "<<get<2>(t)<<")"; return os;}
template<typename T>ostream &operator<<(ostream &os,vector<T>&v){char delim=delim_fun(v[0]);os<<"[";for(auto element:v){os<<delim<<element;}os<<delim<<"]";return os;}
template<typename T>ostream &operator<<(ostream &os,set<T>&v){char delim=delim_fun(*(v.begin()));os<<"{";for(auto element:v){os<<delim<<element;}os<<delim<<"}";return os;}
template<typename T>ostream &operator<<(ostream &os,multiset<T>&v){char delim=delim_fun(*(v.begin()));os<<"{";for(auto element:v){os<<delim<<element;}os<<delim<<"}";return os;}
template<typename T,typename S>ostream &operator<<(ostream &os,map<T,S>&v){os<<"{";for(auto it=v.begin();it!=v.end();it++){os<<"\n{"<<(*it).first<<", "<<(*it).second<<"},";}os<<"\n}";return os;}
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
#define sm_line  cerr << "\033[33m" << "---------X--------" << "\033[37m" << endl
#define lg_line  cerr << "\033[34m" << "------X----------X------" << "\033[37m" << endl
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

void solve(){
    big n;
    cin >> n;
    vector<big> v(n);

    for(big i = 0; i < n; i++){
        cin >> v[i];
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int test = 1;
    cin >> test;
    for (int i = 1; i <= test; i++){
        //cout << "Case #" << i << ": ";
        solve();
    }
    return 0;
}

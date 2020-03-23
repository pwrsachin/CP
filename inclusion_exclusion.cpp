
/*
atcoder beginner 152, problem E
*/
#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define fi first
#define se second
#define pb push_back
#define mk make_pair
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll MOD = 998244353;
 
ll fastpowMOD(ll a, ll p,ll MOD);
ll fastpowMOD(ll a, ll p,ll MOD){ if(p==0) return 1; a %= MOD; ll z = fastpowMOD(a,p/2,MOD); z = (z*z)%MOD; if(p%2) z = (z*a)%MOD; return z; }
 
 
ll combo(ll n, ll k){
 	if(k==0) return 1;
 	ll N=1,D=1;
 	for(ll i = 1;i<=k;i++){
 		N = (((n-i+1)%MOD)*N)%MOD;
 		D = (D*i)%MOD;
	 }
	 
	 return (N*fastpowMOD(D,MOD-2,MOD))%MOD;
 }
 
ll lcm(ll a,ll b){
	return (a*b)/__gcd(a,b);
}

const int maxn = 50+5;
vector< pair<int,int> > edges[maxn];
int n,m;
vector<int> es;//vector to store indices of path
bool dfs(int from,int to,int par){
    if(from==to){
        return true;
    }
    for(pair<int,int> it:edges[from]){
        int a = it.fi;
        int ind = it.se;
        if(a==par) continue;
        if(dfs(a,to,from)){
            es.pb(ind);
            return true;
        }
        return false;
    }
    
    
}


int main(){
    cin>>n;
    for(int i=0;i<n-1;i++){
        int a,b;
        cin>>a>>b;
        edges[a].emplace_back(b,i);
        edges[b].emplace_back(a,i);
    }
    
    cin>>m;
    vector<int> eset(m,0);
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        
        es = vector<int>();
        dfs(a,b,-1);
        for(int e:es){
            eset[i] |= 1LL<<(n-1-e);
        }
        
    }
    
    int ans = 0;
    for(int bit = 0;bit<(1<<m);bit++){
        int mask = 0;
        for(int i=0;i<m;i++){
            if(bit && (1<<(m-1-i))) mask |= eset[i];
        }
        
        int w =  __builtin_popcountll(mask);
        int cnt = 1LL<<(n - 1 - w);
        if (__builtin_popcountll(bit) % 2 == 0) ans -= cnt;
        else ans += cnt;
        
    }
    
    cout<<ans<<"\n";
    
    
}





















#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define fi first
#define se second
#define pb push_back
#define mk make_pair
using namespace std;
typedef long long ll;
typedef long double lld;
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

vector<int> gp[10005];
pair<int,int> best = {-1,-1};

void dfs(int s,int par,int len){
    best = max(best,mk(len,s));
    for(auto it:gp[s]){
        if(it!=par){
            dfs(it,s,len+1);
        }
    }
}


int main(){
	fastio;
	int n;cin>>n;
	for(int i=0;i<n-1;i++){
		int x,y;
		cin>>x>>y;
		x--,y--;
		gp[x].pb(y);
		gp[y].pb(x);
		
	}
	
	dfs(0,-1,0);
	
	int from = best.se;
	dfs(from,-1,0);
	
	cout<<best.fi<<"\n";
	
	
}
 
 
 
 

//codeforces div-2 (290) - C//

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
const ll mod = 1e9+7;
 
ll fastpowMOD(ll a, ll p,ll MOD);
ll fastpowMOD(ll a, ll p,ll MOD){ if(p==0) return 1; a %= MOD; ll z = fastpowMOD(a,p/2,MOD); z = (z*z)%MOD; if(p%2) z = (z*a)%MOD; return z; }
 
ll lcm(ll a,ll b){
	return (a*b)/__gcd(a,b);
}

vector< vector<ll> > gp(26);
string ans;
vector<bool> vis(26,false);
vector<bool> cycle(26,false);

void dfs(ll u){
	vis[u] = true;
	cycle[u] = true;
	for(auto it:gp[u]){
		if(cycle[it]){
			cout<<"Impossible\n";
			exit(0);
		}
		if(!vis[it]){
			dfs(it);
		}
	}
	cycle[u] = false;
	ans += ('a'+u);
}

void solve(){
	ll n;cin>>n;
	vector<string> str(n);
	for(ll i=0;i<n;i++){
		cin>>str[i];
	}
	
	for(ll i=1;i<n;i++){
		ll j = 0;
		while(j<str[i].size() && j<str[i-1].size() && str[i][j]==str[i-1][j]){
			j++;	
		}
		if(j==str[i].size()){
			cout<<"Impossible\n";
			return;
		}
		gp[str[i-1][j]-'a'].pb(str[i][j]-'a');
	}
	
	for(ll i=0;i<26;i++){
		if(!vis[i]){
			dfs(i);
		}
	}
	
	reverse(ans.begin(),ans.end());
	cout<<ans<<"\n";
	
}

int main(){
    fastio;
    ll t=1;//cin>>t;
    for(ll i=1;i<=t;i++){
    	solve();
	}	
}



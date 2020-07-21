//div-2 (244) - C//

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

vector < vector<ll> > g(1e5+100), gr(1e5+100);
vector<bool> used(1e5+100,false);
vector<ll> order, component;
vector<ll> cost(1e5+100,0);
map<ll,ll> mp;
void dfs1 (ll v) {
    used[v] = true;
    for (ll i=0; i<g[v].size(); ++i)
        if (!used[ g[v][i] ])
            dfs1 (g[v][i]);
    order.push_back (v);
}

void dfs2 (ll v) {
    used[v] = true;
    //component.push_back (v);
    mp[cost[v]] ++; 
    for (ll i=0; i<gr[v].size(); ++i)
        if (!used[ gr[v][i] ])
            dfs2 (gr[v][i]);
}

int main() {
	fastio;
    ll n,m;
    cin>>n;
    for(ll i=0;i<n;i++){
    	cin>>cost[i];
	}
	cin>>m;
    for (ll i=0;i<m;i++) {
        ll a, b;
        cin>>a>>b;
        a--;b--;
        g[a].push_back (b);
        gr[b].push_back (a);
    }

    used.assign (n, false);
    for (ll i=0; i<n; ++i)
        if (!used[i])
            dfs1 (i);
    used.assign (n, false);
    
    ll mc = 0, nw = 1;
    for (ll i=0; i<n; ++i) {
    	mp.clear();
        ll v = order[n-1-i];
        if (!used[v]) {
            dfs2 (v);
            
            mc = (mc+(mp.begin()->first));
            nw = (nw * (mp.begin()->second))%mod;
            //component.clear();
        }
    }
    cout<<mc<<" "<<nw<<"\n";
}





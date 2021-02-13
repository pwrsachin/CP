//cses company queries 1
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
const ll MOD = 1e9+7;
ll fastpowMOD(ll a, ll p,ll MOD);
ll fastpowMOD(ll a, ll p,ll MOD){ if(p==0) return 1; a %= MOD; ll z = fastpowMOD(a,p/2,MOD); z = (z*z)%MOD; if(p%2) z = (z*a)%MOD; return z; }
const ll maxn = 1e6+10; 
vector<ll> gp[maxn];
ll bin[maxn][25];

void bin_lift(ll v,ll pr){
	bin[v][0] = pr;
	for(ll i=1;i<25;i++){
		if(bin[v][i-1]!=-1){
			bin[v][i] = bin[bin[v][i-1]][i-1];
		}
		else{
			bin[v][i] = -1;
		}
	}
	for(auto it:gp[v]){
		if(it==pr) continue;
		bin_lift(it,v);
	}
}

ll query(ll v,ll k){
	for(ll i=24;i>=0 && v!=-1;i--){
		//cout<<((1<<i)&k)<<" "<<i<<" "<<(1<<i)<<"\n";
		if((1<<i)&k){
			v = bin[v][i];
		}
	}
	//cout<<"\n";
	return v;
}

/*ll query(int src,int jump){


          if(src==-1 or  jump==0)return src;

          for(int i=29;i>=0;i--){
             if( jump>= (1<<i)){
                    return query(bin[src][i],jump-(1<<i));

             }

          }

}*/


void solve(){
	ll n,q;cin>>n>>q;
	for(ll i=2;i<=n;i++){
		ll x;cin>>x;
		gp[i].pb(x);
		gp[x].pb(i);
	}
	bin_lift(1,-1);
	//cout<<bin[2][0]<<"jbf\n";
	//cout<<query(2,1)<<"\n";
	for(ll i=0;i<q;i++){
		ll v,k;cin>>v>>k;
		cout<<query(v,k)<<"\n";
	}
	//cout<<"\n";
}

int main(){
    fastio;
    ll t=1;
	//cin>>t;
    for(ll j=0;j<t;j++){
    	solve();
	}
}



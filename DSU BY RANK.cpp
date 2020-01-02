#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define fi first
#define se second
#define pb push_back
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll MOD = 1e9+7;

ll sizea[500005],par[500005],ranki[500005];
ll n,m;
ll find_set(ll v) {
    if (v == par[v])
        return v;
    return par[v] = find_set(par[v]);
}

void make_set(ll v) {
    par[v] = v;
    //sizea[v] = 1;
    ranki[v] = 0;
}

void union_sets(ll a,ll b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        /*if (sizea[a] < sizea[b]) //by size or depth
            swap(a, b);
        par[b] = a;
        sizea[a] += sizea[b];*/
        
        if (ranki[a] < ranki[b])   //by rank
            swap(a, b);
        par[b] = a;
        if (ranki[a] == ranki[b])
            ranki[a]++;
        
    }
}

int main(){
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		par[i] = i;
		//sizea[i] = 1;
		ranki[i] = 0;
	}
	
	for(ll i=0;i<m;i++){
		ll k;
		cin>>k;
		ll h;
		if(k>0) cin>>h;
		for(ll j=1;j<k;j++)
        {
            ll x;
            cin>>x;
            union_sets(x,h);
        }
	}	
	
	map<ll,ll> mp;
	
	for(ll i=1;i<=n;i++){
		ll see = find_set(i);
		mp[par[i]]++;
		//cout<<par[i]<<" ";
	} 
	//cout<<"\n";
	for(ll i=1;i<=n;i++){
		cout<<mp[par[i]]<<" ";
	}
	cout<<"\n";
	
	
	
		
	
}


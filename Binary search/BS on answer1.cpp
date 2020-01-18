#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;
const ll MOD = 1e9+7;

bool can(vector<ll> &x,ll n,ll mid, ll c){
	ll placed = 1, last = x[0];
	for(ll i=1;i<n;i++){
		if(x[i]-last>=mid){
			placed++;
			last = x[i];
		}
		if(placed==c) return true;
	}
	return false;
}
 
int main() {
	fastio;
	ll t;
	cin>>t;
	while(t--){
		ll n,c;
		cin>>n>>c;
		vector<ll> x(n);
		for(ll i=0;i<n;i++){
			cin>>x[i];
		}
		sort(x.begin(),x.end());
		ll lowd = x[1]-x[0], highd = x[n-1]-x[0],mid;
		ll ans = 0;
		while(lowd<=highd){
			mid = lowd + (highd-lowd)/2;
			
			if(can(x,n,mid,c)){
				lowd = mid+1;
				ans = mid;
			}
			else{
				highd = mid-1;
			}
			
		}
		cout<<ans<<"\n";
	}
	
}

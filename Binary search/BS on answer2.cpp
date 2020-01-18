#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define pb push_back
using namespace std;
typedef long long ll;
const ll MOD = 1e9+7;
ll n,m;
vector< vector<ll> > a;
ll a1=0,a2=0;
bool can(ll mid){
	vector<ll> msk((1<<m),-1);
	for(ll i=0;i<n;i++){
		ll cur = 0;
		for(ll j=0;j<m;j++){
			if(a[i][j]>=mid)
			cur ^= (1<<j);
		}
		msk[cur] = i;	
	}
	if(msk[(1<<m)-1]!=-1){
		a1 = msk[(1<<m)-1];
		a2 = msk[(1<<m)-1];
		return true;
	}
	for(ll i=0;i<(1<<m);i++){
		for(ll j=0;j<(1<<m);j++){
			if(msk[i]!=-1 && msk[j]!=-1 && (i|j)==(1<<m)-1){
				a1 = msk[i];a2 = msk[j];
				return true;
			}
		}
	}
	return false;
}

int main(){

	cin>>n>>m;
	a.resize(n,vector<ll>(m,0));
	for(ll i=0;i<n;i++){
		for(ll j=0;j<m;j++){
			cin>>a[i][j];
		}
	}
	ll l=0,r=1e9;
	ll ans = -1;
	
	while(l<=r){
		
		ll mid = (l+r)/2;
		if(can(mid)){
			l = mid+1;
		}
		else{
			r = mid-1;
		}
	}
	cout<<a1+1<<" "<<a2+1<<"\n";
	
	
}

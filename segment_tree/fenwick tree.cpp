#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define fi first
#define se second
#define pb push_back
#define mk make_pair
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll MOD = 1e9+7;
 
ll fastpowMOD(ll a, ll p,ll MOD);
ll fastpowMOD(ll a, ll p,ll MOD){ if(p==0) return 1; a %= MOD; ll z = fastpowMOD(a,p/2,MOD); z = (z*z)%MOD; if(p%2) z = (z*a)%MOD; return z; }
 
ll lcm(ll a,ll b){
	return (a*b)/__gcd(a,b);
}

const int maxn = 200005;
int n,q;
vector<ll> tree(maxn,0);
void update(int idx,int val){
	while(idx<=n){
		tree[idx] += val;
		idx += (idx&(-idx));
	}
}

ll read(int idx){
	ll sum = 0;
	while(idx>0){
		sum += tree[idx];
		idx -= (idx&(-idx)); 
	}
	return sum;
}

int main(){
	fastio;
	cin>>n>>q;
	vector<int> a(n,0);
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		update(x,1);
		update(y+1,-1);
	}
	
	sort(a.begin(),a.end());
	vector<ll> freq(n,0);
	for(int i=0;i<n;i++){
		freq[i] = read(i+1);
	}
	sort(freq.begin(),freq.end());
	ll ans = 0;
	for(int i=n-1;i>=0;i--){
		ans += a[i]*freq[i];
	}
	cout<<ans<<"\n";
	
	
}

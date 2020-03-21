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




int main(){
	fastio;
	string str;
	cin>>str;
	int n = (int) str.size();
	vector<int> pal(2*n+1,0);
	string mstr = "";
	
	for(int i=0;i<n;i++){
		mstr += "#";
		mstr += str[i];
	}
	mstr += "#";
	
	int l = 0, r = 0;
	int pc = 0;
	for(int i=1;i<=2*n;i++){
		if(i<r){
			pal[i] = min(pal[2*pc-i],r-i);
				
		}
		else{
			pal[i] = 0;
		
		}
			
			int lc = i-1-pal[i], rc = i+1+pal[i];
			while(lc>=0 && rc<=2*n && mstr[lc]==mstr[rc]){
				pal[i]++;
				lc = i-1-pal[i];
				rc = i+1+pal[i];
			}
			
			if(r<i+pal[i]){
				r = i+pal[i];
				pc = i;
			}	
			
		
			
		
	
	}
	int maxl = 0;
	int maxp = 0;
	cout<<mstr<<"\n";
	for(int i=0;i<=2*n;i++){
		cout<<pal[i];
		if(maxl<pal[i]){
			maxl = pal[i];
			maxp = i;
		}
	}
	cout<<"\n";
	cout<<maxl<<"\n";
	int rl = maxp-pal[maxp];
	int rr = maxp+pal[maxp];
	
	for(int i=rl;i<=rr;i++){
		if(mstr[i]!='#'){
			cout<<mstr[i];
		}
	}
	
	cout<<"\n";
	
	
}
 
 
 
 

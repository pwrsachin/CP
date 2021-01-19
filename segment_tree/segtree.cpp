//https://codeforces.com/edu/course/2/lesson/4/1/practice/contest/273169/problem/C
#include<bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define pb push_back
#define fi first
#define se second
using namespace std;
typedef long long ll;
const ll maxn = 1e6+100;
const ll inf = 1e18;

class segtree{
	public:
		ll li,ri,mn,cmn;
		segtree *left,*right;
		segtree(ll l,ll r,vector<ll> &a){
			this->li = l;
			this->ri = r;
			if(li==ri){
				this->mn = a[l];
				this->cmn = 1;
			}
			else{
				ll m = (l+r)/2;
				this->left = new segtree(l,m,a);
				this->right = new segtree(m+1,r,a); 
			}
			recalc();
		}
		void recalc(){
			if(li==ri){
				return;
			}
			if(left->mn<right->mn){
				mn = left->mn;
				cmn = left->cmn;
			}
			else if(left->mn>right->mn){
				mn = right->mn;
				cmn = right->cmn;
			}
			else{
				mn = left->mn;
				cmn = left->cmn + right->cmn;
			}
			
		}
		void pupdate(ll i,ll nv){
			if(li==ri){
				mn = nv;
				cmn = 1;
				return;
			}
			if(i<=left->ri){
				left->pupdate(i,nv);
			}
			else{
				right->pupdate(i,nv);
			}
			recalc();
		}
		pair<ll,ll> query(ll l,ll r){
			if(l>ri || r<li){
				return {inf,inf};
			}
			if(l<=li && r>=ri){
				return {mn,cmn};
			}
			pair<ll,ll> l1,r1;
			l1 = left->query(l,r);
			r1 = right->query(l,r);
			if(l1.fi<r1.fi){
				return {l1.fi,l1.se};
			}
			else if(l1.fi>r1.fi){
				return {r1.fi,r1.se};
			}
			else{
				return {l1.fi,l1.se+r1.se};
			}
		}
};

void solve(){
	ll n,m;
	cin>>n>>m;
	vector<ll> a(n,0);
	for(ll i=0;i<n;i++){
		cin>>a[i];
	}
	segtree tree(0,n-1,a);
	for(ll i=0;i<m;i++){
		ll t,l,r;cin>>t>>l>>r;
		if(t==1){
			tree.pupdate(l,r);
		}
		else{
			pair<ll,ll> p = tree.query(l,r-1);
			cout<<p.fi<<" "<<p.se<<"\n";
		}
	}
}

int main(){
	fastio;
	int t = 1;
	//cin>>t;
	for(int i=0;i<t;i++){
		solve();	
	}
}

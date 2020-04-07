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

//application of biparigraph codeforces round 170(div.1)- A//


const int maxn = 1005;
vector<int> biparti_graph[maxn];
vector<bool> vis(maxn,false);

void dfs(int v){
    if(!vis[v]){
        vis[v] = true;
        for(auto it:biparti_graph[v]){
            if(!vis[it]){
                dfs(it);
                vis[it] = true;
            }
        }
        
    }
}

int main(){
	fastio;
	int n,m;
	cin>>n>>m;
	int ml = 0;
	for(int i=0;i<n;i++){
	    int k;cin>>k;
	    if(k==0) ml++;
	    for(int j=0;j<k;j++){
	        int x;cin>>x;x--;
	        biparti_graph[i].pb(n+x);
	        biparti_graph[n+x].pb(i);
	    }
	}
    
    int comp = 0;
    for(int i=0;i<n;i++){
        if(!vis[i]){
            comp++;
            dfs(i);
        }
    }
    //cout<<comp<<"\n";
    if(ml==n){
        cout<<n<<"\n";
    }
    else{
        cout<<comp-1<<"\n";
    }
    
	

}

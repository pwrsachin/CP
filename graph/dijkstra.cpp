#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mk make_pair
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long int ll;
typedef long double ld;
typedef unsigned long long int ull;
void SieveOfEratosthenes(ll n);
ll fastpowMOD(ll a, ll p,ll MOD);
ll lcm(ll a, ll b);
const int LIM = 1e5+5; //MOD = 998244353;
ll MOD =  1e18+7;
ll fastpowMOD(ll a, ll p,ll MOD){ if(p==0) return 1; a %= MOD; ll z = fastpowMOD(a,p/2,MOD); z = (z*z)%MOD; if(p%2) z = (z*a)%MOD; return z; }
bool seive[LIM];
/* 
void SieveOfEratosthenes(ll n)
{ memset(seive, true, sizeof(seive));
seive[0] = false;
seive[1] = false;
 for (ll p=2; p*p<=n; p++) if (seive[p] == true) for (ll i=p*p; i<=n; i += p) seive[i] = false; }
 
 
 ll combo(ll n, ll k){
 	if(k==0) return 1;
 	ll N=1,D=1;
 	for(ll i = 1;i<=k;i++){
 		N = (((n-i+1)%MOD)*N)%MOD;
 		D = (D*i)%MOD;
	 }
	 
	 return (N*fastpowMOD(D,MOD-2,MOD))%MOD;
 }
 */
 
ll lcm(ll a, ll b)  
 {  
    return (a*b)/__gcd(a, b);  
 } 
/*********************************************/

const int maxn = 1e5+5;
vector<ll> dist(maxn);
vector<int> par(maxn);
vector<bool> vis(maxn,false);
vector< pair<int,ll> > graph[maxn]; 

//time compexity O(n+ mlogm)//
/*Note that Dijkstra’s algorithm will visit vertices in non-decreasing shortest-path weight since
on each step it visits unvisited vertices that have the minimum shortest-path weight from s.*/
int main(){
    fastio;
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int x,y;
        ll w;
        cin>>x>>y>>w;
        graph[x].emplace_back(y,w);
        graph[y].emplace_back(x,w);
    }
    
    for(int i=2;i<=n;i++){
        dist[i] = (ll)1e18;
    }
    dist[1] = 0;
    set< pair<ll,int> > pq;
    pq.insert(mk(0,1));  // we can use priority queue
    
    while(!pq.empty()){
        pair<ll,int> tmp = *pq.begin();
        pq.erase(pq.begin());
        int cv = tmp.se;  //coming vertex
        if(vis[cv]) continue;
        vis[cv] = true;
        for(auto it:graph[cv]){
            
            if(dist[cv]+it.se<dist[it.fi]){
                dist[it.fi] = dist[cv]+it.se;
                par[it.fi] = cv;
                pq.insert(mk(dist[it.fi],it.fi));
            }
        
        }
        
    }
    
    if(!vis[n]){
        cout<<-1<<"\n";
        return 0;
    }
    
    vector<int> short_path;
    short_path.pb(n);
    int cur = n;
    while(cur!=1){
        short_path.pb(par[cur]);
        cur = par[cur];
    }
    //short_path.pb(1);
    reverse(short_path.begin(),short_path.end());
    
    for(auto it:short_path){
        cout<<it<<" ";
    }
    cout<<"\n";
    
}
















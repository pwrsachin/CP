#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define fi first
#define se second
#define pb push_back
#define mk make_pair
using namespace std;
typedef long long ll;

int main(){
    fastio;
    int n,m;
    cin>>n;
    vector<ll> a(n,0);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    vector<int> lis[60];
    for(int i=0;i<60;i++){
        for(int j=0;j<n;j++){
            if(a[j]%2){
                lis[i].pb(j);
            }
            a[j] /= 2;
        }
        
    }
    
    for(int i=0;i<60;i++){
        if(lis[i].size()>2){
            cout<<3<<"\n";
            return 0;
        }
    }
    
    vector<int> gp[n];
    /*for(int i=0;i<m;i++){
        int x,y;cin>>x>>y;
        x--,y--;
        gp[x].pb(y);
        gp[y].pb(x);
    }*/
    
    for(int i=0;i<60;i++){
        if(lis[i].size()==2){
            gp[lis[i][0]].pb(lis[i][1]);
            gp[lis[i][1]].pb(lis[i][0]);
        }
        
    }
    
    int ans  = 1e9+5;
    //to fing shortest cyclic path between u&v, remove edge u-v and find shortest path between u-v + 1//
    for(int i=0;i<n;i++){
        for(auto it:gp[i]){
            map< pair<int,int> , int> dist;
            dist[{i,it}] = 0;
            vector< pair<int,int> > q = {{i,it}};
            for(int j=0;j<q.size();j++){
                int a = q[j].fi, b = q[j].se;
                for(auto it1:gp[b]){
                    if(it1==a || dist.count({b,it1})) continue;
                    dist[{b,it1}] = dist[{a,b}] + 1;
                    q.pb(make_pair(b,it1));
                }
                
                
            }
            for(auto an:dist){
                if(an.fi.se==i){
                    ans = min(ans,1+an.se);
                }
            }
            
            
        }
    }
    
    if(ans==1e9+5){
        cout<<-1<<"\n";
    }
    else{
        cout<<ans<<"\n";
    }
    
    
    
    
    
}

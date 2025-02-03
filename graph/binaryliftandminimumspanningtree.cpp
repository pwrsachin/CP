//https://codeforces.com/contest/609/problem/E
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 200005;
ll bin[N][25];
int n,m;
vector<vector<pair<int,int>>> mst(N);
vector<int> par(N,0);
vector<ll> depth(N,0);
vector<int> siz(N,0);
ll maxW[N][25];


void bin_lift(ll v,ll pr){
	bin[v][0] = pr;
	for(ll i=1;i<24;i++){
		if(bin[v][i-1]!=-1){
			bin[v][i] = bin[bin[v][i-1]][i-1];
			maxW[v][i] = max(maxW[v][i-1],maxW[bin[v][i-1]][i-1]);
		}
		else{
			bin[v][i] = -1;
		}
	}
	for(auto it:mst[v]){
		if(it.first==pr) continue;
		depth[it.first] = depth[v] + 1;
		maxW[it.first][0] = it.second;
		bin_lift(it.first,v);
	}
}
 
int find(int x){
	if(x==par[x]) return x;
	return par[x] = find(par[x]);
}

void merge(int x,int y){
	int px = find(x);
	int py = find(y);
	if(px!=py){
		if(siz[px]<siz[py]) swap(px,py);
		par[py] = par[px];
		siz[px] += siz[y]; 
	}
}


ll query(int x,int y){
	if(depth[x]<depth[y]) swap(x,y);
	int k = depth[x]-depth[y];
	//cout<<k<<" diff "<<x<<" "<<y<<"\n";
	ll res = 0;
	for(int i=0;i<=24;i++){
		if((1<<i)&k){
			res = max(res,maxW[x][i]);
			x = bin[x][i];
		}
	}
	if(x==y) return res;
	for(int i=24;i>=0;i--){
		if(bin[x][i]==bin[y][i]) continue;
		res = max({res,maxW[x][i],maxW[y][i]});
		x = bin[x][i];
		y = bin[y][i];
	}
	res = max({res,maxW[x][0],maxW[y][0]});
	return res;

}


int main(){
    cin>>n>>m;
    vector<vector<int>> edges;
    for(int i=0;i<m;i++){
    	int u,v,w;cin>>u>>v>>w;
    	edges.push_back({u,v,w});
    }

    vector<int> idx(m);
	iota(idx.begin(),idx.end(),0);
	iota(par.begin(),par.end(),0);
	fill(siz.begin(), siz.end(), 1);
	vector<bool> vis(m,false);

	sort(idx.begin(),idx.end(),[&](int i,int j){
		return edges[i][2]<edges[j][2];
	});
	
	ll mans = 0;
	int root = 0;
	for(int j=0;j<m;j++){
		int i = idx[j];
		int from = edges[i][0]-1;
		int to = edges[i][1]-1;
		int w = edges[i][2];
		if(find(from)==find(to)) continue;
		vis[i] = true;
		root = from;
		mans += w;
		merge(from,to);
		mst[to].push_back({from,w});
		mst[from].push_back({to,w});
	}





	bin_lift(root,-1);

	//cout<<query(6,1);

	for(int i=0;i<m;i++){
		if(vis[i]){
			cout<<mans<<"\n";
			continue;
		}
		vis[i] = true;
		int from = edges[i][0]-1;
		int to = edges[i][1]-1;
		int w = edges[i][2];
		ll rans = mans-query(from,to)+w;
		cout<<rans<<"\n";
	}
	cout<<"\n";

    return 0;
}

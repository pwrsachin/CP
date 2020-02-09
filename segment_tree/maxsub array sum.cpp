#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;


struct segnode{
  int sum;
  int psum;
  int ssum;
  int msb;

  };

struct segnode merge(segnode lt, segnode rt){
    segnode node;
    node.sum = lt.sum + rt.sum;
    node.ssum = max(rt.ssum,lt.ssum+rt.sum);
    node.psum = max(lt.psum,lt.sum+rt.psum);
    node.msb = max(max(lt.msb,rt.msb),lt.ssum+rt.psum);

    return node;

  }

struct segnode emptyn(){
    segnode node;
    node.sum = 0;
    node.ssum = -9999999;
    node.psum = -9999999;
    node.msb = -9999999;
    return node;
  }


struct segnode tree[4*50000];

void build(vector<int> &a, int v, int tl, int tr) {
  
    if (tl == tr) {
        tree[v].sum = a[tl];
        tree[v].ssum = a[tl];
        tree[v].psum = a[tl];
        tree[v].msb = a[tl];
        
    } else {
        int tm = (tl + tr) / 2;
        build(a, v*2, tl, tm);
        build(a, v*2+1, tm+1, tr);
        tree[v].sum = tree[2*v].sum + tree[2*v+1].sum;
        tree[v].ssum = max(tree[2*v+1].ssum,tree[2*v].ssum+tree[2*v+1].sum);
        tree[v].psum = max(tree[2*v].psum,tree[2*v].sum+tree[2*v+1].psum);
        tree[v].msb = max(max(tree[2*v].msb,tree[2*v+1].msb),tree[2*v].ssum+tree[2*v+1].psum);
        
    }
}

segnode rmsb(int v, int tl, int tr, int l, int r) {
    if (l > r) 
       
        return emptyn();

    if (l == tl && r == tr) {
        return tree[v];
    }
    int tm = (tl + tr) / 2;
    segnode lt = rmsb(v*2, tl, tm, l, min(r, tm));
	  segnode rt = rmsb(v*2+1, tm+1, tr, max(l, tm+1), r);

    return merge(lt,rt);
	
}


int main(){
	cin>>n;
	vector<int> a(n,0);
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	
	build(a,1,0,n-1);
	int q;
	cin>>q;
	//cout<<tree[0].sum<<"\n";
	while(q--){
		int x,y;
		cin>>x>>y;
		x--;y--;
		cout<<rmsb(1,0,n-1,x,y).msb<<"\n";
	}
	
}





/*void update(int v, int tl, int tr, int pos, int new_val) {
    if (tl == tr) {
        t[v] = new_val;
    } else {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            update(v*2, tl, tm, pos, new_val);
        else
            update(v*2+1, tm+1, tr, pos, new_val);
        t[v] = t[v*2] + t[v*2+1];
    }
}*/

/*
10
10 11 -12 0 5 -13 15 6 -2 17
*/

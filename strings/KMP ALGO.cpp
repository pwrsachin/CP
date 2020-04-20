//codeforces beta round 93(div-1)-B (PASSWORD)// 
#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define fi first
#define se second
#define pb push_back
#define mk make_pair
using namespace std;
typedef long long ll;
typedef long double lld;
const ll INF = 1e18;
const ll MOD = 1e9+7;
 
ll fastpowMOD(ll a, ll p,ll MOD);
ll fastpowMOD(ll a, ll p,ll MOD){ if(p==0) return 1; a %= MOD; ll z = fastpowMOD(a,p/2,MOD); z = (z*z)%MOD; if(p%2) z = (z*a)%MOD; return z; }
 
ll lcm(ll a,ll b){
	return (a*b)/__gcd(a,b);
}
int maxn = 1e6+5;
vector<ll> lps(maxn,0);

void prefix(string s){
    int n = s.size();
    int len = 0, i = 1;
    while(i<n){
        if(s[len]==s[i]){
            len++;
            lps[i] = len;
            i++;
        }
        else{
            if(len!=0){
                len = lps[len-1];
            }
            else{
                lps[i] = 0;
                i++;
            }
            
        }
        
    }
    
}

int main(){
    fastio;
    string s;
    cin>>s;
    prefix(s);
    int n = s.size();
    if(lps[n-1]==0){
        cout<<"Just a legend\n";
        return 0;
    }
    bool f = false;
    
    for(int i=1;i<n-1;i++){
        if(lps[i]==lps[n-1]){
            f = true;break;
        }
    }
    
    if(f){
        cout<<s.substr(0,lps[n-1])<<"\n";
        return 0;
    }
    
    ll c = lps[n-1]-1;
    
    if(lps[c]==0){
        cout<<"Just a legend\n";
    }
    else{
        cout<<s.substr(0,lps[c])<<"\n";
        
    }
    
    
}

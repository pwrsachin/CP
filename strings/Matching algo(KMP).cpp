//codeforces 342 div-2(B) //
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
vector<int> matchind;

//KMP FUNCTION TO FIND STARTING INDEICES OF MATCHING PATTERN IN THE STRING//
void KMP(string s,string t){
    int n = s.size();
    int m = t.size();
    int i=0, j=0;
    while(i<n){
        if(s[i]==t[j]){
            i++;j++;
        }
        if(j==m){
            matchind.pb(i-j);
            j = lps[j-1];
        }
        else if(i<n && s[i]!=t[j]){
            if(j>0){
                j = lps[j-1];
            }
            else{
                i++;
            }
            
        }
    }
}

//FUNCTION TO OBTAIN LPS ARRAY//
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
    string s,t;
    cin>>s>>t;
    int m = t.size();
    prefix(t);
    KMP(s,t);
    int ans = 0;
    int pr = -1000006;
    for(auto it:matchind){
        if(it-pr>=m){
            ans ++;
            pr = it;
        }
    }
    cout<<ans<<"\n";
    
}

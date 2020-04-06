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

int exten_eucl_gcd(int a,int b,int &x,int &y){
	if(a==0){
		x = 0; y = 1;
		return b;
	}
	int x1,y1;
	int d = exten_eucl_gcd(b%a,a,x1,y1);
	x = y1-(b/a)*x1;
	y = x1;
	return d;
}
 
 
int main(){
	fastio;
	int a,b,c;
	cin>>a>>b>>c;
	int x,y;
	int g = exten_eucl_gcd(a,b,x,y);
	if(c%g!=0){
		cout<<"No\n";
		return 0;
	}
	
	x *= c/g;
	y *= c/g;
	//printf("%d %d\n",x,y);
	//for t->[t1,t2], x' = x + t*(b/g), y' = y + t*(a/g) for +ve x' & y'//
	
	double t1 = ceil((-1.0 * x * g)/b);
    double t2 = floor((1.0 * y * g)/a);
    printf("%lf %lf\n", t1, t2);
    if (t2 >= t1)
        printf("Yes\n");
    else
        printf("No\n");
        
    
}
 
 
 

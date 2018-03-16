///---------------------NumberTheory-----------------------
#include<bits/stdc++.h>
using namespace std;
#define X           first
#define Y           second
#define N           1000005
#define pb          push_back
#define pp          pop_back
#define mk          make_pair
#define PI          acos(-1)
#define EPS         1e-9
#define INF         1<<29
#define ln          '\n'
#define sp          ' '
#define redian      180/PI
#define all(x)      x.begin(),x.end()
#define Sort(x)     sort(all(x))
#define mem(a,b)    memset(a,b,sizeof(a))
#define lpa(p,v)    for(auto p:(v))
#define lp(a,b,c)   for(int a=(b);a<(c);a++)
#define lp0(a,n)    lp(a,0,n)
#define lpr(a,b,c)  for(int a=(b);a>=(c);a--)
#define faster      ios_base::sync_with_stdio(0);cin.tie(0);

const int MOD=1e9+7;
typedef long long ll;
///-------------------------Sieve---------------------------
vector<int> primes;
bool p[N];
void sieve()
{
    int sq=sqrt(N);
    primes.push_back(2);
    for(int i=3;i<=sq;i+=2)
    {
        if(!p[i])
        {
            primes.push_back(i);
            for(int j=i+i;j<=N;j+=i)p[j]=1;
        }
    }
}
///-------------------------NumDiv---------------------------
ll numDiv(ll x) {
	ll PF_idx = 0, PF = primes[PF_idx], ans = 1;
	while (PF * PF <= x) {
		ll power = 0;
		while (x % PF == 0) { x /= PF; power++; }
		ans *= (power + 1);
		PF = primes[++PF_idx];
	}
	if (x != 1) ans *= 2;
	return ans;
}
///-----------------------SumDiv---------------------------
ll sumDiv(ll x) {
	ll PF_idx = 0, PF = primes[PF_idx], ans = 1;
	while (PF * PF <= x) {
		ll power = 0;
		while (x % PF == 0) { x /= PF; power++; }
		ans *= ((ll)pow((double)PF, power + 1.0) - 1) / (PF - 1);
		PF = primes[++PF_idx];
	}
	if (x != 1) ans *= ((ll)pow((double)x, 2.0) - 1) / (x - 1);
return ans;
}
///----------------------EulerPhi--------------------------------
ll EulerPhi(ll x) {
	ll PF_idx = 0, PF = primes[PF_idx], ans = x;
	while (PF * PF <= x) {
		if (x % PF == 0) ans -= ans / PF;
		while (x % PF == 0) x /= PF;
		PF = primes[++PF_idx];
	}
	if (x != 1) ans -= ans / x;
return ans;
}
///------------------ExtendedEuclide------------------------------
int x,y,d;
void extendedEuclid(int a, int b) {
	if (b == 0) { x = 1; y = 0; d = a; return; }
	extendedEuclid(b, a % b);
	int x1 = y;
	int y1 = x - (a / b) * y;
	x = x1;
	y = y1;
}
///------------------------BigMod-----------------------------------
ll BigMod(ll b,ll p,ll M)
{
    if(p==0)return 1%M;
    ll x=BigMod(b,p/2,M);
    x=(x*x)%M;
    if(p&1)
        x=(x*b)%M;
    return x;

}
///---------------------GCD & LCM-------------------------------------
int gcd(int a,int b)
{
    if(b==0)return a;
    return gcd(b,a%b);
}
int lcm(int a,int b)
{
    return (a/gcd(a,b))*b;
}
///------------------Factorial and Inverse Factorial-----------------
int fact[N],ifact[N];
void factorial(){
    ifact[0] = fact[0] = 1;
    for (int i = 1; i <= N; ++i) {
        fact[i] = fact[i - 1] * (ll) i % MOD;
    }
    ifact[N] = (int)BigMod(fact[N], MOD - 2, MOD);
    for (int i = N - 1; i >= 1; --i) {
        ifact[i] = ifact[i + 1] * (i + 1LL) % MOD;
    }
}
///----------------------nCr----------------------------------------
int nCr(int n, int r)
{
	if (n < 0 || r < 0 || r > n) return 0;
	return ll(fact[n]) * ifact[r] %MOD * ifact[n - r] % MOD;
}
int main()
{

}

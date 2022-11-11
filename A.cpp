#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define repab(i,a,b) for (int i=a;i<=(int)(b); i++)
typedef vector<int> vi;
typedef vector<long long> vll;
typedef map<int,int> mapii;
#define pb push_back 
#define all(x) x.begin(),x.end()
#define maxn
#define endl "\n"
#define NO cout<<"NO"<<endl
#define YES cout<<"YES"<<endl
#define fi first
#define se second
#define writefile(f) freopen (f,"r",stdin)
#define readfile(f)  freopen(f,"w",stdout)
const int maxn1=1e6;
ll fac[maxn1+1];
ll inv[maxn1+1];
const ll mod=1e9+7;
ll be ( ll x,ll y,ll p){
   ll res=1;
   x=x%p;
   while (y){
      if (y&1){
        res*=x;
        res%=p;
      }
      y>>=1;
      x*=x;
      x%=p;


   }


return res;
}
void process (ll p){
 fac[0]=1;
 rep1(i,maxn1){
 fac[i]=fac[i-1]*i;
 fac[i]%=p;
}
}

void process1 (ll p)
{
  inv[maxn1]=be(fac[maxn1],p-2,p);
  for (int i=maxn1;i>=1;--i){
     inv[i-1]=(inv[i]*i)%p;

  }



}
ll com(ll n,ll k,ll p){
  return fac[n]*inv[k]%p*inv[n-k]%p;
}







 
int main ()
{ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(0);
  process(mod);
  process1(mod);
   int n;
   cin>>n;
   while (n--){
    ll a,b;
    cin>>a>>b;
    cout<<com(a,b,mod)<<endl;
   }
   
}

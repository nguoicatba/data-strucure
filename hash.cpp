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
long long f[500010],p[500010];
long long base=31;
long long mod=1e9+7;
 long long gethash(int l,int r){
   long long ans=(f[r]-f[l-1]*p[r-l+1]+1ll*mod*mod)%mod;
   return ans;

 }
int main ()
{ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(0);
  /* hash 
  y tuong: mã hóa chuỗi  và tính subtring của chúng 
  ứng dụng : xử lý chuỗi như  so sánh chuỗi
   test : abbsbafjfiwfijew

   */
    string s;
    cin>>s;
    int n=s.size();
    s=' '+s;
    p[0]=1;
    rep1(i,n) 
    p[i]=p[i-1]*base%mod;
    rep1(i,n)
    f[i]=(f[i-1]*base+s[i]-'a'+1)%mod;
  
}

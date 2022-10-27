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
/* 
Z_function
idea: goi z[i] la độ dài tiền tố dài nhất bắt đầu từ s[i];
vd : abcabc
     123456 
z[4]=3 do  abc == abc    
           123    456

test case 
  abcabc

ouptt: ans{0,0,0,3,0,0};


*/
vector<int>z_function(string s){
  int n=s.size();
  vector<int>z(n,0);
  for (int i=1,l=0,r=0;i<n;++i){
       if (i<=r)
      z[i]=min(z[i-l],r-i+1);
      while (i+z[i]<n&&s[z[i]]==s[z[i]+i])
        ++z[i];
      if (i+z[i]-1>r){
        l=i;
        r=i+z[i]-1;
      }

  }
  return z;
}
 
int main ()
{ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(0);

  string s;
  cin>>s;
  vector<int>ans=z_function(s);
  for (auto x: ans)
    cout<<x<<" ";

  
   
}

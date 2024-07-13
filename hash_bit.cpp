#include <bits/stdc++.h>

using namespace std;

#define                 ll  long long
#define          rep(i, n)  for (int i = 0; i <  (int)(n); i ++)
#define         rep1(i, n)  for (int i = 1; i <= (int)(n); i ++)
#define       replr(i,l,r)  for (int i = l; i <= (int)(r); i ++)
#define         rev(i,r,l)  for (int i = r; i >= l; --i)
#define                 pb  push_back 
#define             all(x)  x.begin(),x.end()
#define               maxn
#define               endl  "\n"
#define                 NO  cout<<"NO"<<endl
#define                YES  cout<<"YES"<<endl
#define                 fi  first
#define                 se  second
#define          file(name) if (fopen(name".inp", "r")) { freopen(name".inp", "r", stdin); freopen(name".out", "w", stdout);} 


template <class X, class Y>
   bool minimize (X &x, const Y &y){
       if (x > y){
        x = y;
        return true;
       }
       return false;

   }

template <class X, class Y>
   bool maximize (X &x, const Y &y){
       if (x < y){
        x = y;
        return true;
       }
       return false;

   }
// update character in a string and get hash in range [l,r]
struct hash_BIT
{  
  vector<long long> p, hash;
  long long MOD;
  int n;
  long long base;

  hash_BIT(int n) :hash(n+1,0), p(n+1,0){
    MOD=1e9+21;
    this->n=n;
    p[0]=1;
    base=31;
    for (int i=1;i<=n;++i)
      p[i]= (p[i-1]*base) % MOD;
  }
    
  long long pre(int k){ 
      long long ans=0;
      for (int j = k ; j > 0; j-= j & -j){
          ans = (ans + hash[j] * p[k-j]) %MOD;
      }
      return ans;

  }

  long long get_hash(int l, int r){
    return (pre(r) -pre(l-1)*p[r-l+1] + 1ll * MOD * MOD)%MOD;
  }

  void update (int k, char c) {
        long long delta = c - 'a' + 1 - get_hash(k, k);
        for (int j = k; j < hash.size(); j += j & -j)
            hash[j] = (hash[j] + delta * p[j - k] + MOD * MOD) % MOD;
        
    }


  
};

int main ()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(0);
    
    
     
    return 0;
}


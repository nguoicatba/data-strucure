#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<b;++i)
#define FORR(i,a,b) for(int i=a;i>=b;--i)
using namespace std;
#define ll long long
typedef vector<int> vi;
typedef vector<long long> vll;
typedef map<int,int> mapii;
#define pb push_back 
#define all(x) x.begin(),x.end()
#define maxn 200110
#define endl "\n"
#define NO cout<<"NO"<<endl
#define YES cout<<"YES"<<endl
#define fi first
#define se second
#define writefile(f) freopen (f,"r",stdin)
#define readfile(f)  freopen(f,"w",stdout)


// tim to tien chung gan nhat cua u va v

 vector<int>g[maxn];
 vector<int>vs(maxn,false);
 int up[maxn][20];
 int h[maxn];
 int n,q;
void dfs(int u) {
    for (int v : g[u]) {
        if (v == up[u][0]) continue;
        h[v] = h[u] + 1;
        
        up[v][0] = u;
        for (int j = 1; j < 20; ++j)
            up[v][j] = up[up[v][j - 1]][j - 1];

        dfs(v);
    }
}
int lca(int u, int v) {
    if (h[u] != h[v]) {
        if (h[u] < h[v]) swap(u, v);
    
        // Tìm tổ tiên u' của u sao cho h(u') = h(v)
        int k = h[u] - h[v];
        for (int j = 0; (1 << j) <= k; ++j)
            if (k >> j & 1) // Nếu bit thứ j của k là 1
                u = up[u][j];
    }
    if (u == v) return u;
    
    // Tìm lca(u, v)
    int k = __lg(h[u]);
    for (int j = k; j >= 0; --j)
        if (up[u][j] != up[v][j]) // Nếu tổ tiên thứ 2^j của u và v khác nhau
            u = up[u][j], v = up[v][j];
    return up[u][0];
}

int main ()
{ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(0);
  cin>>n>>q;
  FOR (i,2,n+1){
    int x;
    cin>>x;
    g[x].pb(i);
    g[i].pb(x);
  }
  h[1]=0;
  dfs(1);
  while (q--){
    int a,b;
    cin>>a>>b; 
    cout<<lca(a,b)<<endl; 
  }

   
}

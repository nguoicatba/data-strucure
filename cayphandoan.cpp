#include <bits/stdc++.h>
#define for1n(i,n) for (i=1;i<=(n);i++)
#define forn(i,n) for(int i=0;i<n;++i)
using namespace std;
#define ll long long
typedef vector<int> vi;
typedef vector<long long> vll;
typedef map<int,int> mapii;
#define pb push_back 
const int N=100001;
long long a[N];
long long t[4*N];
void build (int id, int l ,int r){
  if (l==r){
    t[id]=a[l];
    return;
  }
  int mid=(l+r)/2;
  build(id*2,l,mid);
  build(id*2+1,mid+1,r);
  t[id]=(long long)t[id*2]+t[id*2+1];
}
 long long get(int id,int l,int r,int u,int v){
    if(u==v)
     return a[u];
  if (r<u||l>v)
    return 0;
  if(u<=l&&r<=v)
    return t[id];
   int mid=(l+r)/2;
  int t1=get(id*2,l,mid,u,v);
  int t2=get(id*2+1,mid+1,r,u,v);
    return t1+t2;
 }
 void update(int id, int l, int r, int p){
  if (p<l || p>r)
    return;
  if (l==r){
    t[id]=a[p];
    return;
  }
  int mid=(l+r)/2;
  update(id*2,l,mid,p);
  update(id*2+1,mid+1,r,p);
  t[id]=t[id*2]+t[id*2+1];
  
 }
int main ()
{ios_base::sync_with_stdio(false);
// freopen ("input.txt","r",stdin);
// freopen("output.txt","w",stdout);
  memset(a,0,sizeof(a));
  memset(t,0,sizeof(t));
int n,q;
cin>>n>>q;
while (q--){
  int choice,x,y;
  cin>>choice>>x>>y;
   if(choice==1){
    a[x]=y;
     update(1,1,n,x);
   }
   else
    cout<<get(1,1,n,x,y)<<endl;
}
}

#include <bits/stdc++.h>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int parent[10000];
int rank1[10000];
//  Find union set
void makeset( int n)
{
	for (int i=1;i<=n;++i){
		parent[i]=i;
	rank1[i]=1;
   }
}
int find1(int a)
{
	if (parent[a]==a)
		return a;
	return parent[a]=find1(parent[a]); // ki thuat path compression: nen duong giup giam thao tac
	                                   // xuong O(logn)
}
void unionn (int a,int b){
	a=find1(a);
	b=find1(b);
	if (a!=b){
		if (rank1[a]<rank1[b])
			swap(a,b);
		parent[b]=a;
		rank1[a]+=rank1[b];
	}
}

int main(int argc, char** argv) {

makeset(4); // tao set cho co 4 pt
unionn(1,2); //hop nhat 1 va 2  size[1] == 2
unionn(2,3);// 2 3 se trong 1 set cung vs 1 size[1]==3
int t=find1(2);
cout<<t<<endl;
cout<<find1(3);

	return 0;
}

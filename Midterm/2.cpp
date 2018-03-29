#include <iostream>
#include <cmath>
#include <algorithm>
#include <limits>
#include <vector>
#include <bitset>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <time.h>
#include <list>
#include <set>
#include <map>
#include <queue>
#include <cctype>
#include <list>
#include <iterator>
#include <iomanip>

using namespace std;

#define mod 1000000007LL
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ABS(x) ((x)<0?-(x):(x))
#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define FILL(a,b) memset(a,b,sizeof(a))
#define P1(x) cout<<(x)<<"\n"
#define P2(x,y) cout<<(x)<<" "<<(y)<<"\n"
#define P3(x,y,z) cout<<(x)<<" "<<(y)<<" "<<(z)<<"\n"
#define P4(x,y,z,k) cout<<(x)<<" "<<(y)<<" "<<(z)<<" "<<(k)<<"\n"
#define pb push_back
#define PII pair<int,int>
int n,m;

struct node{
	int rank;
	int parent;
	int cnt;
}nodes[1000000];

int findRoot(int x){
	if(nodes[x].parent == x) return x;
	return nodes[x].parent = findRoot(nodes[x].parent);
}

int unionNodes(int x,int y){
	int ans=0;
	int xRoot = findRoot(x);
	int yRoot = findRoot(y);
	if(xRoot!=yRoot){
		ans=nodes[xRoot].cnt*nodes[yRoot].cnt;
		nodes[yRoot].cnt+=nodes[xRoot].cnt;
		nodes[xRoot].cnt=nodes[yRoot].cnt;
	}

	if(nodes[xRoot].rank>nodes[yRoot].rank){
		int temp = xRoot;
		xRoot = yRoot;
		yRoot = temp;
	}
	if(nodes[xRoot].rank==nodes[yRoot].rank){
		nodes[yRoot].rank++;
	}
	nodes[xRoot].parent=yRoot;
	
	return ans;
}



int main(){
	cin>>n>>m;
	REP(i,n+1){
		nodes[i].rank=0;
		nodes[i].parent=i;
		nodes[i].cnt=1;
	}

	REP(i,m){
		int a,b;
		cin>>a>>b;
		cout<<unionNodes(a,b)<<"\n";
	}



}


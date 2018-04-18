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
#include <stack>

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
#define ll long long
#define VI vector<int> 
#define PLL part<ll,ll>
#define int long long
#define INF 1LL<<60
#define mp make_pair
#define int long long
#define MAX_NODES 1000000
int n,q;
int val[MAX_NODES], lazy[MAX_NODES];
void add(int k, int nl, int nr, int l, int r, int v);
void relax(int k, int nl, int nr) {
  int nm = (nl + nr) / 2;
  add(2*k+1, nl, nm, nl, nm, lazy[k]); // just use add() to add lazy propagation value downwards
  add(2*k+2, nm+1, nr, nm+1, nr, lazy[k]);
  lazy[k] = 0; // clear the lazy propagation value
}
void add(int k, int nl, int nr, int l, int r, int v){
  if (r < nl || l > nr) return;
  if (l <= nl && nr <= r) {
  	if(nr%2==nl%2){
  		val[k]^=v;
  	}
    lazy[k] ^= v; // record the lazy propagation value
    return;
  }
  int nm = (nl + nr) / 2;
  if (lazy[k]) relax(k, nl, nr); // there is value to propagate, we first relax
  add(2*k+1, nl, nm, l, r, v);
  add(2*k+2, nm+1, nr, l, r, v);
  val[k] = val[2*k+1] ^ val[2*k+2];
}
int getSum(int k, int nl, int nr, int l, int r) {
  if (r < nl || l > nr) return 0;
  if (l <= nl && nr <= r) return val[k]; // the entire range's sum is part of the answer
  if (lazy[k]) relax(k, nl, nr); // must also relax in a range sum query
  int nm = (nl + nr) / 2;
  return getSum(2*k+1, nl, nm, l, r) ^ getSum(2*k+2, nm+1, nr, l, r);
}



signed main(){
	FILL(val,0);
	FILL(lazy,0);
	cin>>n>>q;
	REP(i,n){
		int x;
		cin>>x;
		add(0,0,n-1,i,i,x);
	}
	REP(i,q){
		char ins;
		int l,r,v;
		cin>>ins;
		if(ins=='q'){
			cin>>l>>r;
			P1(getSum(0,0,n-1,l-1,r-1));
		}
		if(ins=='x'){
			cin>>l>>r>>v;
			add(0,0,n-1,l-1,r-1,v);
		}
	}
}

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
#define ll long long
#define VI vector<int> 
#define PLL part<ll,ll>
#define MAX_NODES 400000
#define int long long
int n,q;
int val[MAX_NODES], lazy[MAX_NODES], lazyc[MAX_NODES],is_c[MAX_NODES];
void add(int k, int nl, int nr, int l, int r, int v,int min);
void change(int k, int nl, int nr, int l, int r, int v);

void relax(int k, int nl, int nr) {
  int nm = (nl + nr) / 2;
  int temp = lazy[k];
  if(is_c[k]){
  	change(2*k+1, nl, nm, nl, nm, lazyc[k]);
  	change(2*k+2, nm+1, nr, nm+1, nr, lazyc[k]);
  }
  add(2*k+1, nl, nm, nl, nm, temp, val[k]); // just use add() to add lazy propagation value downwards
  add(2*k+2, nm+1, nr, nm+1, nr, temp, val[k]);
  lazy[k] = 0; // clear the lazy propagation value
  lazyc[k] = 0;
}

void add(int k, int nl, int nr, int l, int r, int v,int min){
  if (r < nl || l > nr) return;
  if (l <= nl && nr <= r) {
  	
    val[k] += v; // the sum is increased by v * {length of the range}
    if (val[k] < min){
    	val[k] = min;
    }
    lazy[k] += v; // record the lazy propagation value
    return;
  }
  int nm = (nl + nr) / 2;
  int m = MAX(val[k]+v,min);
 
  if (lazy[k]||is_c[k]) relax(k, nl, nr); // there is value to propagate, we first relax
  add(2*k+1, nl, nm, l, r, v, m);
  add(2*k+2, nm+1, nr, l, r, v, m);
  val[k] = MAX(MIN(val[2*k+1] , val[2*k+2]),0);
}

void change(int k, int nl, int nr, int l, int r, int v){
  if (r < nl || l > nr) return;

  if (l <= nl && nr <= r) {
    val[k] = v; // the sum is increased by v * {length of the range}
    lazyc[k] = v; // record the lazy propagation value
    lazy[k] = 0;
    is_c[k] = 1;
    return;
  }
  int nm = (nl + nr) / 2;
 
  if (lazy[k]||lazyc[k]) relax(k, nl, nr); // there is value to propagate, we first relax
  change(2*k+1, nl, nm, l, r, v);
  change(2*k+2, nm+1, nr, l, r, v);
  val[k] = MIN(val[2*k+1] , val[2*k+2]);
}

int getMin(int k, int nl, int nr, int l, int r) {
  if (r < nl || l > nr) return numeric_limits<int>::max();
  if (l <= nl && nr <= r) return val[k]; // the entire range's sum is part of the answer
  if (lazy[k]||is_c[k]) relax(k, nl, nr); // must also relax in a range sum query
  int nm = (nl + nr) / 2;
  int a1 = getMin(2*k+1, nl, nm, l, r);
  int a2 = getMin(2*k+2, nm+1, nr, l, r);
  a1 = MAX(a1,0);
  a2 = MAX(a2,0);
  return MIN(a1,a2);
}

signed main(){
	cin>>n>>q;
	FILL(val,0);
	FILL(lazy,0);
	FILL(lazyc,0);
	FILL(is_c,0);
	REP(i,n){
		int x;
		cin>>x;
		add(0,0,n-1,i,i,x,0);
	}
	// REP(i,15){
	// 	P2(val[i],lazy[i]);
	// }
	// P1("\n");
	// REP(i,n){
	// 	P1(getMin(0,0,n-1,i,n-1));
	// }
	REP(i,q){
		char ins;
		int l,r,v;
		cin>>ins;
		if(ins=='a'){
			cin>>l>>r>>v;
			add(0,0,n-1,l-1,r-1,v,0);
		}
		if(ins=='c'){
			cin>>l>>r>>v;
			change(0,0,n-1,l-1,r-1,v);
		}
		if(ins=='q'){
			cin>>l>>r;
			P1(getMin(0,0,n-1,l-1,r-1));
		}
	}
}



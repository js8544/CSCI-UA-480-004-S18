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
#define int long long
#define MAX_NODES 400000

struct node{
	int x;
	int y;
	node(int xx,int yy){
		x = xx;
		y = yy;
	}
	node(){
		x = 0;
		y = 0;
	}
}lazy[MAX_NODES];

int n,q;
int val[MAX_NODES]; 

void add(int k, int nl, int nr, int l, int r, node v);

void relax(int k, int nl, int nr) {
  int nm = (nl + nr) / 2;
  int x = lazy[k].x;
  int y = lazy[k].y;
  // P4(nl+1,nr+1,x,y);
  // P4(nl+1,nm+1,x,y);
  // P4(nm+2,nr+1,x+(nm-nl+1)*y,y);
  add(2*k+1, nl, nm, nl, nm, node(x,y)); // just use add() to add lazy propagation value downwards
  add(2*k+2, nm+1, nr, nm+1, nr, node(x+(nm-nl+1)*y,y));
  lazy[k].x = 0; // clear the lazy propagation value
  lazy[k].y = 0;
}

void add(int k, int nl, int nr, int l, int r, node v){
  int x = v.x;
  int y = v.y;
  if (r < nl || l > nr) return;
  if (l <= nl && nr <= r) {
    val[k] += ((2*x+(nr+nl-2*l)*y)*(nr-nl+1)/2)%mod; // the sum is increased by v * {length of the range}
    // val[k] += (x*(nr-nl+1))%mod;
    // val[k] += y*(((nl+nr-2*l)%mod*(nr-nl+1)%mod/2)%mod);
    val[k] = val[k]%mod;

    lazy[k].x += (x+(nl-l)*y); // record the lazy propagation value
    lazy[k].y += y;
    return;
  }
  int nm = (nl + nr) / 2;
  if (lazy[k].x||lazy[k].y) relax(k, nl, nr); // there is value to propagate, we first relax
  add(2*k+1, nl, nm, l, r, v);
  add(2*k+2, nm+1, nr, l, r, v);
  val[k] = (val[2*k+1] + val[2*k+2])%mod;
}

int getSum(int k, int nl, int nr, int l, int r) {
  if (r < nl || l > nr) return 0;
  if (l <= nl && nr <= r) return val[k]%mod; // the entire range's sum is part of the answer
  if (lazy[k].x||lazy[k].y) relax(k, nl, nr); // must also relax in a range sum query
  int nm = (nl + nr) / 2;
  return (getSum(2*k+1, nl, nm, l, r)%mod + getSum(2*k+2, nm+1, nr, l, r)%mod)%mod;
}

signed main(){
	FILL(val,0);
	cin>>n>>q;

	REP(i,q){
		char ins;
		cin>>ins;
		int l,r,x,y;
		cin>>l>>r;
		if(ins=='s'){
			P1((getSum(0,0,n-1,l-1,r-1)+mod)%mod);
		}
		if(ins=='a'){
			cin>>x>>y;
			add(0,0,n-1,l-1,r-1,node(x,y));
		}
	}
	

}
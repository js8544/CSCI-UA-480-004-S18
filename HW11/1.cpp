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
#define MAX_NODES 400001
#define int long long
struct node{
  int max;
  int min;
  int sum;
}val[MAX_NODES];
int n,q;
int lazys[MAX_NODES],lazyn[MAX_NODES];
void add(int k, int nl, int nr, int l, int r, int v);
void neg(int k, int nl, int nr, int l, int r);
void relax(int k, int nl, int nr) {
  int nm = (nl + nr) / 2;
  if(lazyn[k]){
    neg(2*k+1, nl, nm, nl, nm);
    neg(2*k+2, nm+1, nr, nm+1, nr);
  }
  add(2*k+1, nl, nm, nl, nm, lazys[k]); // just use add() to add lazy propagation value downwards
  add(2*k+2, nm+1, nr, nm+1, nr, lazys[k]);
  lazys[k] = 0; // clear the lazy propagation value
  lazyn[k] = 0;
}

void add(int k, int nl, int nr, int l, int r, int v){
  if (r < nl || l > nr) return;
  if (l <= nl && nr <= r) {
    val[k].sum += v * (nr - nl + 1); // the sum is increased by v * {length of the range}
    val[k].min += v;
    val[k].max += v;
    lazys[k] += v; // record the lazy propagation value
    return;
  }
  int nm = (nl + nr) / 2;
  if (lazys[k]||lazyn[k]) relax(k, nl, nr); // there is value to propagate, we first relax
  add(2*k+1, nl, nm, l, r, v);
  add(2*k+2, nm+1, nr, l, r, v);
  val[k].sum = val[2*k+1].sum + val[2*k+2].sum;
  val[k].min = MIN(val[2*k+1].min , val[2*k+2].min);
  val[k].max = MAX(val[2*k+1].max , val[2*k+2].max);
}

void neg(int k, int nl, int nr, int l, int r){
  if (r < nl || l > nr) return;
  if (l <= nl && nr <= r) {
    val[k].sum *= -1; // the sum is increased by v * {length of the range}
    int temp = val[k].min;
    val[k].min = -val[k].max;
    val[k].max = -temp;
    lazyn[k] = ~lazyn[k]; // record the lazy propagation value
    lazys[k] = -lazys[k];
    return;
  }
  int nm = (nl + nr) / 2 ;
  if (lazys[k]||lazyn[k]) relax(k, nl, nr); // there is value to propagate, we first relax
  neg(2*k+1, nl, nm, l, r);
  neg(2*k+2, nm+1, nr, l, r);
  val[k].sum = val[2*k+1].sum + val[2*k+2].sum;
  val[k].min = MIN(val[2*k+1].min , val[2*k+2].min);
  val[k].max = MAX(val[2*k+1].max , val[2*k+2].max);
}

int getSum(int k, int nl, int nr, int l, int r) {
  if (r < nl || l > nr) return 0;
  if (l <= nl && nr <= r) return val[k].sum; // the entire range's sum is part of the answer
  if (lazys[k]||lazyn[k]) relax(k, nl, nr); // must also relax in a range sum query
  int nm = (nl + nr) / 2;
  return getSum(2*k+1, nl, nm, l, r) + getSum(2*k+2, nm+1, nr, l, r);
}

int getMin(int k, int nl, int nr, int l, int r) {
  if (r < nl || l > nr) return numeric_limits<int>::max();
  if (l <= nl && nr <= r) return val[k].min; // the entire range's sum is part of the answer
  if (lazys[k]||lazyn[k]) relax(k, nl, nr); // must also relax in a range sum query
  int nm = (nl + nr) / 2;
  int a1 = getMin(2*k+1, nl, nm, l, r);
  int a2 = getMin(2*k+2, nm+1, nr, l, r);
  return MIN(a1,a2);
}

signed main(){
  FILL(lazys,0);
  FILL(lazyn,0);
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
    if(ins=='a'){
      cin>>l>>r>>v;
      add(0,0,n-1,l-1,r-1,v);
    }
    else if(ins=='s'){
      cin>>l>>r;
      P1(getSum(0,0,n-1,l-1,r-1));
    }
    else if(ins=='n'){
      cin>>l>>r;
      neg(0,0,n-1,l-1,r-1);
    }
    else if(ins=='m'){
      cin>>l>>r;
      P1(getMin(0,0,n-1,l-1,r-1));
    }
  }
}



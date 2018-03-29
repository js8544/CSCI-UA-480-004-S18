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
#define ll long long
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
// root is at 0
#define MAXSEG 1000001 // MAXSEG >= 4N
int val[MAXSEG];
int arr[MAXSEG];
int lo[MAXSEG];
int pos[200001];
int ans[200001];
int n,qs;
int qi;

struct query{
	int id,l,r;
}q[200001];

int qcmp(query a,query b){
	if(a.r<b.r) return 1;
	else return 0;
}

void build(int k, int nl, int nr) {
  if (nl == nr) {
    val[k] = arr[nl]; // arr[] is the original array
    return;
  }
  int nm = (nl+nr)/2;
  build(2*k+1, nl, nm);
  build(2*k+2, nm+1, nr);
  val[k] = val[2*k+1] + val[2*k+2];
}
void change(int k, int nl, int nr, int x, int v){
	if(x < nl || x > nr) return;
	if (nl == nr) {
		val[k] = v; // update val using v here
		return;
	}
	int nm = (nl+nr)/2;
	change(2*k+1, nl, nm, x, v);
	change(2*k+2, nm+1, nr, x, v);
	val[k] = val[2*k+1] + val[2*k+2];	// update val here
}
int get(int k, int nl, int nr, int l, int r){
	if(r < nl || l > nr) return 0;
	if(l <= nl && nr <= r) return val[k];	// return answer here
	int nm = (nl+nr)/2, ans = 0;
	ans += get(2*k+1, nl, nm, l, r);	// combine answers of the two children here
	ans += get(2*k+2, nm+1, nr, l, r);
	return ans;
}

int main(){
	cin>>n;
	FILL(lo,-1);
	FILL(arr,0);
	FOR(i,1,n+1){
		cin>>pos[i];
	}
	cin>>qs;
	REP(i,qs){
		q[i].id=i;
		cin>>q[i].l>>q[i].r;
	}
	// REP(i,qs)P2(q[i].l,q[i].r);
	sort(q,q+qs,qcmp);
	// FOR(i,1,n+1)P1(pos[i]);
	// P1(qs);
	// REP(i,qs)P2(q[i].l,q[i].r);

	build(0,0,n+1);
	FOR(i,1,n+1){
		int x = pos[i];
		if(lo[x]!=-1){
			change(0,0,n+1,lo[x],0);
		}
		change(0,0,n+1,i,1);
		lo[x]=i;
		// FOR(j,0,4*n){
		// 	P1(val[j]);	
		// }
		// P1("\n");
		while(qi<qs&&q[qi].r==i){
			ans[q[qi].id]=get(0,0,n+1,q[qi].l,i+1);
			qi++;
		}
	}
	REP(i,qs){
		P1(ans[i]);
	}
}
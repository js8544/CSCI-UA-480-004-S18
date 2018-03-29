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
#define MAXSEG 2000001 // MAXSEG >= 4N
int val[MAXSEG];
int arr[500001];
int q;
int e=0;
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

int check(int x, int i){
	if(i-get(0,0,q,0,i)>=x) return 1;
	else return 0;
}

int search(int x){
	int l = -1;
	int r = e;

	while(r-l>1){
		int m = (l+r)/2;
		if(check(x,m))r=m;
		else l=m;
		//P2(l,r);
	}
	return r;
}

int main(){
	FILL(arr,0);
	
	cin>>q;

	build(0,0,q);

	
	REP(i,q){
		char ins;
		int x;
		cin>>ins>>x;
		if(ins=='a'){
			arr[e]=x;
			e++;
		}
		if(ins=='p'){
			P1(arr[search(x)]);
		}
		if(ins=='d'){
			change(0,0,q,search(x),1);
		}


	}

}
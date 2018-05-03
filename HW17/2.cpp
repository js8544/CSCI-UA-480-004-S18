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
#define fi first
#define se second
#define MAX_NODES 1000000
#define MAXN 100001
int n;
int val[MAX_NODES];
int a[MAXN];
int gcd(int x,int y){
	if(x<y){
		int temp = x;
		x = y;
		y = temp;
	}
	if(y==0) return x;
	return gcd(y,x%y);
}

void build(int k, int nl, int nr) {
  if (nl == nr) {
    val[k] = a[nl];
    return;
  }
  int nm = (nl + nr) / 2;
  build(2*k+1, nl, nm);
  build(2*k+2, nm+1, nr);
  val[k] = gcd(val[2*k+1], val[2*k+2]);
}
int get_gcd(int k, int nl, int nr, int l, int r){
  if(r < nl || l > nr) return 0;
  if(l <= nl && nr <= r) return val[k];
  int nm = (nl + nr) / 2;
  int ansLeft = get_gcd(2*k+1, nl, nm, l, r);
  int ansRight = get_gcd(2*k+2, nm+1, nr, l, r);
  return gcd(ansLeft, ansRight); // combine answers of two children
}

int bs(int index,int left,int val){
	int l = left;
	int r = n;
	while(r>l){
		int m = (l+r)/2;
		if(get_gcd(0,0,n-1,index,m)>=val){
			l = m+1;
		}
		else{
			r = m;
		}
		//P4(index,val,l,r);
	}
	return r;
}
signed main(){
	cin>>n;
	REP(i,n) cin>>a[i];
	build(0,0,n-1);
	// REP(i,n){
	// 	FOR(j,i,n){
	// 		P3(i,j,get_gcd(0,0,n-1,i,j));
	// 	}
	// }
	int ans = 0;
	REP(i,n){
		int g = a[i];
		int cur = i;
		int next;

		while(cur<n){

			if(get_gcd(0,0,n-1,i,n-1)==g){
				ans += (n-cur)*g;
				break;
			}
			else{
				next = bs(i,cur,g);
				ans += (next-cur)*g;
				g = get_gcd(0,0,n-1,i,next);
				cur = next;
			}

			//P2(i,cur);
			
		}

	}
	cout<<ans<<"\n";
}

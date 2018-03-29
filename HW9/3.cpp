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

ll x;
int n,k;
vector<ll> pal;

ll append(ll x,int k){
	ll t = x;
	if(k>=0){
		x = x*10+k;
	}
	while(t>0){
		x = x*10+t%10;
		t = t/10;
	}
	//P1(x);
	return x;
}

ll get_p(ll x,int k){
	int l=0,r=pal.size()-1;
	while(r-l>1){
		int m = (l+r)/2;
		if(pal[m]>=x){
			r = m;
		}
		else{
			l = m;
		}
		//P2(pal[l],pal[r]);
	}

	return pal[r+k-1];
}
int main(){
	cin>>n;

	FOR(i,0,10) pal.pb(i);
	for(ll a=1;a<=10000;a*=10){
		FOR(i,a,10*a){
			pal.pb(append(i,-1));
		}
		FOR(i,a,10*a){
			FOR(j,0,10){
				pal.pb(append(i,j));
			}
		}
	}
	FOR(i,100000,600000){
		pal.pb(append(i,-1));
	}

	// FOR(i,0,pal.size()){
	// 	P1(pal[i]);
	// }
	REP(i,n){
		cin>>x>>k;
		//P2(x,k);
		P1(get_p(x,k));
	}
}
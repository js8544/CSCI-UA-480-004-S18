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

int main(){
	int n,k;
	cin>>n>>k;

	ll prefix_sum[n+k+1];
	FILL(prefix_sum,0);
	ll size[n];

	REP(i,n){
		cin>>size[i];
	}

	ll sum = 0;
	ll ans = 0;
	REP(i,n){
		if(size[i]-sum>0){
			prefix_sum[i] += size[i]-sum;
			prefix_sum[i+k-1] -= size[i]-sum;
			ans += size[i]-sum;
		}
		sum += prefix_sum[i];
	}

	P1(ans);
}
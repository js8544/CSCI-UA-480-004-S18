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
#define MAXN 100001
#define MAXM 51
#define MAXD 11
int n,m;
int inv[MAXN],factorial[MAXN];
int dp[MAXM][MAXD];
int cap[MAXM];
int power(int x,int y){
	//P3("power",x,y);
	if(y==0) return 1;
	if(y==1) return x;
	if(y%2==0) return power((x*x)%mod,y/2) % mod;
	return x*power((x*x)%mod,(y-1)/2) % mod;
}

void pre_compute(){
	int f = 1;
	FOR(i,1,MAXN){
		f = (f*i) % mod;
		factorial[i] = f;

		inv[i] = power(f,mod-2);
		// P3(i,f,inv[i]);
	}
}

int choose(int x,int y){
	if(y==0||x==y) return 1;
	int ans = factorial[x];
	ans = (ans * inv[x-y]) % mod;
	ans = (ans * inv[y]) % mod; 
	return ans;
}
signed main(){
	cin>>n>>m;
	pre_compute();
	int total = 0;
	
	FOR(i,1,m+1){
		int x;cin>>x;
		total += x;
		cap[i] = x;
	}

	int d = total - n;
	REP(i,m+1)REP(j,d+1) dp[i][j] = 0;
	dp[0][0] = 1;
	int cur = n;
	FOR(i,1,m+1){
		int x = cap[i];
		REP(j,d+1){
			if(!dp[i-1][j]) break;
			if(cur+j<0) break;
			int max_e = MIN(d-j,x);
			REP(k,max_e+1){
				dp[i][j+k] += dp[i-1][j]*(choose(cur+j,x-k)) % mod;
			}
		}
		cur -= x;

	}
	// FOR(i,1,m+1){
	// 	REP(j,d+1){
	// 		P3(i,j,dp[i][j]);
	// 	}
	// }

	P1(dp[m][d]);
}

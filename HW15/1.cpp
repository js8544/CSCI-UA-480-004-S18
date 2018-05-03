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
#define MAXU 5001
#define MAXN 1001
int n,u;
int dp[MAXN][MAXU];
int num[MAXN];
signed main(){
	cin>>n>>u;
	REP(i,MAXN){
		REP(j,MAXU)dp[i][j] = 0;
	}

	REP(i,n){
		cin>>num[i];
	}

	dp[0][0] = 1;
	FOR(i,1,n+1){
		REP(j,u+1){
			dp[i][j] = dp[i-1][j];
			if(j>=num[i-1]) dp[i][j] += dp[i-1][j-num[i-1]];
			dp[i][j] %=mod;
			//P3(i,j,dp[i][j]);
		}
	}

	REP(i,u+1){
		cout<<i<<": "<<dp[n][i]%mod<<"\n";
	}
	
}

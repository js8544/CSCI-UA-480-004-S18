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
#define MAXN 1001
int dp[MAXN][MAXN];
int n;
int x[MAXN],y[MAXN];
signed main(){
	cin>>n;
	REP(i,MAXN)REP(j,MAXN)dp[i][j]=0;
	REP(i,n){
		cin>>x[i];
	}
	REP(i,n){
		cin>>y[i];
	}
	dp[0][0] = dp[0][1] = dp[1][0] = 0;
	FOR(i,1,n+1){
		FOR(j,1,n+1){
			dp[i][j] = MAX(dp[i-1][j],dp[i][j-1]);

			dp[i][j] = MAX(dp[i][j],dp[i-1][j-1] + ((x[i-1]==y[j-1])?1:0));	
			
		}
	}
	
	P1(n-dp[n][n]);
}

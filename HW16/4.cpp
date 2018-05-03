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
#define MAXN 16
int n,m;
int dp[MAXN][MAXN][1LL<<MAXN];
int grid[MAXN][MAXN];

signed main(){
	cin>>n>>m;
	REP(i,n)REP(j,m){
		REP(ex,1LL<<m){
			dp[i][j][ex] = 0;
		}
		char c;
		cin>>c;
		grid[i][j] = (c=='#');
	}
	REP(i,n){
		REP(j,m){
			for(int ex = (1LL<<m)-1;ex>=0;ex--){

				if(i==0&&j==0){
					dp[i][j][0] = 1;
					if(i+1<n) if(grid[i][j]==0 && grid[i+1][j]==0) dp[i][j][1] = 1;
				}
				else if(j==0){
					if(grid[i][j]==0 && (ex&1LL<<j)==0){
						dp[i][j][ex] += dp[i-1][m-1][ex];
						if(i+1<n) if(grid[i+1][j]==0) dp[i][j][ex|(1LL<<j)] += dp[i-1][m-1][ex];
					}
					else if(grid[i][j]==1){
						dp[i][j][ex] += dp[i-1][m-1][ex];
					}
					else{
						dp[i][j][ex&(~(1LL<<j))] += dp[i-1][m-1][ex];
					}

				}
				else{
					if(grid[i][j]==0 && (ex&1LL<<j)==0){
						dp[i][j][ex] += dp[i][j-1][ex];
						if(i+1<n) if(grid[i+1][j]==0) dp[i][j][ex|(1LL<<j)] += dp[i][j-1][ex];
						if(j>=1) if((ex&(1LL<<j))==0 && (ex&(1LL<<(j-1)))==0 && grid[i][j-1]==0){
							if(j==1 && i==0 && ex==0) dp[i][j][ex] += 1;
							else if(j==1&&i>=1) dp[i][j][ex] += dp[i-1][m-1][ex];
							else if(j>=2) dp[i][j][ex] += dp[i][j-2][ex];
						}
					}
					else if(grid[i][j]==1){
						dp[i][j][ex] += dp[i][j-1][ex];
					}
					else{
						dp[i][j][ex&(~(1LL<<j))] += dp[i][j-1][ex];
					}
				}

				dp[i][j][ex] %= mod;
			}
		}
	}
	int ans = 0;
	//REP(i,n)REP(j,m)REP(ex,1LL<<m) P4(i,j,ex,dp[i][j][ex]);
	REP(ex,1LL<<m){
		ans += dp[n-1][m-1][ex];
		ans %= mod;
	}
	P1(ans);
}

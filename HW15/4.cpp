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

#define mod 10000
#define REP(i,n) for(int i=0;i<(n);i++)
#define P1(x) cout<<(x)<<"\n"
#define P2(x,y) cout<<(x)<<" "<<(y)<<"\n"
#define P3(x,y,z) cout<<(x)<<" "<<(y)<<" "<<(z)<<"\n"
#define P4(x,y,z,k) cout<<(x)<<" "<<(y)<<" "<<(z)<<" "<<(k)<<"\n"
#define PII pair<int,int>
#define INF 1LL<<60
#define mp make_pair
#define MAXN 15001
int n,m;
int s,a,b,c,d;
PII dp[2][MAXN];
signed main(){
	// clock_t t1,t2;
	// t1 = clock();
	cin>>n>>m;
	cin>>s>>a>>b>>c>>d;
	int last = s;
	int cur;
	int layer = 0, prev_layer;
	REP(i,n){
		prev_layer = layer;
		layer ^= 1;
		REP(j,m){
			int cur = last;
			last = (((last*a)^b)+c)%d;
			// // cout<<cur<<" ";
			if(cur==0){
				dp[layer][j] = mp(0,0);
			}
			else if(i==0&&j==0){
				dp[layer][j] = mp(cur,1);
			}
			else if(i==0){
				if(dp[layer][j-1]==mp(0,0)) dp[layer][j] = mp(0,0);
				else dp[layer][j] = mp(dp[layer][j-1].first+cur,dp[layer][j-1].second);
			}
			else if(j==0){
				if(dp[prev_layer][j]==mp(0,0)) dp[layer][j] = mp(0,0);
				dp[layer][j] = mp(dp[prev_layer][j].first+cur,dp[prev_layer][j].second);
			}
			else{
				if(dp[prev_layer][j].first>dp[layer][j-1].first){
					dp[layer][j] = mp(dp[prev_layer][j].first+cur,dp[prev_layer][j].second);
				}
				else if(dp[prev_layer][j].first<dp[layer][j-1].first){
					dp[layer][j] = mp(dp[layer][j-1].first+cur,dp[layer][j-1].second);
				}
				else{
					if(dp[prev_layer][j]==mp(0,0)&&dp[layer][j-1]==mp(0,0)){
						dp[layer][j] = mp(0,0);
					}
					else dp[layer][j] = mp(dp[prev_layer][j].first+cur,(dp[prev_layer][j].second+dp[layer][j-1].second)%mod);
				}
			}
			// P4(i,j,dp[layer][j].first,dp[layer][j].second);
		}
		// cout<<"\n";
	}
	P2(dp[layer][m-1].first,dp[layer][m-1].second);
	// t2 = clock();
	// float diff =((float)t2-(float)t1)/CLOCKS_PER_SEC;
	// P1(diff);
}

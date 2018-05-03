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
#define MAXN 51
#define MAXSUM 5001

PII dp[MAXN][MAXN][MAXSUM*2+1];
int n;
int levels[MAXN];
signed main(){
	cin>>n;
	REP(i,n)REP(j,n)REP(k,MAXSUM*2+1) dp[i][j][k] = mp(0,0);
	dp[0][0][MAXSUM] = mp(1,0);

	for(int i=1;i<=n;i++){
		int w; cin>>w;
		levels[i-1] = w;
		//P2("w",w);
		for(int k=0;k<=n;k++){
			REP(d,MAXSUM*2+1){
				if(dp[i-1][k][d].fi==1){
					//P2(abs(d-MAXSUM),dp[i-1][k][d].se);
					if(k+1<=n){
						dp[i][k+1][d+w].fi = 1;
						dp[i][k+1][d+w].se = dp[i-1][k][d].se | (1LL<<(i-1));
					}
					dp[i][k][d-w].fi = 1;
					dp[i][k][d-w].se = dp[i-1][k][d].se;
				}

			}
		}
	}
	int ans = INF,pick = 0;
	FOR(k,(n-1)/2,n/2+1){
		REP(d,MAXSUM*2+1){
			if(dp[n][k][d].first){
				int temp = ABS(d-MAXSUM);
				if(temp<ans){
					ans = temp;
					pick = dp[n][k][d].second;
				}
			}
		}
	}

	P1(ans);
	vector<int> left,right;
	REP(i,n){
		if(pick&1LL<<i)left.pb(i);
		else right.pb(i);
	}
	//P1(pick);
	REP(i,left.size()) cout<<levels[left[i]]<<" ";
	cout<<"\n";
	REP(i,right.size()) cout<<levels[right[i]]<<" ";
	cout<<"\n";


}

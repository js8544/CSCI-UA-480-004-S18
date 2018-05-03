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
#define INF (double)1E20
#define mp make_pair
#define int long long
#define fi first
#define se second
#define MAXN 21
int n;
int x[MAXN],y[MAXN];
char color[MAXN];
double dist[MAXN][MAXN];
double dp[MAXN][1LL<<MAXN];
signed main(){
	cin>>n;
	REP(i,n){
		cin>>x[i]>>y[i]>>color[i];
		REP(j,i){
			if(color[i]==color[j]){
				dist[i][j] = dist[j][i] = INF;
			} 
			else{
				dist[i][j] = dist[j][i] = sqrt((x[j]-x[i])*(x[j]-x[i])+(y[i]-y[j])*(y[i]-y[j]));
			}
		}
	}
	// REP(i,n){
	// 	P2(i,color[i]);
	// }
	// REP(i,n){
	// 	REP(j,n){
	// 		if(i!=j) P3(i,j,dist[i][j]);
	// 	}
	// }
	REP(i,n)REP(j,1LL<<n) dp[i][j] = INF;
	dp[0][1] = 0;

	REP(mask,1LL<<n){
		REP(i,n){
			if(dp[i][mask]==INF) continue;
			REP(j,n){
				if(mask&(1LL<<j)) continue;
				if(color[i]==color[j]) continue;

				int newmask = mask|(1LL<<j);
				dp[j][newmask] = MIN(dp[j][newmask],dp[i][mask]+dist[i][j]);
			}
		}
	}
	double ans = INF;
	REP(i,n){
		if(dp[i][(1LL<<n)-1]<ans) ans = dp[i][(1LL<<n)-1];
	}
	if(ans>=INF) cout<<"impossible\n";
	else cout<<setprecision(20)<<ans<<"\n";
}

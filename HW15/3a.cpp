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
#define MAXN 101
int n;
int ans;
int num[101];
int dp[101];
int solve(int r){
	vector<int> temp;
	REP(i,n){
		if(i==r-1) continue;
		temp.pb(num[i]);
	}
	int s = temp.size();

	REP(i,s+1){
		dp[i]=0;
	}
	dp[0] = 0;
	dp[1] = 1;
	//P1(r);
	FOR(i,1,s+1){
		FOR(j,1,i){
			int res = dp[j]+((temp[i-1]>temp[j-1])?1:0);
			if(res>dp[i]) dp[i] = res;
		}
		// P2(i,dp[i]);
	}
	int a = 0;
	//P1(dp[s]);
	return dp[s];
}
signed main(){
	cin>>n;
	REP(i,n){
		cin>>num[i];
	}
	ans = solve(-1);
	// P2(-1,solve(-1));
	// P2(1,solve(1));
	// P2(2,solve(2));
	// P2(3,solve(3));
	// P2(4,solve(4));
	//solve(4);

	int find=0;

	FOR(i,1,n+1){
		if(solve(i)<ans){
			cout<<num[i-1]<<" ";
			find = 1;
		} 
	}
	if(!find) cout<<"-1";
	cout<<"\n";
}

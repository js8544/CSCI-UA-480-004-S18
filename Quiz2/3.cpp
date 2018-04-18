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
#define MAXN 400000
int n,m;
vector<int> order;
vector<int> adj[MAXN];
int turn;
void euler(int x){
	
  while (adj[x].size()) {
    int y = adj[x].back(); // we choose the last edge for fast removal
    adj[x].pop_back(); // remove this edge so that it will not be visited again
    euler(y);
  }
  turn++;
	order.push_back(x);

}

signed main(){
	turn = 0;
	int total=0;
	cin>>n>>m;
	REP(i,m){
		int a,b,w;
		cin>>a>>b>>w;
		total += 2*w;
		adj[a].pb(b);
		adj[b].pb(a);
	}

	euler(1);
	cout<<total<<"\n";
	cout<<turn<<"\n";
	reverse(order.begin(), order.end());
	REP(i,order.size()){
		cout<<order[i]<<" ";
	}
	cout<<"\n";
}

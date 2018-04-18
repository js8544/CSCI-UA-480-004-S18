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

int label = 0;
int vnum[100001]; // the label of each vertex 
int vlow[100001]; // the lowest label a vertex can reach backwards
int pending[100001];
PII edges[100001];

vector<vector<int> >sccs;
map<int,int> scc_index;
vector<map<int,int> > scc_adj(100001,map<int,int>());
vector<int> order;
vector<vector<int> > adj(100001,vector<int>(0,0));

int in_deg[100001];
int out_deg[100001];

void dfs(int x){
	vlow[x] = vnum[x] = ++label;
	pending[x] = 1;
    order.push_back(x);
    REP(i,adj[x].size()) {
    	int y = adj[x][i];
    	if (!vnum[y]) dfs(y);
    	if (pending[y]) vlow[x] = min(vlow[x], vlow[y]);
    }
  	if (vlow[x] == vnum[x]) { // an SCC is found
	    vector<int> scc;
	    while (1) {
	        int y = order.back();
	        scc_index[y] = sccs.size();
	        order.pop_back();
	        scc.push_back(y);
	        pending[y] = false;
	        if (y == x) break;
	    }
	    sccs.push_back(scc);
    }
}

signed main(){
	FILL(vnum,0);
	FILL(vlow,0);
	FILL(pending,0);
	FILL(in_deg,0);
	FILL(out_deg,0);
	int n,m;
	cin>>n>>m;
	REP(i,m){
		int a,b;
		cin>>a>>b;
		edges[i]=mp(a,b);
		adj[a].pb(b);
	}
	FOR(i,1,n+1){
		if(vnum[i]==0){
			//P2("dfs",i);
			dfs(i);
		}
	}

	// REP(i,sccs.size()){
	// 	REP(j,sccs[i].size()){
	// 		cout<<sccs[i][j]<<" ";
	// 	}
	// 	cout<<"\n";
	// }
	REP(i,m){
		int a=edges[i].first,b=edges[i].second;
		int as = scc_index[a],bs = scc_index[b];
		if(as==bs)continue;
		if(scc_adj[as].find(bs)==scc_adj[as].end()){
			scc_adj[as][bs] = 1;
			//P3("connect",a,b);
			out_deg[as]++;
			in_deg[bs]++;
		}
	}
	int zero_in=0,zero_out=0;
	vector<int> sink;
	vector<int> source;
	REP(i,sccs.size()){
		if(in_deg[i]==0){
			zero_in++;
			source.pb(i);
		}
		if(out_deg[i]==0){
			zero_out++;
			sink.pb(i);
		}
	}
	if(sccs.size()==1){
		P1(0);
	}
	else{
		P1(MAX(zero_in,zero_out));

	}
}

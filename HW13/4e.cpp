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
// #define int long long

int label = 0;
int vnum[100001]; // the label of each vertex 
int vlow[100001]; // the lowest label a vertex can reach backwards
int pending[100001];
PII edges[100001];
int cur;

vector<vector<int> >sccs;
map<int,int> scc_index;
vector<int> order;
vector<vector<int> > adj(100001,vector<int>(0,0));
vector<map<int,int> > scc_adj(100001,map<int,int>());
vector<int> sink;
vector<int> source;
vector<PII> bi_match;
vector<PII> res;
int in_deg[100001];
int out_deg[100001];
map<int,bool> sinks[100001];

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
	        //P2(y,sccs.size());
	        order.pop_back();
	        scc.push_back(y);
	        pending[y] = false;
	        if (y == x) break;
	    }
	    sccs.push_back(scc);
    }
}
bool visitedA[100001], visitedB[100001];
int matchedB[100001], matchedA[100001];
bool augment(int x){
  if (visitedA[x]) return false;
  visitedA[x] = true;
  for(map<int,bool>::iterator it=sinks[x].begin();it!=sinks[x].end();++it) {
  	int y = it->first;
    if (!visitedB[y]) {
      visitedB[y] = true;
      // if y is not matched, then we can augment by adding (x, y)
      // Otherwise, we augment from y's matched vertex, i.e. matchedB[y]
      if (matchedB[y] == -1 || augment(matchedB[y])) { 
        matchedB[y] = x;
        return true;
      }
    }
  }
  return false;
}
void maxBipartiteMatching(){
  memset(matchedB, -1, sizeof(matchedB));
  memset(matchedA, -1, sizeof(matchedA));

  REP(i,source.size()) {
  	int x = source[i];
    memset(visitedA, false, sizeof(visitedA));
    memset(visitedB, false, sizeof(visitedB));
    augment(x);
  }
  queue<int> rsource, rsink;
  REP (i,sink.size()) {
  	int y = sink[i];
    if (matchedB[y] != -1){
    	bi_match.pb(mp(matchedB[y],y));
    	matchedA[matchedB[y]] = y;
    } 
    else{
    	rsink.push(y);
    }
  }
  REP(i,source.size()){
  	int x= source[i];
  	if(matchedA[x]==-1){
  		rsource.push(x);
  	}
  }
  if(bi_match.size()){
  	  FOR (i,1,bi_match.size()){
	  	res.pb(mp(bi_match[i-1].second,bi_match[i].first));
	  }
	  res.pb(mp(bi_match[bi_match.size()-1].second,bi_match[0].first));
  }
 while(!rsource.empty()&&!rsink.empty()){
 	if(rsink.front()==rsource.front()){
 		if(rsink.size()==1&&rsource.size()==1){
 			break;
 		}
 		else if(rsink.size()<=rsource.size()){
 			int temp = rsource.front();
 			rsource.pop();
 			rsource.push(temp);
 		}
 		else{
 			int temp = rsink.front();
 			rsink.pop();
 			rsink.push(temp);
 		}
 	}
  	res.pb(mp(rsink.front(),rsource.front()));
  	rsink.pop();
  	rsource.pop();
  }
  while(!rsource.empty()){
  	res.pb(mp(sink[0],rsource.front()));
  	rsource.pop();
  }
  while(!rsink.empty()){
  	res.pb(mp(rsink.front(),source[0]));
  	rsink.pop();
  }
}
void find_sink(int s){
	if(out_deg[s]==0){
		sinks[s].insert(mp(s,true));
	}
	for(map<int,int>::iterator it=scc_adj[s].begin();it!=scc_adj[s].end();++it){
		int y = it->first;
		if(sinks[y].empty()) find_sink(y);
		sinks[s].insert(sinks[y].begin(),sinks[y].end());
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
			// P2("dfs",i);
			cur = i;
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
	REP(i,source.size()){
		find_sink(source[i]);

	}

	if(sccs.size()==1){
		P1(0);
	}
	else{
		P1(MAX(zero_in,zero_out));
		// maxBipartiteMatching();
		// REP(i,res.size()){
		// 	// P2(res[i].first,res[i].second);
		// 	P2(sccs[res[i].first][0],sccs[res[i].second][0]);
		// }

	}
}

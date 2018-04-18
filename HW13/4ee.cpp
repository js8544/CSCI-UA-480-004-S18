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

int mark[100001];
int w;
int notfound;
int marked;
int p;
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

void search(int x){
	if(!mark[x]){
		if(out_deg[x]==0){
			w = x;
			notfound=0;
		}
		mark[x] = 1;
		for(map<int,int>::iterator it=scc_adj[x].begin();it!=scc_adj[x].end();++it){
			if(notfound) search(it->first);
		}
	}
}

signed main(){
	FILL(vnum,0);
	FILL(vlow,0);
	FILL(pending,0);
	FILL(in_deg,0);
	FILL(out_deg,0);
	FILL(mark,0);
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
	queue<int> ssource;
	vector<int> source;
	vector<int> iso;
	vector<int> sink;
	REP(i,sccs.size()){
		if(in_deg[i]==0&&out_deg[i]==0){
			zero_in++;
			zero_out++;
			iso.pb(i);
		}
		else if(in_deg[i]==0){
			zero_in++;
			ssource.push(i);
			source.pb(i);
		}
		else if(out_deg[i]==0){
			zero_out++;
			sink.pb(i);
		}
	}
	vector<int> asource;
	vector<int> asink;
	int marksource[zero_in];
	int marksink[zero_out];
	FILL(marksink,0);
	FILL(marksource,0);

	p=0;
	while(!ssource.empty()){
		int v = ssource.front();
		ssource.pop();
		w = 0;
		notfound = 1;
		search(v);
		if(w!=0){
			p++;
			asource.pb(v);
			asink.pb(w);
			marksource[v]=1;
			marksink[w]=1;
		}
	}

	REP(i,source.size()){
		int x = source[i];
		if(!marksource[x]){
			asource.pb(x);
		}
	}
	REP(i,sink.size()){
		int y = sink[i];
		if(!marksink[y]){
			asink.pb(y);
		}
	}
	vector<PII> res; 

	REP(i,p-1){
		res.pb(mp(asink[i],asource[i+1]));
	}
	int s = source.size();
	int t = sink.size();
	int q = iso.size();
	if(s<=t){
		FOR(i,p,s){
			res.pb(mp(asink[i],asource[i]));
		}
		if(q==0&&s==t){
			res.pb(mp(asink[p-1],asource[0]));
		}
		else if(q==0&&s<t){
			res.pb(mp(asink[p-1],asink[s]));
			FOR(i,s,t-1){
				res.pb(mp(asink[i],asink[i+1]));
			}
			res.pb(mp(asink[t-1],asource[0]));
		}
		else{
			if(s<t)res.pb(mp(asink[p-1],asink[s]));
			else res.pb(mp(asink[p-1],asink[t-1]));
			// FOR(i,s,t-1){
			// 	res.pb(mp(asink[i],asink[i+1]));
			// }
			// res.pb(mp(asink[t-1],iso[0]));
			// REP(i,q-1){
			// 	res.pb(mp(iso[i],iso[i+1]));
			// }
			// res.pb(mp(iso[q-1],asource[0]));

		}
	}
	// else{
	// 	FOR(i,p,t){
	// 		res.pb(mp(asink[i],asource[i]));
	// 	}
	// 	if(q==0&&s==t){
	// 		res.pb(mp(asink[p-1],asource[0]));
	// 	}
	// 	else if(q==0&&t<s){
	// 		res.pb(mp(asink[p-1],asource[t]));
	// 		FOR(i,t,s-1){
	// 			res.pb(mp(asource[i],asource[i+1]));
	// 		}
	// 		res.pb(mp(asource[s-1],asource[0]));
	// 	}
	// 	else{
	// 		res.pb(mp(asink[p-1],asource[t]));
	// 		FOR(i,t,s-1){
	// 			res.pb(mp(asource[i],asource[i+1]));
	// 		}
	// 		res.pb(mp(asource[s-1],iso[0]));
	// 		REP(i,q-1){
	// 			res.pb(mp(iso[i],iso[i+1]));
	// 		}
	// 		res.pb(mp(iso[q-1],asource[0]));

	// 	}
	// }

	if(sccs.size()==1){
		P1(0);
	}
	else P1(MAX(zero_in,zero_out));
}


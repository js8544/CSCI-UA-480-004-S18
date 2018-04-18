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

#define MAXN 1000
#define MAXM 1000
int n,m;
int adj[MAXN];
struct Edge {
  int vertex;
  int nextEdge;
  int c, f; // capacity and flow
  Edge() {}
  Edge(int _vertex, int _c, int _next) { vertex = _vertex; c = _c; f = 0; nextEdge = _next; }
} edges[MAXM * 2]; // double the size because we need to create residual edges

int numEdges;
inline void pushEdge(int x, int y, int c) { // manipulate the adjacency list to add the edge
  //if(c==1)cout<<"added "<<x<<" "<<y<<" "<<adj[x]<<"\n";
  // if(c==0)cout<<"res "<<x<<" "<<y<<"\n";
  edges[numEdges] = Edge(y, c, adj[x]);
  adj[x] = numEdges++;
}
inline void addEdge(int x, int y,int c){ // add an edge (x, y) with capacity c; this creates residual edge too
  pushEdge(x, y, 1);
  pushEdge(y, x, 0); // residual edge initially has capacity zero
}
inline void init() { // must be called before use. otherwise edge links cannot be properly terminated
  numEdges = 0;
  memset(adj, -1, sizeof(adj));
}
int preVertex[MAXN], preEdge[MAXN];
bool v[MAXN];
int edmondsKarp(int S, int T) {
  int maxflow = 0;
  while (true) {
    memset(v, false, sizeof(v));
    bool canAugment = false;
    queue<int> q; q.push(S);
    v[S] = true;
    while(!q.empty()) {
      int x = q.front(); q.pop();
      int edgeIndex = adj[x];
      while (edgeIndex != -1) {
        int y = edges[edgeIndex].vertex;
        // BFS following the edges in the residual graph.
        // if edge.f != edge.c, it means that the edge is not saturated
        if(!v[y] && edges[edgeIndex].f != edges[edgeIndex].c) {
          v[y] = true;
          q.push(y);
          preVertex[y] = x;
          preEdge[y] = edgeIndex;
          if (y == T) { canAugment = true; break; }
        }
        edgeIndex = edges[edgeIndex].nextEdge;
      }
      if (canAugment) break;
    }
    if (!canAugment) break;
    int flow = INF, x = T;
    while (x != S) { // trace the augmenting path to compute how much flow we can send
      //P1("2");
      int unsaturated = edges[preEdge[x]].c - edges[preEdge[x]].f;
      flow = min(flow, unsaturated);
      x = preVertex[x];
    }
    x = T;
    while (x != S) { // actuall send the flow
    	//P1("3");
      edges[preEdge[x]].f += flow;
      edges[preEdge[x]^1].f = -edges[preEdge[x]].f;
      x = preVertex[x];
    }
    maxflow += flow;
  }
  return maxflow;
}



signed main(){
	init();
	cin>>n>>m;
	FOR(i,1,n+1){
		if(i==1||i==n)continue;
		addEdge(i*2,i*2+1,1);
	}
	REP(i,m){
		int a,b;
		cin>>a>>b;
		if((a==1&&b==n)||(a==n&&b==1)){
			P1("impossible");
			return 0;
		}
		if(a!=n&&b!=1)addEdge(a*2+1,b*2,1);
		if(b!=n&&a!=1)addEdge(b*2+1,a*2,1);
	}
	P1(edmondsKarp(3,2*n));
}

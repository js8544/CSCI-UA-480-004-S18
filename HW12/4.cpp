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

struct edge{
	int a;
	int b;
	int w;
}edges[2001];

vector<vector<PII> > adj(2001,vector<PII>(0,mp(0,0)));
int reachable[2001];
int dist[2001];
int n,m;

signed main(){
	FILL(reachable,0);
	
	
	
	reachable[1]=1;
	

	cin>>n>>m;
	REP(i,n+1){
		dist[i] = INF;
	}
	dist[1]=0;
	//P4(dist[1],dist[2],dist[3],dist[4]);


	REP(i,m){
		int a,b,w;
		cin>>a>>b>>w;
		edges[i].a = a;
		edges[i].b = b;
		edges[i].w = w;
		adj[a].pb(mp(b,w));
	}

	queue<int> q;
	q.push(1);
	while(!q.empty()){
		int x = q.front();
		q.pop();
		REP(i,adj[x].size()){
			int y = adj[x][i].first;
			if(!reachable[y]){
				reachable[y] = 1;
				q.push(y);
			}
		}
	}

	int min=0,max=0;
	int ncycle = 0,pcycle = 0;
	

	REP(x1,n-1){
		REP(i,m){
			int a,b,w;
			a = edges[i].a;
			b = edges[i].b;
			w = edges[i].w;
			if(reachable[a]){
				if(dist[a]+w<dist[b]){
					dist[b] = dist[a]+w;
				}
				if(dist[b]<min)min=dist[b];
			}
		}
	}
	//P4(dist[1],dist[2],dist[3],dist[4]);
	REP(i,m){
		int a,b,w;
		a = edges[i].a;
		b = edges[i].b;
		w = edges[i].w;
		if(reachable[a]){
			if(dist[a]+w<dist[b]){
				ncycle = 1;
			}
		}
	}

	REP(i,m){
		edges[i].w *= -1;
	}
	REP(i,n+1){
		dist[i] = INF;
	}
	dist[1]=0;
	REP(x1,n-1){
		REP(i,m){
			int a,b,w;
			a = edges[i].a;
			b = edges[i].b;
			w = edges[i].w;
			if(reachable[a]){
				if(dist[a]+w<dist[b]){
					dist[b] = dist[a]+w;
				}
				if(dist[b]<max)max=dist[b];
			}
		}
	}

	REP(i,m){
		int a,b,w;
		a = edges[i].a;
		b = edges[i].b;
		w = edges[i].w;
		if(reachable[a]){
			if(dist[a]+w<dist[b]){
				pcycle = 1;
			}
		}
	}

	if(ncycle) cout<<"-infinity ";
	else cout<<min<<" ";
	if(pcycle) cout<<"infinity\n";
	else cout<<-max<<"\n";



}

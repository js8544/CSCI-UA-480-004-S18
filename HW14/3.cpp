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
#define MAXA 501
#define MAXB 501
int n,m;

vector<int> adj[MAXA];
bool visitedA[MAXA], visitedB[MAXB];
int matchedB[MAXB], matchedA[MAXA];
vector<int> ansA,ansB;
bool augment(int x){
  if (visitedA[x]) return false;
  visitedA[x] = true;
  REP(i,adj[x].size()) {
  	int y = adj[x][i];
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
int maxBipartiteMatching(){
  memset(matchedB, -1, sizeof(matchedB));
  memset(matchedA, -1, sizeof(matchedA));
  REP(x,n) {
    memset(visitedA, false, sizeof(visitedA));
    memset(visitedB, false, sizeof(visitedB));
    augment(x);
  }
  int cardinality = 0;
  REP(y,m) {
    if (matchedB[y] != -1){
      cardinality++; // matched edge (matchedB[y], y)
      matchedA[matchedB[y]] = y; 
    } 
  }
  return cardinality;
}

void alternate(int a){
  visitedA[a]=true;
  REP(i,adj[a].size()){
    int b = adj[a][i];
    if(visitedB[b]==false){
      visitedB[b] = true;
      alternate(matchedB[b]);
    }
  }
}


signed main(){
	cin>>n>>m;

	REP(i,n)REP(j,m){
		char c;cin>>c;
		if(c=='*') adj[i].pb(j);
	}

	P1(maxBipartiteMatching());
  FILL(visitedA,false);
  FILL(visitedB,false);
  REP(i,n){
    if(matchedA[i]==-1) alternate(i);
  }
  REP(i,n){
    if(!visitedA[i]) P2("r",i+1);
  }
  REP(i,m){
    if(visitedB[i]) P2("c",i+1);
  }
  // REP(i,ansA.size()){
  //   P2("r",ansA[i]+1);
  // }
  // REP(i,ansB.size()){
  //   P2("c",ansB[i]+1);
  // }
}


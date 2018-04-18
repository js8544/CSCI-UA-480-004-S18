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

int n;
int black[100],red[100];
vector<pair<int,pair<int,int> > > edges;
struct node{
  int parent;
  int rank;
}nodes[100];

int findRoot(int x){
  if(nodes[x].parent == x) return x;
  return nodes[x].parent = findRoot(nodes[x].parent);
}

void unionNodes(int x,int y){
  int xRoot = findRoot(x);
  int yRoot = findRoot(y);

  if(nodes[xRoot].rank>nodes[yRoot].rank){
    int temp = xRoot;
    xRoot = yRoot;
    yRoot = temp;
  }
  if(nodes[xRoot].rank==nodes[yRoot].rank){
    nodes[yRoot].rank++;
  }
  nodes[xRoot].parent = yRoot;
}

signed main(){
  cin>>n;
  REP(i,n){
    cin>>red[i]>>black[i];
    nodes[i].parent=i;
    nodes[i].rank=0;
  }
  REP(i,n){
    FOR(j,i+1,n){
      int w = MIN(red[i]^black[j],red[j]^black[i]);
      edges.pb(mp(w,mp(i,j)));
    }
  }
  sort(edges.begin(),edges.end());

  int wMST=0;

  REP(i,edges.size()){
    int x = edges[i].second.first;
    int y = edges[i].second.second;
    //P3(edges[i].first,x,y);
    //P2(findRoot(x),findRoot(y));
    if(findRoot(x)!=findRoot(y)){
      wMST+=edges[i].first;
      unionNodes(x,y);
    }
  }
  P1(wMST);

}



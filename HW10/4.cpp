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

using namespace std;

#define mod 1000000007LL
#define ll long long
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
// root is at 0
#define MAXSEG 2000001 // MAXSEG >= 4N
#define int long long

map<int,int> occur;
int arr[300001];
int depth[200001];
int visited[200001];
int dis[200001];
int seg_count=1;


int val[MAXSEG];
void build(int k, int nl, int nr) {
  if (nl == nr) {
    val[k] = arr[nl]; // arr[] is the original array
    return;
  }
  int nm = (nl+nr)/2;
  build(2*k+1, nl, nm);
  build(2*k+2, nm+1, nr);
  if(depth[val[2*k+1]]<depth[val[2*k+2]])val[k]=val[2*k+1];
  else val[k] = val[2*k+2];
}
// void change(int k, int nl, int nr, int x, int v){
// 	if(x < nl || x > nr) return;
// 	if (nl == nr) {
// 		val[k] = v; // update val using v here
// 		return;
// 	}
// 	int nm = (nl+nr)/2;
// 	change(2*k+1, nl, nm, x, v);
// 	change(2*k+2, nm+1, nr, x, v);
// 	val[k] = MIN(val[2*k+1],val[2*k+2]);	// update val here
// }
int get(int k, int nl, int nr, int l, int r){
	if(r < nl || l > nr) return 0;
	if(l <= nl && nr <= r) return val[k];	// return answer here
	int nm = (nl+nr)/2;
	int a1 = get(2*k+2, nm+1, nr, l, r);
	int a2 = get(2*k+1, nl, nm, l, r);
	if(depth[a1]<depth[a2]) return a1;
	else return a2;
}


struct node{
	vector<int> ns;
	vector<int> ws;
}tree[200001];

void dfs(int x){
	REP(i,tree[x].ns.size()){
		int y = tree[x].ns[i];
		int w = tree[x].ws[i];
		if(!visited[y]){
			//P4("x",x,"y",y);
			depth[y] = depth[x]+1;
			visited[y] = 1;
			dis[y] = dis[x]+w;
			//P4("x:",dis[x],"y:",dis[y]);
			occur[y] = seg_count;
			arr[seg_count] = y;//depth[y];
			seg_count++;
			dfs(y);
			arr[seg_count] = x;//depth[x];
			seg_count++;
		}
	}
}

signed main(){
	FILL(val,0);
	FILL(depth,0);
	FILL(arr,0);
	FILL(visited,0);
	FILL(dis,0);
	int n;
	cin>>n;

	REP(i,n-1){
		int a,b,w;
		cin>>a>>b>>w;

		tree[a].ns.pb(b);
		tree[a].ws.pb(w);
		tree[b].ns.pb(a);
		tree[b].ws.pb(w);
	}
	occur[1]=0;
	visited[1]=1;
	arr[0]=1;
	depth[0]=100007;
	depth[1]=0;
	dfs(1);




	build(0,0,seg_count);

	// FOR(i,0,n+1){
	// 	P1(depth[i]);
	// }
	int q;
	cin>>q;

	REP(i,q){
		int a,b;
		cin>>a>>b;

		int c = get(0,0,seg_count-1,MIN(occur[a],occur[b]),MAX(occur[a],occur[b]));
		//P2(MIN(occur[a],occur[b]),MAX(occur[a],occur[b]));
		//P3(a,b,c);
		P1(dis[a]+dis[b]-2*dis[c]);
	}

}

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
#define MAXN 500000

int n,m, dist[500][500];
int grid[500][500];
PII prev[500][500];
struct Pair { // custom pair (vertex, distance) that compares based on distance
  int x, y,d;
  Pair(int _x, int _y,int _d): x(_x), y(_y),d(_d) {}
  bool operator < (const Pair &another) const { {
  	if(d > another.d){
  		return 1;
  	}
  	else if(d < another.d){
  		return 0;
  	}
  	else{
  		if(x>another.x){
  			return 0;
  		}
  		else if(y<another.y){
  			return 0;
  		}
  		else{
  			return 1;
  		}
  	}
  }
}
};

int valid(int x,int y){
	if(x>=0&&x<n&&y>=0&&y<m){
		if(grid[x][y]) return 1;
	}
	return 0;
}
signed main(){
	cin>>n>>m;

	REP(i,n){
		REP(j,m){
			cin>>grid[i][j];
		}
	}

	priority_queue<Pair> pq;
  	pq.push(Pair(0,0, 0));
  	REP(i,n)REP(j,m)dist[i][j] = INF;
  	dist[0][0] = 0;
  	while (!pq.empty()) {
    	int x,y;
    	Pair cur = pq.top();
    	x = cur.x;
    	y = cur.y;
    	pq.pop();
    	if (cur.d > dist[x][y]) continue; // ignore out-of-date pair
    	
    	if(valid(x+1,y)){
    		if(dist[x][y] + grid[x+1][y] < dist[x+1][y]){
    			dist[x+1][y] = dist[x][y] + grid[x+1][y];
    			pq.push(Pair(x+1,y,dist[x+1][y]));
    			prev[x+1][y] = make_pair(x,y);
    		}
    	}

    	if(valid(x,y-1)){
    		if(dist[x][y] + grid[x][y-1] < dist[x][y-1]){
    			dist[x][y-1] = dist[x][y] + grid[x][y-1];
    			pq.push(Pair(x,y-1,dist[x][y-1]));
    			prev[x][y-1] = make_pair(x,y);
    		}
    	}
    
    	if(valid(x,y+1)){
    		if(dist[x][y] + grid[x][y+1] < dist[x][y+1]){
    			dist[x][y+1] = dist[x][y] + grid[x][y+1];
    			pq.push(Pair(x,y+1,dist[x][y+1]));
    			prev[x][y+1] = make_pair(x,y);
    		}
    	}
    	if(valid(x-1,y)){
    		if(dist[x][y] + grid[x-1][y] < dist[x-1][y]){
    			dist[x-1][y] = dist[x][y] + grid[x-1][y];
    			pq.push(Pair(x-1,y,dist[x-1][y]));
    			prev[x-1][y] = make_pair(x,y);
    		}
    	}
  	}
  	if(dist[n-1][m-1]==INF){
  		P1("impossible");
  		return 0;
  	} 
  	else P1(dist[n-1][m-1]);
  	int curx = n-1;
  	int cury = m-1;
  	stack<char> ins;
  	while(curx!=0||cury!=0){
  		int prevx = prev[curx][cury].first;
  		int prevy = prev[curx][cury].second;
  		if(prevx == curx -1){
  			ins.push('t');
  		}
  		if(prevx == curx +1){
  			ins.push('b');
  		}
  		if(prevy == cury -1){
  			ins.push('r');
  		}
  		if(prevy == cury +1){
  			ins.push('l');
  		}
  	}
  	while(!ins.empty()){
  		char i = ins.top();
  		ins.pop();
  		cout<<i;
  	}
  	cout<<"\n";
  	// REP(i,n){
  	// 	REP(j,m){
  	// 		cout<<dist[i][j]<<" ";
  	// 	}
  	// 	cout<<"\n";
  	// }
}

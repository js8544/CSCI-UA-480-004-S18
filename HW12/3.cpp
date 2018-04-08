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
#define INF 1000000007


char grid[501][501];
vector<PII> fire;
int n,m,dist[501][501];

int valid(PII a){

	int x = a.first;
	int y = a.second;
	//P3("CHECKING",x,y);
	if(x<0||x>=n||y<0||y>=m)return 0;
	if(grid[x][y]=='F'||grid[x][y]=='#') return 0;
	return 1;
}

vector<PII> neighbor(PII x){
	//P3("NEIGHBOR OF",x.first,x.second);
	vector<PII> n;
	PII a = make_pair(x.first-1,x.second);
	PII b = make_pair(x.first+1,x.second);
	PII l = make_pair(x.first,x.second-1);
	PII r = make_pair(x.first,x.second+1);

	if(valid(a)) n.pb(a); 
	if(valid(b)) n.pb(b); 
	if(valid(l)) n.pb(l); 
	if(valid(r)) n.pb(r); 

	// REP(i,n.size()){
	// 	P2(n[i].first,n[i].second);
	// }
	// P1("DONE");
	return n;

}
signed main(){
	cin>>n>>m;
	PII start;
	REP(i,n){
		REP(j,m){
			dist[i][j]=INF;
			cin>>grid[i][j];
			if(grid[i][j]=='J'){
				start.first = i;
				start.second = j;
			}
			if(grid[i][j]=='F'){
				fire.pb(make_pair(i,j));
			}
		}
	}

	queue<PII> q1;
	queue<PII> q2;
    q1.push(start);
    dist[start.first][start.second] = 0;
    int r=0;
    int out=0;
    while (!q1.empty()) {
	    PII x = q1.front();
	    q1.pop();
	    //P2(x.first,x.second);
	    if(grid[x.first][x.second]=='H'){
	    	out=1;
	    	break;
	    }
	    if(grid[x.first][x.second]!='F'){
	    	vector<PII> nei = neighbor(x);
	    	REP(i,nei.size()) {
	    		PII y = nei[i];
		    	//P4(y.first,y.second,dist[y.first][y.second],INF);

			    if (dist[y.first][y.second] == INF) {
			        dist[y.first][y.second] = dist[x.first][x.second] + 1;
			        q2.push(y);
			    }
		    }
	    }
	    
	    if(q1.empty()){
	    	// P2("FIRE",r);
	    	// REP(i,fire.size()){
	    	// 	P2(fire[i].first,fire[i].second);
	    	// }
	    	// P1("DONE");
	    	r++;
	    	int fsize = fire.size();
	    	REP(i,fsize){
	    		vector<PII> nei = neighbor(fire[i]);
		    	REP(j,nei.size()) {
		    		PII y = nei[j];
				    grid[y.first][y.second] = 'F';
				    fire.pb(y);
			    }
	    	}
	    	swap(q1,q2);

	    }

    }
    if(out)P1(r);
    else P1("-1");

}

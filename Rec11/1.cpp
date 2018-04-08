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
char grid[12][12];
int depth[12][12];
signed main(){
	int r,c,e;
	cin>>r>>c>>e;
	while(r!=0&&c!=0){
		//P3(r,c,e);
		FILL(grid,'*');
		FILL(depth,0);
		REP(i,r){
			REP(j,c){
				cin>>grid[i+1][j+1];
			}
		}
		int d = 1;
		int i = 1;
		int j = e;
		int loop = 0;
		int length = 0;
		// REP(i,12){
		// 	REP(j,12){
		// 		cout<<grid[i][j];
		// 	}
		// 	cout<<"\n";
		// }
		while(grid[i][j]!='*'){
			depth[i][j] = d;
			char ins = grid[i][j];
			//P1(ins);
			if(ins=='W')j--;
			if(ins=='N')i--;
			if(ins=='E')j++;
			if(ins=='S')i++;
			d++;
			if(depth[i][j]){
				loop = 1;
				length = d - depth[i][j];
				break;
			}
		}

		if(!loop){
			P2(d-1,"step(s) to exit");
		}
		else{
			P4(depth[i][j]-1,"step(s) before a loop of",length,"step(s)");
		}
		cin>>r>>c>>e;

	}
}

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
int t,n,m,h,v;
char grid[200][200];
int row[200];
int col[200];
signed main(){
	
	cin>>t;
	REP(x1,t){
		vector<int> hcut;
		vector<int> vcut;
		hcut.pb(0);
		vcut.pb(0);
		FILL(grid,0);
		FILL(row,0);
		FILL(col,0);
		int count=0;
		cin>>n>>m>>h>>v;
		REP(i,n){
			REP(j,m){
				cin>>grid[i][j];
				
				if(grid[i][j]=='@'){
					row[i]++;
					col[j]++;
					count++;
				}
			}
		}
		if(count%((h+1)*(v+1))!=0){
			cout<<"Case #"<<x1+1<<": IMPOSSIBLE\n";
			continue;
		}
		int quo = count/(h+1);
		int cur = 0;
		int cur_total = 0;
		int i=0;
		int impossible=0;
		while(i<n){
			cur = 0;
			while(cur<quo){
				cur+=row[i];
				cur_total+=row[i];
				i++;
			}
			if(cur>quo||cur_total>count){
				impossible=1;
				break;
			}
			else{
				// P2("hcut",i);
				hcut.pb(i);
			}
			if(cur_total==count){
				break;
			}
		}

		if(impossible){
			//P4(impossible,cur_total,count,i);
			cout<<"Case #"<<x1+1<<": IMPOSSIBLE\n";
			continue;
		}

		quo = count/(v+1);
		impossible = 0;
		cur_total=0;
		i=0;
		while(i<m){
			cur = 0;
			while(cur<quo){
				cur+=col[i];
				cur_total+=col[i];
				i++;
			}
			if(cur>quo||cur_total>count){
				impossible=1;
				break;
			}
			else{
				// P2("vcut",i);
				vcut.pb(i);
			}
			if(cur_total==count){
				break;
			}

		}
		if(impossible){
			cout<<"Case #"<<x1+1<<": IMPOSSIBLE\n";
			continue;
		}

		quo = count/((h+1)*(v+1));
		impossible=0;

		FOR(h,1,hcut.size()){
			FOR(v,1,vcut.size()){
				// P2(hcut[h],vcut[v]);
				int block = 0;
				FOR(i,hcut[h-1],hcut[h]){
					FOR(j,vcut[v-1],vcut[v]){
						if(grid[i][j]=='@'){
							block++;
						}
					}
				}
				if(block!=quo){
					impossible=1;
					break;
				}
			}

			if(impossible) break;
		}
		if(impossible){
			cout<<"Case #"<<x1+1<<": IMPOSSIBLE\n";
			continue;
		}

		cout<<"Case #"<<x1+1<<": POSSIBLE\n";


	}
}

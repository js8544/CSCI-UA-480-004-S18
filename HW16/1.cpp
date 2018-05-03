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
#define MAXN 100001
int n,m,s;
vector<vector<int> > A;
int block(int i1,int i2,int j1,int j2){
	if(i1>=0&&j1>=0)return A[i2][j2]-A[i1][j2]-A[i2][j1]+A[i1][j1];
	else if(j1!=-1) return A[i2][j2]-A[i2][j1];
	else if(i1!=-1) return A[i2][j2]-A[i1][j2];
	else return A[i2][j2];
}
signed main(){
	cin>>n>>m>>s;

	REP(i,n){
		vector<int> temp;
		REP(j,m){
			int x;
			cin>>x;
			if(i==0&&j==0){
				temp.pb(x);
			}
			else if(i==0){
				temp.pb(temp[j-1]+x);
			}
			else if(j==0){
				temp.pb(A[i-1][0]+x);
			}
			else{
				temp.pb(A[i-1][j]+temp[j-1]-A[i-1][j-1]+x);
			}
		}
		A.pb(temp);
	}

	if(n>m){
		vector<vector<int> > B;
		REP(j,m){
			vector<int> temp;
			REP(i,n){
				temp.pb(A[i][j]);
			}
			B.pb(temp);
		}
		A = B;
		int temp = m;
		m = n;
		n = temp;
	}

	

	// REP(i,n){
	// 	REP(j,m){
	// 		cout<<A[i][j]<<" ";
	// 	}
	// 	cout<<"\n";
	// }

	int count=0;


	REP(i1,n){
		FOR(i2,i1,n){
			vector<int> blocks;
			REP(j1,m){
				// P4(i1-1,i2,j1-1,j1);
				// P1(block(i1-1,i2,j1-1,j1));
				blocks.pb(block(i1-1,i2,j1-1,j1));
				
			}
			int start = 0, cur = 0, area = 0;
			while(cur<m){
				while(area+blocks[cur]>s){
					area -= blocks[start];
					start++;
					if(start>cur) break;
				}
				area += blocks[cur];
				count += (cur-start+1);
				cur++;
				//P3(start,cur,area);

			}
		}
	}

	P1(count);


}

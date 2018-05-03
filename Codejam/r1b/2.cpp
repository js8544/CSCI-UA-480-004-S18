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
int t,n;
int A[100001],B[100001];
int ans[100001];
int valid(int l,int n){
	int c=0;
	REP(i,n-l+1){
		int m1 = A[i]; int n1 = B[i];
		//P2(m1,n1);
		int m2,m3,n2,n3;
		int f2 = 0;
		int f3 = 0;
		int cp;
		FOR(j,i+1,i+l){
			if(A[j]!=m1&&B[j]!=n1){
				f2 = 1;
				m2 = A[j];
				n2 = B[j];
				cp = j;
				// P4(m1,n1,m2,n2);
				break;
			}
		}
		if(f2 == 0){
			c++;
			continue;
		}
		FOR(k,cp+1,i+l){
			if(A[k]!=m1&&A[k]!=m2&&B[k]!=n1&&B[k]!=n2){
				f3 = 1;
				break;
			}
		}
		if(f3 == 0){
			c++;
		}
	}
	// P2(l,c);
	return c;
}
signed main(){
	cin>>t;
	REP(i,t){
		cin>>n;
		REP(j,n){
			int d,a,b;
			cin>>d>>a>>b;
			A[j] = d+a;
			B[j] = d-b;
		}

		int l = 0;
		int r = n;
		int c= valid(r,n);
		if(c){
			cout<<"Case #"<<i+1<<": "<<n<<" "<<1<<"\n";
			continue;
		}
		while(r>l){
			int m = (l+r)/2;
			if(valid(m,n)){
				l = m+1;
			}
			else{
				r = m;
			}
		}
		cout<<"Case #"<<i+1<<": "<<r-1<<" "<<valid(r-1,n)<<"\n";
		
	}
}

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
int t,A;
int n22=0, n24=0,n32=0,n34=0;
int f;
int is_n(int x1,int y1,int x2,int y2){
	if(ABS(x1-x2)<=1&&ABS(y1-y2)<=1){
		return 1;
	}
	else{
		return 0;
	}
}

void o(int x,int y){
	//cout<<x<<" "<<y<<endl;
	cout<<"haha";
	int a,b;
	cin>>a>>b;
	if(a==0&&b==0) f = 1;
	if(is_n(2,2,a,b))n22++;
	if(is_n(2,4,a,b))n24++;
	if(is_n(3,2,a,b))n32++;
	if(is_n(3,4,a,b))n34++;
}
signed main(){
	cin>>t;
	REP(i,t){
		f=0;
		cin>>A;
		while(n22!=9){
			o(2,2);
			if(f) return 0;
		}
		while(n24!=9){
			o(2,4);
			if(f) return 0;
		}
		while(n32!=9){
			o(3,2);
			if(f) return 0;
		}
		while(n34!=9){
			o(3,4);
			if(f) return 0;
		}
	}
}

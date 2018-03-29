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
int votes[2001];
int vj;
int n;

int check(int x){
	int v = vj+x;
	int sum=0;
	FOR(i,1,n){
		if(votes[i]<v){
			continue;
		}
		sum += votes[i]-v+1;
		if(sum>x){
			return 0;
		}
	}
	return 1;
}

int main(){
	cin>>n;
	int max = 0;
	REP(i,n){
		cin>>votes[i];
		max = MAX(max,votes[i]);
	}
	vj = votes[0];
	int l=-1,r=max-vj+1;

	while(r-l>1){
		int m = (r+l)/2;
		if(check(m)) r=m;
		else l=m;
	}

	P1(r);
}
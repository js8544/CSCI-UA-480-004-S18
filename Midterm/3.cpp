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

int main(){
	int n,k;
	cin>>n>>k;

	int pre_sum[n+k+1];
	FILL(pre_sum,0);
	int size[n];

	REP(i,n){
		char c;
		cin>>c;
		if(c=='.')size[i]=0;
		if(c=='*')size[i]=1;
	}

	int sum = 0;
	int ans = 0;

	REP(i,n-k+1){
		//P2(i,sum);
		size[i]+=sum;
		size[i]%=2;
		if(size[i]==1){
			pre_sum[i] += 1;
			pre_sum[i+k-1] += 1;
			ans +=1;
			//P4("put",i,sum,size[i]);
		}
		sum += pre_sum[i];
		sum = sum%2;

	}
	FOR(i,n-k+1,n){
		size[i]+=sum;
		size[i]%=2;
		if(size[i]!=0){
			cout<<"impossible"<<"\n";
			return 0;
		}
		sum+=pre_sum[i];
		sum=sum%2;
	}
	P1(ans);

}

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

using namespace std;

#define mod 1000000007LL
#define ll long long
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ABS(x) ((x)<0?-(x):(x))
#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define FILL(a,b) memset(a,b,sizeof(a))

ll M[4][4] = {{0,1,0,0},{0,0,1,0},{0,0,0,1},{2,4,1,1}};

void mmultiply(ll a[4][4],ll b[4][4]){
	ll mul[4][4];
	FOR(i,0,4){
		FOR(j,0,4){
			mul[i][j] = 0ll;
			FOR(k,0,4){
				mul[i][j] += (a[i][k] * b[k][j]) % mod;
				mul[i][j] %= mod;
			}
		}
	}

	FOR(i,0,4){
		FOR(j,0,4){
			a[i][j] = mul[i][j];
		}
	}
}

void power(ll F[4][4],ll p){
	if(p==1){
		return;
	}

	power(F,p/2);
	mmultiply(F,F);
	if(p%2!=0) mmultiply(F,M);

}

int main(){
	ll F[4][4] = {{0,1,0,0},{0,0,1,0},{0,0,0,1},{2,4,1,1}};
	ll n;
	cin>>n;
	if(n==1){
		cout<<1<<"\n";
	}
	else if(n==2){
		cout<<2<<"\n";
	}
	else if(n==3){
		cout<<7<<"\n";
	}
	else if(n==4){
		cout<<15<<"\n";
	}
	else{
		power(F,n-4);
		cout<<(1*F[3][0]+2*F[3][1]+7*F[3][2]+15*F[3][3])%mod<<"\n";
	}
}

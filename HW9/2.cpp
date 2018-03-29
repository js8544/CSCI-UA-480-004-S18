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

int n;
double loc[200001];
double vel[200001];
double maxd(double t){
	double lm=1E9,rm=-1E9;
	REP(i,n){
		double cur = loc[i]+vel[i]*t;
		lm = MIN(lm,cur);
		rm = MAX(rm,cur);
	}
	return rm-lm;
}

int main(){

	cin>>n;

	double rm_loc=-1E9,lm_loc=1E9,rm_vel=-1E9,lm_vel=1E9;
	REP(i,n){
		cin>>loc[i]>>vel[i];
		if(loc[i]<lm_loc){
			lm_loc = loc[i];
			lm_vel = vel[i];
		}
		else if(loc[i]==lm_loc&&vel[i]<lm_vel) lm_vel=vel[i];
		if(loc[i]>rm_loc){
			rm_loc = loc[i];
			rm_vel = vel[i];
		}
		else if(loc[i]==rm_loc&&vel[i]>rm_vel) rm_vel=vel[i];
	}

	//P4(rm_loc,lm_loc,rm_vel,lm_vel);

	double max_dis = rm_loc-lm_loc;

	if(rm_vel-lm_vel>=0){
		cout<<max_dis<<"\n";
	}
	else{
		double r = max_dis,l=0;
		while(r-l>=1E-8){
			
			double t1 = l+(r-l)/3;
			double t2 = r-(r-l)/3;

			//P4(l,t1,t2,r);

			if(maxd(t1)>maxd(t2)) l=t1;
			else r=t2;
		}
		cout<<setprecision(9)<<maxd(r)<<"\n";
	}
}
#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

const unsigned int m = 1000000007;

int mod_add(int a,int b){
	return (a % m + b % m) % m;
}

int mod_mul(long long a,long long b){
	long long result = (long long) (a % m) * (b % m);
	return result % m;
}
int main(){
	__int128 a=0;
	int b=0;
	string buff;
	long long r=1;

	cin>>a;
	cin>>buff;
	cin>>b;

	long long x = a % m;

	for(int i=0;i<b;i++){
		//cout<<r<<"\n";
		r = mod_mul(r,x);
	}

	cout<<r;
}
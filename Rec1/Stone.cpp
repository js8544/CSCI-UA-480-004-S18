#include<stdio.h>

int main(){
	long long int n,m,a;
	long long int w,l;
	scanf("%lld %lld %lld",&n,&m,&a);

	w = (n % a)? n/a+1 : n/a;
	l = (m % a)? m/a+1 : m/a;

	printf("%lld",w*l);
	return 0;

}
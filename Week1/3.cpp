#include<iostream>

using namespace std;

int main(){
	int m,n;
	scanf("%d %d",&n,&m);

	int a = m/5;
	int b = n/5;
	int c = m%5;
	int d = n%5;

	printf("%d,%d,%d,%d\n",a,b,c,d);
	int r;

	r = a*b*5+c*b+d*a;

	if(c+d>=5){
		r += c + d -4;
	}

	printf("%d\n",r);
}
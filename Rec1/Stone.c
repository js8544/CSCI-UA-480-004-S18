#include<stdio.h>

int main(){
	int n,m,a;
	int w,l;
	scanf("%d %d %d",&n,&m,&a);

	w = (n+a-1)/a;
	l = (m+a-1)/a;

	printf("%d",w*l);
	return 0;

}
#include<stdio.h>

int main(){
	int m,n;
	int i=1;
	int c=0;

	scanf("%d\n%d",&n,&m);

	//printf("%d,%d\n",m,n);
	int r = m;

	while(r>i){
		r = r-i;
		if(c<n){
			i *= 2;
			c++;
		}
		//printf("Power:%d,value:%d,r:%d\n",c,i,r);
	}
	if(c<n){
		printf("%d",m);
	}
	else{
		printf("%d",r-1);
	}
}
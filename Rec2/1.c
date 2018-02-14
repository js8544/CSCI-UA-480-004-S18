#include<stdio.h>

int main(){
	int n;
	scanf("%d",&n);

	char name[n];
	int fib1=0;
	int fib2=1;
	int fib=1;

	for(int i=0;i<n;i++){
		name[i] = 'o';
	}

	while(fib<n+1){
		name[fib-1] = 'O';
		//printf("%d",fib);
		fib = fib1+fib2;
		fib1 = fib2;
		fib2 = fib;
	}

	for(int i=0;i<n;i++){
		printf("%c",name[i]);
	}

}
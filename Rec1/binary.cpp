#include<stdio.h>

int main(){
	int a;
	while(scanf("%d",&a)!=EOF){
		char b[10];
		int d = 0;
		while(a){
			b[d] = '0'+a % 2;
			a = a/2;
			d++;
		}
		for(int i=d-1;i>=0;i--){
			printf("%c",b[i]);
		}
		printf("\n");
	}
}
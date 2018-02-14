#include<stdio.h>

int main(){
	int num = 0;
	scanf("%d",&num);
	int max = -100;
	for(int i=0;i<num;i++){
		int temp;
		scanf("%d",&temp);
		max = (max > temp)? max : temp ;
	}
	printf("%d",max);
	return 0;
}
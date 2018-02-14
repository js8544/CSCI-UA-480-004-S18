#include<stdio.h>

int main(){
	int input;
	char temp;
	int sum = 0;
	while(scanf("%d%c",&input,&temp) != EOF){
		if(temp == '\n'){
			sum+=input;
			printf("%d\n",sum);
			sum = 0;
		}
		else{
			sum += input;
		}
	}
	return 0;
}
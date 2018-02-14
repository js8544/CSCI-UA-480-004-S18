#include<iostream>
using namespace std;

char stack[100000];

int s(char a){
	if(a=='('||a=='['){
		return 1;
	}
	else{
		return 0;
	}
}


int main(){
	int base = 0, top = 0;

	char ch=getchar();
	stack[base] = ch;

	int jump=0;
	while((ch=getchar())!='\n'){
		if(ch==EOF)break;
		if(ch==' ')continue;
		if((stack[top]=='['&&ch==']')||(stack[top]=='('&&ch==')')){
			top--;
		}
		// else if((stack[base]=='['&&ch==']')||(stack[base]=='('&&ch==')')){
		// 	base++;
		// 	jump = 1;
		// }
		else{
			top++;
			stack[top] = ch;
		}
		// printf("Current Stack: Base:%d,Top:%d\n",base,top);
		// for(int i=top;i>=base;i--){
		// 	printf("%d:%c\n",i,stack[i]);
		// }
	}
	if(top-base==-1 && !jump){
		printf("valid");
		return 0;
	}
	else if((top-base)%2==1){
		for(int i=base;i<(top+base-1)/2;i++){
			if(!((stack[base]=='('&&stack[top]==')')||(stack[base]=='['&&stack[top]==']'))){
				printf("invalid no");
				return 0;
			}
			else{
				top--;
				base++;
			}
		}
		//printf("%d\n",top-base);
		if(s(stack[top])==0||s(stack[base])==1)
		{
			printf("invalid yes");
			return 0;
		}
		else{
			printf("invalid no");
			return 0;
		}
	}
	else{
		printf("invalid no");
		return 0;
	}


}
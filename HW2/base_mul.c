#include<stdio.h>
const unsigned int m = 1000000007;

int mod_add(int a,int b){
	return (a % m + b % m) % m;
}

int mod_mul(int a,int b){
	long long result = (long long) (a % m) * (b % m);
	return result % m;
}

int main(){
	int base;
	char buff[100];
	int a=0,b=0;
	char c;
	int d=0;
	scanf("%d",&base);
	fgets(buff,100,stdin);
	while(1){
		scanf("%c",&c);
		if(c!='\n'){
			if(c-'0'<10){
				d = c-'0';
			}
			else if(c - 'A'< 26){
				d = c-'A'+36;
			}
			else if(c - 'a'<26){
				d = c-'a'+10;
			}
			a = mod_add(mod_mul(a,base),d);
		}
		else{
			break;
		}
	}
	while(1){
		scanf("%c",&c);
		if(c!='\n'){
			if(c-'0'<10){
				d = c-'0';
			}
			else if(c - 'A'< 26){
				d = c-'A'+36;
			}
			else if(c - 'a'<26){
				d = c-'a'+10;
			}
			b = mod_add(mod_mul(b,base),d);
		}
		else{
			break;
		}
	}
	printf("%d\n",mod_mul(a,b));

}
#include<stdio.h>
#include<string.h>

int check(int c,char s[c]){

	if(strcmp(s,"[]")==0 || strcmp(s,"()")==0 || c==0){

		return 1;
	}
	else if(((c%2)==1) || (s[0] == ')') || (s[c-1] == '(') || (s[0]==']')||(s[c-1]=='[')){

		return 0;
	}
	else if((s[0]=='('&&s[c-1]==')') || (s[0]=='['&&s[c-1]==']')){


		char m[c-2];
		memcpy(m,&s[1],c-2);
		if(check(c-2,m)){
			return 1;
		}
	}
	int i;
	for(i=2;i<c;i+=2){
		char k[i];
		char l[c-i];
		memcpy(k,s,i);
		memcpy(l,&s[i],c-i);



		if(check(i,k) && check(c-i,l)){
			return 1;
		}
	}
	return 0;
}

int main(){
	int n;
	char buff[100];
	scanf("%d",&n);
	fgets(buff,100,stdin);

	char list[n][200];
	int length[n];
	int i;
	for(i=0;i<n;i++){
		int j=0;
		char c = fgetc(stdin);
		while(c != '\n'){
			list[i][j] = c;
			c = fgetc(stdin);
			j++;
		}
		length[i] = j;

		if(check(length[i],list[i])){
			printf("Yes\n");
		}
		else{
			printf("No\n");
		}
	}

}
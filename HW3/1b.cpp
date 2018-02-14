#include<iostream>
#include<cstring>
#include<map>
#include<stdio.h>
#include<string>

using namespace std;

int main(){
	int n,m;
	scanf("%d",&n);

	char students[n][12];
	map<string,int> pos;

	for(int i=0;i<n;i++){
		scanf("%s ",students[i]);
		pos[students[i]] = i;
	}

	scanf("%d\n",&m);

	for(int i=0;i<m;i++){
		char ins;
		char name[12];
		scanf("%c ",&ins);
		if(ins == 'x'){
			char name2[12];

			scanf("%s %s\n",name,name2);

			int pos1 = pos[name];
			int pos2 = pos[name2];

			pos[name] = pos2;
			pos[name2] = pos1;

			char temp[20];
			strcpy(temp,students[pos2]);
			strcpy(students[pos2],students[pos1]);
			strcpy(students[pos1],temp);
		}
		else{
			scanf("%s\n",name);
			int idx=pos[name];
			//printf("ins:%c, name:%s, idx:%d \n",ins,name,idx);
			switch(ins){
				case 'r':
					if(idx<n-1){
						printf("%s\n",students[idx+1]);
					}
					else{
						printf("-1\n");
					}
					break;
				case 'l':
					if(idx){
						printf("%s\n",students[idx-1]);
					}
					else{
						printf("-1\n");
					}
					break;
				case 'e':
					for(int i=idx;i<n-1;i++){
						strcpy(students[i],students[i+1]);
						pos[students[i]]--;
					}
					n--;
				}
		}
	}	
}
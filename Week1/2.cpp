#include<iostream>

using namespace std;

int main(){
	int n;
	scanf("%d",&n);

	for(int i=1;i<n+1;i++){
		int high=0,low=0;
		int l;
		scanf("%d",&l);
		int current,next;
		scanf("%d",&current);
		for(int j=1;j<l;j++){
			scanf("%d",&next);
			high += next>current;
			low += current>next;
			current = next;
		}
		printf("Case %d: %d %d\n",i,high,low);
	}
}
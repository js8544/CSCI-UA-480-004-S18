#include <iostream>
#include <cstring>
using namespace std;

int main(){
	int t,n;
	cin>>t;

	for(int i=0;i<t;i++){
		cin>>n;
		int crop[n];
		memset(crop,0,sizeof(crop));
		int cover[n];
		memset(cover,0,sizeof(cover));
		int count=0;
		for(int j=0;j<n;j++){
			char c;
			cin>>c;
			if(c=='.'){
				crop[j]=1;
				if(cover[j]==1){
					continue;
				}
				else{
					count++;
					cover[j]=1;
					if(j<=n-2) cover[j+1]=1;
					if(j<=n-3) cover[j+2]=1;
				}
			}
		}
		cout<<"Case "<<i+1<<": "<<count<<"\n";
	}
}
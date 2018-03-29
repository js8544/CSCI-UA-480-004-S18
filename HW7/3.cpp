#include <iostream>
#include <cstring>

using namespace std;

#define int long long
int block[8][8];
int edges[8][8];
int dot[9][9];


signed main(){
	int d;
	cin>>d;
	memset(block,0,sizeof(block));
	memset(edges,0,sizeof(edges));
	memset(dot,0,sizeof(dot));

	for(int i=0;i<d;i++){
		for(int j=0;j<d;j++){
			char c;cin>>c;
			if(c=='-')block[i][j] = -1;
			else block[i][j] = c-'0';
		}
	}

	int choice = 0;
	int max = 0;

	while(choice<(1ll<<(d+1)*(d+1))){
		int unconnected=0;
		int connected=0;
		for(int i=0;i<=2*d-1;i++){
			for(int j=0;j<=i;j++){
				// if(i<d&&j<d){
				// 	if(dot[j][i-j]==0){
				// 		if(block[j][i-j]==0|block[j][i-j]==1){
				// 			continue;
				// 		}
				// 		else if(block)
				// 	}
				// }
				if(dot[i][i-j]==0){
					if(choice&(1ll<<(i*d+i-j))){
						dot[i][i-j]=1;
						dot[i+1][i-j]=1;
						dot[i][i-j+1]=1;
					}
				}	
				if(dot[i][i-j]==1){
					
				}
			}
		}
	}

}
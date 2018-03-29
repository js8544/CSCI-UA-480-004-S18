#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int grid[101][101];
int maxx=0;
int maxy=0;
int num_remain;
void go(int x,int y){
	int found = 0;
	for(int i=x;i<=maxx;i++){
		for(int j=y;j<=maxy;j++){
			if(grid[i][j]==1){
				// cout<<"doing "<<i<<","<<j<<"\n";
				num_remain--;
				grid[i][j]=0;
				go(i,j);
				found=1;
				return;
			}
		}
	}

}

int main(){
	int n;
	cin>>n;

	num_remain = n;
	int times = 0;
	for(int i=0;i<n;i++){
		int x,y;
		cin>>x>>y;
		if(x>maxx) maxx=x;
		if(y>maxy) maxy=y;
		grid[x][y] = 1;
	}

	while(num_remain!=0){
		times+=1;
		go(0,0);
		// cout<<"finish try\n";

	}

	cout<<times<<"\n";
}
#include <iostream>
#include <queue>
#include <map>
using namespace std;

int main(){
	int q;
	cin>>q;
	priority_queue <int,vector<int> > max_heap;
	priority_queue <int,vector<int>, greater<int> > min_heap;
	map <int,int> c;

	int num=0;
	for(int i=0;i<q;i++){
		char in;
		cin>>in;
		if(in == 'a'){
			int k;
			cin>>k;
			max_heap.push(k);
			min_heap.push(k);
			if(c.count(k)){
				c[k]++;
			}
			else{
				c[k]=1;
			}
			num++;
		}
		if(in == 'd'){
			int k;
			cin>>k;
			
			if(c[k]>=1){
				if(k==max_heap.top()) max_heap.pop();
				else if(k==min_heap.top()) min_heap.pop();
				c[k]--;
				num--;
			}
		}
		if(in == 's'){
			if(num){
				while(c[max_heap.top()]==0&&max_heap.empty()==0){
					max_heap.pop();
				}
				while(c[min_heap.top()]==0&&min_heap.empty()==0){
					min_heap.pop();
				}
				if(max_heap.empty()==0&&min_heap.empty()==0){			
					cout<<max_heap.top()-min_heap.top()<<"\n";
				}
				else{
					cout<<"-1\n";
				}
			}
			else{
				cout<<"-1\n";
			}
		}
	}
}
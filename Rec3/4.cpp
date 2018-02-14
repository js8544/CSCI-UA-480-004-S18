#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main(){
	

	int ncase;
	cin>>ncase;
	for(int i=0;i<ncase;i++){

		int nset;
		int n;

		cin>>nset>>n;

		cout<<nset<<" "<<(n+1)/2<<"\n";
		priority_queue <long long> max_heap;
		priority_queue <long long,vector<long long>,greater<long long> > min_heap;
		int nmax=0;
		int nmin=0;

		long long a,b;
		cin>>a>>b;
		cout<<a<<" ";
		int printed = 1;
		if(a>b){
			max_heap.push(b);
			min_heap.push(a);
		}
		else{
			max_heap.push(a);
			min_heap.push(b);
		}
		for(int j=2;j<n;j++){

			long long k;
			cin>>k;

			if(k<max_heap.top()){
				max_heap.push(k);
				nmax++;
			}
			else{
				min_heap.push(k);
				nmin++;
			}

			if(nmin-nmax == 2){
				max_heap.push(min_heap.top());
				nmax++;
				nmin--;
				min_heap.pop();
			}
			else if(nmin-nmax == 1){
				cout<<min_heap.top()<<' ';
				printed++;
				if(printed%10==0){
					if(printed!=((n+1)/2)){
						cout<<"\n";
					}
				}
				
			}
			else if(nmin-nmax == -1){
				cout<<max_heap.top()<<' ';
				printed++;
				if(printed%10==0){
					if(printed!=((n+1)/2)){
						cout<<"\n";
					}
				}
				
			}
			else if(nmin-nmax == -2){
				min_heap.push(max_heap.top());
				nmin++;
				nmax--;
				max_heap.pop();
			}
		}
		cout<<'\n';
	}
}
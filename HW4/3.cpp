#include <iostream>
#include <queue>

using namespace std;
int main(){
	int n,k;
	cin>>n>>k;
	long long sum=0;
	priority_queue <long long, vector<long long>,greater<long long> > min;

	for(int i=0;i<k;i++){
		min.push(0);
	}

	for(int i=0;i<n;i++){
		long long a;
		cin >> a;

		if(a>min.top()){
			sum = sum+a-min.top();

			min.pop();
			min.push(a);
		}

		cout<<sum<<"\n";
	}
}
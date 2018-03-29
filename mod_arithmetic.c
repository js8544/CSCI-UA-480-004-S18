int add(int a,int b){
	return (a % m + b % m) % m;
}

int mul(int a,int b){
	long long result = (long long) (a % m) * (b % m);
	return result % m;
}
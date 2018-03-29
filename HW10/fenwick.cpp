#define MAXN 100005 // Do not call add/get with k >= MAXN!
int fenwick[MAXN];
void add(int k, int v){
	k++;
	for(;k<MAXN;k+=-k&k) fenwick[k]+=v;
}
int get(int k){
	if (k < 0) return 0;
	k++;
	int ans = 0;
	for(;k;k-=-k&k) ans += fenwick[k];
	return ans;
}

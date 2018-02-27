#include <iostream>

using namespace std;

int father[200001];
int counter[200001];
int color[200001];
int tot=0;

int find(int x){
	if (father[x]!=x) father[x]=find(father[x]);
	return father[x];
}

void unions(int x, int y){
	int xf=find(x);
	int yf=find(y);
	if (color[yf]==0 && color[xf]!=0) {
		color[yf]=color[xf];
		tot += counter[yf];
		counter[yf] = 0;
	}
	else if (color[xf] == 0 && color[yf]!=0) {
		color[xf] = color[yf];
		tot += counter[xf];
		counter[xf] = 0;
	}
	counter[yf] += counter[xf];
	father[xf] = yf;
}

int n, q;

int main(){
	cin >> n >> q;
	memset(counter, 0, sizeof(counter));
	memset(color, 0, sizeof(color));
	for (int i=1; i<=n; i++) counter[i] = 1;
	for (int i=1; i<=2*n; i++) father[i] = i;
	for (int i=1; i<=q; i++){
		string op;
		cin >> op;
		int x, y;
		if (op == "d") {
			cin >> x >> y;
			int xf = find(x), xo = find(x+n);
			int yf = find(y), yo = find(y+n);
			if (xf == yf || yo==xo || 
			(color[xf]==1 && color[yf]==1) || (color[xf]==2 && color[yf]==2) ){
				printf("Q%d: ?\n", i);
			}
			else {
				unions(x, y+n);
				unions(y, x+n);
			}
		}
		else if (op == "s"){
			cin >> x >> y;
			int xf = find(x), xo = find(x+n);
			int yf = find(y), yo = find(y+n);
			if (xo == yf || yo==xf || 
			(color[xf]==1 && color[yf]==2) || (color[xf]==2 && color[yf]==1) ) {
				printf("Q%d: ?\n", i);
			}
			else {
				unions(x, y);
				unions(x+n, y+n);
			}
		}
		else if (op=="r") {
			cin >> x;
			int xf = find(x);
			int xo = find(x+n);
			if (color[xf] == 2 || color[xo] == 1){
				printf("Q%d: ?\n", i);
			}
			else{
				color[xf] = 1;
				color[xo] = 2;
				tot += counter[xf] + counter[xo];
				counter[xf] = 0;
				counter[xo] = 0;
			}
		}
		else if (op=="b") {
			cin >> x;
			int xf = find(x);
			int xo = find(x+n);
			if (color[xf] == 1 || color[xo] == 2){
				printf("Q%d: ?\n", i);
			}
			else{
				color[xf] = 2;
				color[xo] = 1;
				tot += counter[xf] + counter[xo];
				counter[xf] = 0;
				counter[xo] = 0;
			}
		}
		if (tot==n) {
			printf("Q%d: I know\n", i);
			for (int j=1; j<=n; j++) {
				if (color[find(j)] == 1) printf("r");
				else if (color[find(j)] == 2) printf("b");
			}
			printf("\n");
			return 0;
		}
		//cout << tot << endl;
	}
	printf("I am not sure\n");
}

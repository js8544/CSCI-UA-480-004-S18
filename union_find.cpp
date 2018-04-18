
int findRoot(int x){
	if(nodes[x].parent == x) return x;
	return nodes[x].parent = findRoot(nodes[x].parent);
}

void unionNodes(int x,int y){
	int xRoot = findRoot(x);
	int yRoot = findRoot(y);

	if(nodes[xRoot].rank>nodes[yRoot].rank){
		int temp = xRoot;
		xRoot = yRoot;
		yRoot = temp;
	}
	if(nodes[xRoot].rank==nodes[yRoot].rank){
		nodes[yRoot].rank++;
}
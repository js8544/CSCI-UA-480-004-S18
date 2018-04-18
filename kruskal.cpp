int n;
struct node{
  int parent;
  int rank;
}nodes[100];

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
  nodes[xRoot].parent = yRoot;
}

int kruskal() {
  initUnionFind(n); // create a union-find structure for n vertices
  sort(edges); // sort edges by increasing weight
  int weightMST = 0;
  for (e of edges) {
    if (find(e.x) != find(e.y)) {
      weightMST += e.weight;
      unionSets(e.x, e.y);
    }
  }
  return weightMST;
}


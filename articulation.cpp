int label = 0;
int vnum[MAXN]; // the label of each vertex 
int vlow[MAXN]; // the lowest label a vertex can reach backwards
void dfs(int x, int prev, int dfsRoot){
  vlow[x] = vnum[x] = ++label;
  int child = 0;
  for (y of x.neighbors) {
    if (y == prev) continue;
    if (!vnum[y]) {
      child++;
      dfs(y, x, dfsRoot);
      vlow[x] = min(vlow[x], vlow[y]);
      // x is an articulation point when vlow[y] >= vnum[x] and x != dfsRoot
      // (x, y) is a bridge when vlow[y] > vnum[x]
    } else {
      vlow[x] = min(vlow[x], vnum[y]); // here we use vnum[y], not vlow[y]!
    }
  }
  if (x == dfsRoot && child > 1) {
    // x (dfsRoot) is an articulation point only when x has two (unconnected) DFS
    // descendants. This is to avoid a special case where the dfsRoot has degree one.
  }
}


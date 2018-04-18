int label = 0;
int vnum[MAXN]; // the label of each vertex 
int vlow[MAXN]; // the lowest label a vertex can reach backwards
bool pending[MAXN];
vector<int> order;
void dfs(int x){
  vlow[x] = vnum[x] = ++label;
  pending[x] = true;
  order.push_back(x);
  for (y of x.neighbors) {
    if (!vnum[y]) dfs(y);
    if (pending[y]) vlow[x] = min(vlow[x], vlow[y]);
  }
  if (vlow[x] == vnum[x]) { // an SCC is found
    vector<int> scc;
    while (true) {
      int y = order.back();
      order.pop_back();
      scc.push_back(y);
      pending[y] = false;
      if (y == x) break;
    }
    // scc stores one SCC and its members
  }
}



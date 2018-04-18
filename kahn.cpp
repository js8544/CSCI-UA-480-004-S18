vector<int> order;
int n, indegree[MAXN];
void kahn() {
  // edge goes from x to y
  for (e of edges) indegree[e.y]++;
  queue<int> q;
  for (int x = 0; x < n; x++)
    if (indegree[x] == 0) q.push(x);
  while (!q.empty()) {
    int x = q.front(); q.pop();
    order.push_back(x);
    for (y of x.neighbors) {
      indegree[y]--;
      if (indegree[y] == 0) q.push(y);
    }
  }
  // order stores a topological order
}


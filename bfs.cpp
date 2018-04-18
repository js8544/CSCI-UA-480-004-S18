int n, dist[MAXN];
void bfs(int s) {
  queue<int> q;
  q.push(s);
  for (int x = 0; x < n; x++) dist[x] = INF;
  dist[s] = 0;
  while (!q.empty()) {
    int x = q.front();
    q.pop();
    for (y of x.neighbors) {
      if (dist[y] == INF) {
        dist[y] = dist[x] + 1;
        q.push(y);
      }
    }
  }
  // dist[x] now stores the unweighted SP for every x
}


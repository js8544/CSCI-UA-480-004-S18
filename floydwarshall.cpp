int n, dist[MAXN][MAXN];
void floydWarshall() {
  for (int x = 0; x < n; x++) {
    for (int y = 0; y < n; y++) dist[x][y] = INF;
    dist[x][x] = 0;
  }
  for (e of edges) dist[e.x][e.y] = e.w; // assume simple graph
  for (int k = 0; k < n; k++) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (dist[i][k] + dist[k][j] < dist[i][j])
          dist[i][j] = dist[i][k] + dist[k][j];
      }
    }
  }
  // dist[x][y] stores the SP from x to y, for every pair (x, y)
}


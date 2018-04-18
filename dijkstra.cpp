int n, dist[MAXN];
struct Pair { // custom pair (vertex, distance) that compares based on distance
  int x, d;
  Pair(int _x, int _d): x(_x), d(_d) {}
  bool operator < (const Pair &another) const { return d > ano.d; }
}
void dijkstra(int s) {
  priority_queue<int> pq;
  pq.push(Pair(s, 0));
  for (int x = 0; x < n; x++) dist[x] = INF;
  dist[s] = 0;
  while (!pq.empty()) {
    Pair cur = pq.top();
    pq.pop();
    if (cur.d > dist[cur.x]) continue; // ignore out-of-date pair
    for (e of cur.x.edges) {
      if (dist[x] + e.weight < dist[y]) {
        dist[y] = dist[x] + e.weight;
        pq.push(Pair(y, dist[y]));
      }
    }
  }
  // dist[x] now stores the weighted SP for every x
}


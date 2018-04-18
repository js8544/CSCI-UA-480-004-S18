vector<int> order;
vector<int> adj[MAXN];
void euler(int x){
  while (adj[x].size()) {
    int y = adj[x].back(); // we choose the last edge for fast removal
    adj[x].pop_back(); // remove this edge so that it will not be visited again
    euler(y);
  }
  order.push_back(x);
}

// usage
euler(startVertex);
reverse(order.begin(), order.end());


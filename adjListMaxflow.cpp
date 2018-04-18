// This is the code presented in the slides.
// The graph is stored using adjacency list. Parallel edges are handled separately.
// Each edge gets its own residual edge.

// For an adjacency matrix based implementation, see adjMatrixMaxflow.java

#define MAXN 50
#define MAXM 1000
int adj[MAXN];
struct Edge {
  int vertex;
  int nextEdge;
  int c, f; // capacity and flow
  Edge() {}
  Edge(int _vertex, int _c, int _next) { vertex = _vertex; c = _c; f = 0; nextEdge = _next; }
} edges[MAXM * 2]; // double the size because we need to create residual edges

int numEdges;
inline void pushEdge(int x, int y, int c) { // manipulate the adjacency list to add the edge
  edges[numEdges] = Edge(y, c, adj[x]);
  adj[x] = numEdges++;
}
inline void addEdge(int x, int y, int c){ // add an edge (x, y) with capacity c; this creates residual edge too
  pushEdge(x, y, c);
  pushEdge(y, x, 0); // residual edge initially has capacity zero
}
inline void init() { // must be called before use. otherwise edge links cannot be properly terminated
  numEdges = 0;
  memset(adj, -1, sizeof(adj));
}

int preVertex[MAXN], preEdge[MAXN];
bool v[MAXN];
int edmondsKarp(int S, int T) {
  int maxflow = 0;
  while (true) {
    memset(v, false, sizeof(v));
    bool augmentable = false;
    queue<int> q; q.push(S);
    v[S] = true;
    while(!q.empty()) {
      int x = q.front(); q.pop();
      int edgeIndex = adj[x];
      while (edgeIndex) {
        int y = edges[edgeIndex].vertex;
        // BFS following the edges in the residual graph.
        // if edge.f != edge.c, it means that the edge is not saturated
        if(!v[y] && edges[edgeIndex].f != edges[edgeIndex].c) {
          v[y] = true;
          q.push(y);
          preVertex[y] = x;
          preEdge[y] = edgeIndex;
          if (y == T) { augmentable = true; break; }
        }
        edgeIndex = edges[edgeIndex].nextEdge;
      }
      if (augmentable) break;
    }
    if (!augmentable) break;
    int flow = INF, x = T;
    while (x != S) { // trace the augmenting path to compute how much flow we can send
      int unsaturated = edges[preEdge[x]].c - edges[preEdge[x]].f;
      flow = min(flow, unsaturated);
      x = preVertex[x];
    }
    x = T;
    while (x != S) { // actually send the flow
      edges[preEdge[x]].f += flow;
      edges[preEdge[x]^1].f = -edges[preEdge[x]].f;
      x = preVertex[x];
    }
    maxflow += flow;
  }
  return maxflow;
}

// usage
int main() {
  int n; // number of vertices in the flow graph
  
  init(); // must initialize
  
  // ... read the input and add the edges to the graph
  
  // compute maxflow from 0 to n-1
  // maxflow doesn't need to know n because it uses adjacency list
  // thus you only need to pass the correct S and T id's
  int maxflow = edmondsKarp(0, n-1);
  return 0;
}
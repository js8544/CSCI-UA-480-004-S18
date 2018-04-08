int val[MAX_NODES], lazy[MAX_NODES];
void add(int k, int nl, int nr, int l, int r, int v);
void relax(int k, int nl, int nr) {
  int nm = (nl + nr) / 2;
  add(2*k+1, nl, nm, nl, nm, lazy[k]); // just use add() to add lazy propagation value downwards
  add(2*k+2, nm+1, nr, nm+1, nr, lazy[k]);
  lazy[k] = 0; // clear the lazy propagation value
}
void add(int k, int nl, int nr, int l, int r, int v){
  if (r < nl || l > nr) return;
  if (l <= nl && nr <= r) {
    val[k] += v * (nr - nl + 1); // the sum is increased by v * {length of the range}
    lazy[k] += v; // record the lazy propagation value
    return;
  }
  int nm = (nl + nr) / 2;
  if (lazy[k]) relax(k, nl, nr); // there is value to propagate, we first relax
  add(2*k+1, nl, nm, l, r, v);
  add(2*k+2, nm+1, nr, l, r, v);
  val[k] = val[2*k+1] + val[2*k+2];
}
int getSum(int k, int nl, int nr, int l, int r) {
  if (r < nl || l > nr) return 0;
  if (l <= nl && nr <= r) return val[k]; // the entire range's sum is part of the answer
  if (lazy[k]) relax(k, nl, nr); // must also relax in a range sum query
  int nm = (nl + nr) / 2;
  return getSum(2*k+1, nl, nm, l, r) + getSum(2*k+2, nm+1, nr, l, r);
}



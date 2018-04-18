bool visitedA[MAXA], visitedB[MAXB];
int matchedB[MAXB];
bool augment(int x){
  if (visitedA[x]) return false;
  visitedA[x] = true;
  for (y of x.neighbors) {
    if (!visitedB[y]) {
      visitedB[y] = true;
      // if y is not matched, then we can augment by adding (x, y)
      // Otherwise, we augment from y's matched vertex, i.e. matchedB[y]
      if (matchedB[y] == -1 || augment(matchedB[y])) { 
        matchedB[y] = x;
        return true;
      }
    }
  }
  return false;
}
int maxBipartiteMatching(){
  memset(matchedB, -1, sizeof(matchedB));
  for (x in A) {
    memset(visitedA, false, sizeof(visitedA));
    memset(visitedB, false, sizeof(visitedB));
    augment(x);
  }
  int cardinality = 0;
  for (y in B) {
    if (matchedB[y] != -1) cardinality++; // matched edge (matchedB[y], y)
  }
  return cardinality
}


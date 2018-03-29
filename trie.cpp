#define MAXN 100000
#define MAXLEN 20
#define MAXNODES (MAXN*MAXLEN + 1)

int trieSize = 0;
struct TrieNode {
  int next[26], numEndNodes;
  trnode(){
    numEndNodes = 0;
    memset(next, 0, sizeof(next));
  }
} nodes[MAXNODES];

void add(int k, int strIndex, char *str) {
  if(str[strIndex] == 0){
    nodes[k].numEndNodes++;
    return;
  }
  char c = str[strIndex];
  int t = c - 'a';
  if(nodes[k].next[t] == 0){
    nodes[k].next[t] = ++trieSize;
    nodes[trieSize] = TrieNode();
  }
  nodes[k].numEndNodes++;
  add(nodes[k].next[t], strIndex + 1, str);
}


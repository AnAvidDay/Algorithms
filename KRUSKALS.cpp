#include <iostream>
#include <tuple>
#include <vector>
using namespace std;

const int MAXN = 100;

int link[MAXN], size[MAXN];
vector<pair<int, int>> edges, min_edges;

int find(int x) {
  while (x != link[x]) x = link[x];
  return x;
}

bool same(int a, int b) {
  return find(a) == find(b);
}

void unite(int a, int b) {
  a = find(a); b = find(b);
  if (size[a] < size[b]) swap(a, b);
  link[b] = a;
  size[a] += size[b];
}

void solve() {
  for (int i = 1; i <= N; ++i) {
    link[i] = i; size[i] = 1;
  }
  sort(edges.begin(), edges.end());
  for (auto e : edges) {
    int x, y; tie(x, y) = e;
    if (!same(x, y)) {
      unite(x, y);
      min_edges.push_back({x, y});
    }
  }
  
}

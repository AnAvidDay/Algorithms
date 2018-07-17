#include <vector>
#include <queue>
using namespace std;

vector<int> adj[MAXN+1];
int dists[MAXN+1], visited[MAXN+1];
queue<int> q;

// Standard DFS
void solve(int s) {
	if (visited[s]) return;
	visited[s] = true;
	for (auto u : adj[s]) solve(u);
}


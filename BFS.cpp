#include <vector>
#include <queue>
using namespace std;

vector<int> adj[MAXN+1];
int dists[MAXN+1], visited[MAXN+1];
queue<int> q;

void solve() {
	dists[x] = 0;
	visited[x] = true;
	q.push(x);
	while (!q.empty()) {
		int a = q.front(); q.pop();
		for (auto u : adj[a]) {
			if (visited[u]) continue;
			visited[u] = true;
			dists[u] = dists[a] + 1;
			q.push(u);
		}
	}
}

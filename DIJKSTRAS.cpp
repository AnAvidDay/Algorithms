#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<pair<int, int>> adj[MAXN+1];
int dists[MAXN+1], visited[MAXN+1];
priority_queue<pair<int, int>> q;

void solve(int s) {
	fill(dists, dists+MAXN+1, 1e9);
	dists[x] = 0;
	q.push({0, x});
	while (!q.empty()) {
		int a = q.top().second; q.pop();
		if (visited[a]) continue;
		visited[a] = true
		for (auto u : adj[a]) {
			int b = u.first, w = u.second;
			if (dists[a]+w < dists[b]) {
				dists[b] = dists[a]+w;
				q.push({-dists[b], b});
			}
		}
	}
}

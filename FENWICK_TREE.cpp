#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 100004;

int maintain[MAXN];

ll sum(int k, ll* tree) {
	ll s = 0;
	while (k >= 1) {
		s += tree[k];
		k -= k&-k;
	}
	return s;
}

void add(int k, int x, ll* tree, int n) {
	while (k <= n) {
		tree[k] += x;
		k += k&-k;
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	ll treex[MAXN], treey[MAXN];
	memset(treex, 0, sizeof(treex));
	memset(treey, 0, sizeof(treey));
	int N, M; cin >> N >> M;
	for (int i = 1; i <= N; ++i) {
		int num; cin >> num;
		maintain[i] = num;
		add(i, num, treex, N);
		add(num, 1, treey, MAXN);
	}
	for (int i = 1; i <= M; ++i) {
		char val; cin >> val;
		if (val == 'C') {
			int x, v; cin >> x >> v;
			add(v, 1, treey, MAXN);
			add(maintain[x], -1, treey, MAXN);
			add(x, v - maintain[x], treex, N);
			maintain[x] = v;

		} else if (val == 'S') {
			int x, y; cin >> x >> y;
			cout << sum(y, treex) - sum(x-1, treex) << "\n";
		} else {
			int x; cin >> x;
			cout << sum(x, treey) << "\n";
		}
	}
}

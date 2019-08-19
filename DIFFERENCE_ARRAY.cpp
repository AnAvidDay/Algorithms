/*
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#ifdef _DEBUG
	freopen("/Users/huogenx/Desktop/__RUN__/input.txt", "r", stdin);
#endif
	int N; cin >> N;
	vector<int> arr (N + 1);
	vector<int> diff (N + 1);
	for (int i = 1; i <= N; i++)
		cin >> arr[i];

	diff[1] = arr[1], diff[N] = 0;

	for (int i = 2; i <= N; i++)
		diff[i] = arr[i] - arr[i - 1];

	int M; cin >> M;
	while (M--) {
		int l, r, v;
		cin >> l >> r >> v;
		diff[l] += v, diff[r + 1] -= v;

		for (int i = 1; i <= N; i++) {
			if (!i)
				arr[i] = diff[i];
			else
				arr[i] = diff[i] + arr[i - 1];
			cout << arr[i] << " ";
		}
		cout << "\n";
	}
	return 0;
}

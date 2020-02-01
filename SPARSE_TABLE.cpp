/*
The first line consists of two integers, N the length of the sequence and M the number of queries. (1≤N≤105, 1≤M≤106)

The second line consists of N integers Ai. (−109≤Ai≤109)

Each of the following M lines consists of two integers L and R. (1≤L≤R≤N)
*/

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100004;

int logm[MAXN], sparse[MAXN][25];

int main() {
#ifdef _DEBUG
	freopen("/Users/huogenx/Desktop/__RUN__/input.txt", "r", stdin);
#endif
	logm[1] = 0;
	for (int i = 2; i <= MAXN; i++)
		logm[i] = logm[i/2] + 1;

	int N, M;
	cin >> N >> M;

	vector<int> arr (N);
	for (int i = 0; i < N; i++)
		cin >> arr[i];

	for (int i = 0; i < N; i++)
		sparse[i][0] = arr[i];

	for (int j = 1; j <= 25; j++)
		for (int i = 0; i + (1 << j) <= N; i++)
			sparse[i][j] = max(sparse[i][j-1], sparse[i + (1 << (j-1))][j-1]);

	while (M--) {
		int L, R;
		cin >> L >> R;
		R--; L--;
		int j = logm[R - L + 1];
		int ans = max(sparse[L][j], sparse[R - (1 << j) + 1][j]);
		cout << ans << "\n";
	}
	return 	0;
}

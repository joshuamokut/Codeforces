#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

#define int long long
const int N = 2e5 + 50;



signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n, m, d; cin >> n >> m >> d;

	vector<int> c(m);

	for (int i = 0; i < m; i++) {
		cin >> c[i];
	}

	int lastend = 0;

	

	for (int i=0; i < m; i++) {
		lastend = lastend + d + c[i] - 1;
	}
	vector<int> ans(n + 1);
	if (lastend + d >= n + 1) {
		int xs = max(0ll, lastend - n);

		cout << "YES\n";
		lastend = 0;
		for (int i = 0; i < m; i++) {
			int start = 0;
			if (xs >= d - 1) {
				xs = xs - (d - 1);
				start = lastend + 1;
			}
			else {
				start = lastend + d - xs;
				xs = 0;
			}

			for (int j = start; j < start + c[i]; j++)
				ans[j] = i + 1;

			lastend = start + c[i] - 1;
		}

		for (int i = 1; i <= n; i++) {
			cout << ans[i] << ' ';
		}

		cout << '\n';
	}
	else {
		return cout << "NO\n", 0;
	}

}


#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <random>
#include <time.h>
using namespace std;

typedef long long ll;
#define int ll

const int N = 2e5 + 50;
int n, m;
int a[N];
pair<int, int>heroes[N];

void solve();
void stress();

signed  main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t; cin >> t;

	while (t--) {
		cin >> n;

		for (int i = 0; i < n; i++) {
			cin >> a[i];

		}

		cin >> m;

		for (int i = 0; i < m; i++) {
			cin >> heroes[i].first >> heroes[i].second;
		}

		solve();
	}

	return 0;
}

void stress() {

}

void solve() {
	int curPos = 0;
	sort(heroes, heroes + m);
	vector<int> endurance(m);

	for (int i = 0; i < m; i++) {
		endurance[i] = heroes[i].second;
	}

	for (int i = m - 2; i >= 0; i--)
		endurance[i] = max(endurance[i], endurance[i + 1]);
	int ans = 0;
	while (curPos < n) {
		int nextMove = 0;
		int maxx = 0;

		auto checkit = lower_bound(heroes, heroes + m, make_pair(a[curPos], 0ll));
		if (checkit == heroes + m) {
			ans = -1;
			break;
		}
		while (nextMove + curPos < n) {
			maxx = max(maxx, a[nextMove + curPos]);

			auto it = lower_bound(heroes, heroes + m, make_pair(maxx, 0ll));

			if (it == heroes + m) {
				break;
			}
			else {
				if (endurance[it - heroes] < nextMove + 1) {
					break;
				}
				else {
					nextMove++;
				}
			}
		}

		ans++;
		curPos += nextMove;
	}
	cout << ans << '\n';
}

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

typedef long long ll;
#define int ll

const int N = 2e5 + 50;

pair<int, int> wages[N];
int n, s;

bool checker(int medianSalary) {
	if (wages[n / 2].first < medianSalary)
		return false;
	int spent = 0;
	int i = 0;

	for ( i = 0; (i < n / 2) && (wages[i].first < medianSalary) ; i++)
		spent += wages[i].second;

	multiset<pair<int, int> > temp;

	for (; i < n; i++) {
		temp.insert({ wages[i].second, wages[i].first });
	}

	while (temp.size() > n / 2 + 1) {
		spent += (*temp.begin()).first;
		temp.erase(temp.begin());
	}

	while(!temp.empty()) {
		spent += max(medianSalary, (*temp.begin()).first);
		temp.erase(temp.begin());
	}

	return spent <= s;
}

signed  main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t;

	cin >> t;

	while (t--) {
		cin >> n >> s;

		for (int i = 0; i < n; i++) {
			cin >> wages[i].second >> wages[i].first;
		}

		sort(wages, wages + n);

		int l = 1, r = 1e9+1;

		while (r - l > 1) {
			int mid = (l + r) >> 1;

			if (checker(mid)) {
				l = mid;
			}
			else {
				r = mid;
			}
		}

		cout << l << '\n';
	}

	return 0;
}

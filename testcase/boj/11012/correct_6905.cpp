#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
int t, n, m, x, y, a, b, r, f[100002];
vector<int> p[100001];
struct A {
	int x, l, r, c;
};
vector<A> cd;
int fnd(int k) {
	for (b = 0; k > 0; k -= k & -k)
		b += f[k];
	return b;
}
void solve() {
	for (int i = 0; i < 100001; i++)
		p[i] = vector<int>(), f[i] = 0;
	cin >> n >> m;
	while (n--) {
		cin >> x >> y;
		p[x].push_back(y + 1);
	}
	while (m--) {
		cin >> a >> x >> b >> y;
		cd.push_back({a, b, ++y, -1}), cd.push_back({x + 1, b, y, 1});
	}
	sort(cd.begin(), cd.end(), [](A& a, A& b) { return a.x < b.x; });
	a = 0;
	for (auto [x, s, e, c] : cd) {
		for (; a < x; a++) {
			for (int i : p[a]) {
				for (; i < 100002; i += i & -i)
					f[i]++;
			}
		}
		r += c * (fnd(e) - fnd(s));
	}
	cout << r << '\n';
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	for (; t--; r = 0, cd = vector<A>())
		solve();
	return 0;
}
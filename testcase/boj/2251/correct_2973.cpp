#include <iostream>
#include <set>
#include <queue>

#define rep(i, n) for(int i=0; i<(n); i++)

using namespace std;
bool seen[201][201][201];
int limit[3];
set<int> ans;
struct state {
	int a[3];
	state(int _a, int _b, int _c) {
		a[0] = _a, a[1] = _b, a[2] = _c;
	};
	state(int _a[]) {
		rep(i,3) a[i] = _a[i];
	};
};
inline bool seenstate(const state &s) {
	return seen[s.a[0]][s.a[1]][s.a[2]];
}
inline void apply(const state &s) {
	seen[s.a[0]][s.a[1]][s.a[2]] = true;
	if(!s.a[0]) ans.insert(s.a[2]);
}
inline bool moveable(const state &s, int from, int to) {
	return s.a[from] && s.a[to] < limit[to];
}
inline state moveby(const state &s, int from, int to) {
	int t = min(s.a[from], limit[to] - s.a[to]);
	int ns[3];
	rep(i,3) ns[i] = s.a[i];
	ns[from] -= t;
	ns[to] += t;
	state ret(ns);
	return ret;
}
int main() {
	rep(i,3) cin >> limit[i];
	state init({0,0,limit[2]});
	queue<state> que;
	apply(init);
	que.push(init);
	while(!que.empty()) {
		state q = que.front();
		que.pop();
		rep(i,3) rep(j,3) {
			if(i == j) continue;
			if(!moveable(q,i,j)) continue;
			state ns = moveby(q,i,j);
			if(seenstate(ns)) continue;
			apply(ns);
			que.push(ns);
		}
	}
	for(int a: ans) cout << a << ' ';
}
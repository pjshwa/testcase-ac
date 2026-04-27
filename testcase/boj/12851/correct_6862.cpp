#include <bits/stdc++.h>
using namespace std;

#define MX 100000
#define ll long long
pair<int, ll> seen[MX+1];
int t = 2;
queue<int> que;

void update(int i, ll f) {
	if(i > MX) return;
	if(!seen[i].first) {
		seen[i].first = t;
		seen[i].second = f;
		que.push(i);
	} else if(seen[i].first == t) {
		seen[i].second += f;
	}
}
int main() {
	ios::sync_with_stdio(false);cin.tie(NULL);
	int n, k;
	cin >> n >> k;
	if(n >= k) {
		return !(cout << n-k << "\n1");
	}
	seen[n].first = seen[n].second = 1;
	que.push(n);
	while(!que.empty()) {
		int s = que.size();
		while(s--) {
			int q = que.front();
			que.pop();
			update(q-1, seen[q].second);
			update(q+1, seen[q].second);
			update(2*q, seen[q].second);
		}
		if(seen[k].first) {
			cout << seen[k].first-1 << '\n' << seen[k].second;
			return 0;
		}
		t++;
	}
}

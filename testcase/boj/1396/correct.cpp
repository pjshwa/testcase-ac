#include <bits/stdc++.h>
using namespace std;
const int MX = 100000, MXC = 1000000;
struct Edge {
	int u, v, w;
	bool operator< (const Edge &e) const {
		return w < e.w;
	}
};
struct DSU {
	int parent[MX], setsz[MX];
	int find(int i){return parent[i] == i ? i : parent[i] = find(parent[i]);}
	void join(int i, int j) {
		i = find(i), j = find(j);
		if(i != j) {
			parent[i] = j;
			setsz[j] += setsz[i];
		}
	}
	void reset() {
		for(int i=0; i<MX; i++) {
			parent[i] = i;
			setsz[i] = 1;
		}
	}
};
Edge edges[MX];
pair<int, int> query[MX];
int l[MX], r[MX], ans[MX];
vector<int> check[MXC+2];
int main() {
	ios::sync_with_stdio(0);cin.tie(0);
	int n, m;
	cin >> n >> m;
	for(int i=0; i<m; i++) {
		cin >> edges[i].u >> edges[i].v >> edges[i].w;
		edges[i].u--, edges[i].v--;
	}
	sort(edges, edges+m);
	int q;
	cin >> q;
	for(int i=0; i<q; i++) {
		cin >> query[i].first >> query[i].second;
		query[i].first--, query[i].second--;
	}
	for(int i=0; i<q; i++)
		r[i] = MXC+1;
	DSU dsu;
	while(1) {
		bool done = true;
		for(int i=0; i<q; i++) {
			if(l[i] <= MXC && !ans[i]) {
				done = false;
				check[(l[i]+r[i])/2].push_back(i);
			}
		}
		if(done) break;
		dsu.reset();
		int eind = 0;
		for(int c=1; c<=MXC; c++) {
			if(eind < m && edges[eind].w == c) {
				dsu.join(edges[eind].u, edges[eind].v);
				eind++;
			}
			if(!check[c].empty()) {
				for(int i: check[c]) {
					if(l[i] == r[i]) {
						ans[i] = dsu.setsz[dsu.find(query[i].first)];
					}
					if(dsu.find(query[i].first) == dsu.find(query[i].second)) {
						r[i] = c;
					} else {
						l[i] = c+1;
					}
				}
				check[c].clear();
			}
		}
	}
	for(int i=0; i<q; i++) {
		if(l[i] > MXC) {
			cout << "-1\n";
		} else {
			cout << l[i] << ' ' << ans[i] << '\n';
		}
	}
}
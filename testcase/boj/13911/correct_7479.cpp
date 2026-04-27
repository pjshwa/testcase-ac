#include <cstdio>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;
using ll = long long;
const int MAX_V = 10000;

struct _d {
	int v;
	ll w;
};

ll min_v(ll a, ll b) { return a < b ? a : b; }

vector<vector<_d>> adj;
bool vi[MAX_V];

void dijkstra(ll dist[], priority_queue<pair<ll,int>>& pq) {
	memset(vi, 0, sizeof(vi));
	while (!pq.empty()) {
		int u = pq.top().second; pq.pop();
		if (vi[u]) continue;
		vi[u] = 1;
		for (_d& e : adj[u])
			if (dist[e.v] > dist[u] + e.w) {
				dist[e.v] = dist[u] + e.w;
				pq.push(make_pair(-dist[e.v], e.v));
			}
	}
}

int main() {
	int V, E, u, v, w, i, M, x, S, y;
	ll distM[MAX_V], distS[MAX_V], ans;

	scanf("%d%d", &V, &E);
	adj.resize(V);
	while (E--) {
		scanf("%d%d%d", &u, &v, &w);
		u--, v--;
		adj[u].push_back(_d{ v, w });
		adj[v].push_back(_d{ u, w });
	}

	memset(distM, 0x7F, sizeof(distM));
	memset(distS, 0x7F, sizeof(distS));
	priority_queue<pair<ll, int>> pqM, pqS;

	scanf("%d%d", &M, &x);
	while (M--) {
		scanf("%d", &u); u--;
		distM[u] = 0;
		pqM.push(make_pair(0, u));
	}

	scanf("%d%d", &S, &y);
	while (S--) {
		scanf("%d", &u); u--;
		distS[u] = 0;
		pqS.push(make_pair(0, u));
	}

	dijkstra(distM, pqM);
	dijkstra(distS, pqS);

	ans = 1e15;
	for (i = 0; i < V; i++)
		if (0 < distM[i] && distM[i] <= x && 0 < distS[i] && distS[i] <= y)
			ans = min_v(ans, distM[i] + distS[i]);

	printf("%lld", ans == 1e15 ? -1 : ans);
	return 0;
}

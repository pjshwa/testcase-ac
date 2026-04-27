#include<iostream>
#include<string>
#include<algorithm>
#include<queue>
using namespace std;
int n, m, k;
string arr[1005];
int dist[1005][1005], sx, sy, ex, ey;
int dx[4] = { -1,1,0,0 }, dy[4] = { 0,0,-1,1 };
queue<pair<int, int>> Q;
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m >> k;
	fill(&dist[0][0], &dist[n][0], 1e9);
	for (int i = 0; i < n; i++) cin >> arr[i];
	cin >> sx >> sy >> ex >> ey;
	sx--; sy--; ex--; ey--;
	Q.push({ sx,sy });
	dist[sx][sy] = 0;
	while (!Q.empty()) {
		auto cur = Q.front(); Q.pop();
		int x = cur.first, y = cur.second;
		for (int dir = 0; dir < 4; dir++) {
			for (int d = 1; d <= k; d++) {
				int nx = x + dx[dir] * d, ny = y + dy[dir] * d;
				if (nx < 0 || nx >= n || ny < 0 || ny >= m || arr[nx][ny] == '#' || dist[nx][ny] <= dist[x][y]) break;
				if (dist[nx][ny] != 1e9) continue;
				dist[nx][ny] = dist[x][y] + 1;
				Q.push({ nx,ny });
			}
		}
	}
	cout << (dist[ex][ey]==1e9?-1:dist[ex][ey]);
}
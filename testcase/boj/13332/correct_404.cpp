// Reference: https://blog.myungwoo.kr/111
// Reference page license: Creative Commons Attribution 4.0 International (CC BY 4.0)
// License URL: https://creativecommons.org/licenses/by/4.0/deed.ko
#include <bits/stdc++.h>
using namespace std;

#define MAXV 2300
#define MAXE 200000 // V = M+20*M+N+2 // E = M+20*M+M*N+N+V
#define pb push_back
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()

typedef pair<int, int> pii;

int M, N, P1, P2, V, E;
int new_source, new_sink;
int Q1[101], Q2[101];
int demand[MAXV], dist[MAXV], cnt[MAXV];
int to[MAXE], flow[MAXE];
vector<pair<int, pii>> plans[101];
vector<int> cone[MAXV];

void add_edge(int s, int e, int l, int r) {
    to[E] = e; 
    flow[E] = r - l;    
    cone[s].pb(E++);    
    to[E] = s; 
    flow[E] = 0;    
    cone[e].pb(E++);    
    demand[s] += l;    
    demand[e] -= l;
}

void bfs() {
    for (int i = 0; i <= V + 2; i++) 
        dist[i] = V + 3;

    queue<int> que;
    dist[new_sink] = 0; 
    que.push(new_sink);
    
    while (!que.empty()) {
        int q = que.front(); 
        que.pop();
        
        for (int e : cone[q]) {
            int t = to[e], f = flow[e ^ 1];
            if (!f || dist[t] != V + 3) continue;
            dist[t] = dist[q] + 1; 
            que.push(t);
        }
    }

    for (int i = 0; i <= V + 3; i++) 
        cnt[i] = 0;
    
    for (int i = 0; i <= V + 2; i++) 
        cnt[dist[i]]++;
}

vector<int> pathe;

int dfs(int n) {
    if (n == new_sink)
        return 1;

    for (int e : cone[n]) {
        int t = to[e], f = flow[e];
        if (!f || dist[n] != dist[t] + 1) continue;
        pathe.pb(e);
        int k = dfs(t);
        if (k) return k;
        pathe.pop_back();
    }

    int tmp = dist[n]; 
    dist[n] = V + 3;
    
    for (int e : cone[n]) {
        int t = to[e], f = flow[e];
        if (f && dist[n] > dist[t] + 1) 
            dist[n] = dist[t] + 1;
    }

    cnt[dist[n]]++;
    if (!--cnt[tmp]) return -1;
    return 0;
}

int main() {
    scanf("%d%d%d%d", &M, &N, &P1, &P2);
    
    for (int i = 1; i <= N; i++) 
        scanf("%d%d", Q1 + i, Q2 + i);
    
    for (int i = 1; i <= M; i++) {
        int n; 
        scanf("%d", &n);
        for (int j = 0; j < n; j++) {
            int d, a, b; 
            scanf("%d%d%d", &d, &a, &b);
            plans[i].pb({d, {a, b}});
        }
    }

    int idx = M, lvl2 = M;
    for (int i = 1; i <= M; i++) 
        lvl2 += sz(plans[i]);
    
    for (int i = 1; i <= M; i++) {
        add_edge(0, i, N - P2, N - P1);
        for (auto &p : plans[i]) {
            idx++;
            int s = p.second.first, e = p.second.second, d = p.first;
            add_edge(i, idx, d, e - s + 1);
            for (int j = s; j <= e; j++) 
                add_edge(idx, lvl2 + j, 0, 1);
        }
    }

    V = lvl2 + N + 1;
    for (int i = 1; i <= N; i++) 
        add_edge(lvl2 + i, V, M - Q2[i], M - Q1[i]);

    // Original source: vertex 0
    // Original sink: vertex V
    new_source = V + 1, new_sink = V + 2;
    for (int i = 0; i <= V; i++) {
        if (demand[i] < 0)
            add_edge(new_source, i, 0, -demand[i]);
        else
            add_edge(i, new_sink, 0, demand[i]);
    }
    add_edge(V, 0, 0, 2e9); // MAXIMUM FLOW

    int total_flow = 0;
    bfs();
    while (dist[new_source] < V + 3) {
        pathe.clear();
        int k = dfs(new_source);
        if (k < 0) break;
        if (!k) continue;

        int f = 2e9;
        for (int e : pathe) 
            f = min(f, flow[e]);
        
        for (int e : pathe) 
            flow[e] -= f, flow[e ^ 1] += f;
        
        total_flow += f;
    }

    int goal = 0;
    for (int i = 0; i <= V; i++) 
        if (demand[i] > 0) 
            goal += demand[i];

    printf("%d\n", total_flow == goal ? 1 : -1);
    if (total_flow != goal) return 0;
    
    idx = M;
    for (int i = 1; i <= M; i++) {
        vector<int> arr;
        for (auto &p : plans[i]) {
            idx++;
            for (int e : cone[idx]) {
                int t = to[e];
                if (lvl2 < t && t <= lvl2 + N && !flow[e]) 
                    arr.pb(t - lvl2);
            }
        }
        sort(all(arr));
        printf("%d", sz(arr));
        for (int t : arr) 
            printf(" %d", t);
        puts("");
    }
}

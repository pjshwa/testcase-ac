#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int u, v, w;
    bool operator<(const Edge& other) const {
        return w < other.w;
    }
};

struct Query {
    int u, v;
};

struct DSU {
    vector<int> parent, size;

    explicit DSU(int n = 0) {
        reset(n);
    }

    void reset(int n) {
        parent.resize(n);
        size.assign(n, 1);
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int x) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }

    void join(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b) return;
        if (size[a] > size[b]) swap(a, b);
        parent[a] = b;
        size[b] += size[a];
    }

    bool connected(int a, int b) {
        return find(a) == find(b);
    }

    int componentSize(int x) {
        return size[find(x)];
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<Edge> edges(m);
    for (auto& edge : edges) {
        cin >> edge.u >> edge.v >> edge.w;
        --edge.u;
        --edge.v;
    }
    sort(edges.begin(), edges.end());

    int q;
    cin >> q;
    vector<Query> queries(q);
    for (auto& query : queries) {
        cin >> query.u >> query.v;
        --query.u;
        --query.v;
    }

    vector<int> lo(q, 0), hi(q, m);
    vector<vector<int>> bucket(m);
    DSU dsu(n);

    bool changed = true;
    while (changed) {
        changed = false;
        for (auto& items : bucket) {
            items.clear();
        }

        for (int i = 0; i < q; ++i) {
            if (lo[i] < hi[i]) {
                int mid = (lo[i] + hi[i]) / 2;
                bucket[mid].push_back(i);
                changed = true;
            }
        }
        if (!changed) break;

        dsu.reset(n);
        for (int i = 0; i < m; ++i) {
            dsu.join(edges[i].u, edges[i].v);
            for (int queryIndex : bucket[i]) {
                const Query& query = queries[queryIndex];
                if (dsu.connected(query.u, query.v)) {
                    hi[queryIndex] = i;
                } else {
                    lo[queryIndex] = i + 1;
                }
            }
        }
    }

    vector<int> answerSize(q, -1);
    for (auto& items : bucket) {
        items.clear();
    }
    for (int i = 0; i < q; ++i) {
        if (lo[i] < m) {
            bucket[lo[i]].push_back(i);
        }
    }

    dsu.reset(n);
    for (int i = 0; i < m; ++i) {
        dsu.join(edges[i].u, edges[i].v);
        for (int queryIndex : bucket[i]) {
            answerSize[queryIndex] = dsu.componentSize(queries[queryIndex].u);
        }
    }

    for (int i = 0; i < q; ++i) {
        if (lo[i] == m) {
            cout << "-1\n";
        } else {
            cout << edges[lo[i]].w << ' ' << answerSize[i] << '\n';
        }
    }

    return 0;
}

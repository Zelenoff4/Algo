#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<queue>
#include<string.h>

using namespace std;

const long long inf = 9e18;
const int maxn = 10004;

struct edge {
	int u, v, c;
	long long f;
	edge() {};
	edge(int _u, int _v, int _c) { u = _u;v = _v;c = _c; f = 0; }
};

int n, m;
int level[maxn], last[maxn];
vector<edge> edges;
vector<int> gr[maxn];
queue<int> q;

void add_edge(int a, int b, int c) {
	int t = edges.size();
	edges.push_back(edge(a, b, c));
	edges.push_back(edge(b, a, 0));
	gr[a].push_back(t);
	gr[b].push_back(t + 1);
}

long long dfs(int v, long long flow, int t) {
	if (flow == 0 || v == t) return flow;
	for (;last[v] < (int)gr[v].size();++last[v]) {
		int nm = gr[v][last[v]];
		if (level[v] + 1 != level[edges[nm].v]) continue;
		long long ann = dfs(edges[nm].v, min(flow, edges[nm].c - edges[nm].f), t);
		if (ann != 0) {
			edges[nm].f += ann;
			edges[nm ^ 1].f -= ann;
			return ann;
		}
	}
	return 0;
}

long long dinic(int s, int t) {
	long long flow = 0;
	while (true) {
		memset(level, -1, (n + 1) * sizeof(int));
		level[s] = 0;
		q.push(s);
		while (q.size() > 0 && level[t] == -1) {
			int v = q.front(); q.pop();
			for (int e : gr[v]) {
				if (level[edges[e].v] == -1 && edges[e].f < edges[e].c) {
					q.push(edges[e].v);
					level[edges[e].v] = level[v] + 1;
				}
			}
		}
		while (q.size() > 0) q.pop();
		if (level[t] == -1) break;
		memset(last, 0, (n + 1) * sizeof(int));
		while (true) {
			long long ann = dfs(s, inf, t);
			if (ann == 0) break;
			flow += ann;
		}
	}
	return flow;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 1;i <= m; ++i) {
		int a, b, c;
		cin >> a >> b >> c;
		if(c > 0) add_edge(a, b, c);
	}
	cout << dinic(1, n);
	return 0;
}


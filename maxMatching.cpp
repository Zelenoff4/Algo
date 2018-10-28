#include <vector>
#include <iostream>

using namespace std;
const int MAXN = 1e5;

int n, m, k, ans = 0;
vector <int> g[MAXN];
vector<int> mt;
bool used[MAXN];

int dfs(int v) {
    if (used[v])
        return 0;
    used[v] = 1;
    for (unsigned int i = 0; i < g[v].size(); i++) {
        int to = g[v][i];
        if (mt[to] == -1 || dfs(mt[to])) {
            mt[to] = v;
            return 1;
        }
    }
    return 0;
}


int main(){
    ios_base::sync_with_stdio(0);
    //freopen("matching.in", "r", stdin);
    //freopen("matching.out", "w", stdout);
    cin >> n >> m >> k;
    mt.assign(m, -1);
    for (int i = 0; i < k; i++){
        int from, to;
        cin >> from >> to;
        g[from - 1].push_back(to - 1);
    }
    for (int i = 0; i < n; i++){
        fill(used, used + MAXN, 0);
        ans += dfs(i);
    }
    cout << ans;
}

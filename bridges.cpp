#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

vector<bool> used;
vector<long long> tin, tout, up;
vector<vector<long long>> g;
long long timer = 0;

void dfs(long long v, long long p = -1)
{
    used[v] = true;
    tin[v] = timer++;
    up[v] = tin[v];
    for (auto i : g[v])
    {
        if (i == p)
        {
            continue;
        }
        if (!used[i])
        {
            dfs(i, v);
            up[v] = min(up[v], up[i]);
        }
        else
        {
            up[v] = min(up[v], tin[i]);
        }
    }
    tout[v] = timer++;
}

int main()
{
    freopen("bridges.in", "r", stdin);
    freopen("bridges.out", "w", stdout);
    long long n = 0, m = 0;
    cin >> n >> m;
    g.resize(n);
    up.resize(n);
    tin.resize(n);
    tout.resize(n);
    used.resize(n, false);
    vector<pair<long long, long long>> e;
    map<pair<long long, long long>, int> kr;
    for (long long i = 0; i < m; i++)
    {
        long long a = 0, b = 0;
        cin >> a >> b;
        g[a - 1].push_back(b - 1);
        g[b - 1].push_back(a - 1);
        e.push_back(make_pair(a - 1, b - 1));
        kr[make_pair(a - 1, b - 1)]++;
        kr[make_pair(b - 1, a - 1)]++;
    }
    for (long long i = 0; i < n; i++)
    {
        if (!used[i])
        {
            dfs(i);
        }
    }
    vector<long long> ans;
    for (long long i = 0; i < (long long)e.size(); i++)
    {
        if ((up[e[i].first] > tin[e[i].second] || up[e[i].second] > tin[e[i].first]) && kr[e[i]] == 1)
        {
            ans.push_back(i);
        }
    }
    cout << ans.size() << endl;
    for (auto i : ans)
    {
        cout << i + 1 << endl;
    }
}

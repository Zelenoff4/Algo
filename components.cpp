#include <bits/stdc++.h>

using namespace std;

const int maxn = 4e5 + 7;

int color[maxn], col;
vector<int> v[maxn];

void dfs(int x){
    color[x] = col;
    for (size_t i = 0; i < v[x].size(); i++){
        if (color[v[x][i]]){
            continue;
        }
        dfs(v[x][i]);
    }
}

int main(){
    ios:: sync_with_stdio(0);
    freopen("components.in", "r", stdin);
    freopen("components.out", "w", stdout);
    int n, m;
    col = 0;
    cin >> n >> m;
    for (int i = 0; i < m; i++){
        int from, to;
        cin >> from >> to;
        v[from - 1].push_back(to - 1);
        v[to - 1].push_back(from - 1);
    }
    for (int i = 0; i < n; i++){
        if (color[i] == 0){
            col += 1;
            dfs(i);
        }
    }
    cout << col << endl;
    for (int i = 0; i < n; i++){
        cout << color[i] << " ";
    }

}

#include <bits/stdc++.h>

using namespace std;
const int MAXN = 4000;
vector<int> g[MAXN], match1, match2;
int n, m, k;
bool L[MAXN], R[MAXN], used[MAXN];

void dfs(int v){
    if (L[v])
        return;
    L[v] = true;
    for (size_t i = 0; i < g[v].size(); i++){
        int to = g[v][i];
        R[to] = true;
        dfs(match2[to]);
    }
}


int main(){
    ios_base::sync_with_stdio(0);
    freopen("vertexcover.in", "r", stdin);
    freopen("vertexcover.out", "w", stdout);
    cin >> m >> n;
    fill(L,L + MAXN, false);
    fill(R, R + MAXN, false);

    for (int i = 0; i < m; i++){
        cin >> k;
        for (int j = 0; j < k; j++){
            int to;
            cin >> to;
            g[i].push_back(to - 1);
        }
    }
    match2.resize(n);
    for (int i = 0; i < m; i++){
        int mt;
        cin >> mt;
        match1.push_back(mt - 1);
        if (mt != 0)
            match2[mt - 1] = i;
    }
    for (int i = 0; i < m; i++){
        if (match1[i] == -1){
            dfs(i);
        }
    }
/

    vector <int> mt1, mt2;
    for (int i = 0; i < m; i++){
        if (L[i] == 0){
            mt1.push_back(i + 1);
        }
    }
    for (int i = 0; i < n; i++){
        if (R[i] == 1){
            mt2.push_back(i + 1);
        }
    }
    size_t S = mt1.size() + mt2.size();
    cout << S << endl;
    if (!mt1.empty()){
        cout << mt1.size() << " ";
        for (size_t i = 0; i < mt1.size(); i++)
            cout << mt1[i] << " ";
        cout << endl;
    }
    else {
        cout << "0" << endl;
    }
    if (!mt2.empty()){
        cout << mt2.size() << " ";
        for (size_t i = 0; i < mt2.size(); i++)
            cout << mt2[i] << " ";
        cout << endl;
    }
    else {
        cout << "0" << endl;
    }
    return 0;
}

#include <bits/stdc++.h>
#include <stack>
#include <iostream>
const int MAXN = 1000;
int n, m;
using namespace std;
vector <int> res;

stack <int> St;

int main(){
    ios_base::sync_with_stdio(0);
    freopen("euler.in", "r", stdin);
    freopen("euler.out", "w", stdout);
    cin >> n;
    vector <vector <int>> g(n, vector<int> (n));
    for (int i = 0; i < n; i++){
        cin >> m;
        for (int j = 0; j < m; j++){
            int to;
            cin >> to;
            g[i][to - 1] += 1;
        }
    }

    vector<int> deg (n);
	for (int i=0; i<n; ++i)
		for (int j=0; j<n; ++j)
			deg[i] += g[i][j];
    int first = 0;
	while (!deg[first])  ++first;
	int v1 = -1,  v2 = -1;
	bool bad = false;
	for (int i=0; i<n; ++i)
		if (deg[i] & 1) {
			if (v1 == -1) {
				v1 = i;
			}
			else {
                if (v2 == -1)
                    v2 = i;
                else
                    bad = true;
			}
		}

	if (v1 != -1)
		++g[v1][v2],  ++g[v2][v1];

    St.push(first);
    while (!St.empty()){
        int v = St.top();
        int i = 0;
        for (i = 0; i < n; i++){
            if (g[v][i])
                break;
        }
        if (i == n){
            res.push_back(v);
            St.pop();
        }
        else {
            --g[v][i];
            --g[i][v];
            St.push(i);

        }
    }
    if (v1 != -1)
		for (size_t i=0; i+1<res.size(); ++i)
			if ((res[i] == v1 && res[i+1] == v2) || (res[i] == v2 && res[i+1] == v1))
			{
				vector<int> res2;
				for (size_t j=i+1; j<res.size(); ++j)
					res2.push_back (res[j]);
				for (size_t j=1; j<=i; ++j)
					res2.push_back (res[j]);
				res = res2;
				break;
			}

	for (int i=0; i<n; ++i)
		for (int j=0; j<n; ++j)
			if (g[i][j])
				bad = true;

	if (bad)
		puts ("-1");
	else
    {
        cout << res.size() - 1 << endl;
		for (size_t i=0; i<res.size(); ++i)
			printf ("%d ", res[i] + 1);
    }

}

#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long ll;
#define pii pair<int, int>
#define pb push_back
#define MAXN 100010
#define debug cout<<"debug"<<endl
int n, m;

vector<int> adj[MAXN];
vector<int> cor(MAXN);
vector<int> tam(5);

int main() {
    cin >> n >> m;  
    while (m--) {
        int a, b;
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    for (int c = 1; c <= 3; c++) {
        vector<bool> aux(MAXN);
        int v = 0;
        // cout << c << endl;
        for (v = 1; v <= n && cor[v] != 0; v++);
        if (v > n) {
            cout << -1 << endl;
            return 0;
        }
        cor[v] = c;
        aux[v] = true;
        tam[c]++;
        for (int w: adj[v]) aux[w] = true;
        for (int u = 1; u <= n; u++)
            if (!aux[u]) {
                cor[u] = c;
                tam[c]++;
            }

    }
    // for (int i = 1; i <= n; i++)
    //     cout << cor[i] << " ";
    // cout << endl;

    //debug;
    //cout  << tam[1] << " " << tam[2] << " " << tam[3] << endl;
    if (tam[1] + tam[2] + tam[3] != n) {
        cout << -1 << endl;
        return 0;
    }
    //debug;
    for (int v = 1; v < n; v++) {
        if (cor[v] == 1 && adj[v].size() != tam[2] + tam[3]) {
            cout << -1 << endl;
            return 0;
        } else if (cor[v] == 2 && adj[v].size() != tam[1] + tam[3]) {
            cout << -1 << endl;
            return 0;   
        } else if (cor[v] == 3 && adj[v].size() != tam[1] + tam[2]) {
            cout << -1 << endl;
            return 0;   
        }    
    }
    //debug;
    for (int v = 1; v < n; v++) {
        for (int w: adj[v]) {
            if (cor[w] == cor[v]) {
                cout << -1 << endl;
                return 0;
            }
        }
    }

    for (int i = 1; i <= n; i++)
        cout << cor[i] << " ";
    cout << endl;

    return 0;
}



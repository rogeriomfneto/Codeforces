#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long

vector<ll> adj[100010];

vector<ll> v;
ll n;
vector<int> d;

void dfs(int s) {
    queue<int> q;
    vector<bool> used(n);
    d.clear();
    d.resize(n);
    q.push(s);
    used[s] = true;
    while (!q.empty()) {
        int w = q.front();
        q.pop();
        for (int u: adj[w]) {
            if (!used[u]) {
                used[u] = true;
                q.push(u);
                d[u] = d[w] + 1;
            }
        }
    }

}

int main() {    
    cin >> n;
    for (ll i = 0; i < n; i++) {
        ll k;
        cin >> k;
        if (k != 0)
            v.push_back(k);
    }

    n = v.size();

    if (n > 128) {
        cout << 3 << endl;
        return 0;
    }



    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (v[i] & v[j]) {
                adj[i].push_back(j);
                adj[j].push_back(i);
            }

    // for (int i = 0; i < n; i++) {
    //     cout << i << ": ";
    //     for (int w: adj[i])
    //         cout << w << " ";
    //     cout << endl;
    // }

    int min = 300;

    for (int u = 0; u < n; u++) 
        for (int i = 0; i < adj[u].size(); i++) {
            int w = adj[u][i];
            adj[u].erase(adj[u].begin() + i);
            dfs(u);
            if (d[w]+1 < min && d[w]+1 > 2) min = d[w]+1;
            //cout << d[w] << endl;
            adj[u].push_back(w);
        }
    if (min == 300) min = -1;
    //cout << endl;
    cout << min << endl;
    


    return 0;
}



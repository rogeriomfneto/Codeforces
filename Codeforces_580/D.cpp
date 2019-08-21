#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long

vector<ll> adj[200];

int v[200];

int main() {
    int n;
    cin >> n;

    if (n > 128) {
        cout << 3 << endl;
        return 0;
    }

    for (int i = 0; i < n; i++)
        cin >> v[i];
    
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (v[i] & v[j]) {
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
    


    return 0;
}



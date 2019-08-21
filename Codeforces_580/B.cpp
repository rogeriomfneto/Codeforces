#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define MAX 100010
 
ll v[MAX];
ll g[MAX];
 
int main() {
    ll n;
    bool z = false;
    cin >> n;
 
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        ll d1 = abs(v[i] - 1);
        ll d2 = abs(v[i] - (-1));
        g[i] = min(d1, d2);
        if (v[i] == 0) z = true;
    }
    ll m = 0;
    ll r = 1;
    for (int i = 0; i < n; i++) {
        m += g[i]; 
        if (v[i] < 0) r*=(v[i] + g[i]);
        else          r*=(v[i] - g[i]);
    }
    if (r == 1) {
        cout << m << endl;
    } else if (r == -1 && z) {
        cout << m << endl;
    } else {
        cout << m+2 << endl;
    }
}
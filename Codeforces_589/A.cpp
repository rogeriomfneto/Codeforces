#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long ll;
#define MAXN 200020
int d[10];


bool diferente (vector<int> v) {
    for (int i = 0; i < 10; i++)
        d[i] = 0;
    int n = v.size();
    for (int i = 0; i < n; i++)
        d[v[i]]++;
    for (int i = 0; i < 10; i++)
        if (d[i] > 1) return false;
    return true;
}

void imprime (vector<int> v) {
    int n = v.size();
    for (int i = n-1; i >= 0; i--)
        cout << v[i];
    cout  << endl;
}

int main() {
    int l, r;
    cin >> l >> r;
    for (int i = l; i <= r; i++) {
        int j = i;
        vector<int> v;
        while (j > 0) {
            int k = j%10;
            j /= 10;
            v.push_back(k);
        }
        if (diferente(v)) {
            imprime (v);
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}



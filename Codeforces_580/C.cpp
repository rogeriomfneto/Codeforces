#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define MAX 200020

int v[MAX];

int main() {
    int n;
    cin >> n;
    if (n%2 == 0) {
        cout << "NO" << endl;
        return 0;
    }

    for (int i = 1; i <= n; i++)
        if (i%2 == 1) {
            v[i]     = 2*i - 1;
            v[i + n] = 2*i;
        } else {
            v[i] = 2*i;
            v[i + n] = 2*i - 1;
        }

    cout << "YES" << endl;
    for (int i = 1; i <= 2*n; i++)
        cout << v[i] << " ";
    cout << endl;

    return 0;
}



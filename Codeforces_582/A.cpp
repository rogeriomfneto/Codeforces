#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long

int v[150010];

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        int tot = 0;
        cin >> n;
        for (int i = 0; i < n; i++)
            cin >> v[i];
        int min = v[n-1];
        for (int i = n-1; i >= 0; i--) {
            if (v[i] > min) tot++;
            else       min = v[i];
        }
        cout << tot << endl;
    }
}



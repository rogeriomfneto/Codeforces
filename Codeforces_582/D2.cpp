#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define MAXN 200010

vector<int> cnt[MAXN];

int v[MAXN];

int main() {
    int n, k;
    int min = INT_MAX;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        int a = v[i];
        int c = 0;
        while (a > 0) {
            cnt[a].push_back(c);
            c++;
            a /= 2;
         }
    }

    for (int x = 1; x < MAXN; x++) {
        if (cnt[x].size() >= k) {
            int m = 0;
            sort(cnt[x].begin(), cnt[x].end());
            for (int i = 0; i < k; i++)
                m += cnt[x][i];
            if (m < min) min = m;
        }
    }
    cout << min << endl;
    return 0;
}



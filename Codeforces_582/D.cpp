#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define MAX 200010
set<int> x;
int v[MAX];
int aux[MAX];
int cnt[MAX];

int main() {
    int n, k, max = INT_MAX;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        int a = v[i];
        while (a > 0) {
            x.insert(-a);
            a /= 2;
        }
    }
    x.insert(0);

    for (auto a = x.begin(); a != x.end(); a++) {
        int x = abs(*a);
        //cout << "x: " << x << endl;
        for (int i = 0; i < n; i++) {
            int c = 0;
            aux[i] = v[i];
            while (aux[i] > x) {
                aux[i] /= 2;
                c++;
            }
            cnt[i] = c;
        }

        //  for (int i = 0; i < n; i++)
        //     cout << aux[i] << " ";
        // cout << endl;
        
        // for (int i = 0; i < n; i++)
        //     cout << cnt[i] << " ";
        // cout << endl;

        int c = 0;
        vector<int> tot;
        for (int i = 0; i < n; i++)
            if (aux[i] == x) {
                c++;
                tot.push_back(cnt[i]);
            }

        // for (int i = 0; i < tot.size(); i++)
        //     cout << tot[i] << " ";
        // cout << endl;

        if (c >= k) {
            int maxx = 0;
            sort(tot.begin(), tot.end());
            
            for (int i = 0; i < k ; i++) 
                maxx += tot[i];
            if (maxx < max) max = maxx;
        }

    }
    cout << max << endl;
}



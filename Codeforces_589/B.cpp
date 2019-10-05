#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long ll;
#define MAXN 1010
#define MOD 1000000007

int ma[MAXN][MAXN];
int h, w;
vector<int> r;
vector<int> c;

void imprime() {
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++)
            cout << ma[i][j] << " ";
        cout << endl;
    }
}

int main() {
    cin >> h >> w;
    for (int i = 0; i < h; i++)
        for (int j = 0; j < w; j++)
            ma[i][j] = -1;

    for (int i = 0; i < h; i++) {
        int k;
        cin >> k;
        r.push_back(k);
    }
    for (int i = 0; i < w; i++) {
        int k;
        cin >> k;
        c.push_back(k);
    }
    for (int i = 0; i < h; i++) {
        int n = r[i];
        for (int j = 0; j < n; j++) {
            if (ma[i][j] == -1) {
                ma[i][j] = 1;
            }
            else if (ma[i][j] != 1) {
                cout << 0 << endl;
                return 0;
            }
            
        }
        if (r[i] < w) {
            if (ma[i][r[i]] == -1) {
                ma[i][r[i]] = 0;
            }
            else if (ma[i][r[i]] != 0) {
                cout << 0 << endl;
                return 0;
            }
        }
        //imprime();
    }
    for (int i = 0; i < w; i++) {
        int n = c[i];
        for (int j = 0; j < n; j++) {
            if (ma[j][i] == -1) {
                ma[j][i] = 1;
            }
            else if (ma[j][i] != 1) {
                cout << 0 << endl;
                return 0;
            }
        }
        if (c[i] < h) {
            if (ma[c[i]][i] == -1) {
                ma[c[i]][i] = 0;
            }
            else if (ma[c[i]][i] != 0) {
                cout << 0 << endl;
                return 0;
            }
        //imprime();
        }
    }
    ll m = 0;
    ll tot = 1;
    for (int i = 0; i < h; i++)
        for (int j = 0; j < w; j++)
            if (ma[i][j] == -1) m++;
    while (m-- > 0) {
        tot *= 2;
        tot %= MOD;
    }
    cout << tot << endl;
}



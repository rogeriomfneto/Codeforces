#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
const int MAX = 55;

int ma[MAX][MAX]; 
int mb[MAX][MAX]; 

vector<pair<int, int>> xy;

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= m; j++)
         cin >> ma[i][j];

    for (int i = 1; i <= n-1; i++)
         for (int j = 1; j <= m-1; j++) {
            if (ma[i][j] && ma[i+1][j] && ma[i][j+1] && ma[i+1][j+1]) {
               mb[i][j] = mb[i+1][j] = mb[i][j+1] = mb[i+1][j+1] = 1;
               xy.push_back({i, j});
            }
         }
    bool equal = true;
    for (int i = 1; i <= n && equal; i++)
      for (int j = 1; j <= m && equal; j++)
         if (ma[i][j] != mb[i][j]) equal = false;

    if (!equal) {
       cout << -1 << endl;
       return 0;
    }

    if (xy.empty()) cout << 0 << endl;
    else {
       cout << xy.size() << endl;
       for (auto x: xy)
         cout << x.first <<  " " << x.second << endl;
    }

    return 0;
}



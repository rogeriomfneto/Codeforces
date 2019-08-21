#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define MAX 1010

vector<int>v1;
vector<int>v2;

int main() {
    int a, b;
    cin >> a;
    while (a--) {
        int k;
        cin >> k;
        v1.push_back(k);
    }

    cin >> b;
    while (b--) {
        int k;
        cin >> k;
        v2.push_back(k);
    }

    sort(v1.begin(),v1.end());
    sort(v2.begin(),v2.end());

    int i = *(--v1.end());
    int j = *(--v2.end());
    cout << i << " " << j << endl;
}



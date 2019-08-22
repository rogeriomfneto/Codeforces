#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long

int main() {
    int n;
    cin >> n;
    while (n--) {
       int b, p, f, c, h;
       cin >> b >> p >> f >> h >> c;
       int m1 = 0, m2 = 0;
       if (h > c) {
          while (b >= 2 && p >= 1) {
             b -= 2;
             p -= 1;
             m1++;
          }
          while (b >= 2 && f >= 1) {
             b -= 2;
             f -= 1;
             m2++;
          }
       } else {
          while (b >= 2 && f >= 1) {
             b -= 2;
             f -= 1;
             m2++;
          }
          while (b >= 2 && p >= 1) {
             b -= 2;
             p -= 1;
             m1++;
          }
       }
       cout << h*m1 + c*m2 << endl;
    }
    return 0;
}



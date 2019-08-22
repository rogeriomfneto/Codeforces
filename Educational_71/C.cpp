#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
const int MAX = 2e5 + 10;

ll cost[MAX];
bool up[MAX];

int main() {
    int t;
    cin >> t;
    while (t--) {
       ll n, a, b;
       cin >> n >> a >> b;
       string s;
       cin >> s;
       ll tot = 0;
       tot +=  b;
       int i = 0;
       int cnt = 0;
      while (s[i] == '0' && i < n) {
            cnt++;
            i++;
      }
      tot += (cnt-1)*b + (cnt-1)*a;
      tot += 2*a + 2*b;

       while (i < n) {
          cnt = 0;
          while (s[i] == '1' && i < n) {
             cnt++;
             i++;
          }
          tot += cnt*a + cnt*2*b;
          cnt = 0;
          while (s[i] == '0' && i < n) {
             cnt++;
             i++;
          }
          if (cnt < 2) tot+= cnt*a + cnt*2*b;
          else if (cnt*a + cnt*2*b < 2*a + b + 2*a + 2*b + (cnt-2)*a + (cnt-2)*b && i < n)
            tot+=cnt*a + cnt*2*b;
          else if (i < n) tot+= 2*a + b + 2*a + 2*b + (cnt-2)*a + (cnt-2)*b;
       }
 
      cout << tot << endl;
    }
    

    return 0;
}



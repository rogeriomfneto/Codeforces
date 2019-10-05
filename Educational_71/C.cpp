#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
 
 
 
ll contazeros(string s, ll i, ll n) {
   ll cnt = 0;
   while (s[i] == '0' && i < n) {
      cnt++;
      i++;
   }
   return cnt;
}
 
ll contauns(string s, ll i, ll n) {
   ll cnt = 0;
   while (s[i] == '1' && i < n) {
      cnt++;
      i++;
   }
   return cnt;
}
 
int main() {
    ll t;
    cin >> t;
    while (t--) {
       ll n, a, b;
       cin >> n >> a >> b;
       string s;
       cin >> s;
       ll tot = 0;
       tot +=  b;
       ll i = 0;
 
 
      ll cnt = contazeros(s, i, n);
      i += cnt;
      if (i == n) tot += cnt*(a + b);
      else        tot += (cnt-1)*(a+b) + 2*a + 2*b;
      
      bool um = true;
      while (i < n) {
         if (um) {
            cnt = contauns(s, i ,n);
            tot += cnt*(a + 2*b);
            i += cnt;
         } else {
            cnt = contazeros(s, i, n);
 
            if (i + cnt == n) {
               tot += 2*a + b + (cnt-1)*(a+b);
            } else if (cnt < 2) tot += a + 2*b;
            else if (i + cnt < n) {
               ll k = cnt*(a + 2*b);
               ll l = (cnt-2)*(a+b) + 4*a + 3*b;
               tot += min(l, k);
            } 
            i += cnt;      
         }
         um = !um;
      }
      cout << tot << endl;
    }
    
 
    return 0;
}
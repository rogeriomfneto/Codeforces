#include <bits/stdc++.h> 
using namespace std;
#define endl "\n"
#define ll long long

int v[5];
vector<char> s;


void apaga(int val, int k) {
   for (int j = 0; j < k; j++) {
      int n = s.size();
      for (int i = n-1; i >= 0; i--) {
         if ( (s[i] - '0')%3 == val ) {
            s.erase(s.begin() + i);
            break;
         }
      }
   }
}

int main() {
   for (int i = 0; i < 5; i++)
      v[i] = 0;
   string aux;
   cin >> aux;
   int k = aux.length();
   for (int i = 0; i < k; i++)
      s.push_back(aux[i]);
   int n = s.size();
   int tot = 0;
   for (int i = 0; i < n; i++) {
      v[ (s[i] - '0')%3 ]++;
      tot += (s[i] - '0')%3;
   }
   tot = tot%3;

   if (tot == 2) {
      if (v[2] >= 1) {
         apaga(2, 1);
      } else if (v[1] >= 2) {
         apaga(1, 2);
      } else {
         cout << -1 << endl;
         return 0;
      }
   } else if (tot == 1) {
      if (v[1] >= 1) {
         apaga(1, 1);
      } else if (v[2] >= 2) {
         apaga(2, 2);
      } else {
         cout << -1 << endl;
         return 0;
      }
   }

   if (s.size() > 1 && s[0] == '0')
      s.erase(s.begin());
   n = s.size();
   if (n == 0) {
      cout << -1 << endl;
      return 0;
   }
   for (int i = 0; i < n; i++)
      cout << s[i];
   cout << endl;
   
   return 0;  
}
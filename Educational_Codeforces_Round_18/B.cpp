#include <bits/stdc++.h> 
using namespace std;
#define endl "\n"
#define ll long long
const int MAX = 1e9 + 10;

int v[110];
vector<int> kids(110);
int n;

int main() {
   int k;
   cin >> n >> k;
   int leader = 0;

   for (int i = 0; i < n; i++)
      kids[i] = i+1;

   for (int i = 0; i < k; i++) {
      cin >> v[i];
      int pos = (leader + v[i])%n;
      if (pos == n-1) leader = 0;
      else            leader = pos;
      cout << kids[pos] << " ";
      kids.erase(kids.begin() + pos);
      n--;
   }
   cout << endl;
   return 0;  
}
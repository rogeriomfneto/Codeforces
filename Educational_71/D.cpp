#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long

vector<pair<int, int>> v;

map<int, int> r1;
map<int, int> r2;

bool second_ordenado() {
   for (int i = 1; i < v.size(); i++)
      if (v[i].second < v[i-1].second)
         return false;
   return true;
}

int main() { 
   int n;
   cin >> n;
   while (n--) {
      int a, b;
      cin >> a >> b;
      r1[a] += 1;
      r2[b] += 1;
      v.push_back({a, b});
   }

   sort(v.begin(), v.end());



   return 0;
}



#include <bits/stdc++.h> 
using namespace std;
#define endl "\n"
#define ll long long
const int MAX = 2e5 + 10;

ll v[MAX];
ll aux[MAX];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
      cin >> v[i];
   
   sort(v, v + n);
   for (int i = 1; i < n; i++)
      aux[i] = v[i] - v[i-1];
   
   ll min = 1e10;

   for (int i = 1; i < n; i++)
      if (aux[i] < min) min = aux[i];
   
   ll cnt = 0;
   for (int i = 1; i < n; i++)
      if (aux[i] == min) cnt++;

   cout << min << " " << cnt << endl;

    return 0;  
}
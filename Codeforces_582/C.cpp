#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long

int main() {
    int q;
    cin >> q;

    while (q--) {
        ll n, m, div, r, tot = 0, max = 0;
        cin >> n >> m;
        div = n/m;
        r = div%10;
        div = div/10;
        for (int i = 1; i <= 10; i++)
            max += (m*i)%10;
        tot += div*max;
        for (int i = 1; i <= r; i++)    
            tot += (i*m)%10;
        printf("%lld\n", tot);
    }

    return 0;
}



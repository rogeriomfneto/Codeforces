#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define pii pair<int, int>
#define pb push_back
typedef long long ll;

ll x, n;
vector<ll> factorization;
vector<ll> ans;
const ll MOD = 1000000007;
const ll MAXN = 1e18 + 10;

// ll binpow(ll a, ll b) {
//     if (b == 0)
//         return 1;
//     ll res = binpow(a, b / 2);
//     if (b % 2)
//         return (res * res * a)%MOD;
//     else
//         return (res * res)%MOD;
// }

ll binpowmod(ll base, ll exp) {
    ll ans = 1;
    while (exp) {
        if (exp % 2) ans*=base;
        base *= base;
        ans %= MOD, base %= MOD, exp /=2;
    }
    return ans;
}


// ll binpowmod(ll a, ll b) {
//     if (b == 0)
//         return 1;
//     ll res = binpow(a, b / 2)%MOD;
//     if (b % 2)
//         return res * res *a;
//     else
//         return res * res;
// }

ll exp_max(ll k) {
    ll MAX = MAXN;
    ll tot = 0;
    while (MAX > 0) {
        tot++;
        MAX /= k;
    }
    return tot;
}

void trial_division1(ll n) {
    for (ll d = 2; d * d <= n; d++) {
        if (n % d == 0) {
            factorization.push_back(d);
            while (n % d == 0)
                n /= d;
        }
    }
    if (n > 1)
        factorization.push_back(n);
}


int main() {
    cin >> x >> n;
    trial_division1(x);
    for (ll p: factorization) {
        ll exp = exp_max(p);
        
        ll tot = 0;
        ll m = n;
        for (ll i = 1; i < exp; i++) {
            tot += m/p;
            m /= p;
        }
        // cout << tot << endl;
        ans.pb(binpowmod(p, tot));
        // cout << p  << " " << tot << endl;
    }
    // for (ll a: ans)
    //     cout << a << " ";
    // cout << endl;
    ll resp = 1;
    for (ll k: ans) {
        resp *= k;
        resp %= MOD;
    }

    cout << resp << endl;

}



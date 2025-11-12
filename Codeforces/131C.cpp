#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define ROF(i, a, b) for (int i = (b)-1; i >= (a); --i)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vl = vector<ll>;
using vpii = vector<pair<int, int>>;

const int MOD = 1e9 + 7;  
const ll INF = 1e18;

ll combinations(int n, int k) {
    if (k < 0 || k > n) {
        return 0;
    }
    if (k == 0 || k == n) {
        return 1;
    }
    if (k > n / 2) {
        k = n - k;  
    }
    ll res = 1;
    FOR(i, 1, k + 1) {
        res = res * (n - i + 1) / i;
    }
    return res;
}

void solve() {
    ll n,m, t; cin >> n >> m>> t;
    //precalcular fatoriais
    vl fact(max(n,m)+1);
    fact[0] =1;
    ll ans = 0;
    FOR(i, 1, max(n,m)+1){
        fact[i]= fact[i-1]* (ll)i % MOD;
    }
    //i homens e j mulheres
    FOR(i, 4, n+1 ){
        int j = t- i;
        if(j > m || j < 1) continue;
       ll CH = combinations(n, i);
        ll CM = combinations(m, j);
        ll C = (CM * CH );
        ans = (ans + C) ;
;    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int t =1; 
    // cin >> t;  

    while (t--) {
        solve();  
    }

    return 0;
}

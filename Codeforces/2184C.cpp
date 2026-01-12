#include <bits/stdc++.h>
using namespace std;

#define fastio cin.tie(0)->sync_with_stdio(0);
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define ROF(i, a, b) for (int i = (b)-1; i >= (a); --i)
#define all(x) (x).begin(), (x).end()
#define deb(k) cerr << #k << ": " << k << "\n";
using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using pii = pair<int, int>;
#define mii map<int, int>

#define st first
#define nd second
const int MOD = 1e9 + 7;  
const ll INF = 1e18;

void solve() {
    int n, k; cin >> n >> k;
    int aux = n;

    if (n == k) {
        cout << 0 << endl;
        return;
    }
    for (int t = 1; t <= log2(n); t++) {
        ll pedacos = (1LL << t);

        if (pedacos > n) break;

        ll val = n / pedacos;     
        ll resto = n % pedacos;   
        
        ll qts = pedacos - resto;
        
        if (val == k && qts > 0) {
            cout << t << endl;
            return;
        }
        if (val + 1 == k && resto > 0) {
            cout << t << endl;
            return;
        }
    }
    cout << -1 << endl;
}

int main() {
    fastio;
    int t =1; 
    cin >> t;  
    while (t--) 
        solve();  
    return 0;
}

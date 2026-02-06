#include <bits/stdc++.h>
using namespace std;

#define fastio cin.tie(0)->sync_with_stdio(0);
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define ROF(i, a, b) for (int i = (b)-1; i >= (a); --i)
#define all(x) (x).begin(), (x).end()
#define deb(k) cerr << #k << ": " << k << "\n";
#define pb push_back
using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using pii = pair<int, int>;

const int MOD = 1e9 + 7;  
const int INF = 2e9;
const ll INFLL = 4e18;

void solve() {
    int n, m;
    cin >> n >> m;

    long long tempo_total = 0;
    int pos_atual = 1;

    for (int i = 0; i < m; i++) {
        int prox;
        cin >> prox;

        if (prox >= pos_atual) {
            tempo_total += (prox - pos_atual);
        } else {
            tempo_total += (n - pos_atual) + prox;
        }

        pos_atual = prox; 
    }

    cout << tempo_total << endl;
}

int main() {
    fastio;
    int t =1; 
    // cin >> t;  
    while (t--) 
        solve();  
    return 0;
}

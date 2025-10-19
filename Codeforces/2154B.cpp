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

void solve() {
    int n; cin >> n;
    vi a(n); FOR(i, 0, n) cin >> a[i];
    ll ans =0;

    int maior = 0;
    FOR(i, 0, n){
        maior = max(maior, a[i]);
        if (i%2 ==1){ 
             a[i] = max(a[i], maior);

        }
    }

    FOR(i, 0, n) {
    if (i % 2 == 0) {  
        ll menor;
            if (i == 0) { 
                if (n > 1) menor = a[i + 1];
                else continue;  //n=1
            } 
            else if (i == n - 1) {
                menor = a[i - 1];
            } 
            else {
                menor = min(a[i - 1], a[i + 1]);
            }

            if (a[i] >= menor) {
                ans += a[i] - menor + 1;
            }
        }
    }
    cout << ans << endl;
}


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int t =1; 
    cin >> t;  

    while (t--) {
        solve();  
    }

    return 0;
}

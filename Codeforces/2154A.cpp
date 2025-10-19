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
    int n, k; cin >> n >>k;
    string s; cin >> s;
    // vi pref(n+1, 0);
    // for (int i =1; i <=n; i++){
    //     pref[i]= pref[i-1]+ (s[i-1] -'0');
    // }

    int ans = 0;
    int ultimo_i = -k;  

    for (int i = 0; i < n; i++) {
        if (s[i] == '1') {
            if (i - ultimo_i < k) {
                ultimo_i = i; // 
                continue;
            }
            ans++;
            ultimo_i = i;
        }
    }

    cout << ans << '\n';
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

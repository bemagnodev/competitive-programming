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
    ll a,b, n; cin >> a >> b >> n;
    string ans;

    FOR(j,0,10){
        if(((10*a) + j )% b ==0){
            a = 10*a+j;
            ans += to_string(a);
            FOR(i,1,n){
                ans += "0";
            }
            cout << ans << endl;
            return;
        }
        if(j == 9){
            cout << -1 << endl;
            return;
        }
    }


    cout << a << endl;

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

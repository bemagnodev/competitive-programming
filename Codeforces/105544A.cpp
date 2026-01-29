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
const int INF = 1e9;
const ll INFLL = 4e18;

void solve() {
    string s; cin >> s;
    reverse(s.begin(), s.end());
    ll ans = 0;

    int n = s.size();
    string atual = "";
    int k =1;
    FOR(i,1,n+1){
        atual += s[i-1];
        if(i%3 == 0 || i == n){
            reverse(all(atual));
            ll x = stoll(atual);
            ans += k*x;
            k*=-1;
            atual = "";
        }
    }
    cout <<abs(ans) << " ";
    if(ans %13 ==0) cout << "YES\n";
    else cout << "NO\n";
}

int main() {
    fastio;
    int t =1; 
    cin >> t;  
    while (t--) 
        solve();  
    return 0;
}

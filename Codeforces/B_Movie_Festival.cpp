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
#define mii map<int, int>

#define st first
#define nd second
const int MOD = 1e9 + 7;  
const ll INF = 1e18;

void solve() {
    int n; cin >> n;
    vector<pii> a(n);
    FOR(i,0,n){
        int x, y; cin >> x>> y;
        a[i].st= y;
        a[i].nd = x;
    }

    sort(all(a));
    int l =a[0].nd, r =a[0].st , ans = 1;
    FOR(i,1,n){
        if(r<= a[i].nd){
            ans++;
            r=a[i].st;
            l=a[i].nd;        }
    }

    cout << ans << endl;
}

int main() {
    fastio;
    int t =1; 
    // cin >> t;  
    while (t--) 
        solve();  
    return 0;
}

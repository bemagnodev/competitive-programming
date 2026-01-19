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
    int n; cin >> n;
    vi a(n);
    map<int,int> freq;
    FOR(i,0,n){
        cin >> a[i];
        freq[a[i]]++;
    } 
    
    vi pref(n);
    pref[0]= a[0];
    FOR(i,1,n){
        pref[i] = __gcd(a[i], pref[i-1]);
        freq[pref[i]]++;
    }

    FOR(i,0,n){
        cerr << pref[i] << endl;
    }

    int q; cin >> q;
    while(q--){
        int x; cin >> x;
        cout<< freq[x] << endl;
    }

}

int main() {
    fastio;
    int t =1; 
    // cin >> t;  
    while (t--) 
        solve();  
    return 0;
}

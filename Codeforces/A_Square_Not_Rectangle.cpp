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

bool check (int x, int n , vi h){
    int c = 0;
    FOR(i,0,n){
        if(h[i] >= x){
            c++;
            if(c == x) return true;
        }
        else c = 0;
    }
    return false;
}

void solve() {
    int n;
    cin >> n;
    vi h(n);
    
    FOR(i,0,n){
        cin >> h[i];
    }

    int l = 1, r = n+2;
    int mid, ans = 0;
    while(l<=r){
        mid = l +(r-l)/2;
        if(check(mid, n , h)){
            l= mid+1;
            ans = mid;
        }
        else{
            r = mid-1;
        }
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

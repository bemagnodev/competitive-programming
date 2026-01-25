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
    vi a(n);
    int maior =n, l =0, r = n-1;
    FOR(i,0,n){
        cin >> a[i];
    } 

    FOR(i,0,n){
        if(a[i] == maior){
            cout << a[i] << " ";
            maior--;
            l = i+1;
        }
        else break;
    }
    
    FOR(i,l,n){
        if(a[i] == maior){
            r= i;
        }
    }
    // deb(l);
    // deb(r);

    for(int i = r; i >= l; i--){
        cout << a[i] << " ";
    }

    FOR(i,r+1,n){
        cout << a[i] << " ";
    }
    cout << "\n";
}

int main() {
    fastio;
    int t =1; 
    cin >> t;  
    while (t--) 
        solve();  
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define mii map<int, int>
#define all(x) x.begin(), x.end()
#define pb push_back
#define sz(x) (int)(x).size()
#define ins insert
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pair<int, int>> vpii;
const int MOD = 998244353;
const int MAXN = 1e3+5;
const ll INF = 4e18;

void solve(){
    int n,q; cin >> n >> q;
    vi a(n), pref;
    pref.pb(0);
    FOR(i,0,n){
        cin >> a[i];
        int v = __gcd(a[i],pref.back());
        pref.pb(v);
    }
    while(q--){
        int tp; cin >> tp;
        if(tp==1){
            int x; cin >> x;
            int v = __gcd(pref.back(),x);
            pref.pb(v);
        }else if(tp==2){
            int k; cin >> k;
            while(k--) pref.pop_back();
        }else{
            int x; cin >> x;
            if(pref.back()%x==0){
                cout << "SIM\n";
            }else cout << "NAO\n";
           // cout << pref.back() << "\n";
        }
    }
}

 
int main(){
    ios::sync_with_stdio(false),cin.tie(0);
    // int t; cin >> t;
    // while(t--)
    solve();
    return 0;
}


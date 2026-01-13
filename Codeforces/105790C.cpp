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
    string s; cin >> s;
    int n; cin >>n;
    set<string> dict;
    FOR(i,0,n){
        string a ,b; cin >> a>> b;
        string q = a+b;
        dict.insert(q);
    }
    FOR(i,1, s.size()){
        string t = "";
        t+=s[i-1];
        t+= s[i];
        if(!dict.count(t)){
            cout << "NAO\n";
            return;
        }
    }
    cout << "SIM\n";

}

int main() {
    fastio;
    int t =1; 
    // cin >> t;  
    while (t--) 
        solve();  
    return 0;
}

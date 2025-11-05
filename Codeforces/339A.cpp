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
    string s, ans; cin >> s;
    int u =0, d=0, t=0;
    FOR(i,0,s.size()){
        if(s[i] == '1') u++;
        else if(s[i] == '2') d++;
        else if(s[i] == '3') t++;
    }

    // cerr << u << " " << d << " "<< t<< endl;
    FOR(i, 0, u){
        ans+='1';
        if(i+1 <u || d || t){
            ans+='+';
        }
    }

    FOR(i, 0, d){
        ans+='2';
        if(i+1 <d || t){
            ans+='+';
        }
    }
    FOR(i, 0, t){
        ans+='3';
        if(i+1 < t){
            ans+='+';
        }
    }

    cout << ans << endl;
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

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
    string s; cin >>s;

    int j= 0; string h = "hello";
    FOR(i,0, s.size()){
        if(s[i] == h[j]){
            // cerr<< s[i] <<" : " << h[j]<<endl;
            if(h[j] == 'o'){
                cout << "YES" << endl;
                return;
            }
            j++;
        }
    }
    cout << "NO" << endl;
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

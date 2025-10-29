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
    int as=0,bs=0, cs=0;
    FOR(i, 0,9){
        char c; cin >> c;
        if(c == 'A')as++;
        else if(c == 'B')bs++;
        else if(c == 'C')cs++;
    }
    if(as == 2){
        cout << 'A' << endl;
        return;
    }
    else if(bs == 2){
        cout << 'B' << endl;
        return;
    }
    else if(cs == 2){
        cout << 'C' << endl;
        return;
    }

}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int t =1; 
    cin >> t;  

    while (t--) {
        solve();  
    }

    return 0;
}

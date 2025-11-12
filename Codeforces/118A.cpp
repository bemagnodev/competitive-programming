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
    string s, r; cin >> s;
    for(char c : s){
        if(tolower(c) != 'a'){
            if(tolower(c) != 'e'){
                if(tolower(c) != 'i'){
                    if(tolower(c) != 'o') {
                        if(tolower(c) != 'u'){
                            if(tolower(c) != 'y'){
                                
                                r+=".";
                                r+=tolower(c);
                    
                            }
                        }
                    }
                }
            }
        }
    }
    cout << r << endl;
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

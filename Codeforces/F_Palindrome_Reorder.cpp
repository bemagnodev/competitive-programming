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
    string s; cin >> s;
    vi dict(26,0);

    for(char c: s){
        dict[c-'A']++;
    }


    string ans= "";
    bool impar = false; string imp="";
    ROF(i,0,26){
        if(dict[i] % 2 != 0 ){
            if(impar || s.size()%2==0){
                cout << "NO SOLUTION" <<endl;
                return;
            }
            impar = true;
            int f = dict[i];
            FOR(j,0,f) {
                imp+= i+'A';
            }
        }
        else{
            int f = dict[i]/2;
            FOR(k,0,f) ans+= i+'A';

        }
    }
    string t = ans;
    sort(all(t));
    
    ans += imp+ t;
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

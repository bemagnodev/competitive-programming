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
    int n, x; cin >> n >>x;
    string s; cin >> s;
    string complemento;
    vector<char> dict = {'A', 'C', 'G', 'T'};
    FOR(i,0,n){
        if(s[i]=='G')complemento+='C';
        else if(s[i]=='C')complemento+='G';
        else if(s[i]=='A')complemento+='T';
        else if(s[i]=='T')complemento+='A';
    }
    string ans;
    int indx0_orig = find(dict.begin(), dict.end(), s[0]) -dict.begin();
    int delta0 = (x^indx0_orig);
    int indx0_comp = find(dict.begin(), dict.end(), complemento[0]) -dict.begin();
    ans+= dict[(indx0_comp+delta0)%4];
    int delta = delta0;
    // deb((7^2^1^3));
    FOR(i,1,n){
        char c = s[i];
        // deb(c); 
        int index_orig = find(dict.begin(), dict.end(), c) -dict.begin();
        // deb(index_orig);
        delta = (delta ^ index_orig);
        // deb(delta);
        int index_comp = find(dict.begin(), dict.end(), complemento[i]) -dict.begin();
        ans+= dict[(index_comp+delta)%4];
        // deb(ans);
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

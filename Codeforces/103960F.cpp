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
    int n, c; cin >>n >> c;
    string t=""; int m = 0;
    map<string, int> dict;
    FOR(i,0,n){
        string s; cin >> s;
        // encotrar *
        int pos;
        FOR(i,0,c){
            if(s[i] =='*') pos = i;
        }
        
        //todas as letras
        FOR(i,0,26){
            char l = 'a'+i;
            // deb(l);
            string nova = s;
            nova[pos] = l;
            dict[nova]++;
            if( dict[nova]> m){
                m = dict[nova];
                t = nova;
            }
            else if ( dict[nova]== m){
                if(nova < t) t = nova;
            }
        }
    }

    cout <<t << " " << m<< endl;

}

int main() {
    fastio;
    int t =1; 
    // cin >> t;  
    while (t--) 
        solve();  
    return 0;
}

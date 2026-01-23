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
    vi freq(14,0);
    vi cartas(4);
    FOR(i,0,4){
        cin >> cartas[i];
        freq[cartas[i]]++;
        cartas[i] = (cartas[i]<10?cartas[i]:10);
    }
    int mesa =0;
    FOR(i,0,n){
        int c; cin >> c;
        freq[c]++;
        int pts = (c<10?c:10);
        mesa+=pts;
    }

    int pj = cartas[0]+ cartas[1]+mesa, faltamJ = 24-pj;
    int pm = cartas[3]+ cartas[2]+mesa, faltamM = 23-pm;
    // deb(pj);
    // deb(faltamJ);
    FOR(i,1,14){
        int pts = (i<10?i:10);
        if(freq[i]<4 ){
            if((pts>= faltamJ && pts+pm <=23)|| pts == faltamM){
                cout << i << endl; return;
            }
        }
    }
    cout << -1 << endl; 

}

int main() {
    fastio;
    int t =1; 
    // cin >> t;  
    while (t--) 
        solve();  
    return 0;
}

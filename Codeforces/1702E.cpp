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

struct DSU{
    vi pai;
    vi sz;
    int components;
    DSU(int n){
        sz.assign(n+1,1);
        pai.resize(n+1);
        FOR(i,1,n+1) pai[i] =  i;
        components = n;
    }

    int find( int x){
        if(pai[x] == x) return x;
        return pai[x] = find(pai[x]);
    }

    void join(int a , int b){
        a = find(a);
        b = find( b);
        if(a==b) return;

        if(sz[b] >sz[a]) swap(a,b);
        pai[b] =a;
        sz[a]+=sz[b];
        components--;
    }
};


void solve() {
    int n; cin >> n;
    vector<pii> dominos(n);
    vi freq(n+1, 0);
    bool ok = true;
    FOR(i,0,n){
        cin >> dominos[i].first >> dominos[i].second;
        freq[dominos[i].first ]++;
        freq[dominos[i].second ]++;
        if( freq[dominos[i].first ] >2 ) {
            ok = false;            
        }
        if( freq[dominos[i].second ] >2 ) {
            ok = false;            
        }
    }

    DSU dsu(n);
    FOR(i,0,n){
        int a = dominos[i].st;
        int b = dominos[i].nd;

        if(dsu.find(a) != dsu.find(b) ){
            dsu.join(a,b);
        }
        else{
            if(dsu.sz[dsu.find(a)] % 2 == 1  ) {//precisa do find ?
           ok = false;
        }
    }
}
    if(ok) cout << "YES\n";
    else cout << "NO\n";

}

int main() {
    fastio;
    int t =1; 
    cin >> t;  
    while (t--) 
        solve();  
    return 0;
}

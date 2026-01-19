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

struct DSU {
    vi pai;
    vi size;
    int components;
    int maior = 1;

    DSU (int n){
        components = n;
        pai.resize(n+1);
        size.assign(n+1,1);
        FOR(i,1,n+1) pai[i] = i;
    }

    int find(int x){
        if(x == pai[x]) return x;
        return pai[x] =  find(pai[x]);
    }

    void unite (int a, int b){
        a = find(a);
        b = find (b);

        if(a == b) return;

        if(size[b] > size[a])  swap(a,b);
        
        pai[b] = a;
        size[a] += size[b];
        maior = max(maior, size[a]);
        components--;
    }
};


void solve() {
    int n,m; cin >> n >> m;
    DSU dsu(n);

    FOR(i,0,m){
        int a,b; cin >> a >> b;
        dsu.unite(a,b);
        cout << dsu.components << " " << dsu.maior << endl;

    }

}

int main() {
    fastio;
    int t =1; 
    // cin >> t;  
    while (t--) 
        solve();  
    return 0;
}

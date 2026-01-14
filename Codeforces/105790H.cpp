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

bool check(ll x, int n , int k, vector<vector<pair<ll, int>>>& adj){
    vl dist(n+1, INF); 
    deque<int> q;

    dist[1] =0;
    q.push_front(1);

    while(!q.empty()){
        int u = q.front();
        q.pop_front();

        for(auto viz : adj[u]){
           ll w= viz.st;
           int v = viz.nd;
           int peso = (x>=w) ? 0:1;

            if (dist[u] + peso < dist[v]) {
                dist[v] = dist[u] + peso;
                if(peso){ //1
                    q.push_back(v);
                }//0
                else q.push_front(v);
               
            }
        }

    }

    if(dist[n] <= k)return true;
    return false;

}

void solve() {
    int n, m, k; cin >> n >>m >>k;
    vector<vector<pair<ll, int>>>adj(n+1); // peso , destino
    FOR(i,0,m){
        int u, v; ll h; cin >>u >> v >> h;
        adj[u].push_back({h, v});
        adj[v].push_back({h, u});
    }
    // bb Higgs 0 a 10^9
    ll l=0, r = 1e9, mid =0, ans = 0;
    while(l<=r){
        mid = l +(r-l)/2;
        if(check(mid, n ,k, adj)){
            r= mid-1;
            ans = mid;
        }
        else{
            l = mid+1;
        }
    }
    
    cout << ans << "\n";
}

int main() {
    fastio;
    int t =1; 
    // cin >> t;  
    while (t--) 
        solve();  
    return 0;
}

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
    int n, m; cin >> n >>m;
    vector<vector<char>> grid(n+2, vector<char>(m+2,'#'));
    vector<vi> vis(n+2, vi(m+2,0));
    FOR(i,1,n+1){
        FOR(j,1,m+1){
            cin >> grid[i][j];
        }
    }
    auto dfs = [&](auto&& self, int i, int j)->void{
        vis[i][j] = true;

        FOR(dx,-1,2){
            FOR(dy, -1, 2){
                int nx = i+dx, ny = j+dy;
                if(abs(dx)+abs(dy)!=1)continue;
                if(grid[nx][ny]!= '#'&& vis[nx][ny] == 0){
                self(self, nx,ny);
            }
            }
        }
    };
    ll ans = 0;
    FOR(i,1,n+1){
        FOR(j,1,m+1){
            if(grid[i][j]== '.'&& vis[i][j] == 0){
                ans++;
                dfs(dfs, i,j);
            }
        }
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

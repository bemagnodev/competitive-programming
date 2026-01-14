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

void bfs01(int r, int c, int n, int m, vector<vector<char>>& grid, vector<vl>& mov_left){
    mov_left[r][c] = 0;
    deque<pii>q;
    q.push_front({r,c});

    while (!q.empty()){
        pii viz = q.front();
        int x = viz.st, y =viz.nd;
        q.pop_front();
        //top
        if(x-1>=0 && grid[x-1][y] =='.'){
            if(mov_left[x][y]+0 < mov_left[x-1][y]){
                mov_left[x-1][y] = mov_left[x][y];
                q.push_front({x-1, y});
            }
        }
        //bot
         if(x+1<n && grid[x+1][y] =='.'){
            if(mov_left[x][y]+0 < mov_left[x+1][y]){
                mov_left[x+1][y] = mov_left[x][y];
                q.push_front({x+1, y});
            }
        }
        //right
        if(y+1<m && grid[x][y+1] =='.'){
            if(mov_left[x][y]+0 < mov_left[x][y+1]){
                mov_left[x][y+1] = mov_left[x][y];
                q.push_front({x, y+1});
            }
        }
        if(y-1>=0 && grid[x][y-1] =='.'){
            if(mov_left[x][y]+1 < mov_left[x][y-1]){
                mov_left[x][y-1] = mov_left[x][y] +1;
                q.push_back({x, y-1});
            }
        }
        

    }
}

void solve() {
    int n, m; cin >> n >>m;
    int r, c; cin >> r >>c;r--;c--;
    int x, y; cin >> x >>y;

    vector<vector<char>> grid(n,vector<char>(m));
    FOR(i,0,n){
        FOR(j,0,m){
            cin >> grid[i][j];
        }
    }
    vector<vl> mov_left(n, vl(m,INF));
    bfs01(r,c,n, m, grid, mov_left);
    ll ans =0;
    FOR(i,0,n){
        FOR(j,0,m){
            if(mov_left[i][j] == INF) continue; 
             int esq = mov_left[i][j];
             int dir = esq +(j-c);
            if(esq <= x && dir <= y ) ans++;
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

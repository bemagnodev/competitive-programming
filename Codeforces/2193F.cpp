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
    ll n, ax, ay, bx, by; cin >> n >> ax >> ay >> bx >> by;
    vector<pii> a(n); //  {x, y }
    map<int, pii> limites; //x : top, obt

    FOR(i,0,n) cin >> a[i].st; //x
    FOR(i,0,n) cin >> a[i].nd; 
    sort(all(a)); //ordenar x -> X


    FOR(i,0,n){
        int x = a[i].st;
        int y = a[i].nd;

        if(!limites.count(x)) limites[x] = {y,y};

        if(y > limites[x].st )  limites[x].st = y;
        if(y < limites[x].nd) limites[x].nd = y;
    }
    
    
    vector<vl> colunas; // x, bot, top 
   for(auto e: limites){
        ll x = e.st;
        ll top = e.nd.st;
        ll bot = e.nd.nd;
        colunas.pb({x, bot, top});
        
   }
   colunas.pb({bx,by,by});
   
   int m = colunas.size();

   vector<vl> dp(m, vl(2, INF));
   // dp[i][0] : dist minima para chegar no topo da coluna i: dx + h + dymin
   // dp[i][0] : dist minima para chegar na base da coluna i
   ll dp_top_ant = 0, dp_bot_ant = 0;
   ll x_ant = ax, top_ant = ay, bot_ant = ay;

   FOR(i,0,m){
       ll x = colunas[i][0];
       ll bot = colunas[i][1];
       ll top = colunas[i][2];

       ll dx = abs(x-x_ant);
       ll h = abs(top-bot);

       //terminando no top [0]]
       dp[i][0]= min(dp_top_ant + abs(top_ant-bot) + dx+ h,
       dp_bot_ant + abs(bot_ant-bot) + dx+ h);
       
       //terminando no bot [1]
        dp[i][1]= min(dp_top_ant + abs(top_ant-top) + dx+ h,
                    dp_bot_ant + abs(bot_ant-top) + dx+ h);


        x_ant = x;
        top_ant = top;
        bot_ant = bot;
        dp_top_ant = dp[i][0];
        dp_bot_ant = dp[i][1];
   }
   cout << min (dp[m-1][0], dp[m-1][1]) << endl;

}

int main() {
    fastio;
    int t =1; 
    cin >> t;  
    while (t--) 
        solve();  
    return 0;
}

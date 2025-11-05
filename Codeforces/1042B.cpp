#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define ROF(i, a, b) for (int i = (b)-1; i >= (a); --i)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vl = vector<ll>;
using vpii = vector<pair<int, int>>;

const int MOD = 1e9 + 7;  
const ll INF = 1e9+5;

void solve() {

    int n; cin >>n;
    vl dp(7, INF);
    FOR(i, 0 , n){
        ll preco; cin >> preco;
        string vit; cin >> vit;
        sort(all(vit));
        if(vit =="A") dp[1] = min(dp[1], preco);
        else if(vit =="B") dp[2] = min(dp[2], preco);
        else if(vit =="AB") dp[3] = min(dp[3], preco);//
        else if(vit =="C") dp[4] = min(dp[4], preco);
        else if(vit =="AC") dp[5] = min(dp[5], preco);//
        else if(vit =="BC") dp[6] = min(dp[6], preco);//
        else if(vit =="ABC") dp[7] = min(dp[7], preco);//

    }

    // dp[3] = min(dp[3], dp[1]+dp[2]);
    // dp[5] = min(dp[5], dp[1]+dp[4]);
    // dp[3] = min(dp[6], dp[4]+dp[2]);
    dp[7] = min( dp[7], dp[1]+dp[2]+dp[4]);
    
    dp[7] = min( dp[7], dp[1]+dp[6]);
    dp[7] = min( dp[7], dp[2]+dp[5]);
    dp[7] = min( dp[7], dp[4]+dp[3]);
    
    dp[7] = min( dp[7], dp[3]+dp[5]);
    dp[7] = min( dp[7], dp[3]+dp[6]);
    dp[7] = min( dp[7], dp[5]+dp[6]);
    

    if(dp[7] >= INF){
        cout << -1 << endl;
    }
    else cout << dp[7] << endl;

}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int t =1; 
    // cin >> t;  

    while (t--) {
        solve();  
    }

    return 0;
}
/*
001 - C
010 - B
100 - A

111 (7) - ABC
mask [1-> 7]

*/
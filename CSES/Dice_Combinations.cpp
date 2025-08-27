#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 

    ll n; cin >> n;
    int MOD = 1000000007;


    vector<ll> dp(n+1);
    dp[0] = 1;

    for (int i= 1; i<n+1; i++){
        if (i-1 >= 0) dp[i] = (dp[i] +dp[i-1])%MOD ;
        if (i-2 >= 0) dp[i] = (dp[i] +dp[i-2])%MOD;
        if (i-3 >= 0) dp[i] = (dp[i] +dp[i-3])%MOD;
        if (i-4 >= 0) dp[i] = (dp[i] +dp[i-4])%MOD;
        if (i-5 >= 0) dp[i] = (dp[i] +dp[i-5])%MOD;
        if (i-6 >= 0) dp[i] = (dp[i] +dp[i-6])%MOD;

    }
    ll resp = dp[n];
    cout << resp << endl;
    return 0;

}

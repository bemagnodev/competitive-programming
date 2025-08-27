#include <bits/stdc++.h>

using namespace std;

using ll = long long;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; // Número de moedas
    int x; // Soma desejada
    cin >> n >> x;

    vector<int> coins(n);
    for (int i = 0; i < n; ++i) {
        cin >> coins[i];
    }

    const int INF = 1e9;

    vector<int> dp(x + 1, INF);

    dp[0] = 0;

    for (int i = 1; i <= x; ++i) {
        for (int coin_value : coins) {
            if (i - coin_value >= 0) {
                dp[i] = min(dp[i], dp[i - coin_value] + 1);
            }
        }
    }


    if (dp[x] == INF) {
        cout << -1 << endl;
    } else {
        cout << dp[x] << endl;
    }

    return 0;
}

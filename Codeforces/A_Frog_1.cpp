#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 

    int n; cin >> n;
    vector<int> dp(n+1); //minima altura pulada até chegar na pedra i
    vector<int> alturas(n+1);

    for( int i = 1; i < n+1; i++){
        int h; cin >>alturas[i];
    }

    //casos base
    dp[1] = 0;
    dp[2] = abs(alturas[1] - alturas[2]); 

    for( int i = 3; i < n+1; i++){
       int caso_pulo_de_um = dp[i-1]+ abs(alturas[i]- alturas[i-1]);
       int caso_pulo_de_dois = dp[i-2]+ abs(alturas[i]- alturas[i-2]);
       
        dp[i] = min(caso_pulo_de_dois, caso_pulo_de_um);

    }
    int resposta = dp[n];
    cout << resposta << endl;

    return 0;


}

#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(NULL);    
    ios_base::sync_with_stdio(false); 


    int n, k ; cin >> n >> k;
    
    vector<int> alturas(n);
    for( int i = 0; i < n; i++){
        cin >>alturas[i];
    }
    
    vector<long long> dp(n); //minima altura pulada até chegar na pedra i
    
    //casos base
    dp[0] = 0;


    for( int i = 1; i < n; i++){
        int caso_minimo = 2e10;
        
        for( int j = 1; j < k+1; j++){
            if (i-j < 0) break;
            int caso_pulo_atual = dp[i-j]+ abs(alturas[i]- alturas[i-j]);
            caso_minimo = min(caso_minimo, caso_pulo_atual);
        }
       
        dp[i] = caso_minimo;
    }
    int resposta = dp[n-1];
    cout << resposta << endl;

    return 0;


}

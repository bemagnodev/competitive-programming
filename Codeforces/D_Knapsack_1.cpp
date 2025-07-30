#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 

    ll n, peso_max; cin >> n >> peso_max;

    vector<bool> possible(peso_max+1, false);
    //caso base
    possible[0] = true;
    ll maior_valor = 0;
    vector<ll> dp(peso_max+1, 0); // valor equivalente a cada caso possible

    vector<ll> pesos(n);
    vector<ll> valores(n);
    for( int i = 0; i < n; i++){

        ll peso, valor; 
        cin >> peso >> valor;
        pesos[i] = peso;
        valores[i] = valor;
    }

    for (int i = 0; i < n; i++) { //itera pelos pesos
        for (int j = peso_max; j >= 0; j--) { //itera reversamente por possible
            ll peso_possivel = j+pesos[i];
            if (possible[j] && peso_possivel <= peso_max){
                possible[peso_possivel] = true; //atualiza possible
                dp [peso_possivel] =   max(dp[peso_possivel],valores[i] + dp[j]); //atualiza dp
                maior_valor = max(maior_valor, dp[peso_possivel]); //atualiza maior valor
            } 
        }
    }
    cout << maior_valor <<endl;

    // for( int i = 0; i < peso_max+1; i++){
    //     cout << possible[i] << endl;
    // }

    return 0;


}

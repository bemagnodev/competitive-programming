#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 

    int t; cin >> t;

    while(t--){
        ll n, b, a ;
        cin >> n >> a >> b;
        string resposta;
        //gerar string de tamanho n, com substirngs de tamnho a 
        //com b letras distintas
        for( int i = 0; i < n; i++){
            char c_inicial = 'a';
            c_inicial += (i % b)%26;
            resposta.push_back(c_inicial);
            cout <<c_inicial ;

            


        }
        cout << endl;
    }
    
    return 0;

}

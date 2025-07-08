#include <bits/stdc++.h>

using namespace std;

bool compararPorTamanho(string& a, string& b){
    return (a.size() < b.size());
}

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 

    //entrada
    int n; cin >> n;
    vector<string> palavras(n);

    for(int i = 0; i<n; i++){
        cin >> palavras[i];
    }  

    //ordenar por tamanho array (palavras) de strings
    sort(palavras.begin(), palavras.end(), compararPorTamanho);
    //verificar substring a[i], a[i+1]
    for(int i = 0; i<n-1; i++){
        string palavra_maior = palavras[i+1];
        string palavra_menor = palavras[i];
        if  (palavra_maior.find(palavra_menor) == string::npos){
            cout << "NO" << endl;
            return 0;

        }

    }


    cout << "YES" <<endl;
    for(int i = 0; i<n; i++){
        cout << palavras[i] << endl;
    }


  
    return 0;


}

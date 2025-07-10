#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 

    int t; cin >> t;
    int numero_unico;
    int index_unico;
    while (t--){
        int n; cin >> n;
        set <int> numeros; // index, freq
        vector<int> lista(n);

    
        for( int i = 0; i < n; i++){
            cin >> lista[i];
            if(numeros.size() && !numeros.count(lista[i])){
                numero_unico = lista[i];
                index_unico = i + 1;
            }
            numeros.insert(lista[i]);
        }

         

        cout << index_unico  << endl;

    }

    return 0;


}

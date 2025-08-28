#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    
    map<int, int> s; 
    long long soma = 0;
    
    for(int j = 0; j < n; j++){
        int valor_procurado = j - a[j];
        if(s.count(valor_procurado)){
            soma += s[valor_procurado];
        }

        int valor_a_guardar = j + a[j];
        s[valor_a_guardar]++;
    }
    
    cout << soma << endl;

    return 0;
}
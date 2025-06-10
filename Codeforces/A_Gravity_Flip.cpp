#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    //1. Recebe n -> colunas
    int n; cin >> n;
    //2. Recebe ai -> altura (guarda num vector)
    vector<int> v(n);

    for (int i =0 ; i< n; i++){
        int altura ; cin >> altura;
        v[i] = altura;
    }
    //3.  resosta sort re verse da lista 
    sort(v.begin(), v.end());

    for (int i =0 ; i< n; i++){
        cout << v[i] << " ";
    }

    return 0;
}
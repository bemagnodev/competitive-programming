#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 


    ll n, m ; cin >> n >> m;
    // maximo = todas as equipes como q e uma com todos os restantes
    // combinação k =(n- m+ 1) escolhe dois
    //(k(k-1))/2
    ll k = n - m +1;
    ll maximo = (k*(k-1))/2;
    // tentar distribuir igualmente entre os grupos
    ll a = n /m;
    ll b = n % m;
    //b grupos de a+1 C(p,2)
    ll p = a+1;
    //m -b grupos de a  C(q,2)
    ll q = a;
    ll minimo = b*(p*(p-1))/2 + (m-b)* (q*(q-1))/2;
    cout << minimo <<" " <<  maximo<<endl;
    
    return 0;

}

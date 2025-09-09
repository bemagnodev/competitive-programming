#include <bits/stdc++.h>
using namespace std;
#define ll long long 
string calc(ll k){

    string resp;
    if (k==1) resp = "2";
    else if (k==2) resp = "(2)^2";
    else if (k%2==0) resp = "(" +calc(k/2) + ")^2";
    else if (k%2!=0) resp = "(2*" +calc(k-1) + ")";

    return resp;
    }

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    

    int t; cin >> t;
    while(t--){
        ll k; cin >>k;
       cout << calc(k) << endl;

    }

    return 0;
}
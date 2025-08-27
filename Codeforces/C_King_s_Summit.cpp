#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int p; cin >> p;
    vector<ll> x(p);
    vector<ll> y(p);
    for(int i =0; i < p; i++){
        ll a, b; cin >>a >> b;
        x[i]= a;
        y[i]= b;
    }
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    ll dx = (x[p-1] - x[0]+1)/2;
    ll dy = (y[p-1] - y[0]+1)/2;
    cout << max(dx, dy) << endl;

   return 0;
}
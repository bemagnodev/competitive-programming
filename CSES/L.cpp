#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define all(x) x.begin(), x.end()
#define pb push_back
#define sz(x) (int)(x).size()
#define ins insert
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pair<int, int>> vpii;

const int MOD = 1e9+7;
ll fexp(ll b, ll e){
    ll ret=1;
    b %= MOD;
    while(e){
        if(e%2) ret = ret*b % MOD;
        e/=2;
        b= b*b%MOD;
    }
    return ret;
}

ll inv(ll b){
    return fexp(b,MOD-2);
}

void solve(){
    ll n; cin >> n;
    n %=MOD;

    ll termo1 = n;
    ll termo2 = ((2*n)%MOD * ((n+1)%MOD))%MOD;
    ll termo3 = (((2*n)%MOD * ((n+1)%MOD))%MOD *  ((2*n+1)%MOD)%MOD);
    termo3 = (termo3 *inv(3))%MOD;
    // ll ans= (((3*(n%MOD))%MOD+(2*(n%MOD)%MOD*(n%MOD)%MOD)%MOD + ((2*(n%MOD))%MOD*((n+1)%MOD)%MOD*((2*((n)%MOD)%MOD)+1)%MOD)%MOD*inv(3)))%MOD;
   ll ans =(( termo1 + termo2)%MOD + termo3)%MOD;
    //cout << (3*inv(3))%MOD << "\n";
    cout << ans << endl;
} 


int main(){
    ios::sync_with_stdio(false),cin.tie(0);
    solve();
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, a ,b; cin >> n >> a >> b;
    string s; cin >> s;
    string r;
    for(int i =a; i< n-b; i++){
        r+=s[i];
    }
    cout << r << endl;
    return 0;
}
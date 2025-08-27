#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int q; cin >> q;
    vector<int> v;
    while(q--){
        int k; cin >>k;
        if (k == 1){
            int b; cin >> b;
            v.push_back(b);
        }
        else if(k ==2){
            sort(v.rbegin(), v.rend());
            cout << v.back() << endl;
            v.pop_back();
        }   
    }

   return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m; cin >> n >> m;
    vector<int> a(n);
    for(int i =0; i< n; i++){
        cin >> a[i];
    }

    for(int i =0; i< m; i++){
        int x ; cin >> x;
        for(int i =0; i< a.size(); i++){
            if(x == a[i]){
                a.erase(a.begin()+ i);
                break;
            }
            
        }

    }
    for(int i : a){
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
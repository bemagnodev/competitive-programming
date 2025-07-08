#include <bits/stdc++.h>

using namespace std;

 
int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 

    //entrada
    string s1, s2 ,s3;
    cin >> s1 >> s2 >> s3;
    string total = s1+s2;
    sort(total.begin(), total.end());
    sort(s3.begin(), s3.end());
    if(total == s3){
        cout << "YES" <<endl;

    }
    else cout << "NO" <<endl;


    


  
    return 0;


}

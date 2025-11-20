    #include <bits/stdc++.h>
    using namespace std;
    #define deb(k) cerr << #k << ": " << k << "\n";

    const double PI = acos(-1.0);

    double R, px, py;

    double calc_calota(double d){
        if (d >= R) return 0;
        double theta =2.0* acos(d/R);
        return (R* R*theta)/2.0 - (d*sqrt(R*R-d*d));
    }

    int main() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        cin >> R >> px >> py;
        px= abs(px);
        py= abs(py);
        
        double ax = sqrt((R*R)-(py*py));
        double by = sqrt((R*R)-(px*px));

        double alfa = asin(px/R);
        double beta = asin(py/R);

        double a1 = (R * R * alfa) / 2.0;
        double a2 = (R * R * beta) / 2.0;
        double setor = (R * R * PI) / 4.0 - a1 - a2;

        double t1 = (ax - px) * py / 2.0;
        double t2 = (by - py) * px / 2.0;

        double q1 = setor - t1 - t2;

         

    double calota_direita = calc_calota(px); 
    double calota_cima = calc_calota(py);    

    double q2 = calota_direita - q1;
    double q3 = calota_cima - q1;

    double q4 = PI * R * R - q1 - q2 - q3;

    vector<double> ans = {q1, q2, q3, q4};
    sort(ans.begin(), ans.end());

    cout << fixed << setprecision(3);
    cout << ans[0] << " " << ans[1] << " " << ans[2] << " " << ans[3] << endl;

    return 0;
}


 
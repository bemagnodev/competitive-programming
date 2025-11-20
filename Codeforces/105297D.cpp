    #include <bits/stdc++.h>
    using namespace std;

    #define fastio cin.tie(0)->sync_with_stdio(0);
    #define FOR(i, a, b) for (int i = (a); i < (b); ++i)
    #define ROF(i, a, b) for (int i = (b)-1; i >= (a); --i)
    #define all(x) (x).begin(), (x).end()
    #define deb(k) cerr << #k << ": " << k << "\n";
    using ll = long long;
    using vi = vector<int>;
    using vl = vector<ll>;
    using pii = pair<int, int>;
    #define mii map<int, int>

    #define st first
    #define nd second
    const int MOD = 1e9 + 7;  
    const ll INF = 1e18;


    double X, Y, Z;         
    double tx, ty, tz;       
    double tr;               

    double dist(double x1, double y1, double z1, double x2, double y2, double z2) {
        return (x1 - x2) * (x1 - x2) + 
            (y1 - y2) * (y1 - y2) + 
            (z1 - z2) * (z1 - z2);
    }

    // da pra botar maca de raio R
    bool check(double R) {
        double min_x = R, max_x = X - R;
        double min_y = R, max_y = Y - R;
        double min_z = R, max_z = Z - R;

        if (min_x > max_x || min_y > max_y || min_z > max_z) {
            return false;
        }

        vector<double> xs = {min_x, max_x};
        vector<double> ys = {min_y, max_y};
        vector<double> zs = {min_z, max_z};

        double min_dist_needed = R + tr;
        double min_dist_sq_needed = min_dist_needed * min_dist_needed;

        for (double cx : xs) {
            for (double cy : ys) {
                for (double cz : zs) {
                    if (dist(cx, cy, cz, tx, ty, tz) >= min_dist_sq_needed) {
                        return true;
                    }
                }
            }
        }

        return false;
    }

    int main() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        cin >> X >> Y >> Z;
        cin >> tx >> ty >> tz;
        cin >> tr;

        double low = 0.0;
        double high = min({X, Y, Z}) / 2.0;
        
        for (int i = 0; i < 100; i++) {
            double mid = low + (high - low) / 2;
            if (check(mid)) {
                low = mid; 
            } else {
                high = mid;  
            }
        }

        cout << fixed << setprecision(15) << low << endl;

        return 0;
    }
    

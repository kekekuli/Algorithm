#include <iostream>
#include <vector>
#define LL long long
using namespace std;

LL gcd(LL a, LL b){
    return b == 0 ? a : gcd(b, a % b);
}
void solve(){
    LL a, b, c, d, x, y;
    cin >> a >> b >> c >> d;
    vector<LL> as, bs;
    for (int i = 1; i <= a / i; i++){
        if (a % i == 0){
            as.push_back(i);
            if(a / i != i)
                as.push_back(a / i);
        }
    }
    for (int i = 1; i <= b / i; i++){
        if (b % i == 0){
            bs.push_back(i);
            if (b / i != i)
                bs.push_back(b / i);
        }
    }

    for (int i = 0; i < as.size(); i++){
        for (int j = 0; j < bs.size(); j++){
            LL factor = as[i] * bs[j];
            y = (d / factor) * factor;

            LL s = a * b / gcd(a * b, y);
            x = (c / s) * s;

            if (x <= c && y <= d && a < x && b < y){
                cout << x << " " << y << endl;
                return;
            }
        }
    }
    cout << "-1 -1" << endl;
}
int main(){
    int t;
    cin >> t;
    while(t--)
        solve();
    
    return 0; 
}
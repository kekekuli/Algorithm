#include <iostream>
#define LL long long
using namespace std;
LL gcd(LL a, LL b){
    return b == 0 ? a : gcd(b, a % b);
}
LL swap(LL &a, LL &b){
    LL t = a;
    a = b;
    b = t;
}
void solve(){
    LL n, m, q, k0, k1, g;
    cin >> n >> m >> q;
    g = gcd(n, m);
    //k0个n分成的小份与k1个m分成的小份处于一个区域
    k0 = n / g, k1 = m / g;      
    for (int i = 0; i < q; i++){
        LL sx, sy, ex, ey;
        LL h0, h1;
        cin >> sx >> sy >> ex >> ey;
        if (g == 1){
            cout << "YES" << endl;
            continue;
        }
        else{
            //处理1 2和2 1
            if (sx != ex){
                if (sx != 1){
                    swap(sx, ex);
                    swap(sy, ey);
                }

                h0 = sy / k0 + (sy % k0 != 0);
                h1 = ey / k1 + (ey % k1 != 0);
            }
            //处理都是1
            else if (sx == 1){
                h0 = sy / k0 + (sy % k0 != 0);
                h1 = ey / k0 + (ey % k0 != 0);
            }
            //处理都是2
            else{
                h0 = sy / k1 + (sy % k1 != 0);
                h1 = ey / k1 + (ey % k1 != 0);
            }
            if (h0 == h1)
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
    }
}
int main(){
    solve();
    return 0;
}
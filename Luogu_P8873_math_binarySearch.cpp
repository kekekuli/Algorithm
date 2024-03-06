#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
#define LL  long long

LL s(LL i){
    LL n = i + 1;
    return n *(2 * n - 1); 
}
// 从0开始计数
LL f(LL k){
    return (long long)((1 + sqrt(1 + 8 * k))/4);
}
int main(){
    LL q, k;
    cin >> q;
    LL bnb = 4000000000000000000 - 1000; 
    while(q--){
        //k = bnb ++ ;
        cin >> k;
        k -= 1;
        if (k == 0){
            cout << 0 << endl;
            continue;
        }
        LL m = f(k);
        // h begin at 0
        LL h = k - s(m - 1);
        //cout << k << " in " << m << " at " << h << endl;
        LL an = 4 * (m + 1) - 3; 
        //cout << m << " has " << an << endl;

        LL dir = 1;
        if (h > an / 2){
            h -= an / 2;
            dir = -1;
        }
        if (h > m){
            cout << dir * (m - (h - m)) << endl;
        }
        else{
            cout << dir * h << endl;
        }
    } 
    return 0;
}